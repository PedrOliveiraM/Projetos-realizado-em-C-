#include "dialogcombobox.h"
#include "ui_dialogcombobox.h"
#include "QRegularExpression"

DialogComboBox::DialogComboBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogComboBox)
{
    ui->setupUi(this);
}

DialogComboBox::~DialogComboBox()
{
    delete ui;
}


void DialogComboBox::on_pushButtonOK_clicked()
{
    QString selectedValue = ui->lineEdit->text();
    emit valueSelected(selectedValue); // Emitir o sinal personalizado com o valor selecionado
    close(); // Fechar a janela DialogComboBox
}

