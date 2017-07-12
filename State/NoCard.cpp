/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       NoCard.cpp
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#include "Nocard.h"

NoCard::NoCard(Geldautomat *aktuellerGeldautomat) {
    this->geldautomat = aktuellerGeldautomat;
}

void NoCard::insertCard() {
    std::cout << "Bitte PIN eingeben" << std::endl;
    this->geldautomat->setATMState(this->geldautomat->getHasPinState());
}

void NoCard::ejectCard() {
    std::cout << "Man kann keine Karte auswerfen, wenn keine enthalten ist." << std::endl;
}

void NoCard::enterPin(int pin) {
    std::cout << "Bitte zuerst Karte einlegen, bevor PIN eingegeben werden kann." << std::endl;
}

void NoCard::requestCash(int requestedCash) {
    std::cout << "Bitte zuerst Karte einlegen, bevor Geld ausgezahlt werden kann." << std::endl;
}