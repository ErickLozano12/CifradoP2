#pragma once
#include <string>

class CifradoCesar {
public:
    static std::string cifrar(const std::string& texto, int clave);
    static std::string descifrar(const std::string& texto, int clave);
};
