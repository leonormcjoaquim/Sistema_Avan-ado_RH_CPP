

#include "menuEstatisticas.h"

void menuEstatisticas(const std::vector<Colaborador>& lista)
{
    int op = -1;

    while (op != 0)
    {
        mostrarMenuEstatisticas();
        std::cin >> op;
        std::cin.ignore();

        switch (op)
        {
            case 1: estatisticasDepartamentos(lista); break;
            case 2: estatisticasDepartamentosCSV(lista); break;
            case 0: break;
            default: std::cout << "Opcao invalida.\n";
        }
    }

    pausarEcra();
}
