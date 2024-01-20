#ifdef _WIN32
#ifndef MAINWINOS_H
#define MAINWINOS_H

#include <pathmanager/pathmanager.h>
#include "Commands.h"
#include "EnvVaribles/env_vars.h"

namespace fs = std::filesystem;

class MainWindow;

class MainWinOS : public Commands
{
public:
    MainWinOS();
    PathManager pathManager;

    void cd(const std::vector<std::string>& input) override;
    void pwd(const std::vector<std::string>& input) override;
    void dir(const std::vector<std::string>& input) override;
    void grep(const std::vector<std::string>& input) override;
    void ls(const std::vector<std::string>& input) override;
    void mkdir(const std::vector<std::string>& input) override;
    void copy(const std::vector<std::string>& input) override;
    void remove(const std::vector<std::string>& input) override;
    void rm(const std::vector<std::string>& input) override;
    void mv(const std::vector<std::string>& input) override;
    void mvdir(const std::vector<std::string>& input) override;
    void rmdir(const std::vector<std::string>& input) override;
    void type(const std::vector<std::string>& input) override;
    void cat(const std::vector<std::string>& input) override;
    void clear(const std::vector<std::string>& input) override;
    void cls(const std::vector<std::string>& input) override;
    void setEnv(const std::vector<std::string>& input) override;
    void rmEnv(const std::vector<std::string>& input) override;
    void getEnv(const std::vector<std::string>& input) override;
    void exec(const std::string& input) override;
    bool is_command(const std::string& input);
    void setW(MainWindow* w);
    void loadCommands();
    void loadVaribles();
    void saveVaribles();


private:
    MainWindow* w;
    env_vars en;
    template <typename ReturnType>
    using CommandFunction = std::function<ReturnType(MainWinOS&, const std::vector<std::string>&)>;
    std::unordered_map<std::string, CommandFunction<void>> commands;
    std::unordered_map<std::string, std::string> dados;

};

#endif // MAINWINOS_H
#endif
