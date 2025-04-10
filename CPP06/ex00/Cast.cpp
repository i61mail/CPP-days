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
            
        // Handle single ScalarConverter::CHAR
        if (literal.length() == 1 && !std::isdigit(literal[0]))
            return ScalarConverter::CHAR;
            
        // Handle sign
        size_t startPos = 0;
        if (literal[0] == '-' || literal[0] == '+')
        {
            startPos = 1;
            if (literal.length() == 1 || !std::isdigit(literal[1]))
                return ScalarConverter::INVALID;
        }
        // Find decimal point
        size_t dotPos = literal.find('.');
        bool hasDot = (dotPos != std::string::npos);
        
        // Find 'f' suffix
        size_t fPos = literal.find('f');
        bool hasF = (fPos != std::string::npos);

        //check if '.' is behind the 'f' && if '.' at the begining followed by 'f'
        if (dotPos + 1 == fPos || (literal.length() != 1 && literal[0] == '.'))
            return ScalarConverter::INVALID;

        // Check if 'f' is at the end
        if (hasF && fPos != literal.length() - 1)
            return ScalarConverter::INVALID;
            
        // Validate all ScalarConverter::CHAR are valid for a number
        for (size_t i = startPos; i < literal.length(); i++)
        {
            if (i == dotPos) // Skip the dot
                continue;
            if (i == fPos) // Skip the f at the end
                continue;
            if (!std::isdigit(literal[i]))
                return ScalarConverter::INVALID;
        }
        
        // Nothing after decimal point
        if (hasDot && dotPos + 1 == literal.length())
            return ScalarConverter::INVALID;
            
        // Determine type based on dot and 'f'
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

static int stringToInt(const std::string& str)
{
    std::istringstream iss(str);
    int result;
    iss >> result;
    return result;
}

void ScalarConverter::convert(const std::string &literal)
{
    Type type = getType(literal);
    // std::cout << "Type : " << type << std::endl;
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
        int c = stringToInt(literal);
        std::cout << "char : ";
        if (c < 0 || c > 127)
            std::cout << "impossible" << std::endl;
        else if (c < 32 || c > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
        std::cout << "int : " << c << std::endl;
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
        std::cout << "int : " << static_cast<int>(c) << std::endl;
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
        std::cout << "int : " << static_cast<int>(c) << std::endl;
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