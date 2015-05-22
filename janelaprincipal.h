#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QDialog>

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();

    void loadCarrosNoPatio();

    void setNewCarro(QString cor,QString marca,QString modelo,QString estado,QString cidade,QString placa);



private slots:
    void on_btnCadastrar_clicked();

    void on_btncadsaida_clicked();

    void on_btnProcurar_clicked();

private:
    Ui::JanelaPrincipal *ui;
    float verificaValor(float precoHora, QString dateTime);

};

#endif // JANELAPRINCIPAL_H
