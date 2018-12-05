 %% Dynamics calculator %%
 
 %% Initial and Goal parameters%%
 initial_position = [0, 0]; 
 initial_bearing = 0;      % Initial angular position [rad]
 initial_velocity = 0;
 
 goal_position  = [2,2];
 
 %% Boat Parameters %%
 
mass = 15;
inertia_z = 5.414;     % Inertia around z
L1 = 0.61;                 % Distance from the motor shaft to x-axis [m] 
damping_yaw = 3.5;
damping_surge = 2.7; 

%% Time settings %%

time_interval = 0.001;
t = 0 : time_interval : 90;  % Discrete time vector
time_points = length(t);    % Size of the time vector (total amount of time points)

%% Forces and Torques %%

ForceL = 2.7;                                         % Force in left motor [N]
ForceR = 2;                                         % Force in right motor [N]
input_torque = L1*ForceL - L1*ForceR;   % Torque that creates to rotation in yaw

%% Velocities and Accelerations %%

linear_acc = zeros([1 time_points]);                        % generates a vector with the length of the time vector with all zeros
linear_acc(1) = (ForceL + ForceR)/(mass);                  % sets the initial linear acceleration at the first entry of the linear acc vector
linear_vel = zeros([1 time_points]);   % generates a vector with the length of the time vector with all zeros      
linear_vel(1) = initial_velocity;
linear_pos_displacement = zeros([1 time_points]);               % generates a vector with the length of the time vector with all zeros

angular_acc = zeros([1 time_points]);           % generates a vector with the length of the time vector with all zeros
angular_acc(1) = input_torque/(inertia_z);      % Initial angular acceleration
angular_vel = zeros([1 time_points]);           % generates a vector with the length of the time vector with all zeros
angular_pos = zeros([1 time_points]);           % generates a vector with the length of the time vector with all zeros
angular_pos(1) = initial_bearing;           % Initial angular position (orientation of the boat in earth frame)


%% Main program %%

for k = 2 : time_points  % A loop that populates all acceleration, velocity and position vectors based on their corresponding formulas

linear_acc(k) =(ForceL + ForceR - damping_surge*linear_vel(k-1))/(mass + damping_surge*time_interval);
linear_vel(k) = linear_vel(k-1) + linear_acc(k-1)*time_interval;
linear_pos_displacement(k) = linear_pos_displacement(k-1) + linear_vel(k-1)*time_interval + linear_acc(k-1)*time_interval^2;

angular_acc(k) = (input_torque - damping_yaw*angular_vel(k-1))/(inertia_z + damping_yaw*time_interval);                    
angular_vel(k) = angular_vel(k-1) + angular_acc(k-1)*time_interval;                         
angular_pos(k) = angular_pos(k-1) + angular_vel(k-1)*time_interval + angular_acc(k-1)*time_interval^2;

end


%% Plotting the data onto a x-y cartessian plane %%

cosine_angle = cos(angular_pos);
sine_angle = sin(angular_pos);

xVelocity = linear_vel .* cosine_angle;
yVelocity = linear_vel .* sine_angle;

xAcc = linear_acc .* cosine_angle;
yAcc = linear_acc .* sine_angle;

cartessian_position_x = zeros([1 time_points]);
cartessian_position_x(1) =initial_position(1);
cartessian_position_y = zeros([1 time_points]);
cartessian_position_y(1) =initial_position(2);

x_goal = goal_position(1);
y_goal = goal_position(2);
%closest_angle = 0.1;



for j = 2 : time_points

cartessian_position_x(j) =  cartessian_position_x(j-1) + xVelocity(j-1) *time_interval + (1/2) * xAcc (j-1) * time_interval^2;
cartessian_position_y(j) =  cartessian_position_y(j-1) + yVelocity(j-1) *time_interval + (1/2) * yAcc (j-1) * time_interval^2;

angle_difference = atan2((y_goal - cartessian_position_y(j)), (x_goal - cartessian_position_x(j))) - angular_pos(j);

% if abs(angle_difference) < 0.1
%     if abs(angle_difference) < closest_angle
%         closest_angle = angle_difference;
%     end
% end

end

constant_vel = linear_vel(90/0.001)

linear_acc_for_const_vel =(ForceL + ForceR)/(mass + damping_surge*900000);
linear_vel_constant= linear_acc_for_const_vel*900000



desired_vel = 5;
Forces_magnitude = (desired_vel*mass + desired_vel*damping_surge*500000)/500000

constant_ang_vel = angular_vel(40/0.001);

angular_acc_for_constant_ang_vel = (input_torque)/(inertia_z + damping_yaw*400000);                 
angular_vel = angular_acc_for_constant_ang_vel*400000;                     



%% Sample time (example time) %%

% time_ex =4.95;                               % Time at which you want the example
% t_ex = (time_interval^-1)*time_ex;          % Calculates in which entry of the time vector is the desired time for the example
% angular_pos_ex = angular_pos(t_ex);
% cartessian_position_x_ex = cartessian_position_x (t_ex);
% cartessian_position_y_ex = cartessian_position_y (t_ex);
% 
% L = 50;
% x2=cartessian_position_x_ex +(L*cos(angular_pos_ex));
% y2=cartessian_position_y_ex +(L*sin(angular_pos_ex));



%atan2((y_goal - cartessian_position_y_ex), (x_goal - cartessian_position_x_ex))*180/pi - angular_pos_ex*180/pi


%% Figures Surge %%

% figure(1)
% plot(t, linear_acc)
% title('Linear Acc')
% xlim([0 30])
% ylim([0 10])
% 
 figure(2)
 plot(t, linear_vel)
 title('Linear Velocity')
 xlim([0 30])
 ylim([0 20])
% 
% figure(3)
% plot(t, linear_pos_displacement)
% title('Linear Position')
% xlim([0 30])
% ylim([0 100])
% 
% figure(4)
% plot (cartessian_position_x, cartessian_position_y);
% xlim([0 4])
% ylim([0 4])
% hold on;
% %plot(cartessian_position_x_ex, cartessian_position_y_ex, 'r*');
% %hold on;
% plot(x_goal, y_goal, 'r*');
%hold on;
%plot([cartessian_position_x_ex x2],[cartessian_position_y_ex y2]);

% 
% %% Figures Yaw %%
% 
% 
% figure(5)
% plot(t, angular_acc)
% title('Angular Acc')
% xlim([0 30])
% ylim([0 10])
% 
% figure(6)
% plot(t, angular_vel)
% title('angular vel')
% xlim([0 30])
% ylim([0 5])
% 
% figure(7)
% plot(t, angular_pos)
% title('Angular Position')
% xlim([0 30])
% ylim([0 10])
% 
% %figure(6)
% %fplot (angular_pos);
% %title('Angular Position')
% %xlim([0 2])
% %ylim([-10 10])



