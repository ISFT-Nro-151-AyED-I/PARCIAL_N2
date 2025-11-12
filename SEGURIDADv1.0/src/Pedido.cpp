#include "../include/Pedido.hpp"

namespace Seguridad
    {
        // Constructor.
        Pedido::Pedido(int id, Cliente* cliente, Empleado* empleado) 
            : id(id), cliente(cliente), empleado(empleado), cantidadEquipos(0), capacidadEquipos(10) 
            {
                // Inicializa arrays dinámicos con capacidad fija.
                equipos = new Equipo*[capacidadEquipos];
                cantidades = new int[capacidadEquipos];
            }
        
        // Destructor.
        Pedido::~Pedido() 
            {
                // 🔥 MUY IMPORTANTE: Solo liberamos los arrays, NO los objetos (agregación PURA).
                delete[] equipos;
                delete[] cantidades;
            }

        // Getters.
        int Pedido::getId() const 
            {
                return id;
            }

        Cliente* Pedido::getCliente() const 
            {
                return cliente;
            }

        Empleado* Pedido::getEmpleado() const 
            {
                return empleado;
            }

        int Pedido::getCantidadEquipos() const 
            {
                return cantidadEquipos;
            }

        // Setters.
        void Pedido::setId(int id) 
            {
                this->id = id;
            }

        void Pedido::setCliente(Cliente* cliente) 
            {
                this->cliente = cliente;
            }

        void Pedido::setEmpleado(Empleado* empleado) 
            {
                this->empleado = empleado;
            }

        // Agrega equipo al pedido.
        void Pedido::agregarEquipo(Equipo* equipo, int cantidad) 
            {
                if (cantidadEquipos >= capacidadEquipos) 
                    {
                        std::cout << "❌ No se puede agregar más equipos. Capacidad máxima alcanzada: " 
                                << capacidadEquipos << std::endl;
                        return;
                    }
                
                // Agrega equipo y cantidad a los arrays.
                equipos[cantidadEquipos] = equipo;
                cantidades[cantidadEquipos] = cantidad;
                cantidadEquipos++;

                std::cout << "✅ Equipo agregado: " << equipo->getNombre() 
                          << " (Cantidad: " << cantidad << ")" << std::endl;
            }

        // Muestra información completa del pedido.
        void Pedido::mostrarPedido() const 
        {
            if (!cliente || !empleado) 
                {
                    std::cout << "❌ Pedido incompleto - falta cliente o empleado asignado" << std::endl;
                    return;
                }

            std::cout << "\n\n📦 PEDIDO #" << id << std::endl;
            std::cout << "=================\n" << std::endl;
            std::cout << "👤 Cliente: " << cliente->getNombre() << std::endl;
            std::cout << "👨‍💼 Empleado: " << empleado->getNombre() << " (" << empleado->getPuesto() << ")" << std::endl;
            std::cout << "\n🦺 Equipos en el pedido:\n" << std::endl;
            
            if (cantidadEquipos == 0) 
                {
                    std::cout << "   📭 No hay equipos en este pedido" << std::endl;
                } 
                else 
                    {
                        for (int i = 0; i < cantidadEquipos; i++) 
                            {
                                std::cout << "   " << (i + 1) << ". " << equipos[i]->getNombre()
                                          << " | Cantidad: " << cantidades[i]
                                          << " | Precio unitario: $" << equipos[i]->getPrecio()
                                          << " | Subtotal: $" << (equipos[i]->getPrecio() * cantidades[i])
                                          << std::endl;
                            }
                    }

            std::cout << "\n------------------------------" << std::endl;
            std::cout << "💰 TOTAL DEL PEDIDO: $" << calcularTotal() << std::endl;
            std::cout << "------------------------------" << std::endl;
        }

        // Calcula total del pedido.
        double Pedido::calcularTotal() const 
            {
                double total = 0.0;

                for (int i = 0; i < cantidadEquipos; i++) 
                    {
                        total += equipos[i]->getPrecio() * cantidades[i];
                    }

                return total;
            }
    }