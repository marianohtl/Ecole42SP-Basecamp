#include <unistd.h>

void ft_print_address(void *address)
{
	write(1, address, 1);
}

void ft_print_char_as_hex(char c)
{
	char hex[3];

	hex[0] = '\\';
	hex[1] = c / 16 + '0';
	if (c % 16 >= 10)
	{
		hex[2] = c % 16 + 87;
	}
	else
	{
		hex[2] = c % 16 + '0';
	}
	write(1, hex, 3);
}

void *ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;
	char *addr_copy;
	addr_copy = addr;
	i = 0;
	ft_print_address(addr);
	while (addr_copy[i] != '\0' && i < size)
	{
		if (i % 16 == 0)
		{
			write(1, "\n", 1);
		}
		if (addr_copy[i] < 32 || addr_copy[i] > 126)
		{
			write(1, ".", 1);
		}
		else
		{
			write(1, &addr_copy[i], 1);
		}
		i++;
	}
	return 1;
}
