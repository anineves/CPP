#include "RPN.hpp"

Rpn::Rpn()
{

}

Rpn::Rpn(const Rpn &source)
{
    *this = source;
}

Rpn &Rpn::operator=(const Rpn &rhs)
{
    (void) rhs;
    return(*this);
}

Rpn::~Rpn() {}


bool Rpn::isOperator(char op)
{
    if(op != '+' && op != '-' && op != '*' && op != '/')
        return false;
    return true; 
}

bool Rpn::validate_input(std::string input)
{
    int i;
    
    for(i=0; input[i]; i++ )
    {
        std::cout<< "valor '" << input[i]<< "'"<< std::endl;
        if(!isdigit(input[i]) && !isOperator(input[i]) && input[i] != ' ')
            return false;
    }
    if(input.size() < 2)
        return false; 
    return true;
}
void Rpn::operation (char op, std::stack<float> &stack)
{
    if(stack.size() < 2)
        throw std::runtime_error("Invalid expression (op)");

    float val2 = stack.top();
    stack.pop();
    float val1 = stack.top();
    stack.pop();

    switch (op)
    {
    case '+':
        stack.push(val1 + val2);
        break;
    case '-':
        stack.push(val1 - val2);
        break;
    case '*':
        stack.push(val1 * val2);
        break;
    case '/':
        stack.push(val1 / val2);
        break;
    
    default:
        throw std::runtime_error("Invalid expression (op)");
        break;
    }

}

float Rpn::solve (std::string input)
{
    if (!validate_input(input))
        throw std::runtime_error("Invalid expression (input)");
    
    std::stack<float> stack;
    std::string::const_iterator it;
    int num;

    for(it = input.begin(); it != input.end(); it++)
    {
        if(*it == ' ')
            continue;
        
        if(std::isdigit(*it))
        {
            num = *it - '0';
            stack.push(num);
            continue;
        }
        if(isOperator(*it))
        {
            operation(*it, stack);
        }
    }

    return(stack.top());
}