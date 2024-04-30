#ifndef INSERTONDB_HPP
#define INSERTONDB_HPP

#include "ConectDB.hpp"
#include "XML.hpp"

class InsertOnDB
{
private:
    ConectDB* conection;
public:
    InsertOnDB();
    ~InsertOnDB();

    void insertData(XML data);
};

#endif