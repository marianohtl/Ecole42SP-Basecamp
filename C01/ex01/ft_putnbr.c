#include <unistd.h>

void ft_putnbr(int nb)
{
	char number[10];
	int i;
	int sign;

	sign = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		sign = -1;
	}
	number[9] = '0';
	i = 9;
	while (nb != 0)
	{
		number[i] = sign * (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	i++;
	if (i == 10)
	{
		i = 9;
	}
	write(1, &number[i], 10 - i);
}
