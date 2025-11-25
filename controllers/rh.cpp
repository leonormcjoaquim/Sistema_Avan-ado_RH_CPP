//===================================================================================
// Ficheiro: rh.cpp
// Objetivo: Implementação das funções principais de recursos humanos para criar e
// gerir colaboradores, marcações e ficheiros CSV
//===================================================================================

#include "rh.h"

// Carregar tudo a partir dos CSV separados
void carregarTudo(std::vector<Colaborador> &lista)
{
    lista.clear();
    carregarCSV(lista);
    carregarNotasCSV(lista);
    carregarFormacoesCSV(lista);
}

// Guarda tudo nos CSV separados
void guardarTudo(const std::vector<Colaborador> &lista)
{
    guardarCSV(lista);
    guardarNotasCSV(lista);
    guardarFormacoesCSV(lista);
}

// Gerar próximo ID
int criarNovoID(const std::vector<Colaborador> &listaColaboradores)
{
    // int nextID = listaColaboradores.empty() ? 0 : listaColaboradores.size();
    // return nextID + 1;
    int idAtual = 0;
    for (size_t i = 0; i < listaColaboradores.size(); i++)
    {
        if (listaColaboradores[i].id > idAtual)
        {
            idAtual = listaColaboradores[i].id;
        }
    }

    return idAtual + 1;
}

// Cria colaborador se não existir já um com mesmo nome
bool adicionarColaborador(std::vector<Colaborador> &listaColaboradores, const std::string &nome)
{
    for (const auto &c : listaColaboradores)
        if (c.nome == nome)
            return false;

    Colaborador novo;
    novo.nome = nome;

    novo.id = criarNovoID(listaColaboradores);

    std::cout << "Departamento: ";
    std::getline(std::cin >> std::ws, novo.departamento);

    listaColaboradores.push_back(novo);
    return true;
}

// procurar colaborador para mostrar calendario
Colaborador *encontrarColaborador(std::vector<Colaborador> &listaColaboradores, const std::string &nome)
{
    for (auto &c : listaColaboradores)
        if (c.nome == nome)
            return &c;
    return 0;
}

// procurar por ID
Colaborador *procurarColaboradorID(std::vector<Colaborador> &listaColaboradores, int id)
{
    for (size_t i = 0; i < listaColaboradores.size(); i++)
        if (listaColaboradores[i].id == id)
            return &listaColaboradores[i];

    return nullptr;
}

// procurar se uma marcação existe mesmo, e devolve a posição
int procurarMarcacao(const Colaborador &c, const std::string &data)
{
    for (int i = 0; i < c.marcacoes.size(); i++) {
        if (c.marcacoes[i].data == data){
            return i;
        }
    }
    return -1;
}

// Construir data YYYY-MM-DD
std::string construirData(int dia, int mes, int ano)
{
    std::string s = std::to_string(ano) + "-";

    if (mes < 10)
        s += "0";
    s += std::to_string(mes) + "-";

    if (dia < 10)
        s += "0";
    s += std::to_string(dia);

    return s;
}

// Verificar conflito de férias
bool isConflitoFerias(const std::vector<Colaborador> &listaColaboradores, const Colaborador &colaborador, const std::string &data)
{
    for (size_t i = 0; i < listaColaboradores.size(); i++)
    {
        // Mesmo departamento, mas colaborador diferente
        if (listaColaboradores[i].departamento == colaborador.departamento && listaColaboradores[i].id != colaborador.id)
        {
            for (size_t j = 0; j < listaColaboradores[i].marcacoes.size(); j++)
            {
                if (listaColaboradores[i].marcacoes[j].data == data && listaColaboradores[i].marcacoes[j].tipo == 'F')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Marcar férias ou faltas
void marcarDia(std::vector<Colaborador> &listaColaboradores, const std::string &nome, int dia, int mes, int ano, char tipo)
{
    if (!isDataValida(dia, mes, ano) || isFimDeSemana(dia, mes, ano))
        return;

    std::string data = construirData(dia, mes, ano);

    // Obter colaborador
    for (auto &colaborador : listaColaboradores) {
        if (colaborador.nome == nome) {
            if (tipo == 'F' && isConflitoFerias(listaColaboradores, colaborador, data)){
                std::cout << "Ja existe alguem do mesmo departamento com ferias nesse dia.\n";
            }
            int index = procurarMarcacao(colaborador, data);

            if (index >= 0)
                colaborador.marcacoes[index].tipo = tipo;
            else
            {
                Marcacao marc;
                marc.data = data;
                marc.tipo = tipo;
                colaborador.marcacoes.push_back(marc);
            }
            return;
        }
    }
}

// Desmarcar
void desmarcarDia(std::vector<Colaborador> &listaColaboradores, const std::string &nome, int dia, int mes, int ano)
{
    std::string data = construirData(dia, mes, ano);

    for (auto &c : listaColaboradores) {
        if (c.nome == nome) {
            int index = procurarMarcacao(c, data);
            if (index >= 0) {
                c.marcacoes.erase(c.marcacoes.begin() + index);
            }
            return;
        }
    }
}
