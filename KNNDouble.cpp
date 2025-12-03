#include "KNNDouble.h"

//distance simple entre deux points (pas besoin de sqrt)
double KNNDouble::similarityMeasure(pair<double, double>& a, pair<double, double>& b)
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return dx*dx + dy*dy;  //juste la distance au carré
}