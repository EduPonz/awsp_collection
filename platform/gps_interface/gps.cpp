#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "gps_interface.hpp"

void print_position(position position)
{
    std::cout << "POSITION"                 << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "Message --------------> " << position.message              << std::endl;
    std::cout << "Timestamp ------------> " << position.timestamp            << std::endl;
    std::cout << "Latitude -------------> " << position.latitude             << std::endl;
    std::cout << "Longitude ------------> " << position.longitude            << std::endl;
    std::cout << "Fix ------------------> " << position.fix                  << std::endl;
    std::cout << "Number of satelites --> " << position.number_of_satelites  << std::endl;
    std::cout << "Horizontal Precision -> " << position.horizontal_precision << std::endl;
    std::cout << "Altitude -------------> " << position.altitude             << std::endl;
}

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

    std::string last_time = "";
    int num_lines = 0;
    for (int i = 0; i < 10; i++)
    {
        delay(1000);
        num_lines = gps.read_lines();
        std::cout << "\nNumber of lines read -> " << num_lines << std::endl;
        position last_position = gps.get_position();
        if (last_position.timestamp != last_time) print_position(last_position);
    }
    gps.close_connection();

    return 0;
}
