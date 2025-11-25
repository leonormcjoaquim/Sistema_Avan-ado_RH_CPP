#ifndef NOTAS_H
#define NOTAS_H

#include <vector>
#include <string>
#include "colaborador.h"

void listarNotas(const Colaborador& c);
void adicionarNota(Colaborador& c);
void editarNota(Colaborador& c);
void removerNota(Colaborador& c);

#endif
