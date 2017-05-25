/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:49:55 by dhervy            #+#    #+#             */
/*   Updated: 2015/11/28 21:30:03 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if ((c >= 0060 && c <= 0071) || (c >= 0101 && c <= 0132) || \
		(c >= 0141 && c <= 0172))
	{
		return (1);
	}
	else
		return (0);
}
