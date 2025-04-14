/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:19:07 by lomajeru          #+#    #+#             */
/*   Updated: 2023/12/26 15:17:48 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *s)
{
	int		i;
	double	nb;
	int		sign;
	double	div;

	i = 0;
	nb = 0;
	sign = 1;
	div = 0.1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign *= -1;
	while (ft_isdigit(s[i]))
		nb = nb * 10.0 + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		nb += ((s[i++] - '0') * div);
		div *= 0.1;
	}
	if (s[i])
		return (42);
	return (nb * sign);
}
