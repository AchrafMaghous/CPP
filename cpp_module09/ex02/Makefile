NAME	=	PmergeMe
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf
CXX		=	c++

SRCS	=	main.cpp PmergeMe.cpp

OBJS	=	$(SRCS:.cpp=.o)

HEADER	=	PmergeMe.hpp

$(NAME)	:	$(OBJS) $(HEADER)
		@$(CXX) $(FLAGS) $(OBJS) -o $(NAME)


%.o:%.cpp $(HEADER)
	@$(CXX) $(FLAGS) -c $< -o $@
	@echo "compiling..."

all:	$(NAME)

clean	:
	@$(RM) $(OBJS)

fclean	: clean
	@$(RM) $(NAME)

re	: fclean all

.PHONY: all clean fclean re