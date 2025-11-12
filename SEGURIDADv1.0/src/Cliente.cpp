#include "../include/Cliente.hpp"

namespace Seguridad 
    {
        // Constructor.
        Cliente::Cliente(int id, const std::string& nombre, const std::string& email) 
                : id(id), nombre(nombre), email(email) {}

        Cliente::~Cliente() {}

        // Getter y setter específico.
        int Cliente::getId() const 
            {
                return id;
            }

            std::string Cliente::getNombre() const 
            {
                return nombre;
            }

        std::string Cliente::getEmail() const 
            {
                return email;
            }
        void Cliente::setId(const int id) 
            {
                this->id = id;
            }
        void Cliente::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }
        void Cliente::setEmail(const std::string& email) 
            {
                this->email = email;
            }

        void Cliente::mostrarInfo() const 
            {
                std::cout << "👤 ID: " << getId() 
                          << " | Cliente: " << getNombre() 
                          << " | Email: " << email << std::endl;
            }
    }