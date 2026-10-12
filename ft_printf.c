/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 10:55:33 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/09 15:59:48 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexadecimal(void *ds, char *base)
{
	unsigned long	hex;
	char			solution[16];
	int				i;
	int				j;

	i = 0;
	hex = (unsigned long) ds;
	if (!hex)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (hex > 0)
	{
		solution[i++] = base[hex % 16];
		hex = hex / 16;
	}
	j = i;
	write(1, "0x", 2);
	while ((i - 1) >= 0)
	{
		write(1, &solution[i - 1], 1);
		i--;
	}
	return (2 + j);
}

static int	control(const char *str, int c, va_list list)
{
	int	i;
	int	j;

	i = c;
	j = 0;
	if (str[i + 1] == 'c')
		j = ft_putchar_fd(va_arg(list, int), 1);
	if (str[i + 1] == '%')
		j = ft_putchar_fd('%', 1);
	if (str[i + 1] == 's')
		j = ft_putstr_fd(va_arg(list, char *), 1);
	if (str[i + 1] == 'p')
		j = hexadecimal(va_arg(list, void *), "0123456789abcdef");
	if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
		j = ft_putnbr_fd(va_arg(list, int), 1);
	if (str[i + 1] == 'u')
		j = ft_utoa(va_arg(list, unsigned int));
	if (str[i + 1] == 'x')
		j = ft_xhexa(va_arg(list, unsigned int), "0123456789abcdef");
	if (str[i + 1] == 'X')
		j = ft_xhexa(va_arg(list, unsigned int), "0123456789ABCDEF");
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		x;

	i = 0;
	x = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			x += control(str, i, list);
			i++;
		}
		else
			x += write(1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (x);
}

/*int	main(void)
{
char			s[] = "prueba string";
char			c = 'b';
int				d = 352;
int				i = 62813618;
unsigned int	u = 271827183;
unsigned int	x = 0123451167;
unsigned int	X = 0123451167;
void			*p = s;
int				h;
void			*a = NULL;

h = 0;
ft_printf("puntero nulo %s\n", (char *)a);
ft_printf("puntero nulo %p", (char *)a);
ft_printf("hacemos una prueba de un string que dice %s\n", s);
ft_printf("el char tiene que ser b y es %c\n", c);
ft_printf("el decimal con d tiene que ser 352 y es %d\n", d);
ft_printf("el decimal con i tiene que ser 62813618 y es %i\n", i);
ft_printf("el unsigned con u tiene que ser 271827183 y es %u\n", u);
ft_printf("el hexasecimal x es %x\n", x);
ft_printf("el hexadecimal X es %X\n", X);
ft_printf("el puntero es %p\n", p);
h = ft_printf("esto son 23 caracteres\n");
ft_printf("%d\n", h);
h = ft_printf("el unsigned con u tiene que ser 271827183 y es %u\n", u);
ft_printf("ahora tiene que darme 57 %d\n", h);
printf("hacemos una prueba de un string que dice %s\n", s);
printf("el char tiene que ser b y es %c\n", c);
printf("el decimal con d tiene que ser 352 y es %d\n", d);
printf("el decimal con i tiene que ser 62813618 y es %i\n", i);
printf("el unsigned con u tiene que ser 27182718378 y es %u\n", u);
printf("el hexasecimal x es %x\n", x);
printf("el hexadecimal X es %X\n", X);
printf("el puntero es %p\n", p);
printf("puntero nulo %s\n", (char *)a);
printf("puntero nulo %p", (char *)a);
return (0);
}*/
