/**
 * Decorator design pattern
 *
 *
 * @package    hsnr_ooa_dp
 * @file       Decorator.h
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */
#ifndef HSNR_OOA_DP_DECORATOR_H
#define HSNR_OOA_DP_DECORATOR_H

#include <string>
#include <iostream>

class IPizza {
public:
    virtual std::string beschreibung() = 0;
    virtual float preis() = 0;
    virtual ~IPizza() {}
};

class TeichPizza : public IPizza {
public:
    std::string beschreibung()
    {
        return "Normaler Teich";
    }

    float preis()
    {
        return 3.50;
    }
};

class Decorator : public IPizza {
protected:
    IPizza *pizza;
public:
    virtual std::string beschreibung() = 0;
    virtual float preis() = 0;
    virtual ~Decorator() {}
};

class SalamiDecorator : public Decorator {
public:
    SalamiDecorator(IPizza *newPizza) {
        this->pizza = newPizza;
    }
    std::string beschreibung() {
        return this->pizza->beschreibung() += " mit Salami";
    }
    float preis()
    {
        return this->pizza->preis() + (float) 1.50;
    }
};

class MozarellaDecorator : public Decorator {
public:
    MozarellaDecorator(IPizza *newPizza) {
        this->pizza = newPizza;
    }
    std::string beschreibung() {
        return this->pizza->beschreibung() += " mit Mozzarella";
    }
    float preis() {
        return this->pizza->preis() + (float) 1.00;
    }
};

class OriganoDecorator : public Decorator {
public:
    OriganoDecorator(IPizza *newPizza) {
        this->pizza = newPizza;
    }
    std::string beschreibung() {
        return this->pizza->beschreibung() += " mit Origano";
    }
    float preis() {
        return this->pizza->preis() + (float) 0.5;
    }
};

class TamatoSauceDecorator : public Decorator {
public:
    TamatoSauceDecorator(IPizza *newPizza) {
        this->pizza = newPizza;
    }
    TamatoSauceDecorator() : Decorator(*this) {}
    std::string beschreibung() {
        return this->pizza->beschreibung() += " mit Tomantensauce";
    }
    float preis() {
        return this->pizza->preis() + (float) 0.25;
    }
};

int decoratorMain() {
    IPizza *pizza = new TamatoSauceDecorator(new OriganoDecorator(new SalamiDecorator(new TeichPizza())));

    std::cout << pizza->beschreibung();
    std::cout << pizza->preis();

    return 0;
}

#endif //HSNR_OOA_DP_DECORATOR_H
