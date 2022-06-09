# *********************************************** #
#      ____  ____ ___  ____ _____  ____ ______    #
#     / __ \/ __ `__ \/ __ `/ __ \/ __ `/ ___/    #
#    / /_/ / / / / / / /_/ / / / / /_/ / /        #
#    \____/_/ /_/ /_/\__,_/_/ /_/\__,_/_/         #
#                                                 #
#    Makefile                                     #
#    By: omanar <omanar@student.1337.ma>          #
#    Created: 2022/05/10 12:36:01 by omanar       #
#                                                 #
# *********************************************** #

NAME	=	philo_bonus
CC		=	gcc
RM		=	rm -f
SRCS	=	srcs/philo_bonus.c srcs/philo_utils.c srcs/ft_atoi.c srcs/simulation.c srcs/printer.c
OBJS	=	$(SRCS:.c=.o)

define HEADER_B
           __    _ __           __                          
    ____  / /_  (_) /___       / /_  ____  ____  __  _______
   / __ \/ __ \/ / / __ \     / __ \/ __ \/ __ \/ / / / ___/
  / /_/ / / / / / / /_/ /    / /_/ / /_/ / / / / /_/ (__  ) 
 / .___/_/ /_/_/_/\____/____/_.___/\____/_/ /_/\__,_/____/  
/_/                   /_____/                               
endef
export HEADER_B

all: header_b $(NAME)

header_b:
	@echo "\033[0;32m$$HEADER_B\033[0m\n"

%.o: %.c
	@ $(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[0;36m</ Compiling philo_bonus >\033[0m"
	@$(CC) -lpthread $(OBJS) -o $(NAME)
	@echo "\033[1;32mphilo_bonus has been compiled!\033[0m\n"

bonus: header_b $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@echo "\n\033[0;31m</ EVERYTHING HAS BEEN DELETED! >\033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus