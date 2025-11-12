#include "../include/Empleado.hpp"

namespace Seguridad 
    {
        // Constructor.
        Empleado::Empleado(int id, const std::string& nombre, const std::string& puesto) 
                 : id(id), nombre(nombre), puesto(puesto) {}

        Empleado::~Empleado() {}

        // Getter y setter específico.
        int Empleado::getId() const 
            {
                return id;
            }

        std::string Empleado::getNombre() const 
            {
                return nombre;
            }

        std::string Empleado::getPuesto() const 
            {
                return puesto;
            }
        
        void Empleado::setId(const int id) 
            {
                this->id = id;
            }
        void Empleado::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }
        void Empleado::setPuesto(const std::string& puesto) 
            {
                this->puesto = puesto;
            }

        void Empleado::mostrarInfo() const 
            {
                std::cout << "👨‍💼 ID: " << getId() 
                          << " | Empleado: " << getNombre() 
                          << " | Puesto: " << puesto << std::endl;
            }
    }