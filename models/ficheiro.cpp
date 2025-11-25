//===================================================================================
// Ficheiro: ficheiro.cpp
// Objetivo: Implementação das funções de guardar e  carregar dados em ficheiros CSV
// incluindo estatisticas ou relatórios
//===================================================================================

#include "ficheiro.h"

// Guarda os colaboradores e as marcações num ficheiro CSV quando o programa termina
bool guardarCSV(const std::vector<Colaborador> &lista)
{
    std::ofstream f("colaboradores.csv");
    if (!f)
        return false;

    f << "ID,Nome,Data,Tipo,Departamento\n";

    for (const auto& c : lista)
    {
        std::string nomeEnc = cifrar(c.nome);
        std::string depEnc = cifrar(c.departamento);

        if (c.marcacoes.empty())
        {
            f << c.id << "," << nomeEnc << ",,," << depEnc << "\n";
        }
        else
        {
            for (const auto& m : c.marcacoes)
            {
                f << c.id << "," << nomeEnc << "," << m.data << "," << m.tipo << "," << depEnc << "\n";
            }
        }
    }
    return true;
}

// Carrega os colaboradores e as marcações de um ficheiro CSV quando o programa inicia
bool carregarCSV(std::vector<Colaborador> &lista)
{
    std::ifstream f("colaboradores.csv");
    if (!f.is_open()) 
        return false;

    lista.clear();
    std::string linha;

    std::getline(f, linha);

    while (std::getline(f, linha))
    {
        if (linha.empty()) 
            continue;

        std::stringstream ss(linha);
        std::string idStr, nomeEnc, data, tipoStr, depEnc;

        std::getline(ss, idStr, ',');
        std::getline(ss, nomeEnc, ',');
        std::getline(ss, data, ',');
        std::getline(ss, tipoStr, ',');
        std::getline(ss, depEnc, ',');

        int id = std::stoi(idStr);

        std::string nome = decifrar(nomeEnc);
        std::string departamento = decifrar(depEnc);

        for (char& c : nome) {
            c = std::tolower(c);
        }

        for (char& d : departamento) {
            d = std::tolower(d);
        }

        Colaborador* col = nullptr;

        for (auto& x : lista)
            if (x.id == id)
                col = &x;

        if (!col)
        {
            Colaborador novo;
            novo.id = id;
            novo.nome = nome;
            novo.departamento = departamento;
            lista.push_back(novo);
            col = &lista.back();
        }

        if (!tipoStr.empty())
        {
            Marcacao m;
            m.data = data;
            m.tipo = tipoStr[0];
            col->marcacoes.push_back(m);
        }
    }
    return true;
}

// Formações
bool guardarFormacoesCSV(const std::vector<Colaborador> &listaFormacoes)
{
    std::ofstream f("formacoes.csv");
    if (!f.is_open())
        return false;

    f << "id,nome,formacao,data\n";

    for (const auto &c : listaFormacoes)
    {
        std::string nomeEnc = cifrar(c.nome);

        for (const auto &fo : c.formacoes)
        {
            f << c.id << "," << nomeEnc << "," << fo.nome_curso << "," << fo.data_conclusao << "\n";
        }
    }
    return true;
}

bool carregarFormacoesCSV(std::vector<Colaborador> &listaFormacoes)
{
    std::ifstream f("formacoes.csv");
    if (!f.is_open())
        return false;

    std::string linha;
    std::getline(f, linha);

    while (std::getline(f, linha))
    {
        if (linha.empty())
            continue;

        std::stringstream ss(linha);
        std::string idStr, nomeEnc, curso, data;

        std::getline(ss, idStr, ',');
        std::getline(ss, nomeEnc, ',');
        std::getline(ss, curso, ',');
        std::getline(ss, data, ',');

        int id = std::stoi(idStr);
        std::string nome = decifrar(nomeEnc);
        for (char &c : nome) {
            c = std::tolower(c);
        }

        // Procurar colaborador
        Colaborador *colPtr = nullptr;
        for (std::size_t i = 0; i < listaFormacoes.size(); i++)
        {
            if (listaFormacoes[i].id == id)
            {
                colPtr = &listaFormacoes[i];
                break;
            }
        }

        if (!colPtr)
        {
            Colaborador novo;
            novo.id = id;
            novo.nome = nome;
            listaFormacoes.push_back(novo);
            colPtr = &listaFormacoes.back();
        }

        Formacao f2;
        f2.nome_curso = curso;
        f2.data_conclusao = data;

        colPtr->formacoes.push_back(f2);
    }

    return true;
}

// Notas
bool guardarNotasCSV(const std::vector<Colaborador> &listaNotas)
{
    std::ofstream f("notas.csv");
    if (!f.is_open())
        return false;

    f << "id,nome,data,texto\n";

    for (const auto &c : listaNotas)
    {
        std::string nomeEnc = cifrar(c.nome);

        for (const auto &n : c.notas)
        {
            std::string textoEnc = cifrar(n.texto);
            f << c.id << "," << nomeEnc << "," << n.data << "," << textoEnc << "\n";
        }
    }
    return true;
}

bool carregarNotasCSV(std::vector<Colaborador> &listaNotas)
{
    std::ifstream f("notas.csv");
    if (!f.is_open())
        return false;

    std::string linha;
    std::getline(f, linha);

    while (std::getline(f, linha))
    {
        if (linha.empty())
            continue;

        std::stringstream ss(linha);
        std::string idStr, nomeEnc, data, textoEnc;

        std::getline(ss, idStr, ',');
        std::getline(ss, nomeEnc, ',');
        std::getline(ss, data, ',');
        std::getline(ss, textoEnc, ',');

        int id = std::stoi(idStr);
        std::string nome = decifrar(nomeEnc);
        for (char &c : nome)
            c = std::tolower(c);

        Colaborador *colPtr = nullptr;
        for (std::size_t i = 0; i < listaNotas.size(); i++)
        {
            if (listaNotas[i].id == id)
            {
                colPtr = &listaNotas[i];
                break;
            }
        }

        if (!colPtr)
        {
            Colaborador novo;
            novo.id = id;
            novo.nome = nome;
            listaNotas.push_back(novo);
            colPtr = &listaNotas.back();
        }

        Nota n;
        n.data = data;
        n.texto = decifrar(textoEnc);

        colPtr->notas.push_back(n);
    }

    return true;
}


void relatorioMensalCSV(const std::vector<Colaborador>& lista, int mes, int ano)
{
    std::ofstream f("relatorio_mensal.csv");
    if (!f.is_open())
    {
        std::cout << "Erro ao criar ficheiro CSV!\n";
        return;
    }

    f << "ID,Nome,Férias,Faltas\n";

    for (size_t i = 0; i < lista.size(); i++)
    {
        int ferias = 0, faltas = 0;
        contarMarcacoesMes(lista[i], mes, ano, ferias, faltas);

        f << lista[i].id << ","
          << lista[i].nome << ","
          << ferias << ","
          << faltas << "\n";
    }

    f.close();
    std::cout << "Ficheiro relatorio_mensal.csv criado com sucesso!\n";
}


//ficheiro estatisticas por departamento em CSV
void estatisticasDepartamentosCSV(const std::vector<Colaborador>& lista)
{
    std::ofstream f("estatisticas_departamentos.csv");
    if (!f.is_open())
    {
        std::cout << "Erro a criar ficheiro CSV!\n";
        return;
    }

    std::vector<Departamento> deps;

    for (size_t i = 0; i < lista.size(); i++)
    {
        const Colaborador& c = lista[i];
        std::string dep = c.departamento;

        if (dep == "") {
            dep = "Sem departamento";
        }

        int idx = procurarDepartamento(deps, dep);
        if (idx == -1)
        {
            Departamento novo;
            novo.departamento = dep;
            novo.ferias = 0;
            novo.faltas = 0;
            deps.push_back(novo);
            idx = deps.size() - 1;
        }

        for (size_t j = 0; j < c.marcacoes.size(); j++)
        {
            if (c.marcacoes[j].tipo == 'F') deps[idx].ferias++;
            if (c.marcacoes[j].tipo == 'X') deps[idx].faltas++;
        }
    }

    f << "Departamento,Férias,Faltas,Total\n";

    for (size_t i = 0; i < deps.size(); i++)
    {
        int total = deps[i].ferias + deps[i].faltas;
        f << deps[i].departamento << "," << deps[i].ferias << "," << deps[i].faltas << "," << total << "\n";
    }

    f.close();
    std::cout << "Ficheiro estatisticas_departamentos.csv criado com sucesso!\n";
}
