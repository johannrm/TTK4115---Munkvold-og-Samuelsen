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
    'OutputName', {'p': 'e_dot'})

%%%%%%%%%%% Finding K and F using place(A,B,p)

% some random eigs
eigs = [-2.1;-3.2;-4.3];
disp(transpose(eigs))
K = place(A,B,eigs)

F = [K(1,1), K(1,3);
     K(2,1), K(2,3)]