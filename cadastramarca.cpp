#include "cadastramarca.h"
#include "ui_cadastramarca.h"
#include "cadastromodelo.h"

CadastraMarca::CadastraMarca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastraMarca)
{
    ui->setupUi(this);
}

CadastraMarca::~CadastraMarca()
{
    delete ui;
}

void CadastraMarca::on_btncadMarca_clicked()
{

    CadastroModelo control;
    control.setNewMarca(this->ui->txtcadMarca->text());


}
