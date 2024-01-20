#ifdef _WIN32

#ifndef PATHMANAGER_H
#define PATHMANAGER_H


#include <windows.h>
#include <string>
#include <vector>
#include <filesystem>
#include <exception>

struct FileInfo {
    std::string type;
    std::string name;
    std::string path;
    std::uintmax_t size;
    std::filesystem::file_time_type lastModified;
};

class PathManager
{
public:
    PathManager();
public:
    std::string getMainPath();
    std::vector<FileInfo> listDir(const std::wstring& path);
    void loadFileTree(std::wstring root);
    std::string getUserName();
    void createDirectory(const std::string& full_path, const bool force);
    void delDirectory(const std::string& full_path);
};

#endif // PATHMANAGER_H


#endif
