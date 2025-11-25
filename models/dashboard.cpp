#include "dashboard.h"
#include <iostream>
#include <fstream>

static const int DIAS_FERIAS_ANO = 22;

// Conta total anual (não só mensal)
void contarTotaisAno(const Colaborador& colaborador, int& ferias, int& faltas)
{
    ferias = 0;
    faltas = 0;

    for (size_t i = 0; i < colaborador.marcacoes.size(); i++)
    {
        if (colaborador.marcacoes[i].tipo == 'F') 
            ferias++;
        if (colaborador.marcacoes[i].tipo == 'X') 
            faltas++;
    }
}

// ==============================
//      DASHBOARD NO ECRÃ
// ==============================
void dashboardResumido(const std::vector<Colaborador>& listaColaboradores)
{
    std::cout << "\n================ DASHBOARD RESUMIDO ================\n";
    std::cout << "Nome                 Férias   Faltas   Restantes\n";
    std::cout << "---------------------------------------------------\n";

    for (size_t i = 0; i < listaColaboradores.size(); i++)
    {
        int ferias = 0; 
        int faltas = 0;
        contarTotaisAno(listaColaboradores[i], ferias, faltas);

        int restantes = DIAS_FERIAS_ANO - ferias;
        if (restantes < 0) 
            restantes = 0;

        std::cout << listaColaboradores[i].nome;

        int espacos = 20 - listaColaboradores[i].nome.size();
        if (espacos < 1) 
            espacos = 1;
        for (int e = 0; e < espacos; e++) std::cout << " ";

        std::cout << ferias << "        "
                  << faltas << "        "
                  << restantes << "\n";
    }

    std::cout << "====================================================\n\n";
}

// ==============================
//      IMPRIMIR PARA CSV
// ==============================
void dashboardResumidoCSV(const std::vector<Colaborador>& listaColaboradores)
{
    std::ofstream f("dashboard.csv");
    if (!f.is_open())
    {
        std::cout << "Erro ao criar dashboard.csv\n";
        return;
    }

    f << "Nome,Férias,Faltas,Restantes\n";

    for (size_t i = 0; i < listaColaboradores.size(); i++)
    {
        int ferias = 0, faltas = 0;
        contarTotaisAno(listaColaboradores[i], ferias, faltas);

        int restantes = DIAS_FERIAS_ANO - ferias;
        if (restantes < 0) restantes = 0;

        f << listaColaboradores[i].nome << ","
          << ferias << ","
          << faltas << ","
          << restantes << "\n";
    }

    f.close();
    std::cout << "dashboard.csv criado com sucesso!\n";
}
