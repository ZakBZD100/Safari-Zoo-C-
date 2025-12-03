#include "Mammal.h"

Mammal::Mammal() : Animal()
{
    furColor = "";
}

Mammal::Mammal(string n, string c, string d, string h, string s, 
               bool p, int a, double w, double ht, string fc)
    : Animal(n, c, d, h, s, p, a, w, ht)
{
    furColor = fc;
}

Mammal::~Mammal()
{
}

string Mammal::getFurColor() const
{
    return furColor;
}

void Mammal::setFurColor(string fc)
{
    furColor = fc;
}

void Mammal::printInfo() const
{
    cout << "Animal of type Mammal:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Fur Color : " << furColor << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}

string Mammal::getType() const
{
    return "Mammal";
}