filedata = 'test_data.xlsx';

increment_increase = xlsread(filedata,'A3:A11'); 
increment_decrease= xlsread(filedata,'F3:F11'); 

force_forward_left = xlsread(filedata,'B3:B11');
force_forward_right = xlsread(filedata,'H3:H11');

force_backward_left = xlsread(filedata,'G3:G11');
force_backward_right = xlsread(filedata,'C3:C11');

fit_forward_left = fit(force_forward_left, increment_increase, 'poly1')
fit_forward_right = fit(force_forward_right,increment_decrease, 'poly1')

fit_backward_left = fit(force_backward_left,increment_decrease, 'poly1')
fit_backward_right = fit(force_backward_right,increment_increase,'poly1')

figure(1)
plot(force_forward_left, increment_increase, '*')
title('Forward Left')
hold on;
plot(fit_forward_left);

figure(2)
plot(force_forward_right, increment_decrease, '*')
title('Forward Right')
hold on;
plot(fit_forward_right);

figure(3)
plot(force_backward_left, increment_decrease, '*')
title('Backward Left')
hold on;
plot(fit_backward_left);

figure(4)
plot(force_backward_right, increment_increase, '*')
title('Backward Right')
hold on;
plot(fit_backward_right);
