#include "carromodel.h"
#include <QMessageBox>
#include <QtCore/QCoreApplication>

CarroModel::CarroModel()
{
}
bool CarroModel::validarCarro(std::string placa, std::string cor, std::string marca, std::string modelo, std::string cidade, std::string uf){

    QStringList erros;

    if(placa.empty() || placa.length() <  8){
        erros.append("Placa");
    }

    if(cor.empty() || cor.length() <  4){
        erros.append("Cor");
    }

    if(marca.empty() || marca.length() <  4){
        erros.append("Marca");
    }

    if(modelo.empty() || modelo.length() <  2){
        erros.append("Modelo");
    }

    if(cidade.empty() || cidade.length() <  3){
        erros.append("Cidade");
    }

    if(uf.empty() || uf.length() !=  2){
        erros.append("UF\Estado");
    }

    if(!erros.isEmpty()){

        QString erro = "Campos inválidos:\n";

        foreach (erro, erros) {
            erro += erro+"\n";
        }

        QMessageBox::critical(NULL,"Error !",erro);
    }

}
