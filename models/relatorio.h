#ifndef RELATORIO_H
#define RELATORIO_H

#include <vector>
#include "colaborador.h"

void contarMarcacoesMes(const Colaborador& c, int mes, int ano, int& ferias, int& faltas);
void relatorioMensalEcra(const std::vector<Colaborador>& lista, int mes, int ano);

#endif
