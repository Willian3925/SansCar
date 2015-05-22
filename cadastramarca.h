#ifndef CADASTRAMARCA_H
#define CADASTRAMARCA_H

#include <QDialog>

namespace Ui {
class CadastraMarca;
}

class CadastraMarca : public QDialog
{
    Q_OBJECT

public:
    explicit CadastraMarca(QWidget *parent = 0);
    ~CadastraMarca();

private slots:
    void on_btncadMarca_clicked();

private:
    Ui::CadastraMarca *ui;
};

#endif // CADASTRAMARCA_H
