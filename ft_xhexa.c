/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_xhexa.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/08 18:00:54 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/09 16:00:06 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xhexa(unsigned int n, char *x)
{
	int		j;
	char	s;

	j = 0;
	s = x[n % 16];
	if (n >= 16)
		j += ft_xhexa(n / 16, x);
	j += write(1, &s, 1);
	return (j);
}
