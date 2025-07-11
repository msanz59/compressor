//
// Created by Miguel on 11/07/2025.
//

#include <utility>

#include "../include/huffman.h"

huffman::huffman(){
    cout << "Inicializando compresor Huffman" << endl;
}

void huffman::contarfrecuencias() {
    for (unsigned char byte : codigosLeidos) {
        frecuencias[byte]++;
    }
}
void huffman::constuirArbol() {
    for (const auto& par : frecuencias) {
        nodoArbol* nuevoNodo = new nodoArbol(par.first, par.second, nullptr, nullptr);
        colaPrioridad.push(nuevoNodo);
    }

    while (colaPrioridad.size() > 1) {
        nodoArbol* izq = colaPrioridad.top();
        colaPrioridad.pop();
        nodoArbol* der = colaPrioridad.top();
        colaPrioridad.pop();

        nodoArbol* combinado = new nodoArbol('\0', izq->frecuencia + der->frecuencia, izq, der);
        colaPrioridad.push(combinado);
    }
    raiz = colaPrioridad.top();

}


void huffman::generarCodigosdesde(nodoArbol* nodo, const string& camino) {
    if (!nodo) return;

    if (!nodo->izquierda && !nodo->derecha) {
        codigos[nodo->valor] = camino;
        return;
    }

    generarCodigosdesde(nodo->izquierda, camino + "0");
    generarCodigosdesde(nodo->derecha, camino + "1");
}
map<unsigned char, string> huffman::getCodigos() {
    constuirArbol();
    generarCodigosdesde(raiz, "");
    return codigos;
}
void huffman::comprimir(const vector<unsigned char> &datos) {
        codigosLeidos = datos;
        contarfrecuencias();
        constuirArbol();
        getCodigos();
}
vector<unsigned char> huffman::escribirCodificado() {
    vector<unsigned char> resultado;
    for (const auto& par : codigos) {
        unsigned char byte = par.first;
        string codigo = par.second;

        // Convertir el código a bits y agregarlo al resultado
        for (char bit : codigo) {
            if (bit == '1') {
                resultado.push_back(byte);
            } else {
                resultado.push_back(0);
            }
        }
    }
}



