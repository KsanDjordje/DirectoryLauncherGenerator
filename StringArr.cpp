#include "StringArr.h"

StringArray::StringArray() : size(0), capacity(0), strings(nullptr) {}
StringArray::StringArray(const StringArray &other) : size(other.size), capacity(other.capacity), strings(new std::string[other.capacity])
{
    for (size_t i = 0; i < other.size; i++)
    {
        strings[i] = other.strings[i];
    }
}
StringArray::StringArray(StringArray &&other) : size(other.size), capacity(other.capacity), strings(other.strings)
{
    other.size = 0;
    other.capacity = 0;
    other.strings = nullptr;
}
StringArray::~StringArray()
{
    delete[] strings;
}
StringArray &StringArray::operator=(const StringArray &other)
{
    if (this != &other)
    {
        delete[] strings;
        capacity = other.capacity;
        size = other.size;
        strings = new std::string[other.capacity];
        for (size_t i = 0; i < size; i++)
        {
            strings[i] = other.strings[i];
        }
    }
    return *this;
}
StringArray &StringArray::operator=(StringArray &&other)
{
    if (this != &other)
    {
        delete[] strings;

        size = other.size;
        capacity = other.capacity;
        strings = other.strings;

        other.size = 0;
        other.capacity = 0;
        other.strings = nullptr;
    }
    return *this;
}
size_t StringArray::getSize() const
{
    return this->size;
}
void StringArray::addString(const std::string &other)
{
    if (size == capacity)
    {
        realloc();
    }
    strings[size++] = other;
}

std::string StringArray::getString(size_t index) const
{
    if (index >= 0 && index < size)
        return strings[index];
    else
        return "";
}

void StringArray::realloc()
{
    size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
    std::string *newStrings = new std::string[newCapacity];
    for (size_t i = 0; i < size; i++)
    {
        newStrings[i] = strings[i];
    }
    delete[] strings;
    strings = newStrings;
    capacity = newCapacity;
}
