//
// Created by Miguel on 11/07/2025.
//

#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include "nodoArbol.h"

using namespace std;

struct Comparador {
    bool operator()(const nodoArbol* a, const nodoArbol* b) const {
        return a->frecuencia > b->frecuencia; // menor frecuencia tiene más prioridad
    }
};

class huffman {
public:
    huffman();
    map<unsigned char, string> getCodigos();
    void constuirArbol();
    vector<unsigned char> comprimir(const vector<unsigned char> &datos);
    std::map<unsigned char, std::string> cargarMapa(const std::string &ruta);
    vector<unsigned char> descomprimir(const vector<unsigned char> &datos, const string &rutaMapa);

    void guardarMapa(const std::string &ruta);

private:
    map<unsigned char, int> frecuencias;
    map<unsigned char, string> codigos;
    vector<unsigned char> codigosLeidos;
    priority_queue<nodoArbol*, vector<nodoArbol*>, Comparador> colaPrioridad;
    void contarfrecuencias();
    void generarCodigosdesde(nodoArbol* nodo, const string& camino);
    nodoArbol* raiz = nullptr;
    vector<unsigned char> escribirCodificado();


};



#endif //HUFFMAN_H
