//===================================================================================
// Ficheiro: menuPrincipal.cpp
// Objetivo: Implementação do menu principal do sistema
//===================================================================================

#include "menuPrincipal.h"

void menuPrincipal(std::vector<Colaborador> &listaColaboradores)
{
    int opcao = -1;

    while (opcao != 0)
    {
        limparEcra();
        mostrarMenu();
        while (true)
        {
            std::cout << "Escolha uma opcao: ";
            std::cin >> opcao;

            if (!std::cin.fail())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Introduza apenas numeros\n";
        }

        switch (opcao)
        {
        case 1:
            mostrarListaColaboradores(listaColaboradores);
            pausarEcra();
            break;
        case 2:
            menuAdicionarColaborador(listaColaboradores);
            break;
        case 3:
            menuMarcarDia(listaColaboradores);
            break;
        case 4:
            menuDesmarcarDia(listaColaboradores);
            break;
        case 5:
            menuMostrarCalendario(listaColaboradores);
            break;
        case 6:
            menuPesquisarColaborador(listaColaboradores);
            break;
        case 7:
            menuFormacoes(listaColaboradores);
            break;
        case 8:
            menuNotas(listaColaboradores);
            break;
        case 9:
            menuRelatorios(listaColaboradores);
            break;
        case 10:
            menuEstatisticas(listaColaboradores);
            break;
        case 11:
            menuDashboard(listaColaboradores);
            break;
        case 0:
            break;
        default:
            std::cout << "Opcao invalida.\n";
            pausarEcra();
        }
    }
}
