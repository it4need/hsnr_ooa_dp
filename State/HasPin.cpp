#include "HasPin.h"

HasPin::HasPin(Geldautomat *aktuellerGeldautomat) {
    this->geldautomat = aktuellerGeldautomat;
}

void HasPin::insertCard() {
    std::cout << "Man kann nicht mehr als eine Karte einfügen!" << std::endl;
}

void HasPin::ejectCard() {
    std::cout << "Karte ausgeworfen!" << std::endl;
    this->geldautomat->setATMState(this->geldautomat->getNoCardState());
}

void HasPin::enterPin(int pin) {
    std::cout << "Die PIN wurde bereits eingegeben." << std::endl;
}

void HasPin::requestCash(int requestedCash) {
    if(this->geldautomat->cashInMachine < requestedCash) {
        std::cout << "Leider nicht genügend Geld im Automaten!" << std::endl;
        std::cout << "Ihre Karte wird ausgeworfen!" << std::endl;
        this->geldautomat->setATMState(this->geldautomat->getNoCardState());
    }
    else
    {
        std::cout << "Geld ausgeworfen." << std::endl;
        this->geldautomat->setCashInMachine(this->geldautomat->cashInMachine - requestedCash);
        std::cout << "Ihre Karte wird ausgeworfen.";
        this->geldautomat->setATMState(this->geldautomat->getNoCardState());

        if(this->geldautomat->cashInMachine <= 0)
        {
            this->geldautomat->setATMState(this->geldautomat->getNoCashState());
        }
    }
}
