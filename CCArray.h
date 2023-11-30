#pragma once
#include <cstring>
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