#include <stdio.h>

int		min(int a, int b)
{
		if (a > b)
				return (b);
		else
				return (a);
}

int		ft_rec(int nb)
{
		if (nb == 1)
				return (0);
		if (nb == 2 || nb == 3)
				return (1);
		if (nb % 2 == 0 && nb % 3 != 0)
				return (min(ft_rec(nb - 1), ft_rec(nb / 2)) + 1);
		if (nb % 6 == 0)
				return (min(ft_rec(nb / 3), ft_rec(nb / 2)) + 1);
		return ft_rec(nb - 1) + 1;
}

int		main(void)
{
		int		result;
		int		nb;

		scanf("%d",&nb);
		result = ft_rec(nb);
		printf("%d",result);
		return (0);
}

