/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       Geldautomat.h
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_GELDAUTOMAT_H
#define HSNR_OOA_DP_GELDAUTOMAT_H

#include "IGeldautomatState.h"

class Geldautomat {
private:
    class IGeldautomatState *atmState;
    class IGeldautomatState *hasCardState;
    class IGeldautomatState *noCardState;
    class IGeldautomatState *hasCorrectPinState;
    class IGeldautomatState *noCashState;
public:
    bool correctPin = false;
    int cashInMachine = 0;
    Geldautomat();
    void setATMState(IGeldautomatState *state);
    int setCashInMachine(int cash);
    void insertCard();
    void ejectCard();
    void enterPin(int pin);
    void requestCash(int requestedCash);
    IGeldautomatState *getHasCardState();
    IGeldautomatState *getNoCardState();
    IGeldautomatState *getHasPinState();
    IGeldautomatState *getNoCashState();
};


#endif //HSNR_OOA_DP_GELDAUTOMAT_H