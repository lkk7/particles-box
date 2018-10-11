#ifndef READCFG_HPP
#define READCFG_HPP

#include <iostream>

/* Read config.cfg into given variables */
bool readcfg(int& win_w, 
             int& win_h, 
             std::string& win_title, 
             int& particle_px_size,
             int& number_of_parrticles, 
             double& particle_speed);

#endif