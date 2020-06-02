#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

class Game
{
    bool att;
    struct Ship{
        int i;
        int j;
    }*ship;

    int ij[2];
    char table_player[10][10];
    char table_enemy[10][10];
    int ships = 20;

public:
    Game();
    ~Game() {};
    void game();
    void begin();
    bool checkb(int i, int j);
    bool check1(int i, int j);
    bool check2(int i, int j);
    void per(int ch);
    void preobr();
    void print1();
    void print2();
    void reset();

};

#endif // GAME_H
