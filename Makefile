NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS		= ft_printf.c \
			ft_printf_flag_handler.c \
			ft_printf_conv_handler.c \
			ft_printf_conv_s.c \
			ft_printf_conv_p.c \
			ft_printf_conv_x.c \
			ft_printf_conv_u.c \
			ft_printf_conv_d_i.c \
			ft_printf_conv_c_else.c \
			ft_printf_ints.c
				

OBJS		= $(SRCS:.c=.o)
RM		= rm -f
LIBC		= ar -rcs
FLAGS		= -w -g3  #-Wall -Wextra -Werror -g3
INCS		= .
COMPILER	= gcc

.c.o:
	${COMPILER} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)

re: fclean all

bonus: all

test: all
	${COMPILER} ${FLAGS} $(NAME) ./tests/main_flo.c -L. $(SRC)
	./a.out

norm:
	norminette *.[ch]

.PHONY: all clean fclean re .c.o bonus
