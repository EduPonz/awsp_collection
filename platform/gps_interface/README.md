Example for interfacing with the Qualcom L86-M33 GPS module. It requires wiringPi library.
To build run:
    
    make
    sudo ./gps

Output example:

    Connected to port: 3

    ********************************** NEW POSITION **********************************
    Ellapsed time --------> 1002
    Number of lines read -> 1
    ----------------------------------------------------------------------------------
    POSITION
    ========================
    Message --------------> $GPGGA,090115.000,5703.1744,N,00954.9365,E,1,11,1.14,24.4,M,42.5,M,,*53
    Timestamp ------------> 090115.000
    Latitude -------------> 57.0529
    Longitude ------------> 9.91561
    Fix ------------------> 1
    Number of satelites --> 11
    Horizontal Precision -> 1.14
    Altitude -------------> 24.4
