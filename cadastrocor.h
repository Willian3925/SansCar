#ifndef CADASTROCOR_H
#define CADASTROCOR_H

#include <QDialog>

namespace Ui {
class CadastroCor;
}

class CadastroCor : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroCor(QWidget *parent = 0);
    ~CadastroCor();

private:
    Ui::CadastroCor *ui;
};

#endif // CADASTROCOR_H
