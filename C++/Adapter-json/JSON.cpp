#include "JSON.hpp"

JSON::JSON()
{
}

JSON::~JSON()
{
}

void JSON::setJson(std::string json)
{
    this->json = json;
};
std::string JSON::getJson()
{
    return this->json;
};
