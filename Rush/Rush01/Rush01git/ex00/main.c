/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:27:27 by panger            #+#    #+#             */
/*   Updated: 2023/08/28 11:26:30 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_line(int tab[6][6], int y);
void	print_tab(int tab[6][6]);
int		valid_line(int tab[6][6], int y);
int		is_valid(int tab[6][6], int x, int y);
void	ft_putstr(char *str);
int		solve_tab(int tab[6][6], int x, int y, int *printed);
void	init_tab(int tab[6][6], char *args);

int	valid_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (0);
		if (i % 2 == 1 && (str[i] != ' '))
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	i = 0;
	while (str[i] && i < 24)
	{
		if (((str[i] - 48) + str[i + 8] - 48) > 5
			|| ((str[i] - 48) + str[i + 8] - 48) < 3)
			return (0);
		i += 2;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	printed;
	int	tab[6][6];

	printed = 0;
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
	{
		if (valid_args(argv[1]) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
		init_tab(tab, argv[1]);
		solve_tab(tab, 1, 1, &printed);
		if (printed == 0)
			ft_putstr("Error\n");
	}
}
