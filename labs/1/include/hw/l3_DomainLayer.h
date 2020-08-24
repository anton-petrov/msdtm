/* 
Программа-заготовка для домашнего задания
*/

#ifndef HW_L3_DOMAIN_LAYER_H
#define HW_L3_DOMAIN_LAYER_H

#include "hw/l4_InfrastructureLayer.h"

const size_t MAX_NAME_LENGTH    = 50;
const size_t MIN_YEAR_OF_BIRTH  = 1900;
const size_t MAX_YEAR_OF_BIRTH  = 2019;

class Person : public ICollectable
{
    std::string _first_name;
    std::string _last_name;
    uint16_t    _year_of_birth;

protected:
    bool invariant() const;

public:
    Person() = delete;
    Person(const Person & p) = delete;

    Person & operator = (const Person & p) = delete;

    Person(const std::string & first_name, const std::string & last_name, uint16_t year_of_birth);

    const std::string & getFirstName() const;
    const std::string & getLastName() const;
    uint16_t       getYearOfBirth() const;

    virtual bool   write(std::ostream& os) override;
};


class ItemCollector: public ACollector
{
public:
    virtual std::shared_ptr<ICollectable> read(std::istream& is) override;
};

#endif // HW_L3_DOMAIN_LAYER_H
