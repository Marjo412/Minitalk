/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:40 by mrosset           #+#    #+#             */
/*   Updated: 2025/01/10 15:07:26 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
 
 void   handle_signal(signal)
 {
   static char c;
   static int  bit;

   c = c | (signal == SIGUSR1);
   bit++;
   if (bit == 8)
   {
      bit = 0;
      if ()
         ft_printf ("\n");
      else
         ft_printf("%c", c);
   }
 }

 int    main (void)
 {
    return (0);
 }