#include <stdlib.h>

int	absval(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	*ft_rrange(int start, int end)
{
	int	len_tab;
	int	i;
	int	*tab;

	i = 0;
	len_tab = absval(start - end);
	tab = (int *)malloc(sizeof(int) * (len_tab + 1));
	while (start != end)
	{
		tab[i] = end;
		i++;
		if (end < start)
			end++;
		else
			end--;
	}
	tab[i] = start;
	return (tab);
}

#include <stdio.h>
int	main(void)
{
	int *tab;

	int i = 0;
	tab = ft_rrange(5, -2);
	while (i < 8)
	{
		printf("%d ", tab[i]);
		i++;
	}
}
