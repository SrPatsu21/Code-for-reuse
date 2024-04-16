#include "AdapterJson2Xml.hpp"

AdapterJson2Xml::AdapterJson2Xml()
:XML()
{
};

AdapterJson2Xml::~AdapterJson2Xml()
{
};

void AdapterJson2Xml::setXml(JSON json)
{
    XML::setXml(json.getJson()+" e agora é xml");
};