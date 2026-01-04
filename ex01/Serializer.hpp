#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
    char nothing;
};

class Serializer
{
    private:
    Serializer();
    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};