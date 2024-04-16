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
    void setJSON(std::string json);
    const std::string getJSON();
};

JSON::JSON(/* args */)
{
}

JSON::~JSON()
{
}


#endif