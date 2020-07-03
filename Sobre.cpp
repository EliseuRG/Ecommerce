#include "Sobre.h"
#include "ui_Sobre.h"

Sobre::Sobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sobre)
{
    ui->setupUi(this);
}

Sobre::~Sobre()
{
    delete ui;
}
