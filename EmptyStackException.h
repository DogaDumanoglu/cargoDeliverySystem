#ifndef UNTITLED7_EMPTYSTACKEXCEPTION_H
#define UNTITLED7_EMPTYSTACKEXCEPTION_H
#include <exception>
using namespace std;
class EmptyStackException : public exception{
    //error message displays if stack is empty
public:
    const char * what () const noexcept override
    {
        return "EmptyStackException";
    }
};


#endif //UNTITLED7_EMPTYSTACKEXCEPTION_H
