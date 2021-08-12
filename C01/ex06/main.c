#include <unistd.h>
int ft_strlen(char *str);

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
