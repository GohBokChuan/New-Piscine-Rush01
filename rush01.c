/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokgoh <bokgoh@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:06:10 by bokgoh            #+#    #+#             */
/*   Updated: 2026/04/19 16:08:51 by bokgoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_all_clues(int grid[4][4], int clues[16]);

int	parse_input(char *str, int *clues)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			clues[count] = str[i] - '0';
			count++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (count == 16)
		return (1);
	return (0);
}

int	check_double(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	print_grid(int grid[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	solve(int grid[4][4], int clues[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_all_clues(grid, clues));
	row = pos / 4;
	col = pos % 4;
	num = 0;
	while (++num <= 4)
	{
		if (check_double(grid, row, col, num) == 1)
		{
			grid[row][col] = num;
			if (solve(grid, clues, pos + 1) == 1)
				return (1);
			grid[row][col] = 0;
		}
	}
	return (0);
}
