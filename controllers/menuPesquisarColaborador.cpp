//===================================================================================
// Ficheiro: menuPesquisarColaborador.cpp
// Objetivo: Implementação do menu para pesquisar um colaborador por ID ou nome
//===================================================================================

#include "menuPesquisarColaborador.h"

void menuPesquisarColaborador(std::vector<Colaborador>& lista)
{
    std::cout << "1. Procurar por ID\n2. Procurar por nome\nEscolha: ";
    int tipo;
    std::cin >> tipo;
    std::cin.ignore();

    Colaborador* c = nullptr;

    if (tipo == 1)
    {
        int id;
        std::cout << "ID: ";
        std::cin >> id;
        std::cin.ignore();

        c = procurarColaboradorID(lista, id);
    }
    else
    {
        std::string nome = lerNomeColaborador();
        c = encontrarColaborador(lista, nome);
    }

    if (!c)
    {
        std::cout << "Colaborador nao encontrado.\n";
        pausarEcra();
        return;
    }

    int mesAtual = obterMesAtual();
    int anoAtual = obterAnoAtual();
    limparEcra();
    std::cout << "Colaborador:\n";
    std::cout << "ID: " << c->id << "\n";
    std::cout << "Nome: " << c->nome << "\n";
    std::cout << "Departamento: " << c->departamento << "\n\n";

    mostrarCalendario(*c, mesAtual, anoAtual);

    pausarEcra();
}
