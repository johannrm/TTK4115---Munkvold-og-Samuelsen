%% LQR with integral from last day
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

% x = [p; pdot; edot; gamma; zeta], u = [V(tilde)_s, D_d],
% r (in Gr) = [p_c; edot_c] = reference

A = [0, 1, 0, 0, 0;
     0, 0, 0, 0, 0;
     0, 0, 0, 0, 0;
     1, 0, 0, 0, 0;
     0, 0, 1, 0, 0];
 
B = [  0,   0;
       0, K_1;
     K_2,   0;
       0,   0;
       0,   0];

G = [ 0,  0;
      0,  0;
      0,  0;
     -1,  0;
      0, -1];
  
C = [1, 0, 0, 0, 0;
     0, 0, 1, 0, 0];

D = [0, 0;
     0, 0];

heli_sys = ss(A, B, C, D, ...
    'StateName', {'p'; 'p_dot'; 'e_dot'; 'gamma'; 'zeta'}, ...
    'InputName', {'V~_s'; 'V_d'}, ...
    'OutputName', {'p'; 'e_dot'});
    

%%%%%%%%%%% Implementing the lqr-with-integral controller

Q1int = [100,  0,   0,  0,  0;
           0, 10,   0,  0,  0;
           0,  0,  100,  0,  0;
           0,  0,   0, 20,  0;
           0,  0,   0,  0, 20];

Q2int = Q1int;

% Kun endring på Q(5,5)
Q2int(5, 5) = 40;
Q3int = Q2int;
Q3int(5,5) = 100;
Q4int = Q3int;
Q4int(5,5) = 10;

% Endring av Q(4,4)
Q5int = Q4int;
Q5(4,4) = 50;
Q6int = Q5int;
Q6int(4,4) = 10;
%kjapp endring av 5,5
R3 = [0.5, 0;
       0, 0.5];

   % Qint å tweake
Q1int = [50,  0,   0,  0,  0;
           0, 10,   0,  0,  0;
           0,  0,  100,  0,  0;
           0,  0,   0, 10,  0;
           0,  0,   0,  0, 10];
 
K = lqr(A, B, Q1int, R3);

F = [K(1,1), K(1,3);
     K(2,1), K(2,3)];

eig(A - B*K);

%% Implementation of observer from day 3
PORT = 7;
K_3 = g*(m_c*l_c - 2*m_p*l_h) / (m_c*l_c^2 + 2*m_p*(l_h^2 + l_p));

A = zeros(5);
A(1, 2) = 1;
A(3, 4) = 1;
A(5, 1) = K_3;

B = zeros(5, 2);
B(2, 2) = K_1;
B(4, 1) = K_2;

% LQR for the new system

%kjapp endring av 5,5
R3 = [1, 0;
       0, 1];

   % Qint å tweake
Q = [800,  0,   0,  0,  0;
           0, 10,   0,  0,  0;
           0,  0,  1000,  0,  0;
           0,  0,   0, 10,  0;
           0,  0,   0,  0, 100];
 
K = lqr(A, B, Q, R3)


F = [K(1,1), K(1,3);
     K(2,1), K(2,3)];


% All states are measurable
C = eye(5);

% Matrix that contains all pole placements to be tested
P = [-1, -1, -1, -1, -1;
     -2, -2, -2, -2, -2;
     -3, -3, -3, -3, -3;
     (15 + 25.98i), (15 - 25.98i), (25.98 + 15i), (25.98 - 15i), 30
     (15 + 25.98i), (15 - 25.98i), (25.98 + 15i), (25.98 - 15i), 30];
    
p = P(3, :); %Choosing row 3 (all poles in  - 3)
L = place(A', C', p)';