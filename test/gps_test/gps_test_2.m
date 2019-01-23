path = [1 1; 2 2; 3 3; 4 4; 5 5; 6 6; 7 7; 8 8; 9 9; 10 10];
real_data = [1 1;1.8 2.1; 3.2 3.4; 3.7 4; 5.1 4.3; 6.2 6.2; 7.3 8.5; 7.8 7.9; 8.8 9.2; 11 9.9];

path_x = [];
path_y = [];
for i = 1:10
    path_x = [path_x, path(i, 1)];
    path_y = [path_y, path(i, 2)];
end

real_x = [];
real_y = [];
for i = 1:10
    real_x = [real_x, real_data(i, 1)];
    real_y = [real_y, real_data(i, 2)];
end

clf(figure(1))
plot(path_x, path_y, '-o')
hold on
plot(real_x, real_y, '-o')
set(gca, 'xtick', [0:1:11])
grid on
axis([0 11 0 11])

segments = [];
for i = 2:10
    start = [path(i - 1, 1), path(i - 1 , 2)];
    end_ = [path(i, 1), path(i, 2)];
    segment = [start; end_]
    segments = [segments, segment];
end

segments

for i = 1:10
    p = [real_data(i, 1) real_data(i, 2)];
end

function d = distance_to_segment(p, start, end_)
      d_01 = distance_between_points(p, start);
      d_02 = distance_between_points(p, end_);
      d_12 = distance_between_points(start, end_);
      
      u = (d_01^2 + d_12^2 - d_02^2)/ (2 * d_01 * d_02);
      
      if (d_01 == 0 || d_02 == 0)
          d = 0;
      elseif (d_12 == 0)
          d = d_01;
      elseif (u <= 0)
          d = d_01;
      elseif ((d_01 * u) >= d_12)
          d = d_02;
      else
          d = d_01 * sqrt(1 - u^2);
      end
      
      d = real(d);
end

function d = distance_between_points(a, b)
    d = sqrt((b(1) - a(1))^2 + (b(2) - a(2))^2);
end
