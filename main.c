#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	int	num;

	num = 10;
	ft_printf("ft: %x - %d", num, num);
	ft_printf("\n");
	printf("original: %x - %d", num, num);
	printf("\n");
	return (0);
}
