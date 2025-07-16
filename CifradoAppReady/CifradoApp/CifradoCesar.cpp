#include "CifradoCesar.h"

std::string CifradoCesar::cifrar(const std::string& texto, int clave) {
    std::string resultado;
    for (char c : texto) resultado += c + clave;
    return resultado;
}

std::string CifradoCesar::descifrar(const std::string& texto, int clave) {
    std::string resultado;
    for (char c : texto) resultado += c - clave;
    return resultado;
}
