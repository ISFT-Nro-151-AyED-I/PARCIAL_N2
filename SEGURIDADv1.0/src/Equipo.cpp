#include "../include/Equipo.hpp"

namespace Seguridad
    {
        // Constructor.
        Equipo::Equipo(int id, const std::string& nombre, double precio) 
            : id(id), nombre(nombre), precio(precio) {}

        // Getters.
        int Equipo::getId() const 
            {
                return id;
            }

        std::string Equipo::getNombre() const 
            {
                return nombre;
            }

        double Equipo::getPrecio() const 
            {
                return precio;
            }

        // Setters.
        void Equipo::setId(int id) 
            {
                this->id = id;
            }

        void Equipo::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }

        void Equipo::setPrecio(double precio) 
            {
                this->precio = precio;
            }

        // Métodos de utilidad
        void Equipo::mostrarInfo() const 
            {
                std::cout << "🦺 ID: " << id 
                          << " | Equipo: " << nombre 
                          << " | Precio: $" << precio << std::endl;
            }
    }