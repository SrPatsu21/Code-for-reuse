#include "XML.hpp"

XML::XML()
{

};
XML::~XML()
{

};

void XML::setXml(std::string xml)
{
    this->xml = xml;
};
std::string XML::getXml()
{
    return this->xml;
};