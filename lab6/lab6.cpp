#include "lab6.h"
#include "ui_lab6.h"
#include "QMessageBox"

lab6::lab6(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lab6)
{
    ui->setupUi(this);


}

lab6::~lab6()
{
    delete ui;
}


void lab6::on_pushButton_clicked()
{
    QMessageBox::critical(this, "It's Error Yeap", "You have error bro");
}

void lab6::on_pushButton_2_clicked()
{
    QMessageBox::warning(this, "It's Warning Yeap", "Be careful man");
}

void lab6::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "It's Information Yeap", "We have a BIG informatoin man");
}
