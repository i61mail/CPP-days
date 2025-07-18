#include "Cast.hpp"

ScalarConverter::ScalarConverter()
{
    // std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "Destructor called" << std::endl;
}

static ScalarConverter::Type getType(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf" || 
            literal == "+inf" || literal == "+inff" || 
            literal == "-inf" || literal == "-inff")
        return ScalarConverter::LITERAL;
    
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return ScalarConverter::CHAR;    
    size_t startPos = 0;
    if (literal[0] == '-' || literal[0] == '+')
    {
        startPos = 1;
        if (literal.length() == 1 || !std::isdigit(literal[1]))
            return ScalarConverter::INVALID;
    }
    size_t dotPos = literal.find('.');
    bool hasDot = true;
    if (dotPos == std::string::npos)
        hasDot = false;
    bool hasF = true;;
    size_t fPos = literal.find('f');
    if (fPos == std::string::npos)
        hasF = false;
    if (dotPos + 1 == fPos || (literal.length() != 1 && literal[0] == '.'))
        return ScalarConverter::INVALID;
    if (hasF && fPos != literal.length() - 1)
        return ScalarConverter::INVALID;
    for (size_t i = startPos; i < literal.length(); i++)
    {
        if (i == dotPos)
            continue;
        if (i == fPos)
            continue;
        if (!std::isdigit(literal[i]))
            return ScalarConverter::INVALID;
    }
    if (hasDot && dotPos + 1 == literal.length())
        return ScalarConverter::INVALID;
    if (!hasDot && !hasF)
        return ScalarConverter::INT;
    if ((hasDot && hasF) || (hasF && !hasDot))
        return ScalarConverter::FLOAT;
    if (hasDot && !hasF)
        return ScalarConverter::DOUBLE;
    return ScalarConverter::INVALID;
}

static double stringToDouble(const std::string& str)
{
    std::istringstream iss(str);
    double d;
    iss >> d;
    return d;
}

static float stringToFloat(const std::string& str)
{
    std::istringstream iss(str);
    float f;
    iss >> f;
    return f;
}

static long stringToInt(const std::string& str)
{
    std::istringstream iss(str);
    long result;
    iss >> result;
    return result;
}

bool    checkOverflow(long c)
{
    if (c > 2147483647 || c < -2147483648)
        return true;
    return false;

}

void ScalarConverter::convert(const std::string &literal)
{
    Type type = getType(literal);
    if (type == INVALID)
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    }
    else if (type == CHAR)
    {
        char c = literal[0];
        std::cout << "char : '" << c << "'" << std::endl;
        std::cout << "int : " << static_cast<int>(c) << std::endl;
        std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (type == INT)
    {
        long c = stringToInt(literal);
        std::cout << "char : ";
        if (c < 0 || c > 127)
            std::cout << "impossible" << std::endl;
        else if (c < 32 || c > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
        std::cout << "int : ";
        if (checkOverflow(c) == true)
            std::cout << "overflow" << std::endl;
        else
            std::cout << c << std::endl;
        std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (type == FLOAT)
    {
        float c = stringToFloat(literal);
        std::cout << "char : ";
        if (c < 0.0 || c > 127.0)
            std::cout << "impossible" << std::endl;
        else if (c < 32.0 || c > 126.0)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "int : ";
        if (checkOverflow(c) == true)
            std::cout << "overflow" << std::endl;
        else
            std::cout << static_cast<int>(c) << std::endl;
        std::cout << "float : " << c << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(c) << std::endl;
    }
    else if (type == DOUBLE)
    {
        double c = stringToDouble(literal);
        std::cout << "char : ";
        if (c < 0.0 || c > 127.0)
            std::cout << "impossible" << std::endl;
        else if (c < 32.0 || c > 126.0)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
        std::cout << "int : ";
        if (checkOverflow(c) == true)
            std::cout << "overflow" << std::endl;
        else
            std::cout << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double : " << c << std::endl;
    }
    else if (type == LITERAL)
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : " << literal << std::endl;
        bool isFloat = (literal.find('f') != std::string::npos);
        if (isFloat)
            std::cout << "double : " << literal.substr(0, literal.length() - 1) << std::endl;
        else
            std::cout << "double : " << literal << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
        std::cerr << "Error" << std::endl;
    return 0;
}