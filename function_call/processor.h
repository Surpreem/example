#pragma once


#include <functional>
#include <map>


enum class CallId {
    hello, hi, go
};


class Processor {
public:
    Processor();
    ~Processor() = default;

    void process(CallId id);

private:
    using Handler = std::function<void()>;

    void initialize();

    // handlers
    void hello();
    void hi();
    void go();

    std::map<CallId, Handler> handlers_;
};
