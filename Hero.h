#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <vector>
#include "Character.h"
using namespace std;


class Hero : public Character {
    public:
        Hero(int health, int x, int y, char symbol, int force);
        ~Hero() {}
    };
    Hero::Hero(int health, int x, int y, char symbol, int force)
    : Character(health, x, y, symbol, force) {}

#endif