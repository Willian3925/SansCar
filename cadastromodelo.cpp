#include "cadastromodelo.h"
#include "ui_cadastromodelo.h"
#include "cadastramarca.h"
#include "controllerfile.h"
#include "cadastradocarro.h"


CadastroModelo::CadastroModelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroModelo)
{
    ui->setupUi(this);
    ui->cbMarca->currentText();
    this->loadMarca();
}

CadastroModelo::~CadastroModelo()
{
    delete ui;
}

void CadastroModelo::on_lkCadModelo_clicked()
{
    CadastraMarca objCadastroMarca;
    objCadastroMarca.setModal(true);
    objCadastroMarca.exec();
}

void CadastroModelo::loadMarca(){

    ControllerFile marca;

    QStringList marcas = marca.getMarcas();
    foreach (QString marca, marcas) {
        this->ui->cbMarca->addItem(marca);

    }

}

void CadastroModelo::setNewMarca(QString newMarca){

    this->ui->cbMarca->addItem(newMarca);
    this->close();
    this->exec();



}

void CadastroModelo::on_btnSalvar_clicked()
{
    CadastradoCarro control;
    control.setNewMarca(this->ui->lnMarca->text(), this->ui->cbMarca->currentText());


}
