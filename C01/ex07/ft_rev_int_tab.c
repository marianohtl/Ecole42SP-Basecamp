void ft_swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void ft_rev_int_tab(int *tab, int size)
{
	int i;
	i = 0;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}
// 3 6 7 8 9
// 9 6 5 8 3
// 9 8 5  6 3
