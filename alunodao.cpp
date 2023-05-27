#include "alunodao.h"
#include "qdebug.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <fstream>

AlunoDAO::AlunoDAO(QString NomeDoArquivo):
    nomeDoArquivoDisco(NomeDoArquivo)
{

}

std::list<Aluno> AlunoDAO::listagem(QString nomeArquivo)
{
    try {
        std::ifstream arquivo(nomeArquivo.toStdString());  // Abre o arquivo especificado pelo nomeArquivo
        if (!arquivo) {
            throw QString("Erro ao abrir o arquivo.");
        }

        std::string linha;
        std::list<Aluno> listaDeAluno;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string matricula, nome, turmas;

            std::getline(ss, matricula, ';');
            std::getline(ss, nome, ';');
            std::getline(ss, turmas, ';');

            std::list<std::string> turmasSeparadas;
            std::stringstream turmasStream(turmas);
            std::string turma;

            while (std::getline(turmasStream, turma, ' ')) {
                if (!turma.empty()) {
                    turmasSeparadas.push_back(turma);
                }
            }

            Aluno objAluno;
            objAluno.setMatricula(QString::fromStdString(matricula));
            objAluno.setAluno(QString::fromStdString(nome));

            std::list<DisciplinaTurma> listaDeDisciplinas;
            for (const auto& t : turmasSeparadas) {
                std::string codDisciplina, numTurma;
                std::stringstream turmaStream(t);

                std::getline(turmaStream, codDisciplina, '-');
                std::getline(turmaStream, numTurma);

                if (!codDisciplina.empty() && !numTurma.empty()) {
                    DisciplinaTurma objDisciplina;
                    objDisciplina.setCodDisciplina(QString::fromStdString(codDisciplina));
                    objDisciplina.setTurma(QString::fromStdString(numTurma));

                    listaDeDisciplinas.push_back(objDisciplina);
                }
            }

            objAluno.setDisciplinas(listaDeDisciplinas);
            listaDeAluno.push_back(objAluno);
        }

        arquivo.close();  // Fecha o arquivo após a leitura

        // Imprimir a lista de alunos (apenas para verificação)
        for (const auto& aluno : listaDeAluno) {
            qDebug() << "Matrícula: " << aluno.getMatricula();
            qDebug() << "Nome: " << aluno.getAluno();
            qDebug() << "Disciplinas: ";
            for (const auto& disciplina : aluno.getDisciplinas()) {
                qDebug() << " - Código: " << disciplina.getCodDisciplina();
                qDebug() << "   Turma: " << disciplina.getTurma();
            }
        }

        return listaDeAluno;
    } catch (std::bad_alloc&) {// Tratamento do erro de alocação de memória
        QString ("lista vazia");
    }
}

std::list<Aluno> AlunoDAO::listagemPorAluno(QString nomeArquivo, QString aluno) {
    try {
        std::ifstream arquivo(nomeArquivo.toStdString());  // Abre o arquivo especificado pelo nomeArquivo
        if (!arquivo) {
            throw QString("Erro ao abrir o arquivo.");
        }

        std::string linha;
        std::list<Aluno> listaDeAluno;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string matricula, nome, turmas;

            std::getline(ss, matricula, ';');
            std::getline(ss, nome, ';');
            std::getline(ss, turmas, ';');

            if (QString::fromStdString(nome) == aluno) {
                std::list<std::string> turmasSeparadas;
                std::stringstream turmasStream(turmas);
                std::string turma;

                while (std::getline(turmasStream, turma, ' ')) {
                    if (!turma.empty()) {
                        turmasSeparadas.push_back(turma);
                    }
                }

                Aluno objAluno;
                objAluno.setMatricula(QString::fromStdString(matricula));
                objAluno.setAluno(QString::fromStdString(nome));

                std::list<DisciplinaTurma> listaDeDisciplinas;
                for (const auto& t : turmasSeparadas) {
                    std::string codDisciplina, numTurma;
                    std::stringstream turmaStream(t);

                    std::getline(turmaStream, codDisciplina, '-');
                    std::getline(turmaStream, numTurma);

                    if (!codDisciplina.empty() && !numTurma.empty()) {
                        DisciplinaTurma objDisciplina;
                        objDisciplina.setCodDisciplina(QString::fromStdString(codDisciplina));
                        objDisciplina.setTurma(QString::fromStdString(numTurma));

                        listaDeDisciplinas.push_back(objDisciplina);
                    }
                }

                objAluno.setDisciplinas(listaDeDisciplinas);
                listaDeAluno.push_back(objAluno);
            }
        }

        arquivo.close();  // Fecha o arquivo após a leitura

        return listaDeAluno;
    } catch (std::bad_alloc&) { // Tratamento do erro de alocação de memória
        QString ("lista vazia");
    }
}

std::list<Aluno> AlunoDAO::listagemPorDisciplinaTurma(QString nomeArquivo, QString disciplina, QString turm)
{
    try {
        std::ifstream arquivo(nomeArquivo.toStdString());  // Abre o arquivo especificado pelo nomeArquivo
        if (!arquivo) {
            throw QString("Erro ao abrir o arquivo.");
        }

        std::string linha;
        std::list<Aluno> listaDeAluno;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string matricula, nome, turmas;

            std::getline(ss, matricula, ';');
            std::getline(ss, nome, ';');
            std::getline(ss, turmas, ';');

            std::list<std::string> turmasSeparadas;
            std::stringstream turmasStream(turmas);
            std::string turma;

            while (std::getline(turmasStream, turma, ' ')) {
                if (!turma.empty()) {
                    turmasSeparadas.push_back(turma);
                }
            }

            Aluno objAluno;
            objAluno.setMatricula(QString::fromStdString(matricula));
            objAluno.setAluno(QString::fromStdString(nome));

            std::list<DisciplinaTurma> listaDeDisciplinas;
            for (const auto& t : turmasSeparadas) {
                std::string codDisciplina, numTurma;
                std::stringstream turmaStream(t);

                std::getline(turmaStream, codDisciplina, '-');
                std::getline(turmaStream, numTurma);

                if (!codDisciplina.empty() && !numTurma.empty()) {
                    DisciplinaTurma objDisciplina;
                    objDisciplina.setCodDisciplina(QString::fromStdString(codDisciplina));
                    objDisciplina.setTurma(QString::fromStdString(numTurma));

                    listaDeDisciplinas.push_back(objDisciplina);
                }
            }

            objAluno.setDisciplinas(listaDeDisciplinas);

            // Verificar se o aluno possui a disciplina e turma desejadas
            for (const auto& disciplinaTurma : objAluno.getDisciplinas()) {
                if (disciplinaTurma.getCodDisciplina() == disciplina && disciplinaTurma.getTurma() == turm) {
                    listaDeAluno.push_back(objAluno);
                    break; // Não é necessário verificar as demais disciplinas do aluno
                }
            }
        }

        arquivo.close();  // Fecha o arquivo após a leitura

        // Imprimir a lista de alunos (apenas para verificação)
        for (const auto& aluno : listaDeAluno) {
            qDebug() << "Matrícula: " << aluno.getMatricula();
            qDebug() << "Nome: " << aluno.getAluno();
            qDebug() << "Disciplinas: ";
            for (const auto& disciplina : aluno.getDisciplinas()) {
                qDebug() << " - Código: " << disciplina.getCodDisciplina();
                qDebug() << "   Turma: " << disciplina.getTurma();
            }
        }

        return listaDeAluno;
    } catch (std::bad_alloc&) {// Tratamento do erro de alocação de memória
        QString ("lista vazia");
    }
}

std::list<Aluno> AlunoDAO::listagemPorDisciplina(QString nomeArquivo, QString disciplina)
{
    try {
        std::ifstream arquivo(nomeArquivo.toStdString());  // Abre o arquivo especificado pelo nomeArquivo
        if (!arquivo) {
            throw QString("Erro ao abrir o arquivo.");
        }

        std::string linha;
        std::list<Aluno> listaDeAluno;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string matricula, nome, turmas;

            std::getline(ss, matricula, ';');
            std::getline(ss, nome, ';');
            std::getline(ss, turmas, ';');

            std::list<std::string> turmasSeparadas;
            std::stringstream turmasStream(turmas);
            std::string turma;

            while (std::getline(turmasStream, turma, ' ')) {
                if (!turma.empty()) {
                    turmasSeparadas.push_back(turma);
                }
            }

            Aluno objAluno;
            objAluno.setMatricula(QString::fromStdString(matricula));
            objAluno.setAluno(QString::fromStdString(nome));

            std::list<DisciplinaTurma> listaDeDisciplinas;
            for (const auto& t : turmasSeparadas) {
                std::string codDisciplina, numTurma;
                std::stringstream turmaStream(t);

                std::getline(turmaStream, codDisciplina, '-');
                std::getline(turmaStream, numTurma);

                if (!codDisciplina.empty() && !numTurma.empty()) {
                    DisciplinaTurma objDisciplina;
                    objDisciplina.setCodDisciplina(QString::fromStdString(codDisciplina));
                    objDisciplina.setTurma(QString::fromStdString(numTurma));

                    listaDeDisciplinas.push_back(objDisciplina);
                }
            }

            objAluno.setDisciplinas(listaDeDisciplinas);

            // Verificar se o aluno possui a disciplina e turma desejadas
            for (const auto& disciplinaTurma : objAluno.getDisciplinas()) {
                if (disciplinaTurma.getCodDisciplina() == disciplina) {
                    listaDeAluno.push_back(objAluno);
                    break; // Não é necessário verificar as demais disciplinas do aluno
                }
            }
        }

        arquivo.close();  // Fecha o arquivo após a leitura

        // Imprimir a lista de alunos (apenas para verificação)
        for (const auto& aluno : listaDeAluno) {
            qDebug() << "Matrícula: " << aluno.getMatricula();
            qDebug() << "Nome: " << aluno.getAluno();
            qDebug() << "Disciplinas: ";
            for (const auto& disciplina : aluno.getDisciplinas()) {
                qDebug() << " - Código: " << disciplina.getCodDisciplina();
                qDebug() << "   Turma: " << disciplina.getTurma();
            }
        }

        return listaDeAluno;
    } catch (std::bad_alloc&) {// Tratamento do erro de alocação de memória
        QString ("lista vazia");
    }

}
std::list<Aluno> AlunoDAO::listagemPorCurso(QString nomeArquivo, QString Curso)
{

    try {
        std::ifstream arquivo(nomeArquivo.toStdString());  // Abre o arquivo especificado pelo nomeArquivo
        if (!arquivo) {
            throw QString("Erro ao abrir o arquivo.");
        }

        std::string linha;
        std::list<Aluno> listaDeAluno;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string matricula, nome, turmas;

            std::getline(ss, matricula, ';');
            std::getline(ss, nome, ';');
            std::getline(ss, turmas, ';');

            // Extrair o número do curso da matrícula do aluno
            size_t pos = matricula.find_last_of('.');
            std::string numeroCurso = matricula.substr(pos - 3, 3); // Considerando que o formato seja sempre "XXXX.X.####.YYYY"

            // Verificar se o número do curso extraído corresponde ao parâmetro Curso
            if (numeroCurso == Curso.toStdString()) {
                std::list<std::string> turmasSeparadas;
                std::stringstream turmasStream(turmas);
                std::string turma;

                while (std::getline(turmasStream, turma, ' ')) {
                    if (!turma.empty()) {
                        turmasSeparadas.push_back(turma);
                    }
                }

                Aluno objAluno;
                objAluno.setMatricula(QString::fromStdString(matricula));
                objAluno.setAluno(QString::fromStdString(nome));

                std::list<DisciplinaTurma> listaDeDisciplinas;
                for (const auto& t : turmasSeparadas) {
                    std::string codDisciplina, numTurma;
                    std::stringstream turmaStream(t);

                    std::getline(turmaStream, codDisciplina, '-');
                    std::getline(turmaStream, numTurma);

                    if (!codDisciplina.empty() && !numTurma.empty()) {
                        DisciplinaTurma objDisciplina;
                        objDisciplina.setCodDisciplina(QString::fromStdString(codDisciplina));
                        objDisciplina.setTurma(QString::fromStdString(numTurma));

                        listaDeDisciplinas.push_back(objDisciplina);
                    }
                }

                objAluno.setDisciplinas(listaDeDisciplinas);
                listaDeAluno.push_back(objAluno);
            }
        }

        arquivo.close();  // Fecha o arquivo após a leitura

        // Imprimir a lista de alunos (apenas para verificação)
        for (const auto& aluno : listaDeAluno) {
            qDebug() << "Matrícula: " << aluno.getMatricula();
            qDebug() << "Nome: " << aluno.getAluno();
            qDebug() << "Disciplinas: ";
            for (const auto& disciplina : aluno.getDisciplinas()) {
                qDebug() << " - Código: " << disciplina.getCodDisciplina();
                qDebug() << "   Turma: " << disciplina.getTurma();
            }
        }

        return listaDeAluno;
    } catch (std::bad_alloc&) { // Tratamento do erro de alocação de memória
        QString ("lista vazia");
    }
}




