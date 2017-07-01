##
## Makefile for 42sh in /home/VEYSSI_B/rendu/tek2/PSU/PSU_2016_myftp/
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Wed May 18 21:26:30 2016 Baptiste veyssiere
##

NAME	= zappy

SERVEUR	= zappy_server

CLIENT	= zappy_ai

CDIR	= client/

SDIR	= serveur/

$(NAME): $(SERVEUR) $(CLIENT)

$(SERVEUR):
	$(MAKE) -C serveur/

$(CLIENT):
	$(MAKE) -C client/

all: $(NAME)

clean:
	$(MAKE) -C $(SDIR) clean
	$(MAKE) -C $(CDIR) clean

fclean:
	$(MAKE) -C $(SDIR) fclean
	$(MAKE) -C $(CDIR) fclean

re: fclean all

.PHONY: all clean fclean re
