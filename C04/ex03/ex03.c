unsigned int ft_get_sign(char *str, unsigned int *i)
{
	// Retorna -1 se for negativo e 1 se for positivo
	int sign;
	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			sign = sign * -1;
		}
		(*i)++;
	}
	return sign;
}

int ft_str_to_int(char *str, int start, int end, int sign)
{
	int n;	   // para indicar o número
	int digit; // para indicar a casa (1 para unidade, 10 para dezena, 100 para centena)

	n = 0;
	digit = 1;
	// convert str to number
	while (end >= start)
	{
		//    0 <- n
		//    4 <- 4 * 1
		//   30 <- 3 * 10
		//  200 <- 2 * 100
		// 1000 <- 1 * 1000
		n = n + (str[end] - '0') * digit;
		digit = digit * 10; // Pula para a próxima casa. Exemplo: unidade para dezena, dezena para centena.
		end--;
	}
	// Aplicando o sinal
	n = n * sign;
	return n;
}

int ft_atoi(char *str)
{
	unsigned int i;		// para percorrer a string
	int sign;			// para armazenar o sinal
	unsigned int start; // indica aonde começa o número

	i = 0;
	// check 'white spaces'
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	// check for signals
	sign = ft_get_sign(str, &i);
	start = i;
	// check for base10 numbers
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	i--;
	return (ft_str_to_int(str, start, i, sign));
}

int main(void)
{
	int i;

	i = ft_atoi("    ---+--+1234ab567");
	// -1234

	i = ft_atoi("    --+--+1234ab567");
	// 1234

	i = ft_atoi("\f\n\r\t\v ---+--+1234ab567");
	// -1234

	i = ft_atoi("    ---+--+0");
	// 0

	i = ft_atoi("1234+2");
	// 1234

	i = ft_atoi("+1234+2");
	// 1234

	i = ft_atoi(" 1234+2");
	// 1234

	i = ft_atoi("-1234-2");
	// -1234

	i = ft_atoi("");
	// 0

	i = i;
	return (0);
}
