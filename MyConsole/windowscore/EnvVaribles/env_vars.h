#ifdef _WIN32

#ifndef ENV_VARS_H
#define ENV_VARS_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>
#include <unordered_map>
class env_vars
{
public:
    env_vars();
    void setVariable(const std::string& key, const std::string& value);
    std::string getVariable(const std::string& key);
    void removeVariable(const std::string& key);
    void recoverVars();
    void recordVars();
private:
    std::unordered_map<std::string, std::string> variables;
};

#endif // ENV_VARS_H


#endif
