NAME := avm

SRC_DIR := ./src/
INC_DIR := ./inc/
OBJ_DIR := ./obj/
INC_DIR := ./inc/

SRC := $(wildcard src/*.cpp)
OBJ = $(addprefix $(OBJ_DIR), $(SRC:src/%.cpp=%.o))
FLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ)
	g++ -std=c++11 $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)	

$(OBJ_DIR)%.o:%.cpp $(INC_DIR)*
	g++ -std=c++11 $(FLAGS) -I inc/ -c $< -o $@
clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
vpath %.cpp $(SRC_DIR)
