%% Known Variables %%

%%% Initial angular position in Euler angles at time t=0 %%%
phi_0 =0; 
theta_0 = 0;
psi_0 = 0;
%P_0 = [phi_0; theta_0; psi_0];

%%% Time in seconds in which the angular velocity is applied
t = 1; 

%%% Angular velocity in body frame
omega_b = [5 ; 0 ; 90];

%%% Rotation matrix for every vector from body frame to earth frame
Rx = [1 0 0; 0 cosd(phi_0) sind(phi_0); 0 -sind(phi_0) cosd(phi_0)];
Ry = [cosd(theta_0) 0 -sind(theta_0); 0 1 0; sind(theta_0) 0  cosd(theta_0)];
Rz = [cosd(psi_0) sind(psi_0) 0; -sind(psi_0) cosd(psi_0) 0; 0 0 1];
Rf = Rz*Ry*Rx;

%%% Angular velocity in world coordinates
omega = Rf*omega_b;

%% Transformation from Angular velocity to Euler angles rate of change (in Earth frame)
T = [1, sind(omega(1)*t)*tand(omega(2)*t), cosd(omega(1)*t)*tand(omega(2)*t); 0, cosd(omega(1)*t), -sind(omega(1)*t); 0, sind(omega(1)*t)/cosd(omega(2)*t), cosd(omega(1)*t)/cosd(omega(2)*t)];
Rate = T * omega;

%% Transformation of Euler rate vector to Euler angles after the motion is completed

%%% Euler angles after the motion with angular velocity omega
phi = Rate(1)*t;
theta = Rate(2)*t;
psi = Rate(3)*t;

%%% Position, described in Euler angles after the motion
Position = [phi; theta; psi]