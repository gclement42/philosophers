.PHONY:					all $(NAME) clear mkbuild clear clean fclean re sanitize

NAME					= philo

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= philo.h

DIR						=	src/
SRC						=	main.c
							
OBJECTS					= $(SRC:%.c=$(BUILD_DIR)%.o)

GCC						= cc
CFLAGS					= -Wall -Werror -Wextra
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)* Makefile
						@mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I/usr/include -O3 -c $< -o $@

all: 					clear mkbuild $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS)
						$(GCC) $(OBJECTS) -o $(NAME) -lreadline

sanit :					$(OBJECTS) 
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) -lreadline
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)

re:						fclean all
						$(MAKE) all