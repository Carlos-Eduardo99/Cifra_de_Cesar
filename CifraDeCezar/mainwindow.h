#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "algoritmocifradecesar.h"

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
    void on_encryptButton_clicked();
    void on_decryptButton_clicked();

private:
    Ui::MainWindow *ui;
    AlgoritmoCifraDeCesar cifraDeCesar;
};

#endif // MAINWINDOW_H
