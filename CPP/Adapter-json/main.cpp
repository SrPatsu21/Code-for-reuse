#include "InsertOnDB.hpp"
#include "AdapterJson2Xml.hpp"
#include "DataXml.hpp"
#include "DataJson.hpp"

int main(void)
{
    //data base
    InsertOnDB insert;

    //using xml
    //XML transform xml structure in data
    XML data;
    DataXml dataxml;
    data.setXml(dataxml.get());
    insert.insertData(data);

    //using json
    JSON data2;
    DataJson datajson;
    data2.setJson(datajson.get());
    
    AdapterJson2Xml dataadp;
    dataadp.setXml(data2);
    insert.insertData(dataadp);
}