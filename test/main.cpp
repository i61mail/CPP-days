#include "class.hpp"

int main()
{
    // Printer obj(10);

    // try
    // {
    //     obj.printMessage("Test For Exceptions : HH");
    //     obj.printMessage("Test For Exceptions : HH");
    //     obj.printMessage("Test For Exceptions : HH");
    //     obj.printMessage("Test For Exceptions : HH");
    //     obj.printMessage("Test For Exceptions : HH");
    //     obj.printMessage("Test For Exceptions : HH");
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // catch (const char *)
    // {
    //     std::cout << "Error" << std::endl;
    // }
    
    const std::string &string = "Hello World";

    bool su = ((long)&string % 2) == 0;

    long address = (long)&string;
    std::cout << "address of string : " << &string << std::endl;
    std::cout << "address of string : " << address << std::endl;
    if (su)
        std::cout << "string is even" << std::endl;
    else
        std::cout << "string is odd" << std::endl;



    return (0);
}