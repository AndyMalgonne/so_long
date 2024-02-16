/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:10:58 by amalgonn          #+#    #+#             */
/*   Updated: 2024/01/10 14:34:20 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	putnbr_base(unsigned long nbr, char *base)
{
	int				size_base;
	int				i;

	size_base = 0;
	i = 1;
	while (base[size_base])
		size_base++;
	if (nbr / size_base)
		i += putnbr_base(nbr / size_base, base);
	ft_putchar_fd(base[nbr % size_base], 1);
	return (i);
}

int	print_ptr(unsigned long nbr, char *base)
{
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (putnbr_base(nbr, base) + 2);
}
