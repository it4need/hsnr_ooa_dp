/**
 * Short description
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       Singleton.h
 * @copyright  Copyright © 12.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_SINGLETON_H
#define HSNR_OOA_DP_SINGLETON_H

#include <string>
#include <iostream>

class Singleton {
private:
    Singleton() {} // make constructor private
    Singleton(const Singleton &s) {} // deactivate copy constructor
    Singleton &operator=(Singleton &s) {} // deactivate equal operator
    static Singleton *singleton;
    std::string zustand = "initialized";
public:
    static Singleton *getInstance() {

        if(Singleton::singleton == nullptr) {
            Singleton::singleton = new Singleton();
        }

        return Singleton::singleton;
    }

    void setZustand(std::string neuerZustand) {
        this->zustand = neuerZustand;
    }

    std::string getZustand() {
        return this->zustand;
    }
};

Singleton *Singleton::singleton = nullptr; // Globale Variable

int singletonMain() {
    Singleton *singleton1 = Singleton::getInstance();
    Singleton *singleton2 = Singleton::getInstance();

    std::cout << "Zustand 1: " << singleton1->getZustand() << std::endl;
    std::cout << "Zustand 2: " << singleton2->getZustand() << std::endl;
    singleton1->setZustand("Zustand 1 verändert (nicht 2).");
    std::cout << "Zustand 1: " << singleton1->getZustand() << std::endl;
    std::cout << "Zustand 2: " << singleton2->getZustand() << std::endl;

    return 0;
}

#endif //HSNR_OOA_DP_SINGLETON_H