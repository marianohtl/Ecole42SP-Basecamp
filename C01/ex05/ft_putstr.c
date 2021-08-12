#include <unistd.h>

void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i] != 0) //strings são terminadas em 0
	{
		write(1, &str[i], 1); //imprime minha string
		i++;
	}
}
