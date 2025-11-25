#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <vector>
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

#include "rh.h"
void menuPrincipal(std::vector<Colaborador>& listaColaboradores);

#endif