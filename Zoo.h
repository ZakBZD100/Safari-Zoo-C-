#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "KNNDouble.h"
#include "KNNString.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Zoo
{
private:
    string name;
    static int MAX_CAPACITY;
    vector<Animal*> animals;

public:
    Zoo();
    Zoo(string n);
    Zoo(const Zoo& other);
    ~Zoo();

    string getName() const;
    void setName(string n);
    static int getMaxCapacity();

    void listAnimals() const;
    bool addAnimal(Animal* animal);
    int searchAnimalByName(string name) const;
    void removeAnimalByName(string name);
    double averageAgeForType(string type) const;
    
    string predictTypeWithKNN(Animal& animal, int k, string dataType);
};

#endif