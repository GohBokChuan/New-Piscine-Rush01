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

int		parse_input(char *str, int *clues);
int		solve(int grid[4][4], int *clues, int pos);
void	print_grid(int grid[4][4]);

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (argc == 2 && parse_input(argv[1], clues) && solve(grid, clues, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
