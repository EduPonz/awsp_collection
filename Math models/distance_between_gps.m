r = 6371; % Earth radious
% theta -> latitude (N)
% phi -> longitude (E)
% beta -> bearing (angle between two point with 0º in N and increasing
% clockwise)
% p = [r, theta, phi]

p1 = [r, 57.049057, 9.921284]; % Rerence point (start)
p2 = [r, 57.059295, 9.935559]; % Actual location
p3 = [r, 57.050027, 9.918123]; % Destination

[distance, bearing] = haversine(p1, p1);
r = [distance, bearing];
[distance, bearing] = haversine(p1, p2);
r1 = [distance, bearing];
[distance, bearing] = haversine(p1, p3);
r2 = [distance, bearing];

cartesian_r = [cosd(to_normal_angle(r(2))) * r(1), sind(to_normal_angle(r(2))) * r(1)]
cartesian_p1 = [cosd(to_normal_angle(r1(2))) * r1(1), sind(to_normal_angle(r1(2))) * r1(1)]
cartesian_p2 = [cosd(to_normal_angle(r2(2))) * r2(1), sind(to_normal_angle(r2(2))) * r2(1)]

function [arc, az] = haversine(p1, p2)
    [arc, az] = distance(p1(2), p1(3), p2(2), p2(3));
    arc = deg2rad(arc) * p1(1);
end

function angle = to_normal_angle(a)
    angle = 450 - a;
    while angle > 360
        angle = angle - 360;
    end
end