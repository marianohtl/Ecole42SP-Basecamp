int ft_str_is_printable(char *str)
{
	unsigned int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126) // \n tab esc delete backspace
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

	result00 = ft_str_is_printable("\n") + '0';
	result01 = ft_str_is_printable("Hello There. General Kenobi.") + '0';
	null = ft_str_is_printable("") + '0';
	write(1, &result00, 1);
	write(1, "\n", 1);
	write(1, &result01, 1);
	write(1, "\n", 1);
	write(1, &null, 1);
	write(1, "\n", 1);

	return (0);
}
