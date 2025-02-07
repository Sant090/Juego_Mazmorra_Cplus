#ifndef SUPERVILLIAN_H
#define SUPERVILLIAN_H

#include <iostream>
#include <vector>
#include "Villian.h"
#include "Character.h"

using namespace std;

class SuperVillian : public Villian {
    public:
        SuperVillian(int health, int x, int y, int f);
        ~SuperVillian() {}
    };
    SuperVillian::SuperVillian(int health, int x, int y, int f)
    : Villian(health, x, y, f) {}

#endif