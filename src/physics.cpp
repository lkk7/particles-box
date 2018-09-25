#include <cmath>
#include <iostream>
#include "physics.hpp"

Physics::Physics(int width, int height, int size, int quantity) : container_width(width), container_height(height), px_size(size)
{   
    /* Create particles and init them*/
    error = 0;
    particles.resize(quantity);
    for (auto &i : particles)
    {
        i = new Particle;
    }
    if (!init_particles()) return;

    std::cout << "particle container: " << container_width << " x " << container_height << " px\n"
                 "number of particles: " << particles.size() << "\n" 
                 "particle size: " << px_size << " px\n"<< std::flush;
}

Physics::~Physics()
{
    /* Delete particles */
    for (unsigned i = 0; i < particles.size(); i++)
    {
        delete(particles[i]);
    }
}


bool Physics::init_particles()
{
    if (static_cast<int>(floor(static_cast<float>(container_width * container_height) / (particles.size() * px_size * px_size))) < 1)
    {
        std::cout << "error: screen surface too small / particles too big!\n";
        error = 1;
        return 0;
    }

    int row_length = static_cast<int>(floor(static_cast<float>(container_width) / px_size));
    int column_length = static_cast<int>(ceil(static_cast<float>(particles.size()) / row_length));
    if (static_cast<int>(particles.size()) < row_length) 
    {
        row_length = particles.size();
    }
    
    for (int j = 0, c = 0; j < column_length; j++)
    {
        for (int i = 0; i < row_length; i++, c++)
        {
            if (c >= static_cast<int>(particles.size())) break;
            particles[c]->x = i * px_size;
            particles[c]->y = j * px_size;
        }
    }

    return 1;
}