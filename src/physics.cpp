#include <cmath>
#include <random>
#include <iostream>
#include "physics.hpp"

Physics::Physics(int width, int height, int size, int quantity, double speed) 
    : container_width(width), container_height(height), px_size(size), particle_speed(speed)
{   
    /* Create particles and init them */
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
    std::uniform_real_distribution<double> dist(0, 1);
    std::uniform_int_distribution<> sign(0, 1);

    for (int j = 0, p = 0; j < column_length; j++)
    {
        for (int i = 0; i < row_length; i++, p++)
        {
            if (p >= static_cast<int>(particles.size())) break;
            particles[p]->x = i * px_size;
            particles[p]->y = j * px_size;
            particles[p]->vx = dist(gen) * particle_speed * (sign(gen) == 1 ? 1 : -1);
            particles[p]->vy = sqrt(particle_speed * particle_speed - particles[p]->vx * particles[p]->vx) * (sign(gen) == 1 ? 1 : -1);
            particles[p]->recent_collisions = 0;
        }
    }

    return 1;
}

void Physics::manage_container(Particle* p)
{
    /* Reverse corresponding velocity if a particle hits a wall of the container */
    if ((p->x < 0) || (p->x + px_size > container_width))
        {
            p->vx = -p->vx;
        }
        if ((p->y < 0) || (p->y + px_size > container_height))
        {
            p->vy = -p->vy;
        }
}

void Physics::manage_collision(Particle *p, Particle* q)
{
    /* Manage a collision of two particles */
    double distance = sqrt(((p->x - q->x) * (p->x - q->x)) + ((p->y - q->y) * (p->y - q->y)));
    if ((p->recent_collisions == 1) && (q->recent_collisions == 1) && distance <= px_size)
    {
        p->vx *= -1;
        p->recent_collisions++;
        q->recent_collisions++;

    }
    else if (distance <= px_size) 
    {
        double temp_vx = p->vx;
        double temp_vy = p->vy;
        p->vx = q->vx;
        p->vy = q->vy;
        q->vx = temp_vx;
        q->vy = temp_vy;
        p->recent_collisions++;
        q->recent_collisions++;
    }
    else
    {
        p->recent_collisions = q->recent_collisions = 0;
    }
}

void Physics::manage_all()
{
    /* Manage all collisions and velocities */
    int i = 0;
    for (auto particle : particles)
    {
        for (int j = particles.size() - 1; j > i; j--)
        {
            manage_collision(particles[i], particles[j]);
        }

        manage_container(particle);

        particle->x += particle->vx;
        particle->y += particle->vy;
        i++;
    }
}