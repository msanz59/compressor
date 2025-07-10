//
// Created by Miguel on 10/07/2025.
//

#ifndef ESCRITOR_H
#define ESCRITOR_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;



class escritor {
public:
    escritor();
    void escribir(const string &texto, const vector<unsigned char> &comprimido);
    vector <unsigned char> leer(const string &texto);
private:
};



#endif //ESCRITOR_H
