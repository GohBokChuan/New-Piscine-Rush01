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
int	check_col_up(int **grid, int *clues, int n)
{
	int	col;
	int	row;
	int	max;
	int	count;

	col = -1;
	while (++col < n)
	{
		row = -1;
		max = 0;
		count = 0;
		while (++row < n)
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

int	check_col_down(int **grid, int *clues, int n)
{
	int	col;
	int	row;
	int	max;
	int	count;

	col = -1;
	while (++col < n)
	{
		row = n;
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
		if (clues[n + col] != count)
			return (0);
	}
	return (1);
}

int	check_row_left(int **grid, int *clues, int n)
{
	int	col;
	int	row;
	int	max;
	int	count;

	row = -1;
	while (++row < n)
	{
		col = -1;
		max = 0;
		count = 0;
		while (++col < n)
		{
			if (grid[row][col] > max)
			{
				max = grid[row][col];
				count++;
			}
		}
		if (clues[2 * n + row] != count)
			return (0);
	}
	return (1);
}

int	check_row_right(int **grid, int *clues, int n)
{
	int	col;
	int	row;
	int	max;
	int	count;

	row = -1;
	while (++row < n)
	{
		col = n;
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
		if (clues[3 * n + row] != count)
			return (0);
	}
	return (1);
}

int	check_all_clues(int **grid, int *clues, int n)
{
	if (check_col_up(grid, clues, n) == 0)
		return (0);
	if (check_col_down(grid, clues, n) == 0)
		return (0);
	if (check_row_left(grid, clues, n) == 0)
		return (0);
	if (check_row_right(grid, clues, n) == 0)
		return (0);
	return (1);
}
