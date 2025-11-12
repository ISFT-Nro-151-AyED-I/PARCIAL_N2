#pragma once

#include <iostream>
#include <string>

namespace Seguridad 
    {
        class Cliente 
            {
                private:
                    int id;
                    std::string nombre;
                    std::string email;
                    
                public:
                    Cliente(int id = 0, const std::string& nombre = "", const std::string& email = "");
                    ~Cliente();
                    
                    // Getters y setters.
                    int getId() const;
                    std::string getNombre() const;
                    std::string getEmail() const;
                    void setId(int id);
                    void setNombre(const std::string& nombre);
                    void setEmail(const std::string& email);
                    
                    void mostrarInfo() const;
            };
    }