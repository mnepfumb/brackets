/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 11:21:06 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/08/14 13:12:36 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int		braclose(char *str, char c, int i, int b)
{
	while (b && *(++str) && (++i))
		if (*str == c || *str == c + c % 2 + 1)
			*str == c ? ++b : --b;
	return (i);
}

int		brackets(char *str, char c)
{
	if (*str == c)
		return (1);
	else if (!*str || *str == ')' || *str == '}' || *str == ']')
		return (0);
	else if ( *str == '(' || *str == '{' || *str == '[')
		return (brackets(str + 1, *str + *str % 2 + 1) * brackets(str +  braclose(str, *str, 1, 1), c));
	else
		return (brackets(str + 1, c));
}

int		main(int av, char **ac)
{
	int i;

	i = 0;
	if (av > 1)
	{
		while (++i < av)
			brackets(ac[i], 0) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
	}
	else
		write(1, "\n", 1);
	return (0);
}
