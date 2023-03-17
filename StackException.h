#pragma once
#include<exception>
#include<string>

class StackArrayOverflow : public std::exception
{
private:
    const std::string reason;
public:
    StackArrayOverflow();
    const char* what() const;
};

class StackArrayUnderflow : public std::exception
{
private:
    const std::string reason;
public:
    StackArrayUnderflow();
    const char* what() const;
};

class WrongStackArraySize : public std::exception
{
private:
    const std::string reason;
public:
    WrongStackArraySize();
    const char* what() const;
};