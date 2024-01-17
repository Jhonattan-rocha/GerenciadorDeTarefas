#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwinos.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    QString getCurrantPath();
    void setCurrantPath(std::string path);
    void initialize();
    void setMainWin(MainWinOS mainwin);
    void setConsoleOutPut(std::string output);
    std::string getConsoleOutPut();
public:
private:
    MainWinOS mainwin;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
