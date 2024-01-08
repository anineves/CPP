#include "Span.hpp"
int main() {
    {
        std::cout << "-----------Subject Test----------------" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    std::cout << "\n\n--------------Exception FullSpan-------------" << std::endl;

    {
        try {
            Span sp(5);

            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            sp.addNumber(20);

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    std::cout << "\n\n--------------Exception Few Elemets (shortest)-------------" << std::endl;

    {
        try{
            Span sp(1);
            sp.addNumber(6);

            std::cout << sp.shortestSpan() << std::endl;

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }


    std::cout << "\n\n--------------Exception Few Elemets (longest)-------------" << std::endl;

    {
        try{
            Span sp(1);
            sp.addNumber(6);

            std::cout << sp.longestSpan() << std::endl;

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }





    std::cout << "\n\n---------Sooooooo Big------------------" << std::endl;

    {
        try {
            Span sp(11000);

            for (int i = 0; i < 11000; i++)
                sp.addNumber(i);
            //sp.print();
            //std::cout << sp.shortestSpan() << std::endl;
            //std::cout << sp.longestSpan() << std::endl;

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    std::cout << "\n\n-----------Using addNumber2----------------" << std::endl;

    {
        try {
            Span sp(10);
            std::vector<int> sp2;

            for (int i = 0; i < 5; i++)
                sp.addNumber(i);

            for (int i = 0; i < 5; i++)
                sp2.push_back(i * 2);

            std::cout << "\n Before addNumber2" << std::endl;
            sp.print();
            sp.addNumber2(sp2.begin(), sp2.end());
            std::cout << "\n After addNumber2" << std::endl;
            sp.print();

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    std::cout << "---------------------------" << std::endl;
     {
        try {
           Span sp(2);
		sp.addNumber(2147483647);
		sp.addNumber(-2147483648);
		sp.print();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan()<< std::endl;

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }


    return 0;
}