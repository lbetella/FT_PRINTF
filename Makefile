NAME = libftprintf.a
CC = gcc # compilator
CFLAGS = -Wall -Wextra -Werror #flagsto use when compila

# list of all the sources files
SRCS = 	ft_itoa.c \
	ft_printf.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_utoa.c \
	ft_xhexa.c \

# OBJS name of the variable to creat to put the list of file objects (.o)
#so we take form SRCS all the file .c and create a list of the same file name but with .o

OBJS = $(SRCS:.c=.o)

# to pack all the files in the .a we use ar(archiver) r(replace) to insert all the file in the archiver .a 
# c(create) to creat the file .a - s (symbol index) to generate symbol index to make the enlace moro faster

AR = ar rcs

# to create all the objects files we use the following comand;the -c say to only compile the object file
# $< is teh first prerequisites (the .c file) $@ represnt the target (the .o file)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# The rule to compile everithing, if we write just "make" in the terminal this rule run

all: $(NAME)

# rule to create the library and creat the .a

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# RM is remove and -f mean (to force) so this comand erase whitout ask permission and with no error message

RM = rm -f

# rule to erase all the .o file created

clean:
	$(RM) $(OBJS)

# rule to erase all the .o file created and also the library file .a
fclean: clean
	$(RM) $(NAME)

# rule to erase everithing and compile again from zero

re: fclean all

# to indicate to the makefile that this words are action and not name of file
.PHONY: all clean fclean re
