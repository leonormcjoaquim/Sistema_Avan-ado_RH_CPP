//===================================================================================
// Ficheiro: menuMarcarDia.cpp
// Objetivo: Implementação das funções de menu para marcar e desmarcar dias
//===================================================================================

#include "menuMarcarDia.h"

void menuMarcarDia(std::vector<Colaborador>& lista)
{
    std::string nome = lerNomeColaborador();
    int d = lerDia();
    int m = lerMes();
    int a = lerAno();
    char tipo = lerTipoMarcacao();
    std::cin.ignore();

    marcarDia(lista, nome, d, m, a, tipo);
    std::cout << "Marcacao registada.\n";

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
    std::cout << "Desmarcacao registada.\n";

    pausarEcra();
}
