#include "Casino.h"

Casino::Casino(double initialCasinoCash, double initialCoupierCash)
    : casinoCash(initialCasinoCash), croupier(initialCoupierCash), gamerCount(0) {
}

void Casino::AddGamer(const Gamer& gamer) {
    if (gamerCount < maxGamers) {
        gamers[gamerCount++] = gamer;
    }
}

void Casino::PlayGame(Gamer& gamer, double bet) {
    if (croupier.GetCash().GetAmount() < bet) {
        if (casinoCash.GetAmount() < bet) {
            cout << "Casino ani krupier nemaji dostatek penez na sazku." << endl;
            return;
        }
        else {
            croupier.GetCash().AddAmount(casinoCash.GetAmount());
            casinoCash.DeductAmount(casinoCash.GetAmount());
        }
    }

    int randomNumber = rand() % 100 + 1;
    bool win = randomNumber < 40;

    if (win) {
        gamer.GetCash().AddAmount(bet);
        croupier.GetCash().DeductAmount(bet);
        cout << "Hrac " << gamer.GetName() << " vyhral " << bet << " ,-" << endl;
    }
    else {
        if (gamer.GetCash().DeductAmount(bet)) {
            croupier.GetCash().AddAmount(bet);
            cout << "Hrac " << gamer.GetName() << " prohral " << bet << " ,-" << endl;
        }
        else {
            cout << "Hrac " << gamer.GetName() << " nema dostatek penez na sazku" << endl;
        }
    }
}

void Casino::PlayAllGames(double bet) {
    for (int i = 0; i < gamerCount; ++i) {
        if (gamers[i].GetCash().GetAmount() < bet) {
            cout << "Hrac " << gamers[i].GetName() << " nema dostatek penez na sazku a prestava hrat." << endl;
           
            for (int j = i; j < gamerCount - 1; ++j) {
                gamers[j] = gamers[j + 1];
            }
            --gamerCount;
            --i; 
        }
        else {
            PlayGame(gamers[i], bet);
        }
    }
}

void Casino::PrintBalances() const {
    for (int i = 0; i < gamerCount; ++i) {
        cout << "Zustatek hrace: " << gamers[i].GetName() << " " << gamers[i].GetCash().GetAmount() << endl;
    }
    cout << "Zustatek kasina: " << GetCasinoCash() << endl;
    cout << "Zustatek krupiera: " << GetCroupierCash() << endl;
}

double Casino::GetCasinoCash() const {
    return casinoCash.GetAmount();
}

double Casino::GetCroupierCash() const {
    return croupier.GetCash().GetAmount();
}


