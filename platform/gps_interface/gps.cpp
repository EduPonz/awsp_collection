#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "gps_interface.hpp"

int main() 
{
    GPSInterface gps;

    if (gps.open_connection("/dev/ttyS0", 9600))
        std::cout << "Connected to port: " << gps.get_port() << std::endl;
    else
    {
        std::cout << "Cannot connect" << std::endl;
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        delay(1000);
        position last_position = gps.get_position();
        std::cout << "\nIteration number " << i << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "\tTimestamp -> " << last_position.timestamp << std::endl;
        std::cout << "\tLatitude -> " << last_position.latitude << std::endl;
        std::cout << "\tLongitude -> " << last_position.longitude << std::endl;
    }
    gps.close_connection();

    return 0;
}
