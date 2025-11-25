#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <vector>
#include <string>
#include "colaborador.h"
#include <iostream>
#include <fstream>

struct Departamento {
    std::string departamento;
    int ferias;
    int faltas;
};

void estatisticasDepartamentos(const std::vector<Colaborador>& listaColaboradores);
void estatisticasDepartamentosCSV(const std::vector<Colaborador>& listaColaboradores);
int procurarDepartamento(const std::vector<Departamento>& deps, const std::string& dep);

#endif
