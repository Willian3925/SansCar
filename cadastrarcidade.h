#ifndef CADASTRARCIDADE_H
#define CADASTRARCIDADE_H

#include <QDialog>

namespace Ui {
class CadastrarCidade;
}

class CadastrarCidade : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarCidade(QWidget *parent = 0);
    ~CadastrarCidade();
    void loadEstado();
    bool setNewEstado(QString newEstado);



private slots:
    void on_cmlcadUF_clicked();

    void on_btncadcidade_clicked();

private:
    Ui::CadastrarCidade *ui;
};

#endif // CADASTRARCIDADE_H
