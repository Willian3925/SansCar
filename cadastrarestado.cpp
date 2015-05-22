#include "cadastrarestado.h"
#include "ui_cadastrarestado.h"
#include "controllerfile.h"
#include "cadastrarcidade.h"

CadastrarEstado::CadastrarEstado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarEstado)
{
    ui->setupUi(this);
    ControllerFile controlaArquivo;
    this->obEstado = controlaArquivo.getEstados();
}

CadastrarEstado::~CadastrarEstado()
{
    delete ui;
}
bool CadastrarEstado::cadastraUf(QString estado){

    foreach (QString comp, this->obEstado) {
        if(comp == estado)
            return 0;
    }
    return 1;

}

void CadastrarEstado::on_btncadUF_clicked()
{

   CadastrarCidade control;
   control.setNewEstado(this->ui->lnEstado->text());


}
