#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class Character {
protected:
    int health;
    int x, y;
    char symbol;
    int force;

public:
    Character(int health, int x, int y, char symbol, int force) 
        : health(health), x(x), y(y), symbol(symbol), force(force) {}

    virtual int getHealth() const { return health; }
    virtual int getX() const { return x; }
    virtual int getY() const { return y; }
    virtual char getSymbol() const { return symbol; }
    virtual int getForce() const { return force; }
    virtual void setSymbol(char s) { symbol = s; }

    virtual void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    virtual void position(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

class Hero : public Character {
public:
    Hero(int health, int x, int y, char symbol, int force) : Character(health, x, y, symbol, force) {}
};

class Villian : public Character {
public:
    Villian(int health, int x, int y, int f) : Character(health, x, y, 'E', f) {}
};

class SuperVillian : public Villian {
public:
    SuperVillian(int health, int x, int y, int f) : Villian(health, x, y, f) {
        this->setSymbol('V');
    }
};

class SuperHero : public Hero {
public:
    bool on;

    SuperHero(int health, int x, int y, int f, bool on) 
    : Hero(health, x, y, '@', f), on(on) {}

    void transform() {
        setSymbol('&');
        force += 20;
        on = true;
    }

    bool getOn() { return on; }
};
vector<Villian> villanos1 = {

    Villian(10, 5, 3, 5),
    Villian(10, 8, 1, 5),
    Villian(10, 10, 2, 5),
    Villian(10, 1, 5, 5),
    Villian(10, 7, 5, 5),
    Villian(10, 7, 1, 5),
    Villian(10, 7, 4, 5),
    Villian(10, 7, 6, 5),
    Villian(10, 2, 10, 5),
    Villian(10, 10, 10, 5),
    Villian(10, 1, 12, 5),
    Villian(10, 3, 12, 5),
    Villian(10, 6, 12, 5)

};

vector<Villian> villanos2 = {
    Villian(10, 1, 8, 5),
    Villian(10, 1, 11, 5),
    Villian(10, 1, 18, 5),
    Villian(10, 2, 15, 5),
    Villian(10, 2, 19, 5),
    Villian(10, 3, 6, 5),
    Villian(10, 3, 18, 5),
    Villian(10, 4, 22, 5),
    Villian(10, 5, 4, 5),
    Villian(10, 7, 9, 5),
    Villian(10, 8, 11, 5),
    Villian(10, 8, 19, 5),
    Villian(10, 9, 26, 5),
    Villian(10, 11, 11, 5),
    Villian(10, 11, 15, 5),
    Villian(10, 12, 9, 5),
    Villian(10, 12, 20, 5),
    Villian(10, 13, 7, 5),
    Villian(10, 13, 14, 5),
    Villian(10, 13, 17, 5),
    Villian(10, 13, 24, 5)
};

vector<Villian> villanos = {};


vector<vector<char>> map1 = {
{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
{'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
{'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
{'#', ' ', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', ' ', '#'},
{'#', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#'},
{'#', '#', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
{'#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
{'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
{'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
{'#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
{'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
{'#', ' ', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#'},
{'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'T', '#'},
{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};
vector<vector<char>> map2 = {
{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
{'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ','#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
{'#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ',' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#'},
{'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ','#', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
{'#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', '#'},
{'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ','#', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', '#'},
{'#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ',' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
{'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#','#', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
{'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ',' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
{'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#',' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
{'#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', ' ',' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
{'#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
{'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#','#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#'},
{'#', '0', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};




void graphVillian(const vector<Villian>& villanos, vector<vector<char>>& matriz) {
    for (const auto& villano : villanos) {
        if (villano.getX() >= 0 && villano.getX() < matriz.size() &&
            villano.getY() >= 0 && villano.getY() < matriz[0].size()) {
            matriz[villano.getX()][villano.getY()] = villano.getSymbol();
        }
    }
}

void displayMap(vector<vector<char>>& map, Hero& player) {
    vector<vector<char>> tempMap = map;
    if (player.getX() >= 0 && player.getX() < tempMap.size() &&
        player.getY() >= 0 && player.getY() < tempMap[0].size()) {
        tempMap[player.getX()][player.getY()] = player.getSymbol();
    }

    graphVillian(villanos, tempMap);

    for (const auto& row : tempMap) {
        for (char cell : row) {
            switch (cell) {
                case '#': cout << "\033[33m" << '#' << "\033[0m"; break;
                case 'E': cout << "\033[31m" << cell << "\033[0m"; break;
                case 'T': cout << "\033[34m" << cell << "\033[0m"; break;
                case '@': cout << "\033[32m" << cell << "\033[0m"; break;
                case '&': cout << "\033[32m" << cell << "\033[0m"; break;
                case 'V': cout << "\033[35m" << cell << "\033[0m"; break;
                default: cout << cell;
            }
        }
        cout << endl;
    }
    cout << "Health: " << player.getHealth() << "%" << endl;
}

void removeVillain(int x, int y) {
    for (size_t i = 0; i < villanos.size(); i++) {
        if (villanos[i].getX() == x && villanos[i].getY() == y) {
            villanos.erase(villanos.begin() + i);
            break;
        }
    }
}

bool movePlayer(SuperHero& player, vector<vector<char>>& map, int dir) {
    int x = player.getX(), y = player.getY(), newX = x, newY = y;

    switch (dir) {
        case 'a': newY--; break;
        case 's': newX++; break;
        case 'd': newY++; break;
        case 'w': newX--; break;
    }

    if (newX < 0 || newX >= map.size() || newY < 0 || newY >= map[0].size()) return false;

    if (map[newX][newY] == '#') return false;

    bool foundEnemy = false;

    for (const auto& villano : villanos) {
        if (villano.getX() == newX && villano.getY() == newY) {
            foundEnemy = true;
            break;
        }
    }

    if (foundEnemy) {
        bool isSupervillain = false;
        
        for (const auto& villano : villanos) {
            if (villano.getSymbol() == 'V' && villano.getX() == newX && villano.getY() == newY) {
                isSupervillain = true;
                break;
            }
        }

        if (player.getOn()) {
            if (isSupervillain) {
                player.takeDamage(20);
                map[1][1] = 'T';
                villanos=villanos2;
            } else {
                player.takeDamage(5);
            }
        } else {
            if (isSupervillain) {
                player.takeDamage(30);
                villanos=villanos2;
            } else {
                player.takeDamage(10);
            }
        }

        map[newX][newY] = ' ';
        removeVillain(newX, newY);
    } else if (map[newX][newY] == 'T') {
        return true;
    } else if (map[newX][newY] == '0') {
        player.transform();
        map[newX][newY] = ' ';
    }

    player.position(newX, newY);
    return false;
}

int main() {
    SuperHero player(100, 1, 1, 10,false);
    vector<vector<char>>* currentMap = &map1;
    int world = 1;
    villanos=villanos1;
    while (player.getHealth() > 0 && world <= 2) {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";



        displayMap(*currentMap, player);
        int dir = _getch();

        

        if (movePlayer(player, *currentMap, dir)) {
            if (world == 1) {
                currentMap = &map2;
                player.position(1, 1);
                villanos=villanos2;
                villanos.push_back(SuperVillian(20, 6, 2, 10));
                world++;
                
            } else {
                break;
            }
        }
    }

    cout << (player.getHealth() > 0 ? "¡Ganaste!" : "Game Over") << endl;
    return 0;
}
