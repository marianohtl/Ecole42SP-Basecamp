char *ft_strcapitalize(char *str)
{
	unsigned int i;
	int start_of_word;

	start_of_word = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (start_of_word == 1 && str[i] >= 97 && str[i] <= 122) // verifica se é minúsculo e se é começo de palavra
		{
			str[i] = str[i] - 32; //converte pra maiúsculo
		}
		if (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
			(str[i] > 90 && str[i] < 97) || str[i] > 122) //verifica se não é alfa-numérico
		{
			start_of_word = 1;
		}
		else
		{
			start_of_word = 0;
		}
		i++;
	}
	return (str);
}

#include <unistd.h>

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

int main(void)
{
	char capitalize[16];
	ft_strncpy(capitalize, "hello there!# 1", 16);
	ft_strcapitalize(capitalize);
	write(1, capitalize, 15);

	return (0);
}
