#ifndef CADASTRARESTADO_H
#define CADASTRARESTADO_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class CadastrarEstado;
}

class CadastrarEstado : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarEstado(QWidget *parent = 0);
    ~CadastrarEstado();
    QStringList obEstado;

private slots:
    void on_btncadUF_clicked();

private:
    Ui::CadastrarEstado *ui;
    bool cadastraUf(QString estado);
};

#endif // CADASTRARESTADO_H
