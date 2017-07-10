/**
 * Observer design pattern
 *
 * Long description
 *
 * @package    hsnr_ooa_dp
 * @file       Observer.h
 * @copyright  Copyright © 10.07.17 by Jan Andrè Schlösser
 * @author     Jan Andrè Schlösser
 */

#ifndef HSNR_OOA_DP_OBSERVER_H
#define HSNR_OOA_DP_OBSERVER_H

#include <vector>
#include <iostream>
#include <string>

class Subject;

class IObserver {
protected:
    Subject *subject;
public:
    virtual void update() = 0;
    virtual ~IObserver() {};
};

class Subject {
private:
    std::vector<IObserver*> observers;
public:
    virtual void registerObserver(IObserver *newObserver) {
        observers.push_back(newObserver);
    };
    virtual void deregisterObserver(IObserver *newObserver) {
        observers.erase(std::remove(observers.begin(), observers.end(), newObserver));
    };
    void notify()
    {
        std::vector<IObserver*>::iterator iter;

        for(iter = observers.begin(); iter != observers.end(); iter++)
        {
            (*iter)->update();
        }
    }
    virtual std::string getInfos() = 0;
    virtual ~Subject() {};
};

class Tabelle : public IObserver {
public:
    Tabelle(Subject *subjectToObserve)
    {
        this->subject = subjectToObserve;
    }
    void update() {
        std::cout << "Tabelle wurde aktualsiiert mit: " << this->subject->getInfos() << std::endl;
    }
};

class Diagram : public IObserver {
public:
    Diagram(Subject *subjectToObserve)
    {
        this->subject = subjectToObserve;
    }
    void update() {
        std::cout << "Diagram wurde aktualsiiert mit: " << this->subject->getInfos() << std::endl;
    }
};

class WetterDaten : public Subject {
private:
    std::string value = "123,4";
public:
    std::string getInfos()
    {
        return this->value;
    }
    void setNewInfos(std::string value)
    {
        this->value = value;
    }
};

int observerMain()
{
    WetterDaten *wetterDaten = new WetterDaten();
    Tabelle *wetterDatenTabelle = new Tabelle(wetterDaten);
    Diagram *wetterDatenDiagram = new Diagram(wetterDaten);
    wetterDaten->registerObserver(wetterDatenDiagram);
    wetterDaten->registerObserver(wetterDatenTabelle);
    wetterDaten->notify();
    wetterDaten->setNewInfos("44555");
    wetterDaten->notify();
    wetterDaten->deregisterObserver(wetterDatenTabelle);
    wetterDaten->setNewInfos("test123");
    wetterDaten->notify();
}

#endif //HSNR_OOA_DP_OBSERVER_H