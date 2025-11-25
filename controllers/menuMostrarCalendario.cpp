//===================================================================================
// Ficheiro: menuMostrarCalendario.cpp
// Objetivo: Implementação da função para mostrar o calendário de um colaborador
//===================================================================================

#include "menuMostrarCalendario.h"

void menuMostrarCalendario(std::vector<Colaborador>& lista)
{
    std::string nome = lerNomeColaborador();
    int mes = lerMes();
    int ano = lerAno();
    std::cin.ignore();

    const Colaborador* c = encontrarColaborador(lista, nome);

    if (!c)
    {
        std::cout << "Colaborador nao encontrado!\n";
        pausarEcra();
        return;
    }

    mostrarCalendario(*c, mes, ano);
    pausarEcra();
}
