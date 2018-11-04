#include "gps_interface.hpp"

GPSInterface::GPSInterface() { }

GPSInterface::~GPSInterface() { }

bool GPSInterface::open_connection(const char* serial_port, long baud_rate)
{
    port_ = serialOpen(serial_port, baud_rate);

    if (port_ >= 0)
    {
        read_raw_lines_();
        return true;
    }
    else return false;
}

int GPSInterface::get_port()
{
    return port_;
}

std::vector<std::string> GPSInterface::break_string_(std::string str, char separator)
{
    std::string result = "";
    std::stringstream ss(str);
    std::string substr;
    std::vector<std::string> content;

    while (ss.good())
    {
        getline(ss, substr, separator);
        if (substr != "")
            content.push_back(substr);
    }

    return content;
}

std::string GPSInterface::parse_to_degrees_(std::string str)
{
    std::vector<std::string> content = break_string_(str, '.');

    std::string minutes = content[0].substr(content[0].size() - 2);
    minutes += "." + content[1];

    std::string::size_type idx;
    float minutes_float = std::stof(minutes, &idx);
    minutes_float = minutes_float / 60;

    content[0].erase(content[0].end() - 2, content[0].end());
    idx = 0;
    float degrees_float = std::stof(content[0], &idx) + minutes_float;

    std::string degrees = std::to_string(degrees_float);
    return degrees;
}

bool GPSInterface::populate_position_(std::string position_line)
{
    std::string start = "$GPGGA";

    if (strncmp(position_line.c_str(), start.c_str(), start.size()) == 0)
    {
        std::vector<std::string> content = break_string_(position_line, ',');
        position_.timestamp = content[1];
        position_.latitude = parse_to_degrees_(content[2]) + content[3];
        position_.longitude = parse_to_degrees_(content[4]) + content[5];
        return true;
    }
    else return false;
}

position GPSInterface::get_position()
{
    std::vector<std::string> raw_lines = read_raw_lines_();

    for (int i = int(raw_lines.size()) - 1; i >= 0; i--)
        if (populate_position_(raw_lines[i])) break;

    return position_;
}

std::vector<std::string> GPSInterface::read_raw_lines_()
{
    char received;
    std::vector<std::string> lines;
    std::string line = "";
    while (serialDataAvail(port_))
    {
        received = serialGetchar(port_);
        line += received;
        if (received == '\n')
        {
            lines.push_back(line);
            line = "";
        }
    }

    return lines;
}

bool GPSInterface::close_connection()
{
    serialClose(port_);
    return true;
}
