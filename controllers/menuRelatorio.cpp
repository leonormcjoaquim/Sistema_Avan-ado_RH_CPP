#include "menuRelatorio.h"
#include "menuRelatorio.h"
#include "../models/relatorio.h"
#include "../models/ficheiro.h"
#include "../views/io.h"
#include <iostream>

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
