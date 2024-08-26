/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:04:49 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/26 20:59:33 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bny_to_ascii(char *s)
{
	int				pow;
	unsigned char	c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	write(1, &c, 1);
}

static void	bits_to_byte(int sig)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_putchar_str(bits, '0');
	else
		bits = ft_putchar_str(bits, '1');
	if (bitcount == 8)
	{
		bny_to_ascii(bits);
		free(bits);
		bits = NULL;
	}
}

int	main(void)
{
	ft_printf("<-->Server PID: [%u]<-->\n", getpid());
	while (1 == 1)
	{
		signal(SIGUSR1, bits_to_byte);
		signal(SIGUSR2, bits_to_byte);
		pause();
	}
	return (0);
}
