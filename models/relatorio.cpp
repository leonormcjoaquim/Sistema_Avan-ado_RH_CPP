//===================================================================================
// Ficheiro: relatorio.cpp
// Objetivo: Implementação das funções para gerar relatórios mensais de férias e faltas
//===================================================================================
#include "relatorio.h"

// Contar numeros de F e X num mês
void contarMarcacoesMes(const Colaborador& c, int mes, int ano, int& ferias, int& faltas)
{
    ferias = 0;
    faltas = 0;
    for (size_t i = 0; i < c.marcacoes.size(); i++)
    {
        const std::string& data = c.marcacoes[i].data;

        int anoData = std::stoi(data.substr(0, 4));
        int mesData = std::stoi(data.substr(5, 2)); 

        if (anoData == ano && mesData == mes)
        {
            if (c.marcacoes[i].tipo == 'F') {
                ferias++;
            }
            if (c.marcacoes[i].tipo == 'X') {
                faltas++;
            }
        }
    }
}

// imprimir relatorio no ecra
void relatorioMensalEcra(const std::vector<Colaborador>& lista, int mes, int ano)
{
    std::cout << "\n============ RELATORIO MENSAL ============\n\n";
    std::cout << "Mes: " << mes << " / " << ano << "\n\n";

    std::cout << "ID   Nome                 Ferias   Faltas\n";
    std::cout << "------------------------------------------\n";

    for (size_t i = 0; i < lista.size(); i++)
    {
        int ferias = 0, faltas = 0;
        contarMarcacoesMes(lista[i], mes, ano, ferias, faltas);

        std::cout << lista[i].id << "   " << lista[i].nome;

        int espacos = 25 - lista[i].nome.size();

        if (espacos < 1) {
            espacos = 1;
        }
        for (int e = 0; e < espacos; e++) {
            std::cout << " ";
        }

        std::cout << ferias << "        " << faltas << "\n";
    }

    std::cout << "===========================================\n";
}
