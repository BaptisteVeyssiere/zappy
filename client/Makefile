##
## Makefile for client_ia in /home/vigner_g/rendu/PSU_2016_zappy/client
##
## Made by vigner_g
## Login   <vigner_g@epitech.net>
##
## Started on  Tue Jun 27 17:24:20 2017 vigner_g
## Last update Sat Jul  1 23:56:09 2017 vigner_g
##

NAME		= zappy_ai

RM		= rm -f

CXX		= g++

CXXFLAGS	= -W -Wall -Wextra -std=c++14 -I./include/ -Weffc++ -g

MKDIR		= mkdir -p

SRC		= src/C_broadcast.cpp \
		  src/C_Eject.cpp \
		  src/C_Fork.cpp \
		  src/C_Forward.cpp \
		  src/C_incantation.cpp \
		  src/C_inventory.cpp \
		  src/C_PlayerConnected.cpp \
		  src/C_Set.cpp \
		  src/C_Take.cpp \
		  src/C_TurnRight.cpp \
		  src/C_TurnLeft.cpp \
		  src/C_Look.cpp \
		  src/Client.cpp \
		  src/CommandBuffer.cpp \
		  src/CommandManager.cpp \
		  src/Inventory.cpp \
		  src/main.cpp \
		  src/Map.cpp \
		  src/Network.cpp \
		  src/Parser.cpp \
		  src/Player.cpp \
		  src/SignalManager.cpp \
		  src/IA.cpp \
		  src/Exploration.cpp \
		  src/Regroup.cpp \
		  src/Elevation.cpp

SRCDIR		= src

OBJDIR		= obj

OBJ		= $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(NAME): $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ)
	@echo "Linking complete!"

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(MKDIR) $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" sucessfully!"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "Cleanup complete!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
