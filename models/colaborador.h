#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <string>
#include <vector>

//Estrutura para guardar as marcações de férias/faltas
struct Marcacao {
    std::string data;
    char tipo;
};

// Estrutura para guardar notas sobre colaborador e texto
struct Nota {
    std::string texto;
    std::string data;
};

//Estrutura para guardar formações e data
struct Formacao {
    std::string nome_curso;
    std::string data_conclusao;
};

//Estrutura para guardar colaboradores e um array das marcações, notas e formações
struct Colaborador {
    int id;
    std::string nome;
    std::string departamento;
    std::vector<Marcacao> marcacoes;
    std::vector<Nota> notas;
    std::vector<Formacao> formacoes;
};

#endif
