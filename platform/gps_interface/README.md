Example for interfacing with the Qualcom L86-M33 GPS module. It requires wiringPi library.
To build run:
    make
    sudo ./gps

Output example:

    Connected to port: 3

    Number of lines read -> 1
    POSITION
    ========================
    Message --------------> $GPGGA,083214.000,5703.1779,N,00954.9530,E,1,9,1.39,23.0,M,42.5,M,,*6E
    Timestamp ------------> 083214.000
    Latitude -------------> 57.053
    Longitude ------------> 9.91588
    Fix ------------------> 1
    Number of satelites --> 9
    Horizontal Precision -> 1.39
    Altitude -------------> 23
