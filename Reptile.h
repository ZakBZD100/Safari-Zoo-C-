#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"

class Reptile : public Animal
{
private:
    string scalePattern;

public:
    Reptile();
    Reptile(string n, string c, string d, string h, string s, 
            bool p, int a, double w, double ht, string sp);
    Reptile(const Reptile&) = default;
    virtual ~Reptile();

    string getScalePattern() const;
    void setScalePattern(string sp);

    virtual void printInfo() const override;
    virtual string getType() const override;
};

#endif