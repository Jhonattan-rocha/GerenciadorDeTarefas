#ifdef _WIN32

#include <string>
#include <vector>
#include "thread_header.h"
#include <QObject>
#include <QThread>
#include "../../mainwindow.h"
#include "StringTools/stringtools.h"

class MainWindow;

class Cd : public ThreadHeader {
    Q_OBJECT
signals:
    void setConsoleOutPut(std::string);
    void setCurrantPath(std::string);
    void finished();
public:
    MainWindow* w;
    std::vector<std::string> input;
    QThread thread;

    Cd(const std::vector<std::string>& input, MainWindow* w) : ThreadHeader::ThreadHeader(){
        this->input = input;
        this->w = w;
    }

    void run() override {
        std::string main_path = this->w->getCurrantPath().toStdString();
        try{
            StringTools st;
            main_path.pop_back();

            fs::path new_path = fs::canonical(main_path + input[1]);

            if(fs::exists(new_path)){
                emit setCurrantPath(new_path.string() + "\\>");
            }else{
                emit setConsoleOutPut("Caminho " + new_path.string() + " inválido ou não existe");
            }
        } catch(const std::exception& e){
            emit setConsoleOutPut("Caminho " + main_path + input[1] + " inválido ou não existe");
        }
        emit finished();
    }
    void init() override {

        // Conectar o sinal da thread ao slot da thread principal
        QObject::connect(this, &Cd::setConsoleOutPut, w, &MainWindow::setConsoleOutPut);
        QObject::connect(this, &Cd::setCurrantPath, w, &MainWindow::setCurrantPath);

        // Criar a thread e mover o objeto Worker para a thread
        thread.setObjectName("WorkerThread");  // Atribua um nome à thread para depuração
        this->moveToThread(&thread);

        // Conectar o início da execução da thread à execução da função na classe Worker
        QObject::connect(&thread, &QThread::started, this, &Cd::run);

        // Conectar o fim da execução da thread ao encerramento da aplicação
        QObject::connect(this, &Cd::finished, &thread, &QThread::quit);
        QObject::connect(&thread, &QThread::finished, &thread, &QThread::deleteLater);
        QObject::connect(&thread, &QThread::finished, this, &Cd::deleteLater);

        // Iniciar a thread
        thread.start();
    }
    void close() override {
        emit finished();
    }

    void await() override {
        try{
            if(thread.isRunning())
                thread.wait();
        }catch(const std::exception& e){
            std::cout << e.what();
        }
    }
};

#endif
