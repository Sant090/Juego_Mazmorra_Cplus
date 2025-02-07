#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <iostream>
#include <vector>
#include "Hero.h"
#include "Character.h"

using namespace std;

class SuperHero : public Hero{
    private:
        bool on;
    
    public:
        SuperHero(int health, int x, int y, int f, bool on);
        void transform();
        bool getOn();
        ~SuperHero() {}
    };

    SuperHero::SuperHero(int health, int x, int y, int f, bool on)
    : Hero(health, x, y, 'S', f), on(on) {}

void SuperHero::transform() { on = !on; }
bool SuperHero::getOn() { return on; }

#endif