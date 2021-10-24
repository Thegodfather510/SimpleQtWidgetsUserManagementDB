#include "interface.h"
#include "ui_interface.h"
#include <QDesktopServices>
#include <QUrl>

Interface::Interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Bouihirchane Mouad/Documents/db/mydb.sqlite");

    if(db.open())
        ui->label->setText("Connected");
    else
        ui->label->setText("Not Connected");
}

Interface::~Interface()
{
    delete ui;

}

void Interface::on_btnReg_clicked()
{
    if(!db.open())
        QMessageBox::information(this,"Information","Database not connected");

    QString username = ui->txtUername->text();
    QString password = ui->txtPassword->text();
    QString email = ui->txtEmail->text();
    QString phone = ui->txtPhone->text();

    QSqlQuery query;

    query.prepare("INSERT INTO users2 VALUES('"+username+"','"+password+"','"+email+"','"+phone+"')");
    if(query.exec()){
        QMessageBox::information(this,"Informatio","Data has been added");
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    else
        QMessageBox::critical(this,"Error","Data hasn't been added");

}


void Interface::on_btnReg_2_clicked()
{
    if(!db.open())
        QMessageBox::information(this,"Informatio","Database is not connected");

    QString username = ui->txtUername->text();
    QString password = ui->txtPassword->text();
    QString email = ui->txtEmail->text();
    QString phone = ui->txtPhone->text();

    QSqlQuery query;
    query.prepare("UPDATE users2 SET userpassword = '"+password+"', useremail = '"+email+"',userphone = '"+phone+"' WHERE username = '"+username+"' ");

    if(query.exec()){
        QMessageBox::information(this,"Information","User has been Updated");
        db.close();
    }
    else
        QMessageBox::information(this,"Information","User has not been Updated");
}


void Interface::on_btnDelete_clicked()
{
    if(!db.open())
        QMessageBox::information(this,"Information","The database is not connected");

    QString username = ui->txtUername->text();
    QString password = ui->txtPassword->text();

    QSqlQuery query;
    query.prepare("DELETE FROM users2 WHERE username = '"+username+"' AND userpassword = '"+password+"'");

    if(query.exec()){
        QMessageBox::information(this,"Information","User has been deleted");
        db.close();
    }
    else
        QMessageBox::critical(this,"Error","User has not been deleted");
}


void Interface::on_btnLoad_clicked()
{
    if(!db.open())
        QMessageBox::information(this,"Information","Database is not connected");

    //Loading the data to table
    QSqlQueryModel *qury = new QSqlQueryModel();
    qury->setQuery("Select * from users2");
    ui->tableView->setModel(qury);

    //Loading to comboBox
    QSqlQueryModel *comboQuery = new QSqlQueryModel();
    comboQuery->setQuery("Select username FROM users2");
    ui->comboName->setModel(comboQuery);

    /*loading to ListView
    QSqlQueryModel *modalQuery = new QSqlQueryModel();
    QSqlQuery* qr = new QSqlQuery(db);
    qr->prepare("select useremail FROM users2");
    qr->exec();
    modalQuery->setQuery(*qr);
    ui->listView->setModel(modalQuery);*/


    db.close();

}


void Interface::on_comboName_currentIndexChanged(int index)
{
    if(!db.open())
        QMessageBox::information(this,"Information","Database is not connected");

    //Displaying the current comboBox index values on the QLineEdits
    QSqlQuery query;
    QString username = ui->comboName->currentText();
    query.prepare("select * from users2 where username='"+username+"' ");

    if(query.exec()){
        while(query.next()){
            ui->txtUername->setText(query.value(0).toString());
            ui->txtPassword->setText(query.value(1).toString());
            ui->txtEmail->setText(query.value(2).toString());
            ui->txtPhone->setText(query.value(3).toString());
        }
    }
    db.close();
}


void Interface::on_tableView_activated(const QModelIndex &index)
{
    if(!db.open())
            QMessageBox::critical(this,"Information","Database not connected");

    QString value = ui->tableView->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM users2 WHERE username = '"+value+"' OR userpassword = '"+value+"' OR useremail = '"+value+"' OR userphone = '"+value+"'");

    if(query.exec()){
        while(query.next()){
            ui->txtUername->setText(query.value(0).toString());
            ui->txtPassword->setText(query.value(1).toString());
            ui->txtEmail->setText(query.value(2).toString());
            ui->txtPhone->setText(query.value(3).toString());
        }
    }
    db.close();
}


void Interface::on_btnLoad_2_clicked()
{
    QString link = "https://hidamek.com/";
    QDesktopServices::openUrl(link);
}

