void ft_ultimate_div_mod(int *a, int *b) //busca o valor armazenado dentro do endereço de memória
{
	int div;
	int mod;
	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
