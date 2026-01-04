#include "Serializer.hpp"

int main()
{
    Data first = {'a'};

    uintptr_t saved = Serializer::serialize(&first);
    Data* second = Serializer::deserialize(saved);


    if (first.nothing == second->nothing)
        std::cout << "it works" << std::endl;
    else
        std::cout << "something wrong" << std::endl;
    
    if (&first == second)
        std::cout << "it works" << std::endl;
    else
        std::cout << "something wrong" << std::endl;

    return (0);
}