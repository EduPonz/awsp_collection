%syms phi theta psi; 
phi =  -pi/2;
theta = pi;
%psi = pi/2; 

Rx = [cos(phi) sin(phi); -sin(phi) cos(phi)]
%%inv(Rx)
%%transpose(Rx)
Ry = [cos(theta) 0 -sin(theta); 0 1 0; sin(theta) 0  cos(theta)]
%Rz = [cos(psi) sin(psi) 0; -sin(psi) cos(psi) 0; 0 0 1]

%Rf = transpose(Rz)*transpose(Ry)*transpose(Rx)
Rf = Ry*Rx

SampleVector = [2; -1];
Rf*SampleVector

%transpose(Rf)*[-3;2;1]
