#ifndef XML_HPP
#define XML_HPP

#include "iostream"

class XML
{
private:
    std::string xml;
public:
    XML();
    ~XML();

    void setXml(std::string xml);
    std::string getXml();
};

#endif