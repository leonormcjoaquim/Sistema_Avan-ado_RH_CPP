//===================================================================================
// Ficheiro: menuFormacoes.cpp
// Objetivo: Implementação do submenu de formações
//===================================================================================

#include "menuFormacoes.h"

void menuFormacoes(std::vector<Colaborador>& lista)
{
    std::string nome = lerNomeColaborador();
    Colaborador* c = encontrarColaborador(lista, nome);

    if (!c)
    {
        std::cout << "Colaborador nao encontrado.\n";
        pausarEcra();
        return;
    }

    int op = -1;
    while (op != 0)
    {
        mostrarMenuFormacoes(*c);
        std::cin >> op;
        std::cin.ignore();

        switch (op)
        {
            case 1: listarFormacoes(*c); break;
            case 2: adicionarFormacao(*c); break;
            case 3: editarFormacao(*c); break;
            case 4: removerFormacao(*c); break;
            case 0: break;
            default: std::cout << "Opcao invalida.\n";
        }
    }

    pausarEcra();
}
