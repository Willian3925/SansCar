#include "cadastrarcidade.h"
#include "ui_cadastrarcidade.h"
#include "ui_cadastrarestado.h"
#include "controllerfile.h"
#include "cadastrarestado.h"
#include "cadastradocarro.h"

CadastrarCidade::CadastrarCidade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarCidade)
{
    ui->setupUi(this);
}

CadastrarCidade::~CadastrarCidade()
{
    delete ui;


}

void CadastrarCidade::loadEstado(){

    ControllerFile estado;

    QStringList estados = estado.getEstados();
    foreach (QString uf, estados){
       this->ui->cbcadestato->addItem(uf);
    }

}

void CadastrarCidade::on_cmlcadUF_clicked()
{

    CadastrarEstado control;
    control.setModal(true);
    control.exec();

}
bool CadastrarCidade::setNewEstado(QString newEstado){

    this->ui->cbcadestato->addItem(newEstado);
    this->close();
    this->exec();


}

void CadastrarCidade::on_btncadcidade_clicked()
{
    CadastradoCarro control;
    control.setNewCidade(this->ui->txtcidade->text(),this->ui->cbcadestato->currentText());



}

