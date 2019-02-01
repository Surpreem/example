#include "processor.h"


int main()
{
    Processor processor;
    processor.process(CallId::hi);
    processor.process(CallId::hello);
    processor.process(CallId::go);

    return 0;
}
