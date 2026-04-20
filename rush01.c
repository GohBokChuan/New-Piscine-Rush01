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

int	check_all_clues(int **grid, int *clues, int n);

int	parse_input(char *str, int *clues, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			clues[count] = str[i] - '0';
			count++;
		}
		else if (str[i] == ' ')
		{
		}
		else
		{
			return (0);
		}
		i++;
	}
	if (count == n * 4)
		return (1);
	else
		return (0);
}

int	check_double(int **grid, int pos, int num, int n)
{
	int	i;
	int	row;
	int	col;

	row = pos / n;
	col = pos % n;
	i = 0;
	while (i < n)
	{
		if (grid[row][i] == num)
		{
			return (0);
		}
		if (grid[i][col] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_grid(int **grid, int n)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < n - 1)
			{
				write(1, " ", 1);
			}
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	solve(int **grid, int *clues, int pos, int n)
{
	int	row;
	int	col;
	int	num;

	if (pos == n * n)
		return (check_all_clues(grid, clues, n));
	row = pos / n;
	col = pos % n;
	num = 1;
	while (num <= n)
	{
		if (check_double(grid, pos, num, n) == 1)
		{
			grid[row][col] = num;
			if (solve(grid, clues, pos + 1, n) == 1)
			{
				return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
