#include <iostream>
#include <windows.h>
#include <string>

#include "../include/Empleado.hpp"
#include "../include/Cliente.hpp"
#include "../include/Equipo.hpp"
#include "../include/Pedido.hpp"

using namespace Seguridad;

// Función para mostrar el encabezado de la aplicación.
void mostrarEncabezado();

int main() 
    {
        // Configura consola para caracteres especiales.
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        
        mostrarEncabezado();
        
        std::cout << "\n🚀 INICIALIZANDO DATOS DE PRUEBA..." << std::endl;
        std::cout << "======================================\n" << std::endl;
        
        // 1. CARGA EQUIPOS.
        std::cout << "\n🦺 CARGANDO EQUIPOS DE SEGURIDAD..." << std::endl;
        
        Equipo* equipo1 = new Equipo(1, "Casco de Seguridad", 45.80);
        Equipo* equipo2 = new Equipo(2, "Chaleco Reflectante", 28.50);
        Equipo* equipo3 = new Equipo(3, "Botas de Seguridad", 75.20);
        Equipo* equipo4 = new Equipo(4, "Guantes Anticorte", 32.90);
        Equipo* equipo5 = new Equipo(5, "Antiparras de Protección", 18.75);
        
        std::cout << std::endl;

        // Muestra equipos cargados.
        equipo1->mostrarInfo();
        equipo2->mostrarInfo();
        equipo3->mostrarInfo();
        equipo4->mostrarInfo();
        equipo5->mostrarInfo();
        
        std::cout << std::endl;

        // 2. CARGA EMPLEADOS (UNO MENOS).
        std::cout << "\n👨‍💼 CARGANDO EMPLEADOS..." << std::endl;
        
        Empleado* empleado1 = new Empleado(201, "Lenandro Vendedor", "Vendedor Senior");
        Empleado* empleado2 = new Empleado(202, "Jazmín Comercial", "Ejecutiva de Ventas");
        // Se eliminó el tercer empleado (Roberto).
        
        std::cout << std::endl;

        // Muestra empleados cargados.
        empleado1->mostrarInfo();
        empleado2->mostrarInfo();
        
        std::cout << std::endl;

        // 3. CARGA CLIENTES.
        std::cout << "\n👥 CARGANDO CLIENTES..." << std::endl;
        
        Cliente* cliente1 = new Cliente(101, "Constructora Horizonte", "compras@horizonte.com");
        Cliente* cliente2 = new Cliente(102, "Industrias Metalúrgicas SA", "compras@imsa.com");
        Cliente* cliente3 = new Cliente(103, "Empresa Energética Nacional", "seguridad@een.com");
        
        std::cout << std::endl;

        // Muestra clientes cargados.
        cliente1->mostrarInfo();
        cliente2->mostrarInfo();
        cliente3->mostrarInfo();
        
        std::cout << std::endl;
        
        // 4. CARGA PEDIDOS (UN EMPLEADO TOMA 2 PEDIDOS).
        std::cout << "\n📋 CARGANDO PEDIDOS...\n" << std::endl;
        
        // Pedido 1: Constructora Horizonte (atendido por Leandro).
        Pedido* pedido1 = new Pedido(1001, cliente1, empleado1);
        pedido1->agregarEquipo(equipo1, 10);  // 10 cascos.
        pedido1->agregarEquipo(equipo2, 15);  // 15 chalecos.
        pedido1->agregarEquipo(equipo3, 8);   // 8 botas.
        
        // Pedido 2: Industrias Metalúrgicas SA (atendido por Jazmín).
        Pedido* pedido2 = new Pedido(1002, cliente2, empleado2);
        pedido2->agregarEquipo(equipo3, 12);  // 12 botas.
        pedido2->agregarEquipo(equipo4, 20);  // 20 guantes.
        pedido2->agregarEquipo(equipo5, 15);  // 15 antiparras.
        
        // Pedido 3: Empresa Energética Nacional (atendido por Leandro - MISMO EMPLEADO QUE PEDIDO 1).
        Pedido* pedido3 = new Pedido(1003, cliente3, empleado1);  // Leandro toma otro pedido.
        pedido3->agregarEquipo(equipo1, 5);   // 5 cascos.
        pedido3->agregarEquipo(equipo2, 8);   // 8 chalecos.
        pedido3->agregarEquipo(equipo4, 12);  // 12 guantes.
        pedido3->agregarEquipo(equipo5, 10);  // 10 antiparras.
        
        // 5. MUESTRA PEDIDOS DE CLIENTES.
        std::cout << "\n=======================================" << std::endl;
        std::cout << "   📊 MOSTRANDO PEDIDOS DE CLIENTES" << std::endl;
        std::cout << "=======================================" << std::endl;
        
        // Muestra todos los pedidos.
        pedido1->mostrarPedido();
        pedido2->mostrarPedido();
        pedido3->mostrarPedido();
        
        // 6. DEMOSTRACIÓN ADICIONAL: Muestra pedidos por empleado.
        std::cout << "\n=======================================" << std::endl;
        std::cout << "       🔍 RESUMEN POR EMPLEADO" << std::endl;
        std::cout << "=======================================" << std::endl;
        
        std::cout << "\n👨‍💼 EMPLEADO: " << empleado1->getNombre() << " (" << empleado1->getPuesto() << ")" << std::endl;
        std::cout << "   📦 Pedido #" << pedido1->getId() << " - Cliente: " << pedido1->getCliente()->getNombre() 
                << " - Total: $" << pedido1->calcularTotal() << std::endl;
        std::cout << "   📦 Pedido #" << pedido3->getId() << " - Cliente: " << pedido3->getCliente()->getNombre() 
                << " - Total: $" << pedido3->calcularTotal() << std::endl;
        std::cout << "   💰 TOTAL VENDIDO: $" << (pedido1->calcularTotal() + pedido3->calcularTotal()) << std::endl;
        
        std::cout << "\n👩‍💼 EMPLEADO: " << empleado2->getNombre() << " (" << empleado2->getPuesto() << ")" << std::endl;
        std::cout << "   📦 Pedido #" << pedido2->getId() << " - Cliente: " << pedido2->getCliente()->getNombre() 
                << " - Total: $" << pedido2->calcularTotal() << std::endl;
        std::cout << "   💰 TOTAL VENDIDO: $" << pedido2->calcularTotal() << std::endl;
        
        // 7. LIMPIEZA DE MEMORIA.
        std::cout << "\n\n=======================================" << std::endl;
        std::cout << "       🧹 LIBERANDO MEMORIA" << std::endl;
        std::cout << "=======================================\n" << std::endl;
        
        // Libera pedidos.
        delete pedido1;
        delete pedido2;
        delete pedido3;
        std::cout << "✅ Pedidos liberados." << std::endl;
        
        // Libera clientes.
        delete cliente1;
        delete cliente2;
        delete cliente3;
        std::cout << "✅ Clientes liberados." << std::endl;
        
        // Libera empleados.
        delete empleado1;
        delete empleado2;
        std::cout << "✅ Empleados liberados." << std::endl;
        
        // Libera equipos.
        delete equipo1;
        delete equipo2;
        delete equipo3;
        delete equipo4;
        delete equipo5;
        std::cout << "✅ Equipos liberados." << std::endl;
        
        std::cout << "\n\n=======================================" << std::endl;
        std::cout << "🎉 PROGRAMA EJECUTADO EXITOSAMENTE! 🎉" << std::endl;
        std::cout << "=======================================" << std::endl;
        
        std::cout << "\nPresiona Enter para salir...";
        std::cin.get();
        
        return 0;
    }

void mostrarEncabezado() 
    {
        std::cout << "\n✨ ======================================= ✨" << std::endl;
        std::cout << "✨            SEGURIDAD v1.0 🦺            ✨" << std::endl;
        std::cout << "✨       Sistema de Gestión de Pedidos     ✨" << std::endl;
        std::cout << "✨          Equipos de Protección          ✨" << std::endl;
        std::cout << "✨ ======================================= ✨" << std::endl;
        std::cout << std::endl;
    }