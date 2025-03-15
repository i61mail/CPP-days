#include "class.hpp"

int main()
{
    Printer obj(10);

    try
    {
        obj.printMessage("Test For Exceptions : HH");
        obj.printMessage("Test For Exceptions : HH");
        obj.printMessage("Test For Exceptions : HH");
        obj.printMessage("Test For Exceptions : HH");
        obj.printMessage("Test For Exceptions : HH");
        obj.printMessage("Test For Exceptions : HH");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const char *)
    {
        std::cout << "Error" << std::endl;
    }
    
    return (0);
}