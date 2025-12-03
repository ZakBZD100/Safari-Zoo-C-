#include "Animal.h"

//constructeurs
Animal::Animal()
{
    name = "";
    color = "";
    diet = "";
    habitat = "";
    sounds = "";
    isPet = false;
    age = 0;
    weight = 0.0;
    height = 0.0;
}

Animal::Animal(string n, string c, string d, string h, string s, 
               bool p, int a, double w, double ht)
{
    name = n;
    color = c;
    diet = d;
    habitat = h;
    sounds = s;
    isPet = p;
    age = a;
    weight = w;
    height = ht;
}



Animal::~Animal()
{
}

//getters
string Animal::getName() const { return name; }
string Animal::getColor() const { return color; }
string Animal::getDiet() const { return diet; }
string Animal::getHabitat() const { return habitat; }
string Animal::getSounds() const { return sounds; }
bool Animal::getIsPet() const { return isPet; }
int Animal::getAge() const { return age; }
double Animal::getWeight() const { return weight; }
double Animal::getHeight() const { return height; }

//setters
void Animal::setName(string n) { name = n; }
void Animal::setColor(string c) { color = c; }
void Animal::setDiet(string d) { diet = d; }
void Animal::setHabitat(string h) { habitat = h; }
void Animal::setSounds(string s) { sounds = s; }
void Animal::setIsPet(bool p) { isPet = p; }
void Animal::setAge(int a) { age = a; }
void Animal::setWeight(double w) { weight = w; }
void Animal::setHeight(double h) { height = h; }

void Animal::make_sound() const
{
    cout << sounds << endl;
}

void Animal::printInfo() const
{
    cout << "Animal of unknown type:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}

string Animal::getType() const
{
    return "Animal";
}