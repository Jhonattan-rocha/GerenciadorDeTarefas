#ifdef _WIN32

#include "stringtools.h"
#include <iomanip>
StringTools::StringTools() {}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    // std::istringstream iss(str);
    // std::string token;

    // while (std::getline(iss, token, delimiter)) {
    //     if (!token.empty()) {
    //         // Adiciona token à result, considerando aspas
    //         std::istringstream tokenStream(token);
    //         std::string quotedToken;
    //         if (std::getline(tokenStream >> std::quoted(quotedToken), quotedToken))
    //             result.push_back(quotedToken);
    //     }
    // }

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

std::vector<size_t> StringTools::find(const std::string& search, const std::string& str, const bool all){
    std::vector<size_t> result;

    size_t pos = str.find(search);
    result.push_back(pos);

    if(all){
        while (pos != std::string::npos) {
            pos = str.find(search, pos + 1);
            result.push_back(pos);
        }
    }

    return result;
}



#endif
