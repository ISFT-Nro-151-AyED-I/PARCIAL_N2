#pragma once

#include <iostream>
#include <string>

namespace Seguridad 
    {
        class Equipo 
            {
                private:
                    int id;
                    std::string nombre;
                    double precio;
                    
                public:
                    Equipo(int id = 0, const std::string& nombre = "", double precio = 0.0);
                    
                    // Getters y setters.
                    int getId() const;
                    std::string getNombre() const;
                    double getPrecio() const;
                    
                    void setId(int id);
                    void setNombre(const std::string& nombre);
                    void setPrecio(double precio);
                    
                    void mostrarInfo() const;
            };
    }