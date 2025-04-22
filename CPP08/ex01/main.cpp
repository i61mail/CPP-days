#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shorspSpan ==  " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan ==  " << sp.longestSpan() << std::endl;

        //test for extra element than it required
        // Span elReq(1);
        // elReq.addNumber(2);
        // elReq.addNumber(5);


        // // test for empty vector
        // Span empty(4);
        // empty.longestSpan();
        // empty.shortestSpan();

        //test for one element
        // Span OneElem(2);

        // OneElem.addNumber(5);
        // OneElem.longestSpan();
        // OneElem.shortestSpan();
        
        //test for puting numbers at once
        // std::vector<long> Onetime(10000, 2);
        // Span    test1(10000);


        // test1.addByOnce(Onetime.begin(), Onetime.end());
        // std::cout << "longestSpan ==  " << test1.longestSpan() << std::endl;
        // std::cout << "shortestSpan ==  " << test1.shortestSpan() << std::endl;
        
    }
    catch(Span::noSpaceLeft &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Span::noSpanCanBeFound &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}