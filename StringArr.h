#pragma once
#include <string>
class StringArray
{
private:
    size_t size;
    size_t capacity;
    std::string *strings;

public:
    StringArray();
    StringArray(const StringArray& other);
    StringArray(StringArray&& other);
    ~StringArray();
    StringArray& operator=(const StringArray& other);
    StringArray& operator=(StringArray&& other);
    size_t getSize() const;
    void addString(const std::string &other);
    std::string getString(size_t index) const;
private:
    void realloc();
};