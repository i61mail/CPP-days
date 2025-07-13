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

        /*     No space Left    */
        Span NoSpaceLeft(1);
        NoSpaceLeft.addNumber(2);
        NoSpaceLeft.addNumber(5);


        /*     Empty Vector     */
        Span empty(4);
        empty.longestSpan();
        empty.shortestSpan();

        /*    One Element in the vector    */
        Span OneElem(2);

        OneElem.addNumber(5);
        OneElem.longestSpan();
        OneElem.shortestSpan();
        
        /*   Putting Numbers At Once    */
        std::vector<long> Onetime(10000, 2);
        Span    test1(10000);
        test1.addByOnce(Onetime.begin(), Onetime.end());
        std::cout << "shortestSpan ==  " << test1.shortestSpan() << std::endl;
        std::cout << "longestSpan ==  " << test1.longestSpan() << std::endl;
    }
    catch(const char *message)
    {
        std::cerr << message << std::endl;
    }
    
    return 0;
}