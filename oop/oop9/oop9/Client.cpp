#include "Client.h"

Client::Client(int clientId, const std::string& clientName)
    : id(clientId), name(clientName), address("") {
}

Client::Client(int clientId, const std::string& clientName, const std::string& clientAddress)
    : id(clientId), name(clientName), address(clientAddress) {
}


int Client::GetId() const {
    return id;
}

std::string Client::GetName() const {
    return name;
}

std::string Client::GetAddress() const {
    return address;
}


void Client::SetName(const std::string& newName) {
    name = newName;
}

void Client::SetAddress(const std::string& newAddress) {
    address = newAddress;
}
