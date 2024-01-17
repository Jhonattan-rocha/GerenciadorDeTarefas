#ifdef _WIN32

#ifndef ENV_VARS_H
#define ENV_VARS_H

#include <iostream>
#include <unordered_map>
class env_vars
{
public:
    env_vars();
    void setVariable(const std::string& key, const std::string& value);
    std::string getVariable(const std::string& key);
    void removeVariable(const std::string& key);
private:
    std::unordered_map<std::string, std::string> variables;
};

#endif // ENV_VARS_H


#endif
