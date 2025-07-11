//
// Created by Miguel on 11/07/2025.
//

#ifndef NODOARBOL_H
#define NODOARBOL_H



class nodoArbol {
    public:
    nodoArbol(unsigned char valor, int frecuencia, nodoArbol* izquierda, nodoArbol* derecha);

    unsigned char valor;
    int frecuencia;
    nodoArbol* izquierda;
    nodoArbol* derecha;



};



#endif //NODOARBOL_H
