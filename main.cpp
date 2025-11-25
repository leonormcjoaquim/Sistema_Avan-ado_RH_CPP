#include <iostream>
#include <vector>
#include "controllers/rh.h"
#include "models/colaborador.h"
#include "models/ficheiro.h"
#include "controllers/rh.h"
#include "controllers/menuPrincipal.h"

int main()
{
    std::vector<Colaborador> lista;

    carregarTudo(lista);

    menuPrincipal(lista);

    guardarTudo(lista);

    std::cout << "A sair, Obrigada!\n";
    return 0;
}
