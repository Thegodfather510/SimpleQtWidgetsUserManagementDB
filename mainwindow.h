#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include "interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    /*void connClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool connOpen(){
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/Bouihirchane Mouad/Documents/db/mydb.sqlite");

        if(db.open()){
            qDebug() <<"Connected";
            return true;
        }
        else{
            qDebug() <<"Not Connected";
            return false;
        }
}*/

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
