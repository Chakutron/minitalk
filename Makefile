# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 15:15:55 by mchiboub          #+#    #+#              #
#    Updated: 2023/04/08 18:26:50 by mchiboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libftprintf.a

SERVER = server

CLIENT = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PRINTFDIR = printf

SRCSERV = server.c utils.c

SRCCLIENT = client.c utils.c

OBJSERV = ${SRCSERV:.c=.o}
	  
OBJCLIENT = ${SRCCLIENT:.c=.o}

all: ${CLIENT} ${SERVER}

${SERVER}: ${OBJSERV}
		cd ${PRINTFDIR}	&& make
		${CC} -o ${SERVER} ${OBJSERV} ${PRINTFDIR}/${LIBNAME}

${CLIENT}: ${OBJCLIENT}
		cd ${PRINTFDIR} && make
		${CC} -o ${CLIENT} ${OBJCLIENT} ${PRINTFDIR}/${LIBNAME}
clean:
	rm -f ${OBJCLIENT} ${OBJSERV}
	cd ${PRINTFDIR} && make clean

fclean: clean
	rm -f ${SERVER} ${CLIENT}
	cd ${PRINTFDIR} && make fclean

re: fclean all
