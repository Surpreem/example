#include "processor.h"

#include <iostream>


Processor::Processor()
{
    initialize();
}

void Processor::process(CallId id)
{
    auto pos{handlers_.find(id)};
    if (handlers_.end() == pos)
        return;

    pos->second();
}

void Processor::initialize()
{
    handlers_.emplace(CallId::hello, std::bind(&Processor::hello, this));
    handlers_.emplace(CallId::hi, std::bind(&Processor::hi, this));
    handlers_.emplace(CallId::go, std::bind(&Processor::go, this));
}

void Processor::hello()
{
    std::cout << "Hello.\n";
}

void Processor::hi()
{
    std::cout << "Hi.\n";
}

void Processor::go()
{
    std::cout << "Go!\n";
}
