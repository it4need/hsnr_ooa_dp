/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       NoCash.cpp
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#include "NoCash.h"

NoCash::NoCash(Geldautomat *aktuellerGeldautomat) {
    this->geldautomat = aktuellerGeldautomat;
}

void NoCash::insertCard() {
    std::cout << "Sie können nicht noch eine Karte einwerfen!" << std::endl;
}

void NoCash::ejectCard() {
    std::cout << "Leider nicht genügend Geld im Automaten!" << std::endl;
}

void NoCash::enterPin(int pin) {
    std::cout << "Leider nicht genügend Geld im Automaten!" << std::endl;
}

void NoCash::requestCash(int requestedCash) {
    std::cout << "Leider nicht genügend Geld im Automaten!" << std::endl;
}