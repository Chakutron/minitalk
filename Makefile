# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 15:15:55 by mchiboub          #+#    #+#              #
#    Updated: 2023/04/11 14:36:28 by mchiboub         ###   ########.fr        #
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

GREEN = \033[0;32m
NC = \033[0m

all: ${CLIENT} ${SERVER}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${SERVER}: ${OBJSERV}
		@echo "Generating ${GREEN}SERVER${NC} executable.."
		@make -sC ${PRINTFDIR} all
		@${CC} -o ${SERVER} ${OBJSERV} ${PRINTFDIR}/${LIBNAME}

${CLIENT}: ${OBJCLIENT}
		@echo "Generating ${GREEN}CLIENT${NC} executable.."
		@make -sC ${PRINTFDIR} all
		@${CC} -o ${CLIENT} ${OBJCLIENT} ${PRINTFDIR}/${LIBNAME}
clean:
		@echo "Deleting object files.."
		@rm -f ${OBJCLIENT} ${OBJSERV}
		@make -sC ${PRINTFDIR} clean

fclean: clean
		@echo "Deleting object & executable files.."
		@rm -f ${SERVER} ${CLIENT}
		@make -sC ${PRINTFDIR} fclean

re: fclean all
