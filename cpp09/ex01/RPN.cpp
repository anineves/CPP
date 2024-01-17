/*
A notação polonesa reversa (RPN) é uma notação matemática em que cada operador segue todos os seus operandos. Também é conhecida como notação postfixa. Em RPN, a ordem das operações é determinada pela posição dos operadores, e não é necessário o uso de parênteses para indicar a ordem de avaliação.

Ao contrário da notação infix, mais comumente usada, em que os operadores são colocados entre os operandos, e parênteses são usados para especificar a ordem das operações, em RPN, essa mesma expressão seria escrita como "3 4 5 * +".

Aqui estão as principais características da Notação Polonesa Reversa:

Sem Parênteses: RPN elimina a necessidade de parênteses para indicar a ordem das operações. A posição dos operadores em relação aos operandos determina a ordem.

Operador Segue Operandos: Em RPN, cada operador vem depois de seus operandos. Por exemplo, "2 3 +" significa "2 + 3".

Análise e Avaliação Mais Simples: Expressões RPN são mais fáceis de serem analisadas e avaliadas algoritmicamente, tornando-as adequadas para uso em calculadoras e programas de computador.

Sem Ambiguidade: RPN elimina ambiguidades na ordem das operações, pois a posição dos operadores é fixa. Isso simplifica o processo de avaliação de expressões.

Avaliação Baseada em Pilha: Expressões RPN são frequentemente avaliadas usando uma estrutura de dados de pilha. Operandos são empilhados, e quando um operador é encontrado, ele é aplicado aos operandos no topo da pilha.

A notação RPN tem vantagens em termos de simplicidade e facilidade de processamento por computadores. É comumente utilizada em algumas calculadoras e linguagens de programação, como Forth. O método de avaliação baseado em pilha torna a RPN adequada para implementação em algoritmos, onde uma pilha pode manter eficientemente o rastro da ordem das operações.
*/
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
    if(input.size() < 3)
        return false; 
    return true;
}

//push(value) adds the specified value to the top of the stack.
//pop() removes the top element of the stack.

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

//stack.top() returns a reference to the top element of the stack.
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