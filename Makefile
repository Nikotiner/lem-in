C = src/lem_in.c src/link_handle.c src/link_validation.c src/params_handle.c src/memory_handle.c src/array_handle.c src/logic.c src/output_handle.c src/room_handle.c src/room_validation.c src/utils.c src/validation.c get_next_line/get_next_line.c
OBJECTS = *.o
INCLUDES = ./includes
NAME = lem-in

all: $(NAME)

$(NAME):
	cd ./ft_printf && make
	gcc -Wextra -Wall -Werror -c $(C) -I $(INCLUDES)
	gcc -Wextra -Wall -Werror -o $(NAME) $(OBJECTS) -L./ft_printf -lftprintf
clean:
	rm -f $(OBJECTS)
	cd ./ft_printf && make clean

fclean: clean
	rm -f $(NAME)
	cd ./ft_printf && make fclean

re: fclean all