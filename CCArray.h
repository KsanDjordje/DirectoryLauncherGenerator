#pragma once
#include <cstring>
// Current not implemented
// Meant for C-style type code
// main currenty uses string type code 
class CCArray
{
private:
    const char **strings;
    size_t size;
    size_t capacity;

public:
    CCArray();
    ~CCArray();
    void add(const char *str);
    size_t getSize() const;
    const char *getString(int index) const;

private:
    void realloc();
};