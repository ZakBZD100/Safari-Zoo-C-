#include "Bird.h"

//Constructeurs
Bird::Bird() : Animal()
{
    wingspan = 0.0;
}

Bird::Bird(string n, string c, string d, string h, string s, 
           bool p, int a, double w, double ht, double ws)
    : Animal(n, c, d, h, s, p, a, w, ht)
{
    wingspan = ws;
}


Bird::~Bird()
{
}

double Bird::getWingspan() const
{
    return wingspan;
}

void Bird::setWingspan(double w)
{
    wingspan = w;
}

void Bird::printInfo() const
{
    cout << "Animal of type Bird:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Wingspan : " << wingspan << "cm" << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}

string Bird::getType() const
{
    return "Bird";
}