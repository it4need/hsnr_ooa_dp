/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       Geldautomat.cpp
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */
#include "Geldautomat.h"
#include "HasCard.h"
#include "NoCard.h"
#include "HasPin.h"
#include "NoCash.h"

Geldautomat::Geldautomat() {
    this->hasCardState = new HasCard(this);
    this->noCardState = new NoCard(this);
    this->hasCorrectPinState = new HasPin(this);
    this->noCashState = new NoCash(this);

    this->atmState = this->noCardState;

    if(this->cashInMachine < 0) {
        this->atmState = this->noCashState;
    }
}

void Geldautomat::setATMState(IGeldautomatState *state) {
    this->atmState = state;
}

int Geldautomat::setCashInMachine(int cash)
{
    this->cashInMachine = cash;
}

void Geldautomat::insertCard() {
    this->atmState->insertCard();
}

void Geldautomat::ejectCard() {
    this->atmState->ejectCard();
}


void Geldautomat::enterPin(int pin) {
    this->atmState->enterPin(pin);
}
void Geldautomat::requestCash(int requestedCash) {
    this->atmState->requestCash(requestedCash);
}

IGeldautomatState *Geldautomat::getHasCardState() {
    return this->hasCardState;
}

IGeldautomatState *Geldautomat::getNoCardState() {
    return this->noCardState;
}

IGeldautomatState *Geldautomat::getHasPinState() {
    return this->hasCorrectPinState;
}

IGeldautomatState *Geldautomat::getNoCashState() {
    return this->noCashState;
}