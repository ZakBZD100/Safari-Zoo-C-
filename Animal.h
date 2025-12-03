#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string name;
    string color;
    string diet;
    string habitat;
    string sounds;
    bool isPet;
    int age;
    double weight;
    double height;

public:
    Animal();
    Animal(string n, string c, string d, string h, string s, 
           bool p, int a, double w, double ht);
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;
    virtual ~Animal();

    string getName() const;
    string getColor() const;
    string getDiet() const;
    string getHabitat() const;
    string getSounds() const;
    bool getIsPet() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

    void setName(string n);
    void setColor(string c);
    void setDiet(string d);
    void setHabitat(string h);
    void setSounds(string s);
    void setIsPet(bool p);
    void setAge(int a);
    void setWeight(double w);
    void setHeight(double h);

    void make_sound() const;
    virtual void printInfo() const;
    virtual string getType() const;
};

#endif