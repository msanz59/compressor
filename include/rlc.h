//
// Created by Miguel on 10/07/2025.
//

#ifndef RLC_H
#define RLC_H
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class rlc {
public:
    vector<unsigned char> comprimir(vector<unsigned char> datos);
    vector<unsigned char> descomprimir(vector<unsigned char> datos);
};



#endif //RLC_H
