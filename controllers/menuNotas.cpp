//===================================================================================
// Ficheiro: menuNotas.cpp
// Objetivo: Implementação do submenu de notas para CRUD de notas
//===================================================================================
#include "menuNotas.h"

void menuNotas(std::vector<Colaborador>& lista)
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
        mostrarMenuNotas(*c);
        std::cin >> op;
        std::cin.ignore();

        switch (op)
        {
            case 1: listarNotas(*c); break;
            case 2: adicionarNota(*c); break;
            case 3: editarNota(*c); break;
            case 4: removerNota(*c); break;
            case 0: break;
            default: std::cout << "Opcao invalida.\n";
        }
    }

    pausarEcra();
}
