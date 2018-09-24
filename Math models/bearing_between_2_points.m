% For these calculations, the Earth radius can be ignored, since we are
% only interested in angles. The coordinate system is placed so the first's
% point latitude is 0, therefore the second's point latitude is the
% difference in the real latitudes.

P_1 = [57.049057, 9.921284]; % Rerence point (start)
P_2 = [57.050027, 9.918123]; % Destination

beta = bearing(P_1(1), P_1(2), P_2(1), P_2(2))

function bear = bearing(phi_1, lambda_1, phi_2, lambda_2)
    d = lambda_2 - lambda_1;
    S = cosd(phi_2) * sind(d);
    C = cosd(phi_1) * sind(phi_2) - sind(phi_1) * cosd(phi_2) * cosd(d);
    bear = rad2deg(atan2(S, C));
    if bear < 0
        bear = 360 + bear;
    end
end
