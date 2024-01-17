#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMainWin(MainWinOS mainwin){
    this->mainwin = mainwin;
}

QString MainWindow::getCurrantPath(){
    return this->ui->currant_path->text();
}

void MainWindow::setCurrantPath(std::string path){
    this->ui->currant_path->setText(QString::fromStdString(path));
}

void MainWindow::setConsoleOutPut(std::string output){
    if(output.length() > 0){
        this->ui->console_output->setPlainText(QString::fromStdString(this->getConsoleOutPut() + "\n" + output));
    }else{
        this->ui->console_output->setPlainText("");
    }

    this->ui->console_output->moveCursor(QTextCursor::End);
}

std::string MainWindow::getConsoleOutPut(){
    return this->ui->console_output->toPlainText().toStdString();
}

void MainWindow::initialize(){
    ui->currant_path->setText(QString::fromStdString(this->mainwin.pathManager.getMainPath()) + "\\>");
    connect(ui->console_input, &QLineEdit::returnPressed, this, [=]() {
        this->mainwin.exec(ui->console_input->text().toStdString());
        this->ui->console_input->setText("");
    });
}
