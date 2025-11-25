#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <vector>
#include <string>
#include "colaborador.h"
#include <iostream>
#include <fstream>

void dashboardResumido(const std::vector<Colaborador>& listaColaboradores);
void dashboardResumidoCSV(const std::vector<Colaborador>& listaColaboradores);

#endif
