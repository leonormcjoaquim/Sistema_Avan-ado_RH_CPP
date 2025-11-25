#include "menuMarcarDia.h"
#include "../views/io.h"
#include "../models/calendario.h"
#include <iostream>

void menuMarcarDia(std::vector<Colaborador>& lista)
{
    std::string nome = lerNomeColaborador();
    int d = lerDia();
    int m = lerMes();
    int a = lerAno();
    char tipo = lerTipoMarcacao();
    std::cin.ignore();

    marcarDia(lista, nome, d, m, a, tipo);
    std::cout << "Marcação registada.\n";

    pausarEcra();
}

void menuDesmarcarDia(std::vector<Colaborador>& lista)
{
    std::string nome = lerNomeColaborador();
    int d = lerDia();
    int m = lerMes();
    int a = lerAno();
    std::cin.ignore();

    desmarcarDia(lista, nome, d, m, a);
    std::cout << "Desmarcação registada.\n";

    pausarEcra();
}
