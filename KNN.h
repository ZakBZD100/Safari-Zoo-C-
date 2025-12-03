#ifndef KNN_H
#define KNN_H

#include <vector>
#include <algorithm>
using namespace std;

//on a juste k (nombre voisins)
//et une fonction pour trouver les k plus proches
template <class T>
class KNN
{
private:
    int k; //combien de voisins on veut

public:
    KNN() : k(1) {}  //par défaut k=1
    KNN(int k) : k(k) {}  //on donne k
    virtual ~KNN() {}
    
    int getK() const { return k; }  //getter
    
    //trouve les k plus proches
    vector<int> findNearestNeighbours(vector<T>& trainData, T& target)
    {
        vector<pair<double, int>> distances;
        
        //calcule toutes les distances
        for (int i = 0; i < trainData.size(); i++) {
            distances.push_back({similarityMeasure(trainData[i], target), i});
        }
        
        sort(distances.begin(), distances.end());
        
        //prend les k premiers
        vector<int> result;
        for (int i = 0; i < k && i < distances.size(); i++) {
            result.push_back(distances[i].second);
        }
        return result;
    }
    
    //fonction virtuelle pure: chaque classe fille doit l'implémenter
    virtual double similarityMeasure(T& a, T& b) = 0;
};

#endif