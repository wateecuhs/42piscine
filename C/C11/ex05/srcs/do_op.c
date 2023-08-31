/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:55:09 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 12:46:31 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		add(int a, int b);

int		substract(int a, int b);

int		divide(int a, int b);

int		modulo(int a, int b);

int		multiply(int a, int b);

void	ft_putchar(char c);

int		ft_strlen(char *str);

void	ft_putnbr(int nb);

int		ft_strcmp(char *str1, char *str2);

void	ft_putstr(char *str);

int		ft_atoi(char *str);

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	do_op(int s1, int s2, char *operator, int (**f)(int, int))
{
	if (ft_strcmp(operator, "+") == 0)
		ft_putnbr(f[0](s1, s2));
	else if (ft_strcmp(operator, "-") == 0)
		ft_putnbr(f[1](s1, s2));
	else if (ft_strcmp(operator, "/") == 0)
	{
		if (s2 == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(f[2](s1, s2));
	}
	else if (ft_strcmp(operator, "%") == 0)
	{
		if (s2 == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(f[4](s1, s2));
	}
	else if (ft_strcmp(operator, "*") == 0)
		ft_putnbr(f[3](s1, s2));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return ;
}

int	main(int argc, char **argv)
{
	int	(*funcs[5])(int, int);

	funcs[0] = add;
	funcs[1] = substract;
	funcs[2] = divide;
	funcs[3] = multiply;
	funcs[4] = modulo;
	if (argc != 4)
		return (0);
	else
	{
		do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2], funcs);
	}
}
