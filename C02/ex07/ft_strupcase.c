char *ft_strupcase(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0') // percorro a string até o byte nullo
	{
		if (str[i] >= 97 && str[i] <= 122) // verifico se está no range de letras minúsculas
		{
			str[i] = str[i] - 32; // converte letra minúsculo para maiúscula (32 posição da distância)
		}
		i++;
	}
	return str;
}

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i; // apenas inteiros positivos
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		dest[n - 1] = '\0'; //garantindo que na última posição seja igual a \0
	}

	return dest;
}

#include <unistd.h>
int main(void)
{
	char upcase[16];
	ft_strncpy(upcase, "hello There!# 1", 16);
	ft_strupcase(upcase);
	write(1, upcase, 15);

	return (0);
}
