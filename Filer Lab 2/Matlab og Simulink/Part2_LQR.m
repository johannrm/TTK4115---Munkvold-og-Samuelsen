%% Initialiering

%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% Helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g   = 9.81;  % gravitational constant [m/s^2]
l_c = 0.46;  % distance elevation axis to counterweight [m]
l_h = 0.66;  % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92;  % counterweight mass [kg]
m_p = 0.72;  % motor mass [kg]

%%%%%%%%%%% measured values
V_s0 = 7.71;   % measured voltage [V]
e_0  = 0.57; % measured zero-angle for elevation [rad] 

%%%%%%%%%%% Measured and calculated constants
K_f = (-g*(m_c*l_c - 2*m_p*l_h))/(V_s0*l_h); %  motor constant = 0.1296 [N / V]
K_1 = K_f / (2*m_p*l_p); % pitch constant = 0.5141 [1/(V*s)] (?)
K_2 = (l_h*K_f) / (m_c*l_c^2 + 2*m_p*l_h^2); % elevation constant = 0.0827


%% State - space
%%%%%%%%%%% Implementing the state space system

% x = [p; p_dot; e_dot], u = [V(tilde)_s; V_d], y = [p; e_dot]

A = [0, 1, 0;
     0, 0, 0;
     0, 0, 0];
 
B = [  0,   0;
       0, K_1;
     K_2,   0];
  
C = [1, 0, 0;
     0, 0, 1];
 
 D = [0, 0;
      0, 0];
  
heli_sys = ss(A, B, C, D, ...
    'StateName', {'p'; 'p_dot'; 'e_dot'}, ...
    'InputName', {'V~_s'; 'V_d'}, ...
    'OutputName', {'p': 'e_dot'});

% %%%%%%%%%%% Finding the controller using place(A,B,p)
% fprintf('\nK- and F-matrix using place\neigenvalues:')

eigs1 = [-2.2;-2.3;-2.1];
eigs2 = [-1.1;-1.2;-1.3];
eigs3 = [-0.5;-0.6;-0.7];
eigs4 = 2 * eigs1;
eigs5 = [-2 + 2i; -2 - 2i; -3];

K = place(A,B,eigs5);

F = [K(1,1), K(1,3);
     K(2,1), K(2,3)];

%% LQR
%%%%%%%%%%% Finding the controller using lqr(A,B,Q,R)
fprintf('K- and F-matrix using lqr\n')
% cost of deviation of states
Q1 =  [100,  0,   0;
       0, 10,   0;
       0,  0, 100];
  
% cost of actuation
R1 = eye(2);
R2 = [0.1, 0;
       0, 0.1];
   
R3 = [0.5, 0;
       0, 0.5];

% gain matrix K
K = lqr(A, B, Q1, R3)

% F-matrix in the state-feedback and reference-feed-foreward controller
F = [K(1,1), K(1,3);
     K(2,1), K(2,3)];
 
A_cl = A - B*K;
eig(A_cl) 
%%
%%%%%%%%%%% Simulating the state-feedback system with gain matrix K
% 
A_cl = A - B*K;
% B_cl = B*F;
% 
% heli_sys_cl = ss(A_cl, B_cl, C, D, ...
%     'StateName', {'p'; 'p_dot'; 'e_dot'}, ...
%     'InputName', {'V~_s'; 'V_d'}, ...
%     'OutputName', {'p': 'e_dot'})
% step(heli_sys_cl)