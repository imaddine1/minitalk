# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharile <iharile@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 15:49:20 by iharile           #+#    #+#              #
#    Updated: 2021/12/23 16:10:32 by iharile          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = server client
CFLAGS = -Wall -Wextra -Werror

all : $(OBJ)

% : %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean

re : fclean all