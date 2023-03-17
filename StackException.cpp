#include "StackException.h"

StackArrayOverflow::StackArrayOverflow() : reason("StackOverflow") {}
const char* StackArrayOverflow::what() const { return reason.c_str(); }

StackArrayUnderflow::StackArrayUnderflow() : reason("StackUnderflow") {}
const char* StackArrayUnderflow::what() const { return reason.c_str(); }

WrongStackArraySize::WrongStackArraySize() : reason("WrongStackArraySize") {}
const char* WrongStackArraySize::what() const { return reason.c_str(); }