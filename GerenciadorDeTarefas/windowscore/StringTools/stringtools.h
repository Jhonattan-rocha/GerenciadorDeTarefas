#ifndef STIRNGTOOLS_H
#define STIRNGTOOLS_H
#include <vector>
#include <iostream>

class StringTools
{
public:
    StringTools();
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::string join(std::vector<std::string> parts, char delimiter);
    std::string lstrip(const std::string& s);
    std::string rstrip(const std::string& s);
    std::string strip(const std::string& s);
    std::string limit_str(int limit, std::string value);
};

#endif // STIRNGTOOLS_H
