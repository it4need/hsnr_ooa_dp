/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       HasCard.h
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_HASCARD_H
#define HSNR_OOA_DP_HASCARD_H

#include "Geldautomat.h"
#include "IGeldautomatState.h"
#include <iostream>

class HasCard : public IGeldautomatState {
private:
    Geldautomat *geldautomat;
public:
    HasCard(Geldautomat *aktuellerGeldautomat);
    void insertCard();
    void ejectCard();
    void enterPin(int pin);
    void requestCash(int requestedCash);
};

#endif //HSNR_OOA_DP_HASCARD_H