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
const std::string XML::getXml()
{
    return this->xml;
};