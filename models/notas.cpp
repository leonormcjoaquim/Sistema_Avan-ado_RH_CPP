#include "notas.h"
#include "../views/io.h"
#include "../models/calendario.h"
#include "cifra.h"
#include <fstream>
#include <sstream>
#include <iostream>

void listarNotas(const Colaborador& c)
{
    std::cout << "\n--- NOTAS DE " << c.nome << " ---\n";

    if (c.notas.empty())
    {
        std::cout << "Sem notas\n";
        return;
    }

    for (size_t i = 0; i < c.notas.size(); i++)
    {
        std::cout << i + 1 << ") [" << c.notas[i].data << "] "
                  << c.notas[i].texto << "\n";
    }
}

void adicionarNota(Colaborador& c)
{
    Nota n;

    int dia, mes, ano;

    // Ler data com validação
    do {
        dia = lerDia();
        mes = lerMes();
        ano = lerAno();

        if (!isDataValida(dia, mes, ano))
            std::cout << "Data invalida! Tente novamente.\n";

    } while (!isDataValida(dia, mes, ano));

    // Guardar como string "YYYY-MM-DD"
    n.data = std::to_string(ano) + "-" +
             (mes < 10 ? "0" : "") + std::to_string(mes) + "-" +
             (dia < 10 ? "0" : "") + std::to_string(dia);

    std::cout << "Texto da nota: ";
    std::getline(std::cin >> std::ws, n.texto);

    c.notas.push_back(n);

    std::cout << "Nota adicionada.\n";
}


// função para editar o texto de uma nota
void editarNota(Colaborador& c)
{
    listarNotas(c);

    if (c.notas.empty()) 
        return;

    int indice;
    std::cout << "Escolha o numero da nota para editar: ";
    std::cin >> indice;
    std::cin.ignore();

    if (indice < 1 || indice > (int)c.notas.size())
    {
        std::cout << "Indice invalido.\n";
        return;
    }

    Nota& n = c.notas[indice - 1];

    int dia, mes, ano;

    // Ler nova data com validação
    do {
        dia = lerDia();
        mes = lerMes();
        ano = lerAno();

        if (!isDataValida(dia, mes, ano))
            std::cout << "Data invalida! Tente novamente.\n";

    } while (!isDataValida(dia, mes, ano));

    // Guardar no formato correto
    n.data = std::to_string(ano) + "-" +
             (mes < 10 ? "0" : "") + std::to_string(mes) + "-" +
             (dia < 10 ? "0" : "") + std::to_string(dia);

    std::cout << "Novo texto: ";
    std::getline(std::cin >> std::ws, n.texto);

    std::cout << "Nota editada.\n";
}


void removerNota(Colaborador& c)
{
    listarNotas(c);

    if (c.notas.empty()) return;

    int indice;
    std::cout << "Escolha o numero da nota para remover: ";
    std::cin >> indice;

    if (indice < 1 || indice > (int)c.notas.size())
    {
        std::cout << "Indice invalido.\n";
        return;
    }

    c.notas.erase(c.notas.begin() + (indice - 1));

    std::cout << "Nota removida.\n";
}