#include "InsertOnDB.hpp"

InsertOnDB::InsertOnDB()
{
    conection = new ConectDB();
}

InsertOnDB::~InsertOnDB()
{
}

void InsertOnDB::insertData(XML data)
{
    this->conection->conect();
    std::cout << "inserindo no banco:" << data.getXml() << std::endl;
};