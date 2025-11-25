//===================================================================================
// Ficheiro: menuRelatorio.cpp
// Objetivo: Implementação do submenu de relatórios para visualização ou exportação
//===================================================================================

#include "menuRelatorio.h"

void menuRelatorios(const std::vector<Colaborador>& lista)
{
    int mes = lerMes();
    int ano = lerAno();

    int op = -1;

    while (op != 0)
    {
        mostrarMenuRelatorios();
        std::cin >> op;
        std::cin.ignore();

        switch (op)
        {
            case 1: relatorioMensalEcra(lista, mes, ano); break;
            case 2: relatorioMensalCSV(lista, mes, ano); break;
            case 0: break;
            default: std::cout << "Opcao invalida.\n";
        }
    }

    pausarEcra();
}
