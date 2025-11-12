#pragma once

#include <iostream>
#include <string>

namespace Seguridad
    {
        class Empleado 
            {
                private:
                    int id;
                    std::string nombre;
                    std::string puesto;
                    
                public:
                    Empleado(int id = 0, const std::string& nombre = "", const std::string& puesto = "");
                    ~Empleado();
                    
                    // Getters y setters.
                    int getId() const;
                    std::string getNombre() const;
                    std::string getPuesto() const;
                    void setId(int id);
                    void setNombre(const std::string& nombre);
                    void setPuesto(const std::string& puesto);
                    
                    void mostrarInfo() const;
            };
    }