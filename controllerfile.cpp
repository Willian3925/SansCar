#include "controllerfile.h"
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDate>


using namespace std;

ControllerFile::ControllerFile()
{
}

QStringList ControllerFile::leArquivo(QString nomeArquivo){

    QFile meuArquivo(nomeArquivo);

    if(!meuArquivo.exists()) {
        QMessageBox::critical(NULL,"Erro Critico","arquivo: "+nomeArquivo+" não encontrado.");
    }
    if(!meuArquivo.open(QFile::ReadOnly|QFile::Text) ) {
        QMessageBox::critical(NULL,"Erro Critico","Erro na tentativa de abrir o arquivo "+nomeArquivo+".");
    }
    QStringList listaDoConteudoDoArquivo;
    while (!meuArquivo.atEnd()) {
        QString linha = meuArquivo.readLine();
        listaDoConteudoDoArquivo.append(linha);
    }
    return listaDoConteudoDoArquivo;
}

bool ControllerFile::gravaArquivo(QString nomeArquivo, QString conteudo){

    QFile mfile(nomeArquivo);
    if(!mfile.open(QFile::Append| QFile::Text)){
        QMessageBox::critical(NULL, "Error", "Ocorreu um erro na tentativa de gravar dados"+nomeArquivo);

        return 0;

     }else if(!mfile.isOpen()){
        QMessageBox::critical(NULL,"Error","Ocorreu um erro na tentativa de acessar os dados"+nomeArquivo);

        return 0;
    }
    else{

    QTextStream out(&mfile);
    out << conteudo<<endl;

    mfile.flush();
    mfile.close();
}
    return 1;
}



bool ControllerFile::updateArquivo(QString arfUp, QString pk, QString item){

    QStringList contem = this->leArquivo(arfUp);
    QString novoConteudo;

    foreach (QString conteudo, contem){
        QStringList fatiaConteudo = conteudo.split(",");
        int qtConteudoNaLinha = fatiaConteudo.length();
            for(int i = 0; i <= qtConteudoNaLinha; i++){
                if(pk == fatiaConteudo[i]){
                    novoConteudo+=","+item;

                }else{
                    novoConteudo +=","+conteudo;

                }


            }

    }

}


QStringList ControllerFile::getEstados(){

    QStringList estados = this->leArquivo(this->arfEstado);
    QStringList uf;
    foreach (QString var, estados) {
        QStringList listaUfLinha = var.split(",");
        uf.append(listaUfLinha[1]);
    }
    uf.removeDuplicates();
    return uf;
}

bool ControllerFile::setEstado(QString estado){

    if(this->gravaArquivo(this->arfEstado, estado))
        return 1;
    return 0;

}
QStringList ControllerFile::getCidades(){

    QStringList cidades = this->leArquivo(this->arfEstado);
    QStringList soAsCidades;
    foreach (QString partes, cidades) {
        QStringList resultadoDaFatia = partes.split(",");
        soAsCidades.append(resultadoDaFatia[0]);
    }
    soAsCidades.removeDuplicates();
    return cidades;

}
bool ControllerFile::setCidade(QString cidade){

    if(this->gravaArquivo(this->arfEstado,cidade))
        return 1;
    return 0;

}
QStringList ControllerFile::getCors(){

    QStringList cores = this->leArquivo(this->arfCor);

    cores.removeDuplicates();
    return cores;
}
bool ControllerFile::setCor(QString cor){

    if(this->gravaArquivo(this->arfCor,cor))
        return 1;
    return 0;

}
QStringList ControllerFile::getMarcas(){

    QStringList marcas = this->leArquivo(this->arfModelo);

    QStringList meMarcas;
    foreach (QString var, marcas) {
        QStringList listamarcasLinha = var.split(",");
        meMarcas.append(listamarcasLinha[1]);

    meMarcas.removeDuplicates();
    return meMarcas;
}
}
bool ControllerFile::setMarcas(QString marca){

    if(this->gravaArquivo(this->arfModelo,marca))
        return 1;
    return 0;

}
QStringList ControllerFile::getModelos(){

    QStringList modelos = this->leArquivo(this->arfModelo);

    QStringList meModelos;
    foreach (QString var, modelos) {
        QStringList listamodelosLinha = var.split(",");
        meModelos.append(listamodelosLinha[0]);
    }

    meModelos.removeDuplicates();
    return meModelos;
}
bool ControllerFile::setModelo(QString modelo){

    if(this->gravaArquivo(this->arfModelo,modelo))
        return 1;
    return 0;

}
QStringList ControllerFile::getlogins(){

    QStringList usuarios =  this->leArquivo(this->arfUser);

    usuarios.removeDuplicates();
    return usuarios;
}

QStringList ControllerFile::getPatio(){

    QStringList patioCarros = this->leArquivo(this->arfPatio);
    QStringList soOsAberto;

    foreach (QString carro, patioCarros){

        QStringList resultadoDaCarros = carro.split(",");
        soOsAberto.append(resultadoDaCarros[0]
            +","+resultadoDaCarros[2]
            +","+resultadoDaCarros[1]
            +","+resultadoDaCarros[3]
            +","+resultadoDaCarros[6]);


    }
    soOsAberto.removeDuplicates();
    return soOsAberto;

}


bool ControllerFile::findPlacaPatio(QString arfPatio, QString placa){

    QStringList carrosNoArquivo = this->leArquivo(arfPatio);


    foreach (QString var, carrosNoArquivo)
    {
        QStringList linha = var.split(",");
        if(linha[0]==placa){

            return 1;

        }

    }

            return 0;
}

bool ControllerFile::findPlacaCarros(QString arfCarros, QString placa){

    QStringList carrosNoArquivo = this->leArquivo(arfCarros);


    foreach (QString var, carrosNoArquivo)
    {
        QStringList linha = var.split(",");
        if(linha[0]==placa){

            return 1;

        }

    }

            return 0;
}


void ControllerFile::gravaEntrada(QString placa){

    QStringList carro = this->findCarro(placa);
    QString conteudo;

    foreach (QString var, carro) {

        conteudo += var;

    }
        // inseri a data e hora
     QString dateTime = QString::number(QDate::currentDate().day())
     +"-"+
     QString::number(QDate::currentDate().month())
     +"-"+
     QString::number(QDate::currentDate().year())
      +" "+
     QString::number(QTime::currentTime().hour())
     +":"+
     QString::number(QTime::currentTime().minute());
}




QString ControllerFile::findCarro(QString placa){

    QStringList carrosNoArquivo = this->leArquivo(arfCarros);

    foreach (QString var, carrosNoArquivo){

             QStringList linha = var.split(",");
             if (linha[0] == placa){
                 return var;
             }
    }
    return carrosNoArquivo;

}




