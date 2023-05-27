#ifndef ALUNODAO_H
#define ALUNODAO_H
#include <QString>
#include <aluno.h>
#include <disciplinaturma.h>
#include <QStringList>
#include <fstream>
#include <list>
class AlunoDAO
{
private:
    QString nomeDoArquivoDisco;
public:
    AlunoDAO() {}
    AlunoDAO(QString NomeDoArquivo);


    std::list<Aluno> listagem(QString nomeArquivo);
    std::list<Aluno> listagemPorAluno(QString nomeArquivo,QString aluno);
    std::list<Aluno> listagemPorDisciplinaTurma(QString nomeArquivo,QString disciplina,QString turma);
    std::list<Aluno> listagemPorDisciplina(QString nomeArquivo,QString disciplina);
    std::list<Aluno> listagemPorCurso(QString nomeArquivo,QString Curso);
};

#endif // ALUNODAO_H
