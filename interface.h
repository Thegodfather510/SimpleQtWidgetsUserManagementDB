#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>

namespace Ui {
class Interface;
}

class Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_btnReg_clicked();

    void on_btnReg_2_clicked();

    void on_btnDelete_clicked();

    void on_btnLoad_clicked();


    void on_comboName_currentIndexChanged(int index);

    void on_tableView_activated(const QModelIndex &index);

    void on_btnLoad_2_clicked();

private:
    Ui::Interface *ui;
    QSqlDatabase db;

};

#endif // INTERFACE_H
