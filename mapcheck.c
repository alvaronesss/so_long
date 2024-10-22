/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aporras- <aporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:16:22 by aporras-          #+#    #+#             */
/*   Updated: 2024/10/22 17:11:15 by aporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	ft_valid_format(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len > 4)
	{
		if (!ft_strncmp(&map_name[len - 4], ".ber", 4))
			return (1);
	}
	write(2, "cagaste\n", 9);
	return (0);
}

int	ft_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01CEP", map[i][j]))
				return (0);
			j++;
		}
		i++;

	}
	return (1);
}

int	ft_muros_y_rectangulo(char **map)
{
	int 	i;
	int		j;
	int		width;
	int		height;

	if (!map || !map[0])
		return (0);

	height = 0;
	while (map[height])
		height++;

	width = 0;
	while (map[0][width])
		width++;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_rectangulo(char **map)
{
	int	x;
	int	y;
	int	len;

	len = 0;
	while (map[0][len])
	{
		len++;
	}
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			x++;
		}
		if (x != len)
			return (1);
		y++;
	}
	return (0);
}

int	ft_one_character(char **map)
{
	int i;
	int j;
	int	c_count;
	int e_count;
	int	p_count; 

	i = 0;
	c_count = 0;
	e_count = 0;
	p_count = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c_count++;
			else if (map[i][j] == 'E')
				e_count++;
			else if (map[i][j] == 'P')
				p_count++;
			j++;
		}
		i++;
	}

	if (c_count < 1 || e_count != 1 || p_count != 1)
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (0);
}
