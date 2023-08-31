/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:53:58 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 16:51:44 by panger           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	*dict;
	char	*input;

	if (argc == 2)
	{
		dict = get_str("numbers.dict");
		input = atoa(argv[1]);
		split_number(input, dict);
		free(input);
	}
	else if (argc == 3)
	{
		dict = get_str(argv[1]);
		input = atoa(argv[2]);
		split_number(input, dict);
		free(input);
	}
	else if (argc == 1)
	{
		dict = get_str("numbers.dict");
		read_stdin(dict);
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	free(dict);
	return (0);
}
