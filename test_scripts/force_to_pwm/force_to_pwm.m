filedata = 'test_data.xlsx';

increment_forward = xlsread(filedata,'A3:A11'); 
increment_backward= xlsread(filedata,'F3:F11'); 

force_forward_left = xlsread(filedata,'B3:B11');
force_forward_right = xlsread(filedata,'C3:C11');

force_backward_left = xlsread(filedata,'G3:G11');
force_backward_right = xlsread(filedata,'H3:H11');

fit_forward_left = fit(force_forward_left, increment_forward, 'poly2')
fit_forward_right = fit(force_forward_right,increment_forward, 'poly2')

fit_backward_left = fit(force_backward_left,increment_backward, 'poly2')
fit_backward_right = fit(force_backward_right,increment_backward,'poly2')

plot(force_backward_left, increment_backward)
hold on;
plot(fit_backward_left);
