#include <cmath>
#include <random>
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
    /* Check if particles can fit in */
    if (static_cast<int>(floor(static_cast<float>(container_width * container_height) / (particles.size() * px_size * px_size))) < 1)
    {
        std::cout << "error: screen surface too small / particles too big!\n";
        error = 1;
        return 0;
    }

    /* Set position and random velocities for each particle */
    int row_length = static_cast<int>(floor(static_cast<float>(container_width) / px_size));
    int column_length = static_cast<int>(ceil(static_cast<float>(particles.size()) / row_length));
    if (static_cast<int>(particles.size()) < row_length) 
    {
        row_length = particles.size();
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-9.99, 10.0);

    for (int j = 0, p = 0; j < column_length; j++)
    {
        for (int i = 0; i < row_length; i++, p++)
        {
            if (p >= static_cast<int>(particles.size())) break;
            particles[p]->x = i * px_size;
            particles[p]->y = j * px_size;
            particles[p]->vx = dist(gen);
            particles[p]->vy = dist(gen);
        }
    }

    return 1;
}

void Physics::manage_all()
{
    /* Manage collisions, velocities */
    for (auto particle : particles)
    {
        if ((particle->x < 0) || (particle->x + px_size > container_width))
        {
            particle->vx = -particle->vx;
        }
        if ((particle->y < 0) || (particle->y + px_size > container_height))
        {
            particle->vy = -particle->vy;
        }

        particle->x += particle->vx;
        particle->y += particle->vy;
    };
    return;
}