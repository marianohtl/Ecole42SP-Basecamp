char *ft_strcpy(char *dest, char *src)
{
	unsigned int i; //sem índice negativo
	i = 0;
	while (src[i] != 0) //percorro src até byte nullo
	{
		dest[i] = src[i]; //copio
		i++;
	}
	dest[i] = src[i]; ///"batata\0" -> adiciona byte nullo

	return dest;
}

#include <unistd.h>
int main(void)
{

	char destiny[7];

	ft_strcpy(destiny, "BATATA");
	write(1, destiny, 7);
	return (0);
}
