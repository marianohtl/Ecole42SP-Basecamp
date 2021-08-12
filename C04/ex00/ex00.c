int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int main(void)
{
	int teste;
	char *str;
	str = "hello there";
	teste = ft_strlen(str);
	teste++;
	teste--;
	return (0);
}
