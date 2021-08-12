
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i; // apenas inteiros positivos
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0'; //garantindo que nas últimas posições sejam igual a \0 <doc.>
		i++;			//não garante se n tem byte nulo
	}

	return dest;
}

#include <unistd.h>
int main(void)
{

	char destiny[25];

	ft_strncpy(destiny, "BATATA", 4); // 7 inclui null
	write(1, destiny, 4);

	return (0);
}
