#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoritmocifradecesar.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), cifraDeCesar(0) // Defina um valor padrão para a chave
{
    ui->setupUi(this);

    // Conectando os sinais dos botões aos slots
    connect(ui->encryptButton, SIGNAL(clicked()), this, SLOT(on_encryptButton_clicked()));
    connect(ui->decryptButton, SIGNAL(clicked()), this, SLOT(on_decryptButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_encryptButton_clicked() {
    QString mensagem = ui->plainTextEdit->toPlainText();
    int chave = ui->keySpinBox->value();

    AlgoritmoCifraDeCesar cifraDeCesar(chave);
    std::string mensagemCriptografada = cifraDeCesar.criptografar(mensagem.toStdString(), chave);

    QString mensagemCriptografadaQString = QString::fromStdString(mensagemCriptografada);
    ui->encryptedTextEdit->setPlainText(mensagemCriptografadaQString);
}

void MainWindow::on_decryptButton_clicked() {
    QString mensagemCriptografada = ui->encryptedTextEdit->toPlainText();
    int chave = ui->keySpinBox->value();

    AlgoritmoCifraDeCesar cifraDeCesar(chave);
    std::string mensagemDescriptografada = cifraDeCesar.descriptografar(mensagemCriptografada.toStdString(), chave);

    QString mensagemDescriptografadaQString = QString::fromStdString(mensagemDescriptografada);
    ui->decryptedTextEdit->setPlainText(mensagemDescriptografadaQString);
}




