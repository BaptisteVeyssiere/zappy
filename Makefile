##
## Makefile for 42sh in /home/VEYSSI_B/rendu/tek2/PSU/PSU_2016_myftp/
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Wed May 18 21:26:30 2016 Baptiste veyssiere
##

SERVER	= zappy_server

RM	= rm -rf

CC	= gcc

MKDIR	= mkdir -p

SRC	= src/write_error.c \
	src/init_server.c \
	src/main_loop.c

SRCDIR	= src

OBJDIR	= obj

OBJ	= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CFLAGS	= -Iinclude -W -Wextra -Wall -Werror

$(SERVER): $(OBJ)
	@$(CC) -o $(SERVER) $(OBJ)
	@echo "Linking complete!"

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

all: $(SERVER)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJDIR)
	@echo "Cleanup complete!"

fclean: clean
	@$(RM) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
