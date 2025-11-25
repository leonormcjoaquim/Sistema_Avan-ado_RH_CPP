//===================================================================================
// Ficheiro: formacoes.cpp
// Objetivo: Implementação das funções para listar, adicionar, editar e remover formações
//===================================================================================
#include "formacoes.h"

void listarFormacoes(const Colaborador &c)
{
    std::cout << "\n--- FORMACOES DE " << c.nome << " ---\n";

    if (c.formacoes.empty())
    {
        std::cout << "Sem formacoes\n";
        return;
    }

    for (size_t i = 0; i < c.formacoes.size(); i++)
    {
        std::cout << i + 1 << ") " << c.formacoes[i].nome_curso
                  << "  [" << c.formacoes[i].data_conclusao << "]\n";
    }
}

void adicionarFormacao(Colaborador &c)
{
    Formacao fo;

    std::cout << "Nome da formacao: ";
    std::getline(std::cin >> std::ws, fo.nome_curso);

    int dia, mes, ano;

    do
    {
        dia = lerDia();
        mes = lerMes();
        ano = lerAno();

        if (!isDataValida(dia, mes, ano))
            std::cout << "Data invalida! Tente novamente.\n";

    } while (!isDataValida(dia, mes, ano));

    fo.data_conclusao = std::to_string(ano) + "-" +
                        (mes < 10 ? "0" : "") + std::to_string(mes) + "-" +
                        (dia < 10 ? "0" : "") + std::to_string(dia);

    c.formacoes.push_back(fo);

    std::cout << "Formacao adicionada.\n";
}

void editarFormacao(Colaborador &c)
{
    listarFormacoes(c);
    if (c.formacoes.empty())
        return;

    int indice;
    std::cout << "Escolha o numero da formacao: ";
    std::cin >> indice;
    std::cin.ignore();

    if (indice < 1 || indice > (int)c.formacoes.size())
    {
        std::cout << "Indice invalido.\n";
        return;
    }

    Formacao &fo = c.formacoes[indice - 1];

    std::cout << "Novo nome da formacao: ";
    std::getline(std::cin >> std::ws, fo.nome_curso);

    int dia, mes, ano;
    do
    {
        dia = lerDia();
        mes = lerMes();
        ano = lerAno();

        if (!isDataValida(dia, mes, ano))
            std::cout << "Data invalida! Tente novamente.\n";

    } while (!isDataValida(dia, mes, ano));

    fo.data_conclusao = std::to_string(ano) + "-" +
                        (mes < 10 ? "0" : "") + std::to_string(mes) + "-" +
                        (dia < 10 ? "0" : "") + std::to_string(dia);

    std::cout << "Formacao editada.\n";
}

void removerFormacao(Colaborador &c)
{
    listarFormacoes(c);

    if (c.formacoes.empty())
        return;

    int indice;
    std::cout << "Escolha o numero da formacao para remover: ";
    std::cin >> indice;

    if (indice < 1 || indice > (int)c.formacoes.size())
    {
        std::cout << "Indice invalido.\n";
        return;
    }

    c.formacoes.erase(c.formacoes.begin() + (indice - 1));

    std::cout << "Formacao removida.\n";
}