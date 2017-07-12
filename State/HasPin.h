/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       HasPin.h
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_HASPIN_H
#define HSNR_OOA_DP_HASPIN_H

#include "IGeldautomatState.h"
#include "Geldautomat.h"
#include <iostream>

class HasPin : public IGeldautomatState {
    Geldautomat *geldautomat;

public:
    HasPin(Geldautomat *aktuellerGeldautomat);

    void insertCard();
    void ejectCard();
    void enterPin(int pin);
    void requestCash(int requestedCash);
};

#endif //HSNR_OOA_DP_HASPIN_H