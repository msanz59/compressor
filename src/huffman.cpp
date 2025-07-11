//
// Created by Miguel on 11/07/2025.
//

#include <utility>

#include "../include/huffman.h"

#include <fstream>
#include <sstream>

huffman::huffman(){
    cout << "Inicializando compresor Huffman" << endl;
    raiz = nullptr;
}

void huffman::contarfrecuencias() {
    for (unsigned char byte : codigosLeidos) {
        frecuencias[byte]++;
        cout << "Leído: " << (int)byte << " -> '" << byte << "'" << std::endl;

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
std::map<unsigned char, std::string> huffman::cargarMapa(const std::string& ruta) {
    std::ifstream archivo(ruta);
    std::map<unsigned char, std::string> mapa;

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo del mapa." << std::endl;
        return mapa;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string parte;
        int claveAscii;
        std::string codigo;

        if (std::getline(ss, parte, ':')) {
            claveAscii = std::stoi(parte);
            if (std::getline(ss, codigo)) {
                mapa[static_cast<unsigned char>(claveAscii)] = codigo;
            }
        }
    }

    archivo.close();
    return mapa;
}

void huffman::guardarMapa(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para guardar el mapa." << std::endl;
        return;
    }

    for (const auto& par : codigos) {
        archivo << static_cast<int>(par.first) << ":" << par.second << "\n";
    }

    archivo.close();
    std::cout << "Mapa guardado en: " << ruta << std::endl;
}

vector<unsigned char> huffman::descomprimir(const vector<unsigned char> &datos, const string &rutaMapa) {
    // Cargar el mapa de códigos
    map<unsigned char, string> mapaCodigos = cargarMapa(rutaMapa);

    // Convertir los datos comprimidos a un string de bits
    string bits;
    for (unsigned char byte : datos) {
        for (int i = 7; i >= 0; --i) {
            bits += ((byte >> i) & 1) ? '1' : '0';
        }
    }

    vector<unsigned char> resultado;
    string codigoActual;

    // Recorrer los bits y reconstruir los caracteres originales
    for (char bit : bits) {
        codigoActual += bit;
        for (const auto& par : mapaCodigos) {
            if (codigoActual == par.second) {
                resultado.push_back(par.first);
                codigoActual.clear();
                break;
            }
        }
    }

    return resultado;
}



