NAME = a.out
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp\
	 Bureaucrat.cpp\
	 AForm.cpp\
	 PresidentialPardonForm.cpp\
	 RobotomyRequestForm.cpp\
	 ShrubberyCreationForm.cpp
	
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[34m'$(NAME)'\033[0m is ready to execute!"
clean :
	rm -f $(OBJS) *_shrubbery

fclean: clean
	rm -f $(NAME) *_shrubbery

re: fclean all
