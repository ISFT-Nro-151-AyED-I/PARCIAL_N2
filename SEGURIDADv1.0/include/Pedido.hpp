#pragma once

#include "Equipo.hpp"
#include "Cliente.hpp"
#include "Empleado.hpp"

namespace Seguridad 
    {
        class Pedido 
            {
                private:
                    int id;
                    Cliente* cliente;
                    Empleado* empleado;           
                    Equipo** equipos;             
                    int* cantidades;
                    int cantidadEquipos;
                    int capacidadEquipos;
                    
                public:
                    Pedido(int id = 0, Cliente* cliente = nullptr, Empleado* empleado = nullptr); 
                    ~Pedido();
                    
                    // Getters.
                    int getId() const;
                    Cliente* getCliente() const;
                    Empleado* getEmpleado() const;
                    int getCantidadEquipos() const;
                    
                    // Setters.
                    void setId(int id);
                    void setCliente(Cliente* cliente);
                    void setEmpleado(Empleado* empleado);
                    
                    // Gestión de equipos.
                    void agregarEquipo(Equipo* equipo, int cantidad); 
                    void mostrarPedido() const;
                    double calcularTotal() const;
            };
    }