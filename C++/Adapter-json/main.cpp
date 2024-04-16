#include "InsertOnDB.hpp"
#include "AdapterJson2Xml.hpp"

int main(void)
{
    InsertOnDB insert;
    XML data;
    data.setXml("isso é um dado do tipo xml");

    JSON datajson;
    datajson.setJson("isso é um dado do tipo json");
    AdapterJson2Xml dataadp;
    dataadp.setXml(datajson);

    insert.insertData(data);
    insert.insertData(dataadp);
}