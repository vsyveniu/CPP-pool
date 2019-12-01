NAME   = megaphone

SRC	 =  megaphone.cpp

CPPC = clang++ -std=c++11

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 $(CPPC) $(OBJ) $(FLAGS) -o $(NAME)
	 @echo "\x1b[36m$(NAME)\x1b[0;32m OK \033[0m"

%.o: %.cpp
	$(CPPC) $(FLAGS) -c -o $@ $<


clean:
	@echo "\x1b[0;32mClean \x1b[36m $(OBJ) \x1b[0;32m --->\033[0m"
	rm -f $(OBJ)


fclean: clean
	@echo "\x1b[0;32mFClean \x1b[36m $(NAME) \x1b[0;32m --->\033[0m"
	rm -f $(NAME)

re: fclean all

.PHONY: re, all, clean, fclean

