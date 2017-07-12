/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       IGeldautomatState.h.h
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_IGELDAUTOMATSTATE_H_H
#define HSNR_OOA_DP_IGELDAUTOMATSTATE_H_H

class IGeldautomatState {
public:
    virtual void insertCard() = 0;
    virtual void ejectCard() = 0;
    virtual void enterPin(int) = 0;
    virtual void requestCash(int) = 0;
    virtual ~IGeldautomatState() {}
};


#endif //HSNR_OOA_DP_IGELDAUTOMATSTATE_H_H