#ifndef MENU_MARCAR_DIA_H
#define MENU_MARCAR_DIA_H

#include <vector>
#include "../models/colaborador.h"
#include "../controllers/rh.h"
#include "../views/io.h"
#include "../models/calendario.h"
#include <iostream>

void menuMarcarDia(std::vector<Colaborador>& lista);
void menuDesmarcarDia(std::vector<Colaborador>& lista);

#endif
