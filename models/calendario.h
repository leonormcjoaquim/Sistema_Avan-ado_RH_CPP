#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <chrono>

int diasNoMes(int mes, int ano);
bool isAnoBissexto(int ano);
int diaSemana(int dia, int mes, int ano);
bool isFimDeSemana(int dia, int mes, int ano);
bool isDataValida(int dia, int mes, int ano);
int obterMesAtual();
int obterAnoAtual();

#endif
