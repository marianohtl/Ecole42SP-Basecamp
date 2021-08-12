char *ft_strlowcase(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90) //verifica se está no intervalo das maiúsculas
		{
			str[i] = str[i] + 32; //converte para minúsculo <posição ascii table>
		}
		i++;
	}
	return (str);
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
	char lowcase[16];
	ft_strncpy(lowcase, "hello THERE!# 1", 16);
	ft_strlowcase(lowcase);
	write(1, lowcase, 15);

	return (0);
}
