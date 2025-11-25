//===================================================================================
// Ficheiro: menuAdicionarColaborador.cpp
// Objetivo: Implementação do menu para adicionar um colaborador
//===================================================================================
#include "menuAdicionarColaborador.h"

void menuAdicionarColaborador(std::vector<Colaborador>& lista)
{
    std::string nome = lerNomeColaborador();

    if (adicionarColaborador(lista, nome))
        std::cout << "Colaborador adicionado com sucesso!\n";
    else
        std::cout << "Já existe colaborador com esse nome.\n";
    pausarEcra();
}
