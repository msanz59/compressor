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
    void escribir(string texto, vector<unsigned char> comprimido);
    vector <unsigned char> leer(string texto);
private:
};



#endif //ESCRITOR_H
