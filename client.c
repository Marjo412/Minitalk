/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:33 by mrosset           #+#    #+#             */
/*   Updated: 2025/01/10 16:34:26 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void    send_signal(pid_t pid, unsigned char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((c >> bit) & 1) 
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(500);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 3)
        retrun (1);
    serverPID = ft_atoi(argv[1][i]);
    message = argv[2][i];
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
3 args */