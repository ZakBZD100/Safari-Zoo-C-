#ifndef KNNDOUBLE_H
#define KNNDOUBLE_H

#include "KNN.h"
#include <cmath>
using namespace std;

//utilise pair<double,double> pour weight/height
//distance euclidienne entre deux points
class KNNDouble : public KNN<pair<double, double>>
{
public:
    KNNDouble() : KNN() {}  //k=1 par defaut
    KNNDouble(int k) : KNN(k) {}  //k choisi
    ~KNNDouble() {}
    
    //distance euclidienne entre deux paires (x1,y1) et (x2,y2)
    double similarityMeasure(pair<double, double>& a, pair<double, double>& b);
};

#endif