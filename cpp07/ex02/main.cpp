#include "Array.hpp"


#define SIZE 10
int main(int, char**)
{
    Array<int> intArray(SIZE);
    int* intArray2 = new int[SIZE - 5];

    for (int i = 0; i < SIZE; i++)
    {
        intArray[i] = i * 2;
        intArray2[i] = i * 3;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        std::cout << "intArray2[" << i << "] = " << intArray2[i] << std::endl;
        std::cout << std::endl;
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;
    {
        std::cout << "Operator =" << std::endl;
        Array<int> arrayOp;
        arrayOp = intArray;
        for (int i = 0; i < SIZE; i++)
        {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
            std::cout << "arrayOp[" << i << "]    = " << arrayOp[i] << std::endl;
        }
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;

    try
    {
        Array<int> intArray3(-1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        intArray[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what()  << std::endl;
    }

    try
    {
        intArray[13] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what()  << std::endl;
    }


    delete [] intArray2;
    return 0;
}
