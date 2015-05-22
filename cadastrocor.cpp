#include "cadastrocor.h"
#include "ui_cadastrocor.h"

CadastroCor::CadastroCor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroCor)
{
    ui->setupUi(this);
}

CadastroCor::~CadastroCor()
{
    delete ui;
}
