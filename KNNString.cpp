#include "KNNString.h"

//Distance Levenshtein: nombre d'operations pour transformer s1 en s2
//(insertion, suppression, substitution)
//https://www.geeksforgeeks.org/dsa/introduction-to-levenshtein-distance/
int KNNString::levenshteinDistance(const string& s1, const string& s2) const
{
    int m = (int)s1.length();
    int n = (int)s2.length();
    if (m == 0) return n;
    if (n == 0) return m;

    vector<int> prev(n + 1), curr(n + 1);
    for (int j = 0; j <= n; j++) prev[j] = j;

    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
            else curr[j] = 1 + min( min(prev[j], curr[j-1]), prev[j-1]);
        }
        prev = curr;
    }
    return curr[n];
}

//somme des distances Levenshtein pour chaque paire de strings
double KNNString::similarityMeasure(const vector<string>& a, const vector<string>& b) const
{
    double total = 0.0;
    size_t common = min(a.size(), b.size());

    for (size_t i = 0; i < common; ++i) {
        total += static_cast<double>(levenshteinDistance(a[i], b[i]));
    }

    //ajouter distances manquantes
    for (size_t i = common; i < a.size(); ++i) total += static_cast<double>(a[i].length());
    for (size_t i = common; i < b.size(); ++i) total += static_cast<double>(b[i].length());

    return total;
}