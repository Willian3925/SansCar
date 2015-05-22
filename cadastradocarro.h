#ifndef CADASTRADOCARRO_H
#define CADASTRADOCARRO_H

#include <QDialog>

namespace Ui {
class CadastradoCarro;
}

class CadastradoCarro : public QDialog
{
    Q_OBJECT

public:
    explicit CadastradoCarro(QWidget *parent = 0);
    ~CadastradoCarro();
    bool setNewCidade(QString cidade, QString uf);
    void setNewMarca(QString modelo, QString marca);



private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

//_____________________________________
//    Carregando dados abaixo
//_____________________________________

    void loadCidades();

    void loadEstado();

    void loadCor();

    void loadMarca();

    void loadModelo();

    void on_pushButton_clicked();

private:
    Ui::CadastradoCarro *ui;
};

#endif // CADASTRADOCARRO_H
