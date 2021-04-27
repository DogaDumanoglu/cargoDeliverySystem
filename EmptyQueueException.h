#ifndef UNTITLED7_EMPTYQUEUEEXCEPTION_H
#define UNTITLED7_EMPTYQUEUEEXCEPTION_H
#include <exception>
using namespace std;
    class EmptyQueueException : public exception{
        //error message displays if queue is empty
public:
    const char * what () const noexcept override
    {
        return "EmptyQueueException";
    }
};

#endif //UNTITLED7_EMPTYQUEUEEXCEPTION_H
