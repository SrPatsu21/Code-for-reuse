#ifndef JSON_HPP
#define JSON_HPP

#include "iostream"

class JSON
{
private:
    std::string json;
public:
    JSON();
    ~JSON();
    void setJson(std::string json);
    std::string getJson();
};
#endif