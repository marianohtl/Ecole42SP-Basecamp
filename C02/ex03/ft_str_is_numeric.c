
int ft_str_is_numeric(char *str)
{
	unsigned int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57) // 0 à 9
		{
			return 0;
		}
		i++;
	}
	return 1;
}

#include <unistd.h>
int main(void)
{
	char result00;
	char result01;
	char null;

	result00 = ft_str_is_numeric("123A") + '0';
	result01 = ft_str_is_numeric("1234") + '0';
	null = ft_str_is_numeric("") + '0';

	write(1, &result00, 1);
	write(1, "\n", 1);
	write(1, &result01, 1);
	write(1, "\n", 1);
	write(1, &null, 1);
	write(1, "\n", 1);
	return (0);
}
