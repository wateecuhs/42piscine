/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:53:58 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 20:28:35 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*lookup_word(unsigned long int nb, char *dict)
{
	char	*str;
	char	*ret;
	int		i;

	i = 0;
	str = ft_itoa(nb);
	ret = line_by_line(dict, str);
	free(str);
	if (!ret)
	{
		return (NULL);
	}
	return (ret);
}

void	init(char *path, char *nbr)
{
	char	*input;
	char	*dict;

	dict = get_str(path);
	if (!check_dict(dict))
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	if (!check_number(nbr))
	{
		write(1, "Error\n", 6);
		return ;
	}
	input = atoa(nbr);
	if (!is_printable(input, dict))
	{
		write(1, "Dict Error\n", 11);
		free(input);
		return ;
	}
	split_number(input, dict);
	free(input);
}

int	main(int argc, char **argv)
{
	char	*dict;

	if (argc == 2)
		init("numbers.dict", argv[1]);
	else if (argc == 3)
		init(argv[1], argv[2]);
	else if (argc == 1)
	{
		dict = get_str("numbers.dict");
		if (!check_dict(dict))
		{
			free(dict);
			write(1, "Dict Error\n", 11);
			return (1);
		}
		read_stdin(dict);
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
