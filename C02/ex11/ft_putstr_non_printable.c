#include <unistd.h>

void ft_print_char_as_hex(char c)
{
	char hex[3];

	hex[0] = '\\';
	hex[1] = c / 16 + '0'; //converti o primeiro dígito para base 16 + 0 (imprimir char )
	if (c % 16 >= 10)	   //verifica se o segundo dígito passa da 9
	{
		hex[2] = c % 16 + 87; // converte para a, b ou c
	}
	else
	{
		hex[2] = c % 16 + '0'; //converte para 0 ~ 9
	}
	write(1, hex, 3);
}

void ft_putstr_non_printable(char *str)
{
	unsigned int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126) //caso não seja imprimível
		{
			ft_print_char_as_hex(str[i]); //imprime o índice do ascii do caracter como hexadecimal
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

int main(void)
{

	ft_putstr_non_printable("Hello There\nGeneral\tKenobi!!");
	return (0);
}
