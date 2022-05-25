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

NAME	=	philo
CC		=	gcc
RM		=	rm -f
SRCS	=	philo.c ft_atoi.c
OBJS	=	$(SRCS:.c=.o)

define HEADER_M
           __    _ __                       __                  
    ____  / /_  (_) /___  _________  ____  / /_  ___  __________
   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/
  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) 
 / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  
/_/                              /_/                            
endef
export HEADER_M

all: header_m $(NAME)

header_m:
	@echo "\033[0;32m$$HEADER_M\033[0m\n"

%.o: %.c
	@ $(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[0;36m</ Compiling Philosophers >\033[0m"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\033[1;32mPhilosophers has been compiled!\033[0m\n"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@echo "\n\033[0;31m</ EVERYTHING HAS BEEN DELETED! >\033[0m\n"

re: fclean all

.PHONY: all clean fclean re