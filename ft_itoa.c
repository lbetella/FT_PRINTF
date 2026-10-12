/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 12:24:11 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/09 15:59:31 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	newn;
	char	*result;

	newn = n;
	i = ft_counter(newn);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (newn < 0)
	{
		result[0] = '-';
		newn = -newn;
	}
	while (i > (n < 0))
	{
		result[i - 1] = (newn % 10) + '0';
		newn = newn / 10;
		i--;
	}
	return (result);
}
