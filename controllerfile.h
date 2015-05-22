#ifndef CONTROLLERFILE_H
#define CONTROLLERFILE_H
#include <QtCore>

class ControllerFile
{
public:
    ControllerFile();

//    QString arfEstado = ":/data/source/data/cidades.csv";
//    QString arfCor = ":/data/source/data/cores.csv";
//    QString arfModelo = ":/data/source/data/marcas.csv";
//    QString arfUser = ":/data/source/data/users.csv";
//    QString arfCarros = ":/data/source/data/carros.csv";
//    QString arfPatio = ":/data/source/data/patio.csv";


    QString arfEstado = "../SansCar/source/data/cidades.csv";
    QString arfCor = "../SansCar/source/data/cores.csv";
    QString arfModelo = "../SansCar/source/data/marcas.csv";
    QString arfUser = "../SansCar/source/data/users.csv";
    QString arfCarros = "../SansCar/source/data/carros.csv";
    QString arfPatio = "../SansCar/source/data/patio.csv";






    QStringList leArquivo(QString nomeArquivo);
    bool gravaArquivo(QString nomeArquivo, QString conteudo);
    bool updateArquivo(QString arfUp, QString pk, QString item);
    //retorna  lista de estados
    QStringList getEstados();
    //grava o novo estado
    bool setEstado(QString estado);
    //retorna lista de cidades
    QStringList getCidades();
    //grava o novo cidade
    bool setCidade(QString cidade);
    //Retorna lista de cores
    QStringList getCors();
    //grava nova cor
    bool setCor(QString cor);
    //retorna lista de marca
    QStringList getMarcas();
    //grava a nova marca
    bool setMarcas(QString marca);
    //retorna lista de modelos
    QStringList getModelos();
    //grava novo modelo
    bool setModelo(QString modelo);

     QStringList getlogins();
     QStringList getPatio();

     bool findPlacaPatio(QString arfPatio, QString placa);
     bool findPlacaCarros(QString arfCarros, QString placa);

     void gravaEntrada(QString placa);

     QString findCarro(QString placa);


};

#endif // CONTROLLERFILE_H
