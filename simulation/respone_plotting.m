%% Tuned surge step responses

figure();
plot(tuned_pid.Time ,tuned_pid.Data)
legend('tuned PID response');
xlabel('Time [s]')
ylabel('Distance step [m]')
grid on;

figure();
plot(tuned_p.Time ,tuned_p.Data)
legend('tuned P response');
xlabel('Time [s]')
ylabel('Distance step [m]')
grid on;

figure();
plot(tuned_pd.Time ,tuned_pd.Data)
legend('tuned PD response');
xlabel('Time [s]')
ylabel('Distance step [m]')
grid on;

figure();
plot(tuned_pi.Time ,tuned_pi.Data)
legend('tuned PI response');
xlabel('Time [s]')
ylabel('Distance step [m]')
grid on;

figure();
plot(tuned_pid.Time ,tuned_pid.Data)
hold on;
plot(tuned_p.Time ,tuned_p.Data)
hold on;
plot(tuned_pd.Time ,tuned_pd.Data)
hold on;
plot(tuned_pi.Time ,tuned_pi.Data)
title('Combined Tuned Responses')
xlabel('Time [s]')
ylabel('Distance step [m]')
lgd = legend('tuned PID response', 'tuned P response', 'tuned PD response','tuned PI response');
lgd.Location = 'south';
grid on;

%% Tuned yaw step responses

figure();
plot(tuned_pid_yaw.Time ,tuned_pid_yaw.Data)
legend('Tuned PID response');
xlabel('Time [s]')
ylabel('Angle step [degrees]')
grid on;

figure();
plot(tuned_p_yaw.Time ,tuned_p_yaw.Data)
legend('Tuned P response');
xlabel('Time [s]')
ylabel('Angle step [degrees]')
grid on;

figure();
plot(tuned_pd_yaw.Time ,tuned_pd_yaw.Data)
legend('Tuned PD response');
xlabel('Time [s]')
ylabel('Angle step [degrees]')
grid on;

figure();
plot(tuned_pi_yaw.Time ,tuned_pi_yaw.Data)
legend('Tuned PI response');
xlabel('Time [s]')
ylabel('Angle step [degrees]')
grid on;

figure();
plot(tuned_pid_yaw.Time ,tuned_pid_yaw.Data)
hold on;
plot(tuned_p_yaw.Time ,tuned_p_yaw.Data)
hold on;
plot(tuned_pd_yaw.Time ,tuned_pd_yaw.Data)
hold on;
plot(tuned_pi_yaw.Time ,tuned_pi_yaw.Data)
title('Combined Tuned Yaw Responses')
xlabel('Time [s]')
ylabel('Angle step [degrees]')
lgd = legend('tuned PID response', 'tuned P response', 'tuned PD response','tuned PI response');
lgd.Location = 'south';
grid on;