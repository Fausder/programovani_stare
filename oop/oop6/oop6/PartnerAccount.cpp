#include "PartnerAccount.h"
#include <iostream>

using namespace std;


PartnerAccount::PartnerAccount(int n, Client* o, Client* p)
    : Account(n, o, true), partner(p) {
    std::cout << "PartnerAccount konstruktor: " << o->GetName() << " a " << p->GetName() << std::endl;
}

PartnerAccount::PartnerAccount(int n, Client* o, Client* p, double ir)
    : Account(n, o, ir, true), partner(p) {
    std::cout << "PartnerAccount konstruktor (s vlastní úrokovou sazbou): " << o->GetName() << " a " << p->GetName() << std::endl;
}

PartnerAccount::~PartnerAccount() {
    std::cout << "PartnerAccount destruktor: " << owner->GetName() << " a " << partner->GetName() << std::endl;
}

Client* PartnerAccount::GetPartner() const {
    return partner;
}
