#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

class Mammal : public Animal
{
private:
    string furColor;

public:
    //constructors
    Mammal();
    Mammal(string n, string c, string d, string h, string s, 
           bool p, int a, double w, double ht, string fc);
    Mammal(const Mammal&) = default;
    virtual ~Mammal();

    //getter and Setter
    string getFurColor() const;
    void setFurColor(string fc);

    //override virtual
    virtual void printInfo() const override;
    virtual string getType() const override;
};

#endif