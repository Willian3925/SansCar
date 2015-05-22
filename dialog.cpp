#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "janelaprincipal.h"
#include "controllerfile.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lblLogin->setStyleSheet("");
}

Dialog::~Dialog()
{
    delete ui;
}
/*Verifica Login e senha*/
void Dialog::on_btnAcessar_clicked()
{
    ControllerFile controler;
    QStringList usuarios = controler.getlogins();
    foreach (QString usuario, usuarios){

        QStringList user = usuario.split(",");

    if(ui->lblLogin->text().toStdString() == user[0].toStdString() && user[1].compare(ui->lblSenha->text())==1){
        this->close();
        JanelaPrincipal objJanelaPrincipal;
        objJanelaPrincipal.setModal(true);
        objJanelaPrincipal.exec();
        return;
    }

}
    QMessageBox::critical(NULL,"Error !", "Login ou senha inválidos !");
}
