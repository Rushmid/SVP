#include "glavnoeokno.h"
#include "ui_glavnoeokno.h"
#include <QMessageBox>
#include <QDebug>
#include"../qq/qq.h"
#include<QTableView>
GLAVNOEOKNO::GLAVNOEOKNO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GLAVNOEOKNO)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if (db.open())
        qDebug("БАЗА ДАННЫХ ОТКРЫТА");
    else
        qDebug("ОШИБКА!БАЗА ДАННЫХ НЕ ОТКРЫТА!");
    query = new QSqlQuery(db);
    query -> exec("CREATE TABLE testDB(ФИО_ПАЦИЕНТА TEXT, НОМЕР TEXT);");
    model = new QSqlTableModel(this,db);
    model -> setTable("testDB");
    model ->select();
    ui ->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
}
GLAVNOEOKNO::~GLAVNOEOKNO()
{
    delete ui;
}
void GLAVNOEOKNO::on_udPOLZ_clicked()
{
    ui->statusbar->showMessage("Удаление позиции...");
    QMessageBox::warning(this,"УДАЛЕНИЕ ПОЗИЦИИ.","Позиция успешно удалена!");
    model->removeRow(row); //УДАЛЕНИЕ СТРОКИ ПО ЕЕ НОМЕРУ
    ui->statusbar->showMessage(" ");
}
void GLAVNOEOKNO::on_doPol_clicked()
{
    ui->statusbar->showMessage("Пациент добавлен...");
    QMessageBox::information(this,"ДОБАВЛЕНИЕ ПАЦИЕНТА.","Строка для заполнения информации о пациенте была успешно добавлена!");
    model -> insertRow(model ->rowCount());
    ui->statusbar->showMessage(" ");
}
void GLAVNOEOKNO::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void GLAVNOEOKNO::on_vihod_clicked()
{
    ui->statusbar->showMessage("Выход из приложения...");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Выход из приложения.","Вы уверены, что хотите выйти из приложения?");
    if(reply == QMessageBox::Yes)
{   Qq o;
    o.clos();
}
    else
        qDebug("/q");
    ui->statusbar->showMessage(" ");
}

void GLAVNOEOKNO::on_obnn_clicked()
{
    Qq p;
    p.obn();
}
