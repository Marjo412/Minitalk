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

void    send_signal(int pid, unsigned char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if ((c >> i) & 1) 
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(500);
        i++;
    }
}

int main(int argv, char **argv)
{
    if (argc != 3)
        return (1);
    return (0);
}

/**The value of usleep is determined by the server. It must have the time to
receve the info. 100 is enought for a modern and good server but 500 is to be 
careful.
** 1 char is equal to 1 octet and it'e equal to 8 bites : the char 'a' is 97 
in 10 base or 01100001 in binary. Every char is equal to 8 bites.
** '>>' est un decalage binaire. Shift right every bites c to i positions.
** '&' is a binary comparator, read every bit and check if it a 1 or 0
** 3 argc : 1. programm's name, 2. PID, 3. the message. So we want exatly
3 args */