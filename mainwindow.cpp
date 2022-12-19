#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    baza = QSqlDatabase::addDatabase("QSQLITE");
    baza.setDatabaseName("./baza.db");
    if(baza.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }

    query = new QSqlQuery(baza);
    query->exec("CREATE TABLE Teeth(Number INT, Date DATE);");

    model = new QSqlTableModel(this, baza);
    model->setTable("Teeth");
    model->select();

    ui->tableView->setModel(model);

        QLabel *label = new QLabel(this);
        QPixmap pix;
        pix.load("://picture/osnova.png");
        ui->label->setPixmap(pix);
        ui->label->setScaledContents(true);

        //установка размеров label
        int pixWidh=pix.width();
        int labelWidth=ui->label->width();
        double factor = double(labelWidth)/pixWidh;
        qDebug()<<pixWidh;
        qDebug()<<labelWidth;
        qDebug()<<factor;
        ui->label->setFixedWidth(factor * ui->label->pixmap()->width());
        ui->label->setFixedHeight(factor * ui->label->pixmap()->height());

        //установка размера окна
        QWidget::setFixedSize(550,670);
}

MainWindow::~MainWindow()
{
    delete ui;
}
