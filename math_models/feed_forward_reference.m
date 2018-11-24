 %% Dynamics calculator %%
 
 %% Initial and Goal parameters%%
 initial_position = [-1, 3]; 
 initial_bearing = pi/2;      % Initial angular position [rad]
 initial_velocity = 0;
 
 goal_position  = [10,10];
 
 %% Boat Parameters %%
 
mass = 15;
inertia_z = 5.414;     % Inertia around z
L1 = 0.61;                 % Distance from the motor shaft to x-axis [m] 
damping_yaw = 3.5;
damping_surge = 2.7; 

%% Forces and Torques %%

ForceL = 1.38; % Force in left motor [N]
ForceR = 1.4; % Force in right motor [N]
input_torque = L1*ForceL - L1*ForceR; %% Torque that contributes to rotation

%% Velocities and Accelerations %%

%syms position(t) cosine_angle(t) cartessian_position_x(t) cartessian_position_y(t);
%syms linear_acc(t) linear_vel(t) linear_pos(t);
%syms angular_acc(t) angular_vel(t) angular_pos(t);
%syms xVelocity(t) yVelocity(t) xAcc(t) yAcc(t);
t = 0 : 0.5 : 500;
conv_rad_deg = 1; % Set to "1" if the desired unit is radians. Set to 180/pi if the desired unit is degrees

linear_acc = (ForceL + ForceR)./(mass + damping_surge.*t);
linear_vel = initial_velocity + linear_acc.*t;
linear_pos_displacement = 1/2*linear_acc.*t.*t;  

angular_acc = conv_rad_deg.*input_torque./(inertia_z + damping_yaw.*t);
angular_vel = angular_acc.*t;
angular_pos = initial_bearing + 1/2*angular_acc.*t.*t;


cosine_angle = cos(initial_bearing + 1/2*angular_acc.*t.*t);
sine_angle = sin(initial_bearing + 1/2*angular_acc.*t.*t);

xVelocity = (initial_velocity + linear_acc.*t) .* cosine_angle;
yVelocity = (initial_velocity + linear_acc.*t) .* sine_angle;

xAcc = linear_acc .* cosine_angle;
yAcc = linear_acc .* sine_angle;

cartessian_position_x =  initial_position(1) + (1/2) * xAcc .* t.*t;
cartessian_position_y =  initial_position(2) + (1/2) * yAcc .* t.*t;

plot (cartessian_position_x, cartessian_position_y)
xlim([-40 40])
ylim([-40 40])

















%% Figures Surge %%

%figure(1)
%fplot (linear_acc);
%title('Linear Acceleration')
%xlim([0 40])
%ylim([0 10])

%figure(2)
%fplot (linear_vel);
%title('Linear Velocity')
%xlim([0 40])
%ylim([0 2])

%figure(3)
%fplot (position);
%title('Linear Position')
%xlim([0 20])
%ylim([0 50])

%% Figures Yaw %%


%figure(4)
%fplot (angular_acc);
%title('Angular Acceleration')
%xlim([0 20])
%ylim([-50 50])

%figure(5)
%fplot (angular_vel);
%title('Angular Velocity')
%xlim([0 5])
%ylim([0 1])

%figure(6)
%fplot (angular_pos);
%title('Angular Position')
%xlim([0 2])
%ylim([-10 10])



