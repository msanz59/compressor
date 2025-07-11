//
// Created by Miguel on 11/07/2025.
//

#include "../include/nodoArbol.h"

nodoArbol::nodoArbol(unsigned char valor, int frecuencia, nodoArbol* izquierda, nodoArbol* derecha){
    this->frecuencia = frecuencia;
    this->valor = valor;
    this->izquierda = izquierda;
    this->derecha = derecha;
}
