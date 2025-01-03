#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;


	std::string str;
	if (ac > 1)
	{
		while (av[i])
		{
			j = 0;
			str = av[i];
			while (str[j])
			{
				std::cout << (char)toupper(str[j]);
				j++;
			}
			i++;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}
	std::cout << "\n";
	return (0);
}
