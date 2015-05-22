#include "cadastradocarro.h"
#include "ui_cadastradocarro.h"
#include "cadastrocor.h"
#include "cadastromodelo.h"
#include "cadastramarca.h"
#include "cadastrarestado.h"
#include "cadastrarcidade.h"
#include "controllerfile.h"
#include <iostream>
#include "janelaprincipal.h"
#include <QMessageBox>


using namespace std;

CadastradoCarro::CadastradoCarro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastradoCarro)
{
    ui->setupUi(this);
    this->loadCidades();
    this->loadCor();
    this->loadEstado();
    this->loadMarca();
    this->loadModelo();
}

CadastradoCarro::~CadastradoCarro()
{
    delete ui;
}

void CadastradoCarro::on_pushButton_6_clicked()
{
    CadastroCor objCadastroCor;
    objCadastroCor.setModal(true);
    objCadastroCor.exec();
}

void CadastradoCarro::on_pushButton_2_clicked()
{
    CadastroModelo objCadastroModelo;
    objCadastroModelo.setModal(true);
    objCadastroModelo.exec();
}



void CadastradoCarro::on_pushButton_5_clicked()
{
    CadastrarCidade objcidade;
    objcidade.setModal(true);
    objcidade.exec();
}

void  CadastradoCarro::loadCidades(){

    ControllerFile cidade;
    QStringList cidades = cidade.getCidades();
    foreach (QString city, cidades){
        this->ui->cbCidade->addItem(city);
    }
}

void CadastradoCarro::loadEstado(){

    ControllerFile estado;

    QStringList estados = estado.getEstados();
    foreach (QString uf, estados){
       this->ui->cbEstado->addItem(uf);
    }

}

void CadastradoCarro::loadCor(){

    ControllerFile cor;

    QStringList cores = cor.getCors();
    foreach (QString cor, cores){
        this->ui->cbCor->addItem(cor);

    }

}

void CadastradoCarro::loadMarca(){

    ControllerFile marca;

    QStringList marcas = marca.getMarcas();
    foreach (QString marca, marcas) {
        this->ui->cbMarcas->addItem(marca);

    }

}

void CadastradoCarro::loadModelo(){

    ControllerFile modelo;

    QStringList modelos = modelo.getModelos();
    foreach (QString modelo, modelos){
        this->ui->cbModelos->addItem(modelo);    }



}

bool CadastradoCarro::setNewCidade(QString cidade, QString uf){

    if(!cidade.isEmpty()){
        this->ui->cbCidade->addItem(cidade);
    }
    if(!uf.isEmpty()){
        this->ui->cbEstado->addItem(uf);
    }
    this-> close();

    if(!cidade.isEmpty()&& !uf.isEmpty()){

    QString conteudo = cidade+","+uf;


    //cout << conteudo.toStdString() <<endl;
    ControllerFile file;
    file.gravaArquivo(file.arfEstado, conteudo);

}

    this->exec();


}

void CadastradoCarro::setNewMarca(QString modelo, QString marca){


    if (!modelo.isEmpty()){

        this->ui->cbModelos->addItem(modelo);
    }

    if(!marca.isEmpty()){
        this->ui->cbMarcas->addItem(marca);

    }

    this->close();
    if(!marca.isEmpty()&& !modelo.isEmpty()){
        QString conteudo = modelo+","+marca;
        ControllerFile file;
        file.gravaArquivo(file.arfModelo, conteudo);
    }
    this->exec();
}
void CadastradoCarro::on_pushButton_clicked()
{
    if(this->ui->lnPlaca->text().isNull()){
        JanelaPrincipal control;
        control.setNewCarro(
                this->ui->cbCor->currentText(),
                this->ui->cbMarcas->currentText(),
                this->ui->cbModelos->currentText(),
                this->ui->cbEstado->currentText(),
                this->ui->cbCidade->currentText(),
                this->ui->lnPlaca->text());


        return;

    }

    QMessageBox::warning(NULL,"Error","Erro ao tentar cadastrar carro");
}
