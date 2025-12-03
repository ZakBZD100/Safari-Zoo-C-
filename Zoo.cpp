#include "Zoo.h"
#include <iostream>
#include <map>
using namespace std;

int Zoo::MAX_CAPACITY = 100;

Zoo::Zoo() { name = ""; }  //zoo sans nom
Zoo::Zoo(string n) { name = n; }  //zoo avec nom

Zoo::Zoo(const Zoo& other) {
    name = other.name;
    for (Animal* a : other.animals) {
        if ((*a).getType() == "Mammal") animals.push_back(new Mammal(*dynamic_cast<Mammal*>(a)));
        else if ((*a).getType() == "Bird") animals.push_back(new Bird(*dynamic_cast<Bird*>(a)));
        else if ((*a).getType() == "Reptile") animals.push_back(new Reptile(*dynamic_cast<Reptile*>(a)));
        else animals.push_back(new Animal(*a));
    }
}

Zoo::~Zoo() { for (Animal* a : animals) delete a; }  //supprime tout

string Zoo::getName() const { return name; }
void Zoo::setName(string n) { name = n; }
int Zoo::getMaxCapacity() { return MAX_CAPACITY; }

//liste tous les animaux
void Zoo::listAnimals() const {
    cout << "Animals in " << name << "\n";
    for (const Animal* a : animals) { (*a).printInfo(); cout << "---\n"; }
}

//ajoute si place + nom unique, garde ordre alphabétique
bool Zoo::addAnimal(Animal* animal) {
    if (animals.size() >= MAX_CAPACITY) return false;
    if (searchAnimalByName((*animal).getName()) != -1) return false;
    auto it = lower_bound(animals.begin(), animals.end(), animal,
        [](const Animal* a, const Animal* b) { return (*a).getName() < (*b).getName(); });
    animals.insert(it, animal);
    return true;
}

//recherche simple dans la liste
int Zoo::searchAnimalByName(string name) const {
    for (int i = 0; i < animals.size(); i++) {
        if ((*animals[i]).getName() == name) return i;
    }
    return -1; //pas trouvé
}

//supprime par nom
void Zoo::removeAnimalByName(string name) {
    int idx = searchAnimalByName(name);
    if (idx == -1) { cout << name << " not found\n"; return; }
    delete animals[idx]; animals.erase(animals.begin() + idx);
    cout << "removed " << name << "\n";
}

//moyenne d'âge pour un type
double Zoo::averageAgeForType(string type) const {
    int sum = 0, cnt = 0;
    for (const Animal* a : animals) if ((*a).getType() == type) { sum += (*a).getAge(); cnt++; }
    return cnt ? (double)sum/cnt : 0.0;
}

//KNN: prédit le type (numerical=poids/taille, categorical=strings)
string Zoo::predictTypeWithKNN(Animal& animal, int k, string dataType) {
    if (animals.empty()) return "Unknown";
    if (dataType == "numerical") {
        //preparer données (weight,height) et labels
        KNNDouble knn(k);
        vector<pair<double,double>> train;
        vector<string> labels;
        for (Animal* a : animals) {
            train.push_back({ (*a).getWeight(), (*a).getHeight() });
            labels.push_back((*a).getType());
        }

        //l'animal qu'on veut classer
        pair<double,double> target = { animal.getWeight(), animal.getHeight() };

        //Trouver plus proches voisins
        vector<int> neighbours = knn.findNearestNeighbours(train, target);

        //votes de majorité
        map<string,int> votes;
        for (int idx : neighbours) votes[ labels[idx] ]++;

        string best = "Unknown";
        int bestVotes = 0;
        for (const auto& kv : votes) {
            if (kv.second > bestVotes) { bestVotes = kv.second; best = kv.first; }
        }
        return best;
    }
    //même principe
    //categorical: color/diet/habitat/sounds -> compare via KNNString
    KNNString knn(k);
    vector<vector<string>> train;
    vector<string> labels;
    for (Animal* a : animals) {
        train.push_back({ (*a).getColor(), (*a).getDiet(), (*a).getHabitat(), (*a).getSounds() });
        labels.push_back((*a).getType());
    }

    vector<string> target = { animal.getColor(), animal.getDiet(), animal.getHabitat(), animal.getSounds() };
    vector<int> neighbours = knn.findNearestNeighbours(train, target);

    map<string,int> votes;
    for (int idx : neighbours) votes[ labels[idx] ]++;

    string best = "Unknown";
    int bestVotes = 0;
    for (const auto& kv : votes) {
        if (kv.second > bestVotes) { bestVotes = kv.second; best = kv.first; }
    }
    return best;
}