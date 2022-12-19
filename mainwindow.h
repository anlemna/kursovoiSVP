#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QDebug>
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase baza;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
