/**-                                 --**/
//verifica se o simbolo está dentro da base
unsigned int ft_find_char_in_str(char c, char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}

unsigned int ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int ft_check_base(char *str)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' ||
			str[i] == '+' || str[i] == '-')
		{
			return (0);
		}
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
//converte string com a base especificada com o inteiro
int ft_str_base_to_int(char *str, char *base, int start, int end)
{
	int n;
	int digit;
	int base_len;

	n = 0;
	digit = 1;
	base_len = ft_strlen(base);
	while (end >= start)
	{
		n = n + (ft_find_char_in_str(str[end], base) - 1) * digit;
		digit = digit * base_len;
		end--;
	}
	return (n);
}

int ft_atoi_base(char *str, char *base)
{
	unsigned int i;
	int sign;
	unsigned int start;

	i = 0;
	//base válida 1 ou vazia
	if (ft_strlen(base) < 2 || ft_check_base(base) == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') //verifica espaços em branco
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-') //verifica o sinal do número
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	start = i;
	while (ft_find_char_in_str(str[i], base) > 0)
		i++;
	i--;
	return (ft_str_base_to_int(str, base, start, i) * sign);
}

#include <unistd.h>
int main(void)
{
	int i;

	i = ft_atoi_base("    ---+--+f", "0123456789abcdef");
	// -15

	char test[4] = {48, 49, -29, 0};
	// 01ã

	i = ft_atoi_base(&test[1], test);
	// 5
	if (i == 5)
	{
		write(1, "SUCCESS\n", 8);
	}
	else
	{
		write(1, "FAILED\n", 7);
	}

	i = ft_atoi_base("    ---+--+1234ab567", "012");
	// -5

	i = ft_atoi_base("    --+--+1234ab567", "01234");
	// 194

	i = ft_atoi_base("\f\n\r\t\v ---+--+ababc", "ab");
	// abab
	// 0101
	// -5

	i = ft_atoi_base("    ---+--+@", "@1");
	// 0

	i = ft_atoi_base("batata", "bat");
	// 012121
	// 151

	i = ft_atoi_base("", "0123456789ABCDEF");
	// 0

	i = ft_atoi_base(" 1234+2", "0123456789ABCDEF");
	// 4660

	i = ft_atoi_base("-abcd-2", "0123456789abcdef");
	// -43981

	i = ft_atoi_base("-abcd-2", "");
	// 0 - base vazia

	i = ft_atoi_base("-abcd-2", "Z");
	// 0 - base de tamanho 1

	i = ft_atoi_base("-abcd-2", "+-");
	// 0 - base com char '+' ou '-'

	i = ft_atoi_base("-abcd-2", "123 456");
	// 0 - base com white space

	i = ft_atoi_base("-abcd-2", "123\t456");
	// 0 - base com white space

	i = ft_atoi_base("-abcd-2", "batata");
	// 0 - base com char repetido

	i = ft_atoi_base("   \t", "0123456789");
	// 0

	i = ft_atoi_base("+12", "0123456789");
	// 12

	i = ft_atoi_base("90", "0123456789");
	// 90

	i = ft_atoi_base("-", "0123456789");
	// 0

	i = ft_atoi_base("+", "0123456789");
	// 0

	i = i;
	return (0);
}
