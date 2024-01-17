#ifdef _WIN32

#include "env_vars.h"

env_vars::env_vars() {}

void env_vars::setVariable(const std::string& key, const std::string& value) {
    variables[key] = value;
}

std::string env_vars::getVariable(const std::string& key) {
    auto it = variables.find(key);
    return (it != variables.end()) ? it->second : "";
}

void env_vars::removeVariable(const std::string& key) {
    variables.erase(key);
}

#endif
