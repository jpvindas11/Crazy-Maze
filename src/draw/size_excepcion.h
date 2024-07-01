#include <iostream>
#include <exception>

class Size_excepcion : public std::exception {
private:
    std::string error_message;
public:
    Size_excepcion(const std::string& mensaje) : error_message(mensaje) {}

    const char* what() const noexcept override {
        return error_message.c_str();
    }
};