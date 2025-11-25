#include "menuAdicionarColaborador.h"
#include "../views/io.h"
#include "../controllers/rh.h"
#include <iostream>

void menuAdicionarColaborador(std::vector<Colaborador>& lista)
{
    std::string nome = lerNomeColaborador();

    if (adicionarColaborador(lista, nome))
        std::cout << "Colaborador adicionado com sucesso!\n";
    else
        std::cout << "Já existe colaborador com esse nome.\n";
    pausarEcra();
}
