//
// Created by Miguel on 10/07/2025.
//

#include "../include/rlc.h"

#include <iostream>
#include <bits/ostream.tcc>


vector<unsigned char> rlc::comprimir(vector<unsigned char> datos) {
    vector<unsigned char> resultado;
    int i = 0;
    while (i < datos.size()) {
        unsigned char valorActual = datos[i];
        int contador = 1;

        // Contar repeticiones del mismo byte
        while (i + 1 < datos.size() && datos[i + 1] == valorActual) {
            contador++;
            i++;
        }
        // Agregar el byte y su contador al resultado
        resultado.push_back(static_cast<unsigned char>(contador));
        resultado.push_back(valorActual);

        i++;
    }

    cout << endl << "Resultado en hexadecimal: " << endl;
    for (unsigned char byte : resultado) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
    }

    return resultado;

}
vector<unsigned char> rlc::descomprimir(vector<unsigned char> datos) {
    vector<unsigned char> resultado;
    for (int i = 0; i < datos.size(); i+= 2) {
        unsigned char repeticiones = datos[i];
        unsigned char dato = datos[i + 1];
        for (int j = 0; j < repeticiones; j++) {
            resultado.push_back(dato);
        }
    }

    return resultado;

}


