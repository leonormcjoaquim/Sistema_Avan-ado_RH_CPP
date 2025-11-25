#ifndef FORMACOES_H
#define FORMACOES_H

#include <vector>
#include <string>
#include "colaborador.h"
#include "../models/calendario.h"
#include "../views/io.h"
#include "cifra.h"
#include <fstream>
#include <sstream>
#include <iostream>

void listarFormacoes(const Colaborador& c);
void adicionarFormacao(Colaborador& c);
void editarFormacao(Colaborador& c);
void removerFormacao(Colaborador& c);

#endif