#include "mainwindow.h"
#include <stdlib.h>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "GerenciadorDeTarefas_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    MainWinOS mainwin;
    mainwin.loadCommands();
    mainwin.setW(&w);
    w.setMainWin(mainwin);
    w.show();
    w.initialize();
    return a.exec();
}
