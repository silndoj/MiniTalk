/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:16:34 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/26 21:13:04 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg(int pid, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

static char	*str_to_bit(char *s, size_t i, size_t j)
{
	char	*bnary;
	int		c;
	int		bytes;

	i = ft_strlen(s);
	bnary = ft_calloc(i * 8 + 1, sizeof(char));
	if (bnary == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				bnary[ft_strlen(s) * 8 - j - 1] = '1';
			else
				bnary[ft_strlen(s) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (bnary);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("--Try -> $ ./client [PID] {Text to Send}--\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = str_to_bit(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("--Memory Issues Detected--\n");
		return (0);
	}
	send_msg(pid, bits);
	free(bits);
}
