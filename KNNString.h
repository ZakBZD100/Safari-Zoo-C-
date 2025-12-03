#ifndef KNNSTRING_H
#define KNNSTRING_H

#include "KNN.h"
#include <vector>
#include <string>
using namespace std;

//KNN POUR LES STRINGS 
//Utilise vector<string> pour color/diet/habitat/sounds
//Distance de Levenshtein entre chaque paire de strings
class KNNString : public KNN<vector<string>>
{
public:
    KNNString() : KNN() {}  // k=1 par defaut
    KNNString(int k) : KNN(k) {}  // k choisi
    ~KNNString() {}
    
    //Distance totale entre deux vecteurs de strings
    double similarityMeasure(const vector<string>& a, const vector<string>& b) const;
    
private:
    //Distance Levenshtein entre deux strings (nb operations)
    int levenshteinDistance(const string& s1, const string& s2) const;
};

#endif