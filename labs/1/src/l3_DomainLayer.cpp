/* Программа-заготовка для домашнего задания
*/

#include "hw/l3_DomainLayer.h"

using namespace std;


bool Person::invariant() const
{
    return _year_of_birth >= MIN_YEAR_OF_BIRTH
        && _year_of_birth <= MAX_YEAR_OF_BIRTH
        && !_first_name.empty() && _first_name.size() <= MAX_NAME_LENGTH
        && !_last_name.empty() && _last_name.size() <= MAX_NAME_LENGTH;
}

Person::Person(const std::string & first_name, const std::string & last_name, uint16_t year_of_birth)
    : _first_name(first_name), _last_name(last_name), _year_of_birth(year_of_birth)
{
    assert(invariant());
}

const string & Person::getFirstName() const
{
    return _first_name;
}

const string & Person::getLastName() const
{
    return _last_name;
}

uint16_t Person::getYearOfBirth() const
{
    return _year_of_birth;
}

bool   Person::write(ostream& os)
{
    writeString(os, _first_name);
    writeString(os, _last_name);
    writeNumber(os, _year_of_birth);

    return os.good();
}



shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   first_name = readString(is, MAX_NAME_LENGTH);
    string   last_name  = readString(is, MAX_NAME_LENGTH);
    uint16_t year       = readNumber<uint16_t>(is);

    return std::make_shared<Person>(first_name, last_name, year);
}
