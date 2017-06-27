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

CC	= gcc -g

MKDIR	= mkdir -p

SRC	= src/writes.c \
	src/init_server.c \
	src/main_loop.c \
	src/init_data.c \
	src/main.c \
	src/prints.c \
	src/get_args.c \
	src/signal_manager.c \
	src/check_sockets.c \
	src/free_data.c \
	src/check_team_wish.c \
	src/add_player.c \
	src/update_player_action.c \
	src/free_tools.c \
	src/update_status.c \
	src/send_basic_info.c \
	src/init_graphic.c \
	src/graphic_init_cmd.c \
	src/graphic_command.c \
	src/update_player_status.c \
	src/get_command_duration.c \
	src/action_move.c \
	src/action_look.c \
	src/action_connect.c \
	src/action_item.c \
	src/incantation.c \
	src/incantation2.c \
	src/action_broadcast.c \
	src/execute_actions.c

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
