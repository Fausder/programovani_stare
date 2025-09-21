#pragma once
#include "Gamer.h"
#include "Croupier.h"
#include <iostream>
#include <cstdlib> 
using namespace std;
class Casino
{
private:
    static const int maxGamers = 100;
    Gamer gamers[maxGamers];
    int gamerCount;
    Croupier croupier;
    Cash casinoCash;

public:
    Casino(double initialCasinoCash, double initialCoupierCash);
    void AddGamer(const Gamer& gamer);
    void PlayGame(Gamer& gamer, double bet);
    void PlayAllGames(double bet);
    void PrintBalances() const;
    double GetCasinoCash() const;
    double GetCroupierCash() const;
};


