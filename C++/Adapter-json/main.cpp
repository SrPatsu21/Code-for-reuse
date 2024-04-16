#include "InsertOnDB.hpp"

int main(void)
{
    InsertOnDB insert;
    XML data;
    data.setXml("isso é um dado do tipo xml");

    insert.insertData(data);
}