#include "CCArray.h"

CCArray::CCArray() : strings(nullptr), size(0), capacity(0) {}
CCArray::~CCArray()
{
    for (int i = 0; i < size; i++)
    {
        delete[] strings[i];
    }
    delete[] strings;
}
void CCArray::add(const char *str)
{
    if (size == capacity)
        realloc();
    strings[size] = new char[strlen(str) + 1];
    strcpy(const_cast<char *>(strings[size]), str);
    size++;
}
size_t CCArray::getSize() const
{
    return this->size;
}
const char *CCArray::getString(int index) const
{
    return (index < size) ? strings[index] : nullptr;
}
void CCArray::realloc()
{
    size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
    const char **newStrings = new const char *[newCapacity];

    for (size_t i = 0; i < size; i++)
    {
        newStrings[i] = strings[i];
    }
    delete[] strings;
    strings = newStrings;
    capacity = newCapacity;
}
