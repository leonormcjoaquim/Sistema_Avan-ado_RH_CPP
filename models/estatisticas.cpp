#include "estatisticas.h"
#include <iostream>
#include <fstream>

// Procura índice de departamento
int procurarDepartamento(const std::vector<Departamento> &departamento, const std::string &dep)
{
    for (size_t i = 0; i < departamento.size(); i++)
    {
        if (departamento[i].departamento == dep)
        {
            return i;
        }
    }

    return -1;
}

void estatisticasDepartamentos(const std::vector<Colaborador> &lista)
{
    std::vector<Departamento> departamento;

    for (size_t i = 0; i < lista.size(); i++)
    {
        const Colaborador &c = lista[i];
        std::string dep = c.departamento;
        
        // para ter todos os departamentos lowercase para comparar
        for (char &c : dep) {
            c = std::tolower(static_cast<unsigned char>(c));
        }

        if (dep == "")
        {
            dep = "sem departamento";
        }

        int index = procurarDepartamento(departamento, dep);
        // caso o departamento nao exista na lista ainda, cria um novo
        if (index == -1)
        {
            Departamento novoDepartamento;
            novoDepartamento.departamento = dep;
            novoDepartamento.ferias = 0;
            novoDepartamento.faltas = 0;
            departamento.push_back(novoDepartamento);
            index = departamento.size() - 1;
        }

        for (size_t j = 0; j < c.marcacoes.size(); j++)
        {
            if (c.marcacoes[j].tipo == 'F')
            {
                departamento[index].ferias++;
            }

            if (c.marcacoes[j].tipo == 'X')
            {
                departamento[index].faltas++;
            }
        }
    }

    std::cout << "\n========== ESTATISTICAS POR DEPARTAMENTO ==========\n";
    std::cout << "Departamento               Ferias   Faltas   Total\n";
    std::cout << "-----------------------------------------------------\n";

    int maiorTotal = -1;
    std::string depMax = "";

    for (size_t i = 0; i < departamento.size(); i++)
    {
        int total = departamento[i].ferias + departamento[i].faltas;

        std::cout << departamento[i].departamento;

        int espacos = 29 - departamento[i].departamento.size();
        if (espacos < 1)
        {
            espacos = 1;
        }
        for (int e = 0; e < espacos; e++)
        {
            std::cout << " ";
        }

        std::cout << departamento[i].ferias << "        " << departamento[i].faltas << "        "
                  << total << "\n";

        // Guardar o departamento com mais ausências para imprimir
        if (total > maiorTotal)
        {
            maiorTotal = total;
            depMax = departamento[i].departamento;
        }
    }

    std::cout << "-----------------------------------------------------\n";
    std::cout << "Departamento com mais ausencias: " << depMax << " (" << maiorTotal << ")\n";
    std::cout << "=====================================================\n\n";
}