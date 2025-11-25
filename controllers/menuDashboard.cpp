//===================================================================================
// Ficheiro: menuDashboard.cpp
// Objetivo: Implementação do submenu do dashboard
//===================================================================================

#include "menuDashboard.h"

void menuDashboard(const std::vector<Colaborador>& lista)
{
    int op = -1;

    while (op != 0)
    {
        mostrarMenuDashboard();
        std::cin >> op;
        std::cin.ignore();

        switch (op)
        {
            case 1: dashboardResumido(lista); break;
            case 2: dashboardResumidoCSV(lista); break;
            case 0: break;
            default: std::cout << "Opcao invalida.\n";
        }
    }

    pausarEcra();
}
