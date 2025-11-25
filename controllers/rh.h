#ifndef RH_H
#define RH_H

#include <vector>
#include <string>
#include "../models/colaborador.h"
#include "../models/colaborador.h"
#include "../models/calendario.h"
#include "../models/notas.h"
#include "../models/ficheiro.h"
#include "../models/formacoes.h"
#include <string>
#include <vector>
#include <iostream>

// Carregar e Guardar todos CSVS
void carregarTudo(std::vector<Colaborador>& lista);
void guardarTudo(const std::vector<Colaborador>& lista);

int criarNovoID(const std::vector<Colaborador>& listaColaboradores);
bool adicionarColaborador(std::vector<Colaborador>& listaColaboradores, const std::string& nome);
Colaborador* encontrarColaborador(std::vector<Colaborador>& listaColaboradores, const std::string& nome);
Colaborador* procurarColaboradorID(std::vector<Colaborador>& listaColaboradores, int id);

//Marcar ou Desmarcar Datas
void marcarDia(std::vector<Colaborador>& listaColaboradores, const std::string& nome, int dia, int mes, int ano, char tipo);
void desmarcarDia(std::vector<Colaborador>& listaColaboradores, const std::string& nome, int dia, int mes, int ano);
std::string construirData(int dia, int mes, int ano);
bool isConflitoFerias(const std::vector<Colaborador>& listaColaboradores, const Colaborador& colaborador, const std::string& data);


#endif
