/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:02:53 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/16 10:10:09 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	index;

	if (s != 0)
	{
		index = 0;
		while (s[index] != '\0')
		{
			s[index] = '\0';
			index++;
		}
	}
}
