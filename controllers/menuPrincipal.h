#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include "../models/colaborador.h"
#include "menuNotas.h"
#include "menuFormacoes.h"
#include "menuRelatorio.h"
#include "menuEstatisticas.h"
#include "menuDashboard.h"
#include "../views/io.h"
#include "menuPesquisarColaborador.h"
#include "menuMostrarCalendario.h"
#include "menuMarcarDia.h"
#include "menuAdicionarColaborador.h"
#include "../views/io.h"
#include "../models/notas.h"
#include "../models/formacoes.h"
#include "../models/calendario.h"
#include "../models/relatorio.h"
#include "../models/estatisticas.h"
#include "../models/dashboard.h"
#include <vector>
#include "rh.h"
#include <iostream>
#include <limits>

void menuPrincipal(std::vector<Colaborador>& listaColaboradores);

#endif