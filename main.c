/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilyip <wilyip@42kl.student.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:29:30 by wilyip            #+#    #+#             */
/*   Updated: 2026/04/19 16:17:37 by bokgoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		parse_input(char *str, int *clues, int n);
int		solve(int **grid, int *clues, int pos, int n);
void	print_grid(int **grid, int n);

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	get_n(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			count++;
		i++;
	}
	if (count % 4 != 0 || count == 0)
		return (0);
	return (count / 4);
}

int	**allocate_grid(int n)
{
	int	**grid;
	int	row;
	int	col;

	grid = (int **)malloc(sizeof(int *) * n);
	row = 0;
	while (row < n)
	{
		grid[row] = (int *)malloc(sizeof(int) * n);
		col = 0;
		while (col < n)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	return (grid);
}

void	free_all(int **grid, int *clues, int n)
{
	int	i;

	i = 0;
	if (grid)
	{
		while (i < n)
		{
			free(grid[i]);
			i++;
		}
		free(grid);
	}
	if (clues)
		free(clues);
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;
	int	n;

	if (argc != 2)
		return (ft_error());
	n = get_n(argv[1]);
	if (n == 0)
		return (ft_error());
	clues = (int *)malloc(sizeof(int) * (n * 4));
	if (parse_input(argv[1], clues, n) == 0)
	{
		free(clues);
		return (ft_error());
	}
	grid = allocate_grid(n);
	if (solve(grid, clues, 0, n) == 1)
		print_grid(grid, n);
	else
		ft_error();
	free_all(grid, clues, n);
	return (0);
}
