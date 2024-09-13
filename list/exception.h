#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

#include <string>

class RuntimeException {
private:
    std::string errorMsg;
public:
    RuntimeException(const std::string& err) {errorMsg = err;}
    std::string getMessage() const {return errorMsg; }
};

class IndexOutofBounds : public RuntimeException {
public:
    IndexOutofBounds(const std::string& err): RuntimeException(err) {}
};

class StackEmpty : public RuntimeException {
public:
    StackEmpty(const std::string& err): RuntimeException(err) {}
};

class StackFull : public RuntimeException { 
public:
    StackFull(const std::string& err) : RuntimeException(err) {}
};

#endif