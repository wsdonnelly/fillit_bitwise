/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:35:00 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/19 14:38:20 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**check_connection function:
**
**This function in the validate function's loop will iterate through
**on each individual grid, and check/count is there 6 or 8 connection
**as that's the two option what the given tetriminos can have only.
*/

static int	check_connection(char *str, int i)
{
	int	connections;

	connections = 0;
	if (i >= 1 && str[i - 1] == '#')
	{
		connections++;
	}
	if (i < 19 && str[i + 1] == '#')
	{
		connections++;
	}
	if (i >= 5 && str[i - 5] == '#')
	{
		connections++;
	}
	if (i < 15 && str[i + 5] == '#')
	{
		connections++;
	}
	return (connections);
}

/*
**validate function:
**
**The validate function, as from it's name coming also,
**validating is the individual piece of grid proper one or no.
**In the while loop we filtering out all the possible errors,
**and counting the maximum connections and tetrimino pieces,
**by calling the check_connection function.
**If everything went as supposed, we adding the piece to the add_tetri funnction.
*/

static int	validate(char *str, t_tetri *tetri, int *count)
{
	int	i;
	int	hash_counter;
	int	total_connections;

	hash_counter = 0;
	total_connections = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4 && (str[i] != '#' && str[i] != '.'))
			return (0);
		else if (i % 5 == 4 && str[i] != '\n')
			return (0);
		if (str[i] == '#' && ++hash_counter < 5)
			total_connections += check_connection(str, i);
		i++;
	}
	if (total_connections < 6 || hash_counter != 4 || *count > 25)
		return (0);
	else
	{
		add_tetri(tetri + *count, str, count);
		(*count)++;
	}
	return (1);
}

/*
**reader function:
**
**In the reader function, first we handling the posibble errors
**then we read through the given file, and validating it,
**is it correct or no.
*/

int	reader(int fd, t_tetri *tetri, int *count)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		ret;
	ssize_t		ret_copy;

	ret = read(fd, &buffer, BUFF_SIZE);
	if (ret == -1 || ret == 0 || fd == -1)
		return (0);
	while (ret)
	{
		ret_copy = ret;
		if ((ret == 21 && buffer[20] != '\n') || ret == -1)
			return (0);
		buffer[ret] = '\0';
		if (!(validate(buffer, tetri, count)))
			return (0);
		ret = read(fd, &buffer, BUFF_SIZE);
		if (ret_copy == 21 && ret == 0)
			return (0);
	}
	return (1);
}
