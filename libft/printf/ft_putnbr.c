/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:58:29 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/16 17:12:51 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	char	result;
	long	number;

	number = (long)n;
	if (number < 0)
	{
		ft_putchar('-', count);
		if (*count == -1)
			return ;
		number = -number;
	}
	if (number > 9)
	{
		ft_putnbr(number / 10, count);
		if (*count == -1)
			return ;
	}
	result = (number % 10) + '0';
	ft_putchar(result, count);
	if (*count == -1)
		return ;
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	char	result;
	long	number;

	number = (long)n;
	if (number > 9)
	{
		ft_putnbr(number / 10, count);
		if (*count == -1)
			return ;
	}
	result = (number % 10) + '0';
	ft_putchar(result, count);
	if (*count == -1)
		return ;
}
