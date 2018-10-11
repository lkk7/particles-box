#include <fstream>
#include <string>
#include "readcfg.hpp"

bool readcfg(int& win_w,  int& win_h,  std::string& win_title, int& particle_px_size,
             int& number_of_parrticles, double& particle_speed)
{
    std::ifstream cfg_stream("config.cfg");
    if(!cfg_stream.is_open())
    {
       std::cout << "error: couldn't open config.cfg\n";
       return 0;
    }

    std::string buffer;
    while (cfg_stream >> buffer)
    {
        std::cout << buffer;
        if (buffer == "WIN_W")
        {
            win_w = std::stoi(buffer);
        }
        else if (buffer == "WIN_H")
        {
            std::cout << "X\n";
            win_h = std::stoi(buffer);
            std::cout << "X\n";
        }
        else if (buffer == "WIN_TITLE")
        {
            win_title = buffer;
        }
        else if (buffer == "PARTICLE_PX_SIZE")
        {
            particle_px_size = std::stoi(buffer);
        }
        else if (buffer == "PARTICLE_SPEED")
        {
            particle_speed = std::stod(buffer);
        }
    }
    return 1;
}