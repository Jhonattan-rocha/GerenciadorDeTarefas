#ifndef COMMANDS_H
#define COMMANDS_H

// Commands.h
#include <string>
#include <iostream>
#include <vector>

#pragma once

class Commands {
public:
    virtual ~Commands() = default;
    virtual void cd(const std::vector<std::string>& input) = 0;
    virtual void pwd(const std::vector<std::string>& input) = 0;
    virtual void dir(const std::vector<std::string>& input) = 0;
    virtual void ls(const std::vector<std::string>& input) = 0;
    virtual void mkdir(const std::vector<std::string>& input) = 0;
    virtual void copy(const std::vector<std::string>& input) = 0;
    virtual void remove(const std::vector<std::string>& input) = 0;
    virtual void rm(const std::vector<std::string>& input) = 0;
    virtual void mv(const std::vector<std::string>& input) = 0;
    virtual void mvdir(const std::vector<std::string>& input) = 0;
    virtual void rmdir(const std::vector<std::string>& input) = 0;
    virtual void type(const std::vector<std::string>& input) = 0;
    virtual void cat(const std::vector<std::string>& input) = 0;
    virtual void cls(const std::vector<std::string>& input) = 0;
    virtual void clear(const std::vector<std::string>& input) = 0;
    virtual void setEnv(const std::vector<std::string>& input) = 0;
    virtual void rmEnv(const std::vector<std::string>& input) = 0;
    virtual void getEnv(const std::vector<std::string>& input) = 0;
    virtual void exec(const std::string& input) = 0;
};


#endif // COMMANDS_H
