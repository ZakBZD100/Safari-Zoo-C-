#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal
{
private:
    double wingspan;

public:
    Bird();
    Bird(string n, string c, string d, string h, string s, 
         bool p, int a, double w, double ht, double ws);
    Bird(const Bird&) = default;
    virtual ~Bird();

    double getWingspan() const;
    void setWingspan(double w);

    virtual void printInfo() const override;
    virtual string getType() const override;
};

#endif