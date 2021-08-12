void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	int tab[7];
	tab[0] = 7;
	tab[1] = 4;
	tab[2] = 2;
	tab[3] = 4;
	tab[4] = 1;
	tab[5] = -9;
	tab[6] = 0;
	ft_sort_int_tab(tab, sizeof(tab) / 4);
	return (0);
}
