#ifndef GESTAOPRODUTO_H
#define GESTAOPRODUTO_H

#include <QDialog>
#include <QMessageBox>
#include "Produto.h"
#include "Produtos.h"

namespace Ui {
class GestaoProduto;
}

class GestaoProduto : public QDialog
{
    Q_OBJECT

    public:
        explicit GestaoProduto(QWidget *parent = nullptr);
        ~GestaoProduto();

    private slots:
        void on_pushButtonGPNCadastrar_clicked();
        void on_pushButtonGPABuscar_clicked();
        void on_pushButtonGPAAlterar_clicked();
        void on_pushButtonGPGExcluir_clicked();
        void on_pushButtonGPGListar_clicked();

    private:
        Ui::GestaoProduto *ui;
        TP::Produto produto;
};
#endif // GESTAOPRODUTO_H
