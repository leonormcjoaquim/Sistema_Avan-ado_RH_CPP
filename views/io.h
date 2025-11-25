#ifndef IO_H
#define IO_H

#include <vector>
#include <string>
#include <iostream>
#include "../models/colaborador.h"

void mostrarMenu();
void mostrarMenuNotas(const Colaborador& colaborador);
void mostrarMenuFormacoes(const Colaborador& ccolaborador);
void mostrarMenuRelatorios();
void mostrarMenuEstatisticas();
void mostrarMenuDashboard();

std::string lerNomeColaborador();
int lerDia();
int lerMes();
int lerAno();
char lerTipoMarcacao();


void mostrarListaColaboradores(const std::vector<Colaborador>& listaColaboradores);
void mostrarCalendario(const Colaborador& c, int mes, int ano);


void limparEcra();
void pausarEcra();

#endif
