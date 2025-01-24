/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:58:00 by mrosset           #+#    #+#             */
/*   Updated: 2025/01/24 09:58:14 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	handle_signal(int signal)
{
	static char	c;
	static int	bit;

	c |= (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			ft_printf ("\n");
		else
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("Server PID is: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
