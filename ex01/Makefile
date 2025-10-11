CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook
DEPS = PhoneBook.hpp Contact.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# CPP = c++
# CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# SRCS = main.cpp PhoneBook.cpp Contact.cpp
# OBJS = $(SRCS:.cpp=.o)
# NAME = phonebook

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

# PhoneBook.o: PhoneBook.cpp PhoneBook.hpp Contact.hpp
# Contact.o: Contact.cpp Contact.hpp
# main.o: main.cpp PhoneBook.hpp Contact.hpp

# %.o: %.cpp
# 	$(CPP) $(CPPFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re