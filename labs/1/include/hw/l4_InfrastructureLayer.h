/* 
Программа-заготовка для домашнего задания
*/

#ifndef HW_L4_INFRASTRUCTURE_LAYER_H
#define HW_L4_INFRASTRUCTURE_LAYER_H

#include <string>
#include <vector>
#include <cassert>
#include <memory>

#include <fstream>

template<typename T>
T readNumber(std::istream& is)
{   
	T result;
    is.read(reinterpret_cast<char *>(&result), sizeof(result));
    return result;
}

std::string readString(std::istream& is, size_t max_string_length);

template<typename T>
void writeNumber(std::ostream& os, T i)
{
    os.write(reinterpret_cast<char *>(&i),sizeof(i));
}

void writeString(std::ostream& os, const std::string& s);

class ICollectable
{
public:
    virtual ~ICollectable() = default;

    virtual bool write(std::ostream& os) = 0;
};

class ACollector
{
    std::vector<std::shared_ptr<ICollectable>> _items;
    std::vector<bool>                          _removed_signs;
    size_t                                     _removed_count = 0;

    bool    invariant() const
    {
        return _items.size() == _removed_signs.size() && _removed_count <= _items.size();
    }

public:
    virtual ~ACollector() = default;

    virtual std::shared_ptr<ICollectable> read(std::istream& is) = 0;

    size_t getSize() const { return _items.size(); }

    std::shared_ptr<ICollectable> getItem(size_t index) const;

    bool isRemoved(size_t index) const;

    void addItem(std::shared_ptr<ICollectable> item);

    void removeItem(size_t index);

    void updateItem(size_t index, const std::shared_ptr<ICollectable> & item);

    void clean();

    bool loadCollection(const std::string file_name);

    bool saveCollection(const std::string file_name) const;
};

#endif // HW_L4_INFRASTRUCTURE_LAYER_H
