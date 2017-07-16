/**
 * State design pattern
 *
 * @package    hsnr_ooa_dp
 * @file       State.h
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_STATE_H
#define HSNR_OOA_DP_STATE_H

#include <iostream>
#include "State/Geldautomat.h"

/*
 * Zustände:
 *   - NoCard
 *   - HasCard
 *   - HasPin
 *   - NoCash
 *
 *  Methoden zu Zuständen:
 *   - insertCard() : void
 *   - ejectCard() : void
 *   - enterPin(int) : void
 *   - requestCash(int) : void
 */


int stateMain()
{
    Geldautomat *geldautomat = new Geldautomat();
    geldautomat->setCashInMachine(500);
    geldautomat->insertCard();
    geldautomat->ejectCard();
    geldautomat->insertCard();
    geldautomat->enterPin(1234);
    geldautomat->requestCash(500);
    geldautomat->insertCard();
    geldautomat->enterPin(1234);



}

#endif //HSNR_OOA_DP_STATE_H