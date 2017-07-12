/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       HasCard.cpp
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#include "HasCard.h"

HasCard::HasCard(Geldautomat *aktuellerGeldautomat) {
    this->geldautomat = aktuellerGeldautomat;
}

void HasCard::insertCard() {
    std::cout << "Man kann nicht mehr als eine Karte in den Geldautomaten stecken!" << std::endl;
}

void HasCard::ejectCard() {
    std::cout << "Die Karte wird nun entfernt!" << std::endl;
    this->geldautomat->setATMState(this->geldautomat->getNoCardState());
}

void HasCard::enterPin(int pin) {
    if(pin == 1234)
    {
        std::cout << "Korrekter PIN!" << std::endl;
        this->geldautomat->correctPin = true;
        this->geldautomat->setATMState(this->geldautomat->getHasPinState());
    }
    else
    {
        std::cout << "Nicht korrekter PIN!" << std::endl;
        std::cout << "Karte wird ausgeschmissen!" << std::endl;
        this->geldautomat->setATMState(this->geldautomat->getNoCardState());
    }
}

void HasCard::requestCash(int requestedCash) {
    std::cout << "Bitte vorher die PIN eingeben!" << std::endl;
}