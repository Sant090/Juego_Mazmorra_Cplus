#ifndef VILLIAN_H
#define VILLIAN_H

#include <iostream>
#include <vector>
#include "Character.h"
using namespace std;

class Villian : public Character {
    public:
        Villian(int health, int x, int y, int f);
        ~Villian() {}
    };

    Villian::Villian(int health, int x, int y, int f)
    : Character(health, x, y, 'V', f) {}
#endif