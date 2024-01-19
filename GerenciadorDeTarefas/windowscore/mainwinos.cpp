#ifdef _WIN32

#include "StringTools/stringtools.h"
#include "../mainwindow.h"
#include "exception"

MainWinOS::MainWinOS() : Commands::Commands() {}


void MainWinOS::cd(const std::vector<std::string>& input) {
    std::string main_path = this->w->getCurrantPath().toStdString();
    try{
        StringTools st;
        main_path.pop_back();


        fs::path new_path = fs::canonical(main_path + input[1]);

        if(fs::exists(new_path)){
            this->w->setCurrantPath(new_path.string() + "\\>");
        }else{
            this->w->setConsoleOutPut("Caminho " + new_path.string() + " inválido ou não existe");
        }
    }catch(const std::exception& e){
        this->w->setConsoleOutPut("Caminho " + main_path + input[1] + " inválido ou não existe");
    }
}

void MainWinOS::setW(MainWindow* w2){
    this->w = w2;
}

void MainWinOS::pwd(const std::vector<std::string>& input) {

}

void MainWinOS::dir(const std::vector<std::string>& input) {
    StringTools st;
    std::wstring path = this->w->getCurrantPath().toStdWString();
    try{
        if (input.size() > 1){
            path = fs::canonical(input[1]);
        }

        path.pop_back();
        std::vector<FileInfo> dirs = pathManager.listDir(path);

        std::stringstream result;

        result << std::left << std::setw(4) << "Type"
               << std::left << std::setw(50) << "Name"
               << std::left << std::setw(80) << "Path"
               << std::right << std::setw(15) << "Size"
               << std::right << std::setw(25) << "LastModification" << std::endl;

        this->w->setConsoleOutPut("Caminho: " + std::string(path.begin(), path.end()));

        for (const auto& dir : dirs){
            auto timePoint = std::chrono::time_point_cast<std::chrono::system_clock::time_point::duration>(dir.lastModified - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
            auto lastModifiedTime = std::chrono::system_clock::to_time_t(timePoint);
            result << std::left << std::setw(4) << dir.type
                   << std::left << std::setw(50) << st.limit_str(49, dir.name)
                   << std::left << std::setw(80) << st.limit_str(79, dir.path)
                   << std::right << std::setw(15) << (dir.type == "file" ? std::to_string(dir.size) : "")
                   << std::put_time(std::localtime(&lastModifiedTime), "%c") << std::endl;
        }

        this->w->setConsoleOutPut(result.str());
        this->w->setConsoleOutPut("\x02");
    }catch(const std::exception& e){
        this->w->setConsoleOutPut("Caminho " + std::string(path.begin(), path.end()) + " inválido ou não existe");
    }
}

void MainWinOS::ls(const std::vector<std::string>& input) {
    this->dir(input);
}

void MainWinOS::mkdir(const std::vector<std::string>& input) {

}

void MainWinOS::copy(const std::vector<std::string>& input) {}

void MainWinOS::remove(const std::vector<std::string>& input) {}

void MainWinOS::rm(const std::vector<std::string>& input) {}

void MainWinOS::mv(const std::vector<std::string>& input) {}

void MainWinOS::mvdir(const std::vector<std::string>& input) {}

void MainWinOS::rmdir(const std::vector<std::string>& input) {}

void MainWinOS::type(const std::vector<std::string>& input) {}

void MainWinOS::cat(const std::vector<std::string>& input) {}

void MainWinOS::clear(const std::vector<std::string>& input) {
    this->w->setConsoleOutPut("");
}

void MainWinOS::cls(const std::vector<std::string>& input) {
    this->w->setConsoleOutPut("");
}

void MainWinOS::setEnv(const std::vector<std::string>& input) {
    std::string key = input[1];
    std::string value = input[3];
    en.setVariable(key, value);
}

void MainWinOS::rmEnv(const std::vector<std::string>& input) {
    en.removeVariable(input[1]);
}

void MainWinOS::getEnv(const std::vector<std::string>& input) {
    std::string value = en.getVariable(input[1]);
    this->w->setConsoleOutPut(input[1] + ": " + value);
}

bool MainWinOS::is_command(const std::string& input){
    std::vector<std::string> cos = {"cls", "clear", "setVarEnv", "rmVarEnv", "getVarEnv", "cd", "pwd", "dir", "ls", "mkdir", "copy", "remove", "rm", "mv", "mvdir", "rmdir", "type", "cat"};
    for (const auto& c : cos){
        if(input == c){
            return true;
        }
    }
    return false;
}

void MainWinOS::loadCommands(){
    this->commands["cd"] = &MainWinOS::cd;
    this->commands["dir"] = &MainWinOS::dir;
    this->commands["ls"] = &MainWinOS::ls;
    this->commands["cls"] = &MainWinOS::cls;
    this->commands["clear"] = &MainWinOS::clear;
    this->commands["setVarEnv"] = &MainWinOS::setEnv;
    this->commands["rmVarEnv"] = &MainWinOS::rmEnv;
    this->commands["getVarEnv"] = &MainWinOS::getEnv;
}

void MainWinOS::loadVaribles(){
    this->en.recoverVars();
}

void MainWinOS::exec(const std::string& input) {
    StringTools st;
    char delimiter = ' ';

    std::vector<std::string> parts = st.split(input, delimiter);

    for(int i = 0; i < parts.size(); i++){
        if(this->is_command(parts[i])){
            this->commands[parts[i]](*this, parts);
        }
    }
}
#endif
