void ft_rev_int_tab(int *tab, int size);

int main(void)
{
	int tab[6];
	tab[0] = 2;
	tab[1] = 3;
	tab[2] = 4;
	tab[3] = 5;
	tab[4] = 6;
	tab[5] = 7;
	ft_rev_int_tab(tab, 6); // sizeof(tab) > cada inteiro ocupa 4 bytes (32 bits) / 4
	return (0);
}
