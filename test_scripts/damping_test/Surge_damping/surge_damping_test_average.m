%%Load excel tables %%

filedata1 = 'Test_6.xlsx';
filedata2 = 'Test_7.xlsx';
filedata3 = 'Test_8.xlsx';
filedata4 = 'Test_9.xlsx';
filedata5 = 'Test_10.xlsx';

%% Data definitions

mass = 16.084; %mass of the vessel in kg
time = xlsread(filedata1,'Z25:Z38'); %time vector in seconds

vel6= xlsread(filedata1,'O25:O38'); %Velocity vector in test 1
vel7= xlsread(filedata2,'O23:O36'); %Velocity vector in test 2
vel8= xlsread(filedata3,'O21:O34'); %Velocity vector in test 3
vel9= xlsread(filedata4,'O23:O36'); %Velocity vector in test 1
vel10= xlsread(filedata5,'O23:O36'); %Velocity vector in test 1
Velocity =[vel6 vel7 vel8 vel9 vel10]; %Velocity matrix for all three tests

%% Fitting the exponential to the test data points

Vel_mean = mean([Velocity], 2); %Average values from the velocity tests
ExpFit = fit(time,Vel_mean,'exp1') %The "fit" function fits an exponential from the form a*exp(b*x) to data points



ExpValues = coeffvalues(ExpFit); %Extracts the coefficients "a" and "b" from the form "a*exp(b*x)" into a vector;
ExpExpression = ExpValues(1)*exp(ExpValues(2)*time); %Populating the form "a*exp(b*x)" with the coefficients

Damping = -mass*ExpValues(2) %Damping in surge, sway and yaw is defined by m/s, where s corresponds to -b from the form "a*exp(b*x)"

plot(time, ExpExpression, 'LineWidth', 2) %Plotting the fit
hold on;
plot (time, Vel_mean) %Plotting the test results
