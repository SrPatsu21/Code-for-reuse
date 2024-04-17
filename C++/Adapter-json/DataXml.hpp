#ifndef DATAXML_HPP
#define DATAXML_HPP

#include "XML.hpp"

class DataXml : public XML
{
private:
public:
    DataXml();
    ~DataXml();

    std::string get();
};

#endif