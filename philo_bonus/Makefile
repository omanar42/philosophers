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
PHILOBN	=	philo_bonus
CC		=	gcc
RM		=	rm -f

SRCS	=	philo/philo.c philo/atoi.c
OBJS	=	$(SRCS:.c=.o)
SRCSBN	=	
OBJSBN	=	$(SRCSBN:.c=.o)

define HEADER_M
           __    _ __                       __                  
    ____  / /_  (_) /___  _________  ____  / /_  ___  __________
   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/
  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) 
 / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  
/_/                              /_/                            
endef
export HEADER_M

define HEADER_B
           __    _ __           __                          
    ____  / /_  (_) /___       / /_  ____  ____  __  _______
   / __ \/ __ \/ / / __ \     / __ \/ __ \/ __ \/ / / / ___/
  / /_/ / / / / / / /_/ /    / /_/ / /_/ / / / / /_/ (__  ) 
 / .___/_/ /_/_/_/\____/____/_.___/\____/_/ /_/\__,_/____/  
/_/                   /_____/                               
endef
export HEADER_B

all: header_m $(NAME)

header_m:
	@echo "\033[0;32m$$HEADER_M\033[0m\n"

header_b:
	@echo "\033[0;32m$$HEADER_B\033[0m\n"

%.o: %.c
	@ $(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[0;36m</ Compiling Philosophers >\033[0m"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\033[1;32mPhilosophers has been compiled!\033[0m\n"

$(PHILOBN): $(OBJSBN)
	@echo "\033[0;36m</ Compiling philo_bonus >\033[0m"
	@$(CC) $(OBJSBN) -o $(PHILOBN)
	@echo "\033[1;32mphilo_bonus has been compiled!\033[0m\n"

bonus: header_b $(PHILOBN)

clean:
	@$(RM) $(OBJS) $(OBJSBN)

fclean: clean
	@$(RM) $(PHILOBN)
	@echo "\n\033[0;31m</ EVERYTHING HAS BEEN DELETED! >\033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus