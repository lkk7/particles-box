#ifndef READCFG_HPP
#define READCFG_HPP

#include <iostream>

/* Read config.cfg into given variables */
bool readcfg(int &win_w, 
             int& win_h, 
             int& particle_px_size,
             int& number_of_particles, 
             double& particle_speed);

#endif