#ifndef FICHEIRO_H
#define FICHEIRO_H

#include <vector>
#include <iostream>
#include "colaborador.h"
#include "relatorio.h"
#include "estatisticas.h"
#include "cifra.h"
#include <fstream>
#include <sstream>
#include "colaborador.h"

bool guardarCSV(const std::vector<Colaborador>& listaColaboradores);
bool carregarCSV(std::vector<Colaborador>& listaColaboradores);

bool guardarFormacoesCSV(const std::vector<Colaborador>& listaFormacoes);
bool carregarFormacoesCSV(std::vector<Colaborador>& listaFormacoes);

bool guardarNotasCSV(const std::vector<Colaborador>& listaNotas);
bool carregarNotasCSV(std::vector<Colaborador>& listaNotas);

void relatorioMensalCSV(const std::vector<Colaborador>& lista, int mes, int ano);

void estatisticasDepartamentosCSV(const std::vector<Colaborador>& lista);

#endif
