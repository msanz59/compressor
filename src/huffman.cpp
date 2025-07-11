//
// Created by Miguel on 11/07/2025.
//

#include <utility>

#include "../include/huffman.h"

huffman::huffman(){
    cout << "Inicializando compresor Huffman" << endl;
    raiz = nullptr;
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
    generarCodigosdesde(raiz, "");
    return codigos;
}
vector<unsigned char> huffman::comprimir(const vector<unsigned char> &datos) {
        codigosLeidos = datos;
        contarfrecuencias();
        constuirArbol();
        getCodigos();
        return escribirCodificado();
}
vector<unsigned char> huffman::escribirCodificado() {
    vector<unsigned char> resultado;
    string codigoCompleto;
    for (unsigned char byte : codigosLeidos) {
        codigoCompleto += codigos[byte];
    }
    // Convertir el código binario a bytes
    for (size_t i = 0; i < codigoCompleto.size(); i += 8) {
        std::string byteStr = codigoCompleto.substr(i, 8);
        while (byteStr.length() < 8) byteStr += '0'; // Rellenar si es el último byte

        unsigned char byte = 0;
        for (int j = 0; j < 8; ++j) {
            if (byteStr[j] == '1') {
                byte |= (1 << (7 - j));  // Poner el bit en su lugar
            }
        }

        resultado.push_back(byte);
    }
    return resultado;
}



