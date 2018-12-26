%% Load csv file
file_name = '/home/davidm/Documents/Projects/P5/catkin_ws/10_min_recording/mpu6050_recording_10hz.csv';
M = csvread(file_name);

% M columns: timestamp, accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z

format longG;

timestamp = M(:,1);
recording_length = timestamp(end) - timestamp(1);   %total runtime in millis
recording_length = recording_length/1000;           %seconds
recording_length = recording_length/60              %minutes
z_score_99 = 2.576;
M(:,8) = [];

%% Acceleration x, y, z drift:
figure('Renderer', 'painters', 'Position', [1000 1000 900 600]);
    
subplot(3,1,1);
timestamp = M(:,1);
for i = 1:length(timestamp)
    timestamp_1(i) = timestamp(i) - timestamp(1);
end
[XOut,YOut] = prepareCurveData(timestamp_1, M(:,2));
mdl1 = fit(XOut, YOut, 'poly1')
plot(timestamp_1, M(:,2));
% axis([0, inf]);
hold on;
plot(mdl1);
title('$\ddot{x_b}$','Interpreter', 'latex', 'FontSize', 15)
% xlim([0, length(M(:,2))]);

subplot(3,1,2);
timestamp = M(:,1);
for i = 1:length(timestamp)
    timestamp_2(i) = timestamp(i) - timestamp(1);
end
[XOut,YOut] = prepareCurveData(timestamp_1, M(:,3));
mdl2 = fit(XOut, YOut, 'poly1')
plot(timestamp_2, M(:,3));
hold on;
plot(mdl2);
title('$\ddot{y_b}$','Interpreter', 'latex', 'FontSize', 15)
ylabel('Acceleration [g]')
% xlim([0, length(M(:,2))]);

subplot(3,1,3);
timestamp = M(:,1);
for i = 1:length(timestamp)
    timestamp_3(i) = timestamp(i) - timestamp(1);
end
[XOut,YOut] = prepareCurveData(timestamp_1, M(:,4));
mdl3 = fit(XOut, YOut, 'poly1')
plot(timestamp_3, M(:,4));
hold on;
plot(mdl3);
xlabel('Samples');
title('$\ddot{z_b}$','Interpreter', 'latex', 'FontSize', 15)
% xlim([0, length(M(:,2))]);


%% Gyro x, y, z drift
figure('Renderer', 'painters', 'Position', [1000 1000 900 600]);
subplot(3,1,1);
timestamp = M(:,1);
for i = 1:length(timestamp)
    timestamp_4(i) = timestamp(i) - timestamp(1);
end
[XOut,YOut] = prepareCurveData(timestamp_1, M(:,5));
mdl4 = fit(XOut, YOut, 'poly1')
plot(timestamp_4, M(:,5));
hold on;
plot(mdl4);
title('$\dot{\phi_b}$','Interpreter', 'latex', 'FontSize', 15)
% xlim([0, length(M(:,5))]);

subplot(3,1,2);
timestamp = M(:,1);
for i = 1:length(timestamp)
    timestamp_5(i) = timestamp(i) - timestamp(1);
end
[XOut,YOut] = prepareCurveData(timestamp_5, M(:,6));
mdl5 = fit(XOut, YOut, 'poly1')
plot(timestamp_5, M(:,6));
hold on;
plot(mdl5);
title('$\dot{\theta_b}$','Interpreter', 'latex', 'FontSize', 15)
ylabel('Angular velocity [degrees/sec]')
% xlim([0, length(M(:,6))]);

subplot(3,1,3);
timestamp = M(:,1);
for i = 1:length(timestamp)
    timestamp_6(i) = timestamp(i) - timestamp(1);
end
[XOut,YOut] = prepareCurveData(timestamp_6, M(:,7));
mdl6 = fit(XOut, YOut, 'poly1')
plot(timestamp_6, M(:,7));
hold on;
plot(mdl6);
xlabel('Samples');
title('$\dot{\psi_b}$','Interpreter', 'latex', 'FontSize', 15)
% xlim([0, length(M(:,7))]);

%% Regression line on drift
figure();
timestamp = M(:,1);
for i = 1:length(timestamp)
    timestamp_1(i) = timestamp(i) - timestamp(1);
end
[XOut,YOut] = prepareCurveData(timestamp_1, M(:,3));
mdl = fit(XOut, YOut, 'poly1')
plot(timestamp_1, M(:,3));
hold on;
plot(mdl);


%% Calculate standard dev and variance of data

% Columns: timestamp, accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z
disp("Standard deviation and variance of each column:")
for column=M
    disp("---------------")
    avrg = mean2(column);
    disp(avrg)
%     std_dev = std(column);
%     variance = var(column);
%     disp("Std dev:")
%     disp(std_dev)
%     disp("Variance:")
%     disp(variance)
%     disp("Lower conf interfval:")
%     mean = mean2(column);
%     conf_lower = mean - (z_score_99 * (std_dev / sqrt(length(column))))
%     disp("Higher conf interfval:")
%     conf_higher = mean + (z_score_99 * (std_dev / sqrt(length(column))))
end
