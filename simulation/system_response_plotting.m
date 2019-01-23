%% Subplots of all the recorded responses
figure()
subplot(5,1,1)
plot(x_coordinates_pd_tuned.Data, y_coordinates_pd_tuned.Data)
title('Boat movement over time')
xlabel('X coordinates over time')
ylabel('Y coordinates over time')
grid on;
xlim([0, 1000])


subplot(5,1,2)
plot(theta_pd_tuned.Data)
title('Desired angle calculated')
xlabel('Time [s]')
ylabel('Angle [degrees]')
grid on;
xlim([0, 1000])

subplot(5,1,3)
plot(d_pd_tuned.Data)
title('Desired distance calculated')
xlabel('Time [s]')
ylabel('Distance [meters]')
grid on;
xlim([0, 1000])

subplot(5,1,4)
plot(d_travelled_pd_tuned.Data)
title('Distance travelled over time')
xlabel('Time [s]')
ylabel('Distance [meters]')
grid on;
xlim([0, 1000])

subplot(5,1,5)
plot(angle_travelled_pd_tuned.Data)
title('Angle rotated over time')
xlabel('Time [s]')
ylabel('Angle [degrees]')
grid on;
xlim([0, 1000])

%% Coordinates over time plot
figure()
plot(x_coordinates_pd_tuned.Data, y_coordinates_pd_tuned.Data)
title('Boat movement over time')
xlabel('X coordinates over time')
ylabel('Y coordinates over time')
grid on;
% xlim([0, 1000])

%% Desired angle
figure()
plot(theta_pd_tuned.Data)
title('Desired angle calculated')
xlabel('Time [s]')
ylabel('Angle [degrees]')
grid on;
xlim([0, 500])

%% Desired distance

figure()
plot(d_pd_tuned.Data)
title('Desired distance calculated')
xlabel('Time [s]')
ylabel('Distance [meters]')
grid on;
% xlim([0, 1000])

%% Distance travelled over time
figure()
plot(d_travelled_pd_tuned.Data)
title('Distance travelled over time')
xlabel('Time [s]')
ylabel('Distance [meters]')
grid on;
xlim([0, 1000])

%% Angle rotated over time
figure()
plot(angle_travelled_pd_tuned.Data)
title('Angle rotated over time')
xlabel('Time [s]')
ylabel('Angle [degrees]')
grid on;
xlim([0, 200])