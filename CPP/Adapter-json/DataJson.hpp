#ifndef DATAJSON_HPP
#define DATAJSON_HPP

#include "JSON.hpp"

class DataJson : public JSON
{
private:
public:
    DataJson();
    ~DataJson();

    std::string get();
};

#endif