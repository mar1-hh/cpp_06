#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {};

Base * generate(void)
{
    int rand_num = rand() % 3;

    if (rand_num == 0)
        return (new A());
    else if (rand_num == 1)
        return (new B());
    return (new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A*> (p))
        std::cout << "A class" << std::endl;
    else if (dynamic_cast<B*> (p))
        std::cout << "B class" << std::endl;
    else if (dynamic_cast<C*> (p))
        std::cout << "C class" << std::endl;
    else
        std::cout << "casting failed" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a_class = dynamic_cast<A&> (p);
        (void)a_class;
        std::cout << "A class" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
    try
    {
        B& b_class = dynamic_cast<B&> (p);
        (void)b_class;
        std::cout << "B class" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
    try
    {
        C& c_class = dynamic_cast<C&> (p);
        (void)c_class;
        std::cout << "C class" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}