/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilyip <wilyip@42kl.student.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 00:13:59 by wilyip            #+#    #+#             */
/*   Updated: 2026/04/19 16:02:57 by bokgoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int grid[4][4], int clues[16])
{
	int	col;
	int	row;
	int	max;
	int	count;

	col = -1;
	while (++col < 4)
	{
		row = -1;
		max = 0;
		count = 0;
		while (++row < 4)
		{
			if (grid[row][col] > max)
			{
				max = grid[row][col];
				count++;
			}
		}
		if (clues[col] != count)
			return (0);
	}
	return (1);
}

int	check_col_down(int grid[4][4], int clues[16])
{
	int	col;
	int	row;
	int	max;
	int	count;

	col = -1;
	while (++col < 4)
	{
		row = 4;
		max = 0;
		count = 0;
		while (--row >= 0)
		{
			if (grid[row][col] > max)
			{
				max = grid[row][col];
				count++;
			}
		}
		if (clues[4 + col] != count)
			return (0);
	}
	return (1);
}

int	check_row_left(int grid[4][4], int clues[16])
{
	int	row;
	int	col;
	int	max;
	int	count;

	row = -1;
	while (++row < 4)
	{
		col = -1;
		max = 0;
		count = 0;
		while (++col < 4)
		{
			if (grid[row][col] > max)
			{
				max = grid[row][col];
				count++;
			}
		}
		if (clues[8 + row] != count)
			return (0);
	}
	return (1);
}

int	check_row_right(int grid[4][4], int clues[16])
{
	int	row;
	int	col;
	int	max;
	int	count;

	row = -1;
	while (++row < 4)
	{
		col = 4;
		max = 0;
		count = 0;
		while (--col >= 0)
		{
			if (grid[row][col] > max)
			{
				max = grid[row][col];
				count++;
			}
		}
		if (clues[12 + row] != count)
			return (0);
	}
	return (1);
}

int	check_all_clues(int grid[4][4], int clues[16])
{
	if (check_col_up(grid, clues) == 1
		&& check_col_down(grid, clues) == 1
		&& check_row_left(grid, clues) == 1
		&& check_row_right(grid, clues) == 1)
	{
		return (1);
	}
	return (0);
}
