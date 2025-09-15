
# Compiler
CPP = c++
# Flags
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources
SRCS = Account.cpp
# Objects
OBJS = $(SRCS:.cpp=.o)
# Executable name
NAME = account

# Default target
all: $(NAME)

# Link
$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

# Compile
%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove objects and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re