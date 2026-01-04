#pragma once

#include <cstdlib>
#include <time.h>
#include <iostream>

class Base
{
    public:
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);