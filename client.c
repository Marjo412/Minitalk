/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:57:55 by mrosset           #+#    #+#             */
/*   Updated: 2025/01/24 10:02:52 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp;

	i = 8;
	temp = c;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_printf("Invalid server PID\n");
			return (1);
		}
		message = argv[2];
		while (*message)
		{
			send_signal(server_pid, *message);
			message++;
		}
		send_signal(server_pid, '\0');
	}
	else
		ft_printf("You have to do: %s <server_pid> <message>\n", argv[0]);
	return (0);
}

/**The value of usleep is determined by the server. It must have the time to
receve the info. 100 is enought for a modern and good server but 500 is to be 
careful.
** 1 char is equal to 1 octet and it'e equal to 8 bites : the char 'a' is 97 
in 10 base or 01100001 in binary. Every char is equal to 8 bites.
** '>>' est un decalage binaire. Shift right every bites c to i positions.
** '&' is a binary comparator, read every bit and check if it a 1 or 0.
** '|' is a binary comparator, it compare if two bites and check if it the
same or different. return (1) if it's true or return (0)
** 3 argc : 1. programm's name, 2. PID, 3. the message. So we want exatly
3 args 
** To compile the project : make
gcc -Wall -Wextra -Werror server.c -o server -Llibft -lft 
-Lft_printf -lftprintf
gcc -Wall -Wextra -Werror client.c -o client -Llibft -lft 
-Lft_printf -lftprintf
open one terminal for the server and one for the client
./server "PID"
./client "PID" "Message"
*/