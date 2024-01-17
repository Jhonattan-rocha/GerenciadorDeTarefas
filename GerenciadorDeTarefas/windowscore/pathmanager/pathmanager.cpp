#ifdef _WIN32

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <filesystem>
#include <FileTree/FileTree.h>
#include "pathmanager.h"

namespace fs = std::filesystem;

PathManager::PathManager() {
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
}

std::string PathManager::getUserName(){
    const DWORD buffer_size = 256;
    char username[buffer_size];
    DWORD size = buffer_size;

    if (GetUserNameA(username, &size)) {
        //tirar isso para a versão final, pequeno ajuste para arrumar um problema do meu pc em questão
        std::string usr = username;
        size_t pos = usr.find("o");
        usr.replace(pos, 1, "i");
        return usr;
    } else {
        return "";
    }
}

std::string PathManager::getMainPath(){
    return "C:\\Users\\" + this->getUserName();
}

std::vector<FileInfo> PathManager::listDir(const std::wstring& path) {
    std::vector<FileInfo> files_directories;

    for (const auto& entry : fs::directory_iterator(path)) {
        FileInfo info;
        info.path = entry.path().string();
        info.name = entry.path().filename().string();
        if (fs::is_directory(entry.path())) {
            info.type = "D";
        } else {
            info.type = "F";
            info.size = fs::file_size(entry.path());
        }
        info.lastModified = fs::last_write_time(entry.path());
        files_directories.push_back(info);
    }

    return files_directories;
}

void PathManager::loadFileTree(std::wstring root){
    try{
        FileTree& fileTreeInstance = FileTree::getInstance();

        for (const auto& entry : fs::directory_iterator(root)){
            if(fs::is_directory(entry.path())){
                fileTreeInstance.insert(entry.path().string(), true);
                this->loadFileTree(entry.path());
            }else{
                fileTreeInstance.insert(entry.path().string(), false);
            }
        }
    }catch(std::exception& e){
        std::cout << "\n" << e.what();
    }
}

void PathManager::createDirectory(const std::string& full_path, const bool force){
    if(!force && fs::exists(full_path)){
        throw std::ios_base::failure("Diretório já existe");
    }
    fs::create_directories(full_path);
}

void PathManager::delDirectory(const std::string& full_path){
    fs::path path = full_path;

    if(!fs::exists(path)){
        throw std::runtime_error("Diretório não existe");
    }

    for(const auto& entry : fs::directory_iterator(path)){
        if(entry.is_directory()){
            delDirectory(entry.path().string());
        }else{
            fs::remove(entry.path());
        }
    }

    try {
        fs::remove(path);
    } catch (const std::exception& e) {
        // Handle exception or log the error if necessary
        std::cerr << "Erro ao remover diretório " << path.string() << ": " << e.what() << std::endl;
    }
}

#endif
