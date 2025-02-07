#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
using namespace std;

class Character {
protected:
    int health;
    int x, y;
    char symbol;
    int force;

public:
    Character(int health, int x, int y, char symbol, int force);
    virtual int getHealth() const;
    virtual int getX() const;
    virtual int getY() const;
    virtual char getSymbol() const;
    virtual int getForce() const;
    virtual void setSymbol(char s);
    virtual void takeDamage(int damage);
    virtual void position(int newX, int newY);
    virtual ~Character() {}
};

Character::Character(int health, int x, int y, char symbol, int force)
    : health(health), x(x), y(y), symbol(symbol), force(force) {}

int Character::getHealth() const { return health; }
int Character::getX() const { return x; }
int Character::getY() const { return y; }
char Character::getSymbol() const { return symbol; }
int Character::getForce() const { return force; }
void Character::setSymbol(char s) { symbol = s; }
void Character::takeDamage(int damage) { health -= damage; }
void Character::position(int newX, int newY) { x = newX; y = newY; }


#endif
