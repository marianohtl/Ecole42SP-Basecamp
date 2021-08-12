#include <unistd.h>

// Conta o número de char dentro da string, excluindo o byte nulo
unsigned int ft_strlen(char *str)
{
	unsigned int i;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

// Verifica se a string contém os chars '+' ou '-'
int ft_has_plus_or_minus(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			return 1;
		}
		i++;
	}
	return 0;
}

// Verifica se a string tem algum char repetido
int ft_has_repeated_char(char *str)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
			{
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}

// Imprime os dígitos de nbr, considerando a base e sinal do número
void ft_put_digits(int nbr, char *base, int sign)
{
	int i;
	int digits[32]; // int pode ser escrito com no máximo 32 bits na base 2, sendo que 1 dos bits é o de sinal
	int base_len;

	i = 0;
	base_len = (int)ft_strlen(base);

	// Converte de base 10 para a base especificada
	while (nbr != 0)
	{
		// Armazena o índice de cada dígito
		//    C C * 1
		//   D0 D * 16
		digits[i] = (nbr % base_len) * sign;

		nbr = nbr / base_len;
		i++;
	}
	// Imprime os dígitos em ordem reversa (similar a conversão feita na mão de uma base para outra)
	while (i > 0)
	{
		write(1, &base[digits[i - 1]], 1);
		i--;
	}
}
void ft_putnbr_base(int nbr, char *base)
{
	int sign;

	sign = 1;
	// Verifica se a base tem tamanho de 1 ou menos, ou se tem '+' ou '-' ou se tem símbolo repetido
	if (ft_strlen(base) < 2 || ft_has_plus_or_minus(base) == 1 || ft_has_repeated_char(base) == 1)
	{
		return;
	}
	if (nbr < 0)
	{
		// Se o número for negativo, imprime o sinal e armazena o sinal do número numa variável
		write(1, "-", 1);
		sign = -1;
	}
	if (nbr == 0)
	{
		// Se o número for 0, apenas imprime o primeiro char da base
		write(1, &base[0], 1);
	}
	else
	{
		ft_put_digits(nbr, base, sign);
	}
}

#include <unistd.h>

int main(void)
{
	ft_putnbr_base(16, "01");
	write(1, "\n", 1);
	// 10000

	ft_putnbr_base(-16, "01");
	write(1, "\n", 1);
	// -10000

	ft_putnbr_base(16, "ab");
	write(1, "\n", 1);
	// baaaa

	ft_putnbr_base(0, "xyz");
	write(1, "\n", 1);
	// x

	ft_putnbr_base(-65244, "0123456789ABCDEF");
	write(1, "\n", 1);
	// -FEDC

	ft_putnbr_base(47768, "FEDCBA9876543210");
	write(1, "\n", 1);
	// BA98
	// 4567

	ft_putnbr_base(-30292, "0123@#$!89ABCDEF");
	write(1, "\n", 1);
	// -7654
	// -!$#@

	ft_putnbr_base(2930, "poney");
	write(1, "\n", 1);
	// 43210
	// yenop

	ft_putnbr_base(10, "my+base");
	write(1, "Tem +\n", 6);
	// Tem +

	ft_putnbr_base(10, "my-base");
	write(1, "Tem -\n", 6);
	// Tem -

	ft_putnbr_base(10, "0");
	write(1, "Base com tamanho 1\n", 19);
	// Base com tamanho 1

	ft_putnbr_base(10, "");
	write(1, "Base vazia\n", 11);
	// Base vazia

	ft_putnbr_base(10, "batata");
	write(1, "Base com simbolo repetido\n", 26);
	// Base com símbolo repetido

	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	// -2147483648

	ft_putnbr_base(2147483647, "01");
	write(1, "\n", 1);
	// 1111111111111111111111111111111 (31 vezes 1)
	return (0);
}
