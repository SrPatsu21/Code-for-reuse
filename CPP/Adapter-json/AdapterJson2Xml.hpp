#ifndef ADAPTERJSON2XML_HPP
#define ADAPTERJSON2XML_HPP

#include "XML.hpp"
#include "JSON.hpp"

class AdapterJson2Xml : public XML
{
private:
public:
    AdapterJson2Xml();
    ~AdapterJson2Xml();
    void setXml(JSON json);
};

#endif