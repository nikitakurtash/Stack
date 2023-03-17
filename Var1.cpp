#include <iostream>
#include "StackArray.h"
#include "StackException.h"

int evaluatePostfix(const std::string& postfix, const size_t stackSize);

int main() {
    try {
        std::cout << "Test 1: ";
        std::string test1 = "52+";
        std::cout << test1 << " = " << evaluatePostfix(test1, 10) << std::endl;

        std::cout << "Test 2: ";
        std::string test2 = "34*";
        std::cout << test2 << " = " << evaluatePostfix(test2, 10) << std::endl;

        std::cout << "Test 3: ";
        std::string test3 = "62/";
        std::cout << test3 << " = " << evaluatePostfix(test3, 10) << std::endl;

        std::cout << "Test 4: ";
        std::string test4 = "921*-8-4+";
        std::cout << test4 << " = " << evaluatePostfix(test4, 10) << std::endl;

        std::cout << "Test 1: ";
        std::string test5 = "237*+";
        std::cout << test5 << " = " << evaluatePostfix(test5, 10) << std::endl;

        std::cout << "Test 2: ";
        std::string test6 = "12+34*+5/";
        std::cout << test6 << " = " << evaluatePostfix(test6, 10) << std::endl;

        std::cout << "Test 3: ";
        std::string test7 = "12+345*+-";
        std::cout << test7 << " = " << evaluatePostfix(test7, 10) << std::endl;

        std::cout << "Test 4: ";
        std::string test8 = "95/3*4-";
        std::cout << test8 << " = " << evaluatePostfix(test8, 10) << std::endl;

        std::cout << "Test 1: ";
        std::string test9 = "52*8+4/";
        std::cout << test9 << " = " << evaluatePostfix(test9, 10) << std::endl;

        std::cout << "Test 2: ";
        std::string test10 = "123+45*6+esfw*+";
        std::cout << test10 << " = " << evaluatePostfix(test10, 4) << std::endl;

        std::cout << "Test 3: ";
        std::string test11 = "15+2/3*+";
        std::cout << test11 << " = " << evaluatePostfix(test11, 10) << std::endl;

        std::cout << "Test 4: ";
        std::string test12 = "123*+4564*+-";
        std::cout << test12 << " = " << evaluatePostfix(test12, 4) << std::endl;

    }
    catch (const StackArrayOverflow& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }
    catch (const StackArrayUnderflow& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "error: unknown" << std::endl;
    }

    return 0;
}


int evaluatePostfix(const std::string& postfix, const size_t stackSize) {
    StackArray<int> operandStack(stackSize);

    for (const char& ch : postfix) {
        if (isdigit(ch)) {
            if (operandStack.isFull()) {
                throw StackArrayOverflow();
            }
            operandStack.push(ch - '0');
        }
        else {
            if (operandStack.isEmpty()) {
                throw StackArrayUnderflow();
            }
            int op2 = operandStack.pop();

            if (operandStack.isEmpty()) {
                throw StackArrayUnderflow();
            }
            int op1 = operandStack.pop();

            switch (ch) {
            case '+':
                operandStack.push(op1 + op2);
                break;
            case '-':
                operandStack.push(op1 - op2);
                break;
            case '*':
                operandStack.push(op1 * op2);
                break;
            case '/':
                if (op2 == 0) {
                    throw std::runtime_error("Divide by zero");
                }
                operandStack.push(op1 / op2);
                break;
            default:
                throw std::runtime_error("Invalid postfix expression");
            }
        }
    }

    if (operandStack.isEmpty()) {
        throw StackArrayUnderflow();
    }

    int result = operandStack.pop();

    if (!operandStack.isEmpty()) {
        throw std::runtime_error("Invalid postfix expression");
    }

    return result;
}
