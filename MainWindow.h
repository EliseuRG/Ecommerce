#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include "Cliente.h"
#include "Clientes.h"
#include "Pedido.h"
#include "Pedidos.h"
#include "Produto.h"
#include "Produtos.h"
#include "LoginMaster.h"
#include "AreaCliente.h"
#include "Sobre.h"
#include "CadastroCliente.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:

        void on_actionMaster_triggered();
        void on_actionSair_triggered();
        void on_actionSobre_triggered();
        void on_pushButtonEntrarCliente_clicked();
        void on_pushButtonCadastrarCliente_clicked();

private:
    Ui::MainWindow *ui;   
};
#endif // MAINWINDOW_H
