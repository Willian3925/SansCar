#ifndef CADASTROMODELO_H
#define CADASTROMODELO_H

#include <QDialog>

namespace Ui {
class CadastroModelo;
}

class CadastroModelo : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroModelo(QWidget *parent = 0);
    ~CadastroModelo();
    void loadMarca();
    void setNewMarca(QString newMarca);


private slots:
    void on_lkCadModelo_clicked();

    void on_btnSalvar_clicked();

private:
    Ui::CadastroModelo *ui;
};

#endif // CADASTROMODELO_H
