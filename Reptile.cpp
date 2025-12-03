#include "Reptile.h"

//constructeurs
Reptile::Reptile() : Animal()
{
    scalePattern = "";
}

Reptile::Reptile(string n, string c, string d, string h, string s, 
                 bool p, int a, double w, double ht, string sp)
    : Animal(n, c, d, h, s, p, a, w, ht)
{
    scalePattern = sp;
}


Reptile::~Reptile()
{
}

string Reptile::getScalePattern() const
{
    return scalePattern;
}

void Reptile::setScalePattern(string sp)
{
    scalePattern = sp;
}

void Reptile::printInfo() const
{
    cout << "Animal of type Reptile:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Scale Pattern : " << scalePattern << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}

string Reptile::getType() const
{
    return "Reptile";
}