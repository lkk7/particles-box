#include <fstream>
#include <string>
#include "readcfg.hpp"

bool readcfg(int& win_w,  int& win_h, int& particle_px_size,
             int& number_of_particles, double& particle_speed)
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
        if (buffer == "WIN_W")
        {
            cfg_stream >> buffer;
            win_w = std::stoi(buffer);
        }
        
        else if (buffer == "WIN_H")
        {
            cfg_stream >> buffer;
            win_h = std::stoi(buffer);
        }
        else if (buffer == "PARTICLE_PX_SIZE")
        {
            cfg_stream >> buffer;
            particle_px_size = std::stoi(buffer);
        }
        else if (buffer == "NUMBER_OF_PARTICLES")
        {
            cfg_stream >> buffer;
            number_of_particles = std::stoi(buffer);
        }
        else if (buffer == "PARTICLE_SPEED")
        {
            cfg_stream >> buffer;
            particle_speed = std::stod(buffer);
        }
        else
        {
            std::cout << "error: wrong config!";
        }
    }
    return 1;
}