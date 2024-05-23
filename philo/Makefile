NAME = philo
bonus_pgrm = philo_bonus

SRCS =	mandatory/main.c	mandatory/check_argument.c		mandatory/ft_atoi.c		mandatory/ft_strlen.c		mandatory/get_time.c	mandatory/print_msg.c\
		mandatory/routine.c		mandatory/take_forks.c		mandatory/initialize_philo.c	mandatory/initialize_data.c		mandatory/create_mutex.c\
		mandatory/create_threads.c\

SRCS_BNS =	bonus/main_bonus.c		bonus/check_argument_bonus.c	bonus/ft_atoi_bonus.c	bonus/take_care.c\
			bonus/initialize_data_bonus.c		bonus/initialize_philo_bonus.c		bonus/create_process.c\
			bonus/get_time_bonus.c		bonus/print_msg_bonus.c		bonus/create_semaphors.c	bonus/process.c\
			bonus/kill_all_process.c\

OBJS = ${SRCS:.c=.o}
OBJS_BNS = ${SRCS_BNS:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${bonus_pgrm}: ${OBJS_BNS}
	${CC} ${CFLAGS} ${OBJS_BNS} -o ${bonus_pgrm}
	

bonus:${bonus_pgrm}

clean:
	${RM} ${OBJS} ${OBJS_BNS}

fclean: clean
	${RM} ${NAME} ${bonus_pgrm}

re: fclean all

.PHONY: all clean fclean re