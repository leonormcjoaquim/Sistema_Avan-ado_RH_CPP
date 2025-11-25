#ifndef NOTAS_H
#define NOTAS_H

#include <vector>
#include <string>
#include "colaborador.h"
#include "../views/io.h"
#include "../models/calendario.h"
#include "cifra.h"
#include <fstream>
#include <sstream>
#include <iostream>

void listarNotas(const Colaborador& c);
void adicionarNota(Colaborador& c);
void editarNota(Colaborador& c);
void removerNota(Colaborador& c);

#endif
