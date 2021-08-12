void ft_swap(int *a, int *b) //apontando pro valor do end.
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void ft_sort_int_tab(int *tab, int size)
{
	int i;
	int *minvalue;
	int sorted; //quantidade de números que organizei
	sorted = 0;

	while (sorted < size)
	{
		i = sorted + 1;
		minvalue = &tab[sorted];

		while (i < size) //percorrendo todos os elementos do array
		{
			if (*minvalue > tab[i])
			{
				minvalue = &tab[i];
			}
			i++;
		}
		ft_swap(&tab[sorted], minvalue);
		sorted++;
	}
}

//2   -> começa no 1º minvalue vale 2
//5	..
//1 ..  -> minvalue = 1
//0 ..  -> minvalue = 0
//6 ..
//7 ..

// após percorrer lista, ele troca valor posição 0, para valor do min value

//0
//5	.. -> começa no 2º minvalue vale 5
//1 .. -> começa no 1º minvalue vale 1
//2 ..
//6 ..
//7 ..

//...

//0
//1
//5  -> começa no 3º minvalue vale 5
//2 ..
//6 ..
//7 ..
