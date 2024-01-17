#include "stringtools.h"

StringTools::StringTools() {}

std::vector<std::string> StringTools::split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    result.push_back(str.substr(start, end - start));

    return result;
}


std::string StringTools::limit_str(int limit, std::string value){
    std::string result;
    result = value.substr(size_t(0), size_t(limit));
    return this->strip(result);
}

std::string StringTools::join(std::vector<std::string> parts, char delimiter) {
    std::string result;

    for (const auto& part : parts){
        result = result + part + delimiter;
    }

    return result;
}

std::string StringTools::lstrip(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string StringTools::rstrip(const std::string& s) {
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string StringTools::strip(const std::string& s) {
    return rstrip(lstrip(s));
}

