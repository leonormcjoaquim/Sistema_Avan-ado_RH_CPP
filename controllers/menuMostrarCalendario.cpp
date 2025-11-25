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
        std::cout << "Colaborador não encontrado!\n";
        pausarEcra();
        return;
    }

    mostrarCalendario(*c, mes, ano);
    pausarEcra();
}
