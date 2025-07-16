#include "CifradoXOR.h"

std::string CifradoXOR::cifrar(const std::string& texto, char clave) {
    std::string resultado;
    for (char c : texto) {
        resultado += c ^ clave; // operación XOR
    }
    return resultado;
}

std::string CifradoXOR::descifrar(const std::string& texto, char clave) {
    // mismo proceso: XOR es reversible
    return cifrar(texto, clave);
}