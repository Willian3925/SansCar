#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include "cadastradocarro.h"
#include <QTime>
#include "controllerfile.h"
#include "pagamento.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_btnCadastrar_clicked()
{
    CadastradoCarro objTelaCadastroCarro;
    objTelaCadastroCarro.setModal(true);
    objTelaCadastroCarro.exec();
}
//recebe: 5.0,"13-05-2013 19:00"
float JanelaPrincipal::verificaValor(float precoHora, QString dateTime){

    float valor = 0.0;

    QStringList data = dateTime.split(" ");

    // Pegando hora atual
    int horaRetirada = QTime::currentTime().hour();
    int minutoRetirada = QTime::currentTime().minute();

    //Pegando a hora que foi estacionada
    QStringList tempo = data[1].split(":");
    int minutoEstacionado = tempo[1].toInt();
    int horaEstacionado = tempo[0].toInt();

    int qtHoras = horaRetirada - horaEstacionado;
    int qtMinutos = minutoRetirada - minutoEstacionado;

    if(qtHoras > 0){
        valor+= qtHoras*precoHora;
    }
    if(qtMinutos > 0){
        valor += (precoHora/60)*qtMinutos;
    }

    return valor;
}

void JanelaPrincipal::loadCarrosNoPatio(){

    ControllerFile carro;
    QStringList carros = carro.getPatio();

    foreach (QString itemCarro, carros){

        QTreeWidgetItem *item = new QTreeWidgetItem(ui->twListagem);
        QStringList carroFatiado = itemCarro.split(",");

        item->setText(0,carroFatiado[0]);
        item->setText(1,carroFatiado[1]);
        item->setText(2,carroFatiado[2]);
        item->setText(3,carroFatiado[3]);
        item->setText(4,carroFatiado[4]);

        ui->twListagem->addTopLevelItem(item);

    }

}


void JanelaPrincipal::on_btncadsaida_clicked()
{
    Pagamento telaPagamento;
    telaPagamento.setModal(true);
    telaPagamento.exec();

    QTreeWidgetItem *item = ui->twListagem->currentItem();
/*
    if(this->pagamento(item)){
        delete item;
    }
*/
}

/*
bool JanelaPrincipal::pagamento(QTreeWidgetItem item){

    ControllerFile pagamento;
    if(pagamento.updateArquivo(pagamento.arfPatio,item[0],item)){
        return true;
    return false;
}

}
*/

void JanelaPrincipal::setNewCarro(QString cor, QString marca, QString modelo, QString estado, QString cidade, QString placa){

    if (!placa.isNull() && !estado.isNull() && !cidade.isNull() && !cor.isNull() && !modelo.isNull() && !marca.isNull()){

        ControllerFile control;

        QString conteudo = placa.trimmed()+",";
        conteudo += modelo.trimmed()+",";
        conteudo += marca.trimmed()+",";
        conteudo += cor.trimmed()+ ",";
        conteudo += cidade.trimmed()+ ",";
        conteudo += estado.trimmed();

        cout << conteudo.toStdString()<<endl;

//        control.gravaArquivo(control.arfCarros,conteudo);
        return;
    }

    QMessageBox::warning(NULL,"Error","Erro ao tentar cadastrar Dados");


}


void JanelaPrincipal::on_btnProcurar_clicked()
{

    if (!this->ui->lnPlaca->text().isNull()){

        ControllerFile controle;

        if(controle.findPlacaPatio(controle.arfPatio,this->ui->lnPlaca->text())){

            cout <<"1"<< "Atualiza o horario de saída e exibi na tela com o valor" << endl;

        }else if(controle.findPlacaCarros(controle.arfCarros, this->ui->lnPlaca->text())){

            cout <<"inseri o carro no arquivo patio" <<endl;

            return;
        }
         else{

            CadastradoCarro telaCadastrarCarro;
            telaCadastrarCarro.setModal(true);
            telaCadastrarCarro.exec();
            cout << "Placa não consta no sistema\n abre a tela Cadastro" <<endl;
            return;
         }
    }

    QMessageBox::critical(NULL,"Erro","Operação inválida,\n verifique os campos");

}








