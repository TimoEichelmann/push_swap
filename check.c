/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:20:35 by marvin            #+#    #+#             */
/*   Updated: 2023/05/05 13:20:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(int argc, char	**argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (ft_digit_check(argv[j]) == 0
			&& ft_check_double(argv, argv[j], argc) == 0)
			j++;
		else
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	return (0);
}

int	ft_digit_check(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(argv) > 10)
		return (-1);
	if ((ft_atoi(argv) < 0 && argv[0] != '-')
		|| (ft_atoi(argv) > 0 && argv[0] == '-'))
		return (-1);
	while (i < ft_strlen(argv))
	{
		if (ft_isdigit(argv[i]) == 1 || (i == 0 && argv[i] == '-'))
			i++;
		else
			return (-1);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if ((unsigned char)s1[i] == (unsigned char)s2[i])
		return (0);
	else
		return (-1);
}

int	ft_check_double(char **argv, char *str, int argc)
{
	int	i;
	int	indicator;

	indicator = 1;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(str) == ft_strlen(argv[i]))
		{
			if (ft_strcmp(str, argv[i]) != 0)
				i++;
			else
			{
				i++;
				indicator++;
				if (indicator > 2)
					return (-1);
			}
		}
		else
			i++;
	}
	return (0);
}
