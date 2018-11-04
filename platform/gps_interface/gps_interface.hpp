#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <wiringPi.h>
#include <wiringSerial.h>

struct position {
    std::string timestamp = "";
    std::string latitude = "";
    std::string longitude = "";
};

class GPSInterface
{
    private:
        int port_;
        position position_;
        std::vector<std::string> read_raw_lines_();
        bool populate_position_(std::string position_line);
        std::string parse_to_degrees_(std::string str);
        std::vector<std::string> break_string_(std::string str, char separator);
    public:
        GPSInterface();
        ~GPSInterface();
        bool open_connection(const char* serial_port, long baud_rate);
        bool close_connection();
        int get_port();
        position get_position();
};
