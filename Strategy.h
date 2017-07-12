/**
 * Strategy design pattern
 *
 *
 * @package    hsnr_ooa_dp
 * @file       Strategy.h
 * @copyright  Copyright © 10.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_STRATEGY_H
#define HSNR_OOA_DP_STRATEGY_H

#include <iostream>

/**
 * Interfaces (Abstract Behaviour classes)
 */
class IFlyBehaviour {
public:
    virtual void fly() = 0;
    virtual ~IFlyBehaviour() {};
};

class IWalkBehaviour {
public:
    virtual void walk() = 0;
    virtual ~IWalkBehaviour() {};
};

class ISwimBehaviour {
public:
    virtual void swim() = 0;
    virtual ~ISwimBehaviour() {};
};

class ISpeechBehaviour {
public:
    virtual void speech() = 0;
    virtual ~ISpeechBehaviour() {};
};

/**
 * Interface implementations
 * - Flying -
 */
class FlyHigh : public IFlyBehaviour {
public:
    void fly()
    {
        std::cout << "I can fly high" << std::endl;
    }
};

class FlyNo : public IFlyBehaviour {
public:
    void fly()
    {
        std::cout << "I can't even fly." << std::endl;
    }
};

class FlyLow : public IFlyBehaviour {
public:
    void fly()
    {
        std::cout << "I only can fly low." << std::endl;
    }
};

/**
 * Interface implementations
 * - Walking -
 */
class WalkFast : public IWalkBehaviour {
public:
    void walk()
    {
        std::cout << "I can walk fast." << std::endl;
    }
};

class WalkNo : public IWalkBehaviour {
public:
    void walk()
    {
        std::cout << "I cannot walk." << std::endl;
    }
};

class WalkSlow : public IWalkBehaviour {
public:
    void walk()
    {
        std::cout << "I can only walk slowly." << std::endl;
    }
};

/**
 * Interface implementations
 * - Swimming -
 */
class SwimFast : public ISwimBehaviour {
public:
    void swim()
    {
        std::cout << "I can swim fast." << std::endl;
    }
};

class SwimNo : public ISwimBehaviour {
public:
    void swim()
    {
        std::cout << "I cannot swim." << std::endl;
    }
};

class SwimSlow : public ISwimBehaviour {
public:
    void swim()
    {
        std::cout << "I can only swim slowly." << std::endl;
    }
};

/**
 * Interface implementations
 * - Swimming -
 */
class SpeechClear : public ISpeechBehaviour {
public:
    void speech()
    {
        std::cout << "I can speak clearly." << std::endl;
    }
};

class SpeechNoClear : public ISpeechBehaviour {
public:
    void speech()
    {
        std::cout << "I can speak, but not clearly." << std::endl;
    }
};

class SpeechNo : public ISpeechBehaviour {
public:
    void speech()
    {
        std::cout << "I can't speak." << std::endl;
    }
};

class Mensch {
protected:
    IFlyBehaviour* flyBehaviour;
    IWalkBehaviour* walkBehaviour;
    ISwimBehaviour* swimBehaviour;
    ISpeechBehaviour* speechBehaviour;
public:
    virtual void fly() {
        this->flyBehaviour->fly();
    }
    virtual void walk() {
        this->walkBehaviour->walk();
    }
    virtual void swim()
    {
        this->swimBehaviour->swim();
    }
    virtual void speech()
    {
        this->speechBehaviour->speech();
    }
    virtual ~Mensch() {};
};

class Sportler : public Mensch {
public:
    Sportler()
    {
        this->flyBehaviour = new FlyHigh();
        this->walkBehaviour = new WalkFast();
        this->swimBehaviour = new SwimFast();
        this->speechBehaviour = new SpeechNoClear();
    }
};

class IT_Student : public Mensch {
public:
    IT_Student()
    {
        this->flyBehaviour = new FlyNo();
        this->walkBehaviour = new WalkSlow();
        this->swimBehaviour = new SwimSlow();
        this->speechBehaviour = new SpeechClear();
    }
};

int stratgyMain()
{
    Sportler sportler = Sportler();
    IT_Student it_studnent = IT_Student();

    sportler.fly();
    sportler.speech();
    sportler.swim();
    sportler.walk();

    it_studnent.walk();
    it_studnent.swim();
    it_studnent.speech();
    it_studnent.fly();
}

#endif //HSNR_OOA_DP_STRATEGY_H