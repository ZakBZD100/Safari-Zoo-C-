#include "Zoo.h"
#include <iostream>
using namespace std;

int main() {
    cout << "systeme de gestion du zoo\n\n";

    Zoo zoo("Safari zoo");

    //création d'animaux
    auto* lion = new Mammal("Leo", "Golden", "Carnivore", "Grassland", "Roar", false, 5, 180.5, 3.5, "Tawny");
    auto* eagle = new Bird("Eagle1", "Brown", "Carnivore", "Mountains", "Screech", false, 3, 4.5, 80, 200);
    auto* snake = new Reptile("Python1", "Green", "Carnivore", "Forest", "Hiss", false, 2, 15, 300, "Diamond");
    auto* elephant = new Mammal("Elephant1", "Gray", "Herbivore", "Grassland", "Trumpet", false, 8, 5000, 300, "Gray");
    auto* parrot = new Bird("Parrot1", "Red", "Omnivore", "Rainforest", "Squawk", true, 4, 1.2, 35, 80);

    cout << "ajout des animaux au zoo...\n";
    zoo.addAnimal(lion);
    zoo.addAnimal(eagle);
    zoo.addAnimal(snake);
    zoo.addAnimal(elephant);
    zoo.addAnimal(parrot);

    cout << "\nanimaux enregistres :\n";
    zoo.listAnimals();

    //recherche simple
    cout << "\nOn recherche de 'Leo' : ";
    int pos = zoo.searchAnimalByName("Leo");
    if (pos != -1) cout << "trouve l'index " << pos << "\n";
    else cout << "non trouve\n";

    //moyennes d'age
    cout << "\nages moyens par categorie :\n";
    cout << "mammiferes : " << zoo.averageAgeForType("Mammal") << "\n";
    cout << "oiseaux    : " << zoo.averageAgeForType("Bird") << "\n";
    cout << "reptiles   : " << zoo.averageAgeForType("Reptile") << "\n";

    //Test KNN
    cout << "\n classification KNN \n";

    Animal unknown("Mystery", "Brown", "Carnivore", "Forest", "Growl", false, 6, 200, 150);
    cout << "donnees de l'animal inconnu :\n";
    unknown.printInfo();
    cout << "\n";

    cout << "prediction (numerique) : "
        << zoo.predictTypeWithKNN(unknown, 3, "numerical") << "\n";
    cout << "prediction (categorielle) : "
        << zoo.predictTypeWithKNN(unknown, 3, "categorical") << "\n";

    //sons
    cout << "\nsons des animaux :\n";
    (*lion).make_sound();
    (*eagle).make_sound();
    (*snake).make_sound();

    cout << "\nenlever l'animal 'Eagle1'...\n";
    zoo.removeAnimalByName("Eagle1");

    if (zoo.searchAnimalByName("Eagle1") == -1)
        cout << "Eagle1 a bien ete retire.\n";

    //test doublon
    cout << "\ntenter d'ajouter un deuxieme 'Leo'...\n";
    auto* duplicate = new Mammal("Leo", "White", "Carnivore", "Arctic", "Roar", false, 3, 150, 110, "White");

    if (!zoo.addAnimal(duplicate)) {
        delete duplicate;
        cout << "nom deja utilise, donc ajout refuse.\n";
    }

    cout << "\nfin.\n";
    return 0;
}
