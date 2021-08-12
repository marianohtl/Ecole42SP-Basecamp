unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	i = 0;
	while (i < size && src[i] != '\0') //verifica o tamanho e se não é byte nulo
	{
		dest[i] = src[i]; //copia se não for
		i++;
	}
	if (size > 0)
	{
		dest[size - 1] = '\0'; //garante byte nulo no último índice
	}

	if (i == size) //caso i ==
	{
		i--;
	}
	return i; //colocar no watch
}

#include <unistd.h>
int main(void)
{

	char destiny[25];

	ft_strlcpy(destiny, "batata", 5);
	write(1, destiny, 5);
	return (0);
}
