#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_global
{
    int t_eat;
    int t_die;
    long start;
    int n_philo;
    int t_sleep;
    int nbr_to_eat;
}   t_global;

typedef struct s_philo
{
    int id;
    int is_dead;
    int philo_eat;
    long last_eat;
    pthread_t philo;
    t_global *info;
    pthread_mutex_t chopstick;
    pthread_mutex_t eat_flag;
    pthread_mutex_t dead_flag;
    struct s_philo *next;
}   t_philo;

/************************* Philo ****************************/

t_global    *parsing(char **av);
void        ft_start(t_global *g);
void        to_eat(t_philo *philo);
int         is_dead(t_philo *philo);
void        *routine(t_philo *philo);
void        to_sleep(t_philo *philo);


/*************************  Tools  **************************/

int		ft_atoi(const char *str);
t_philo	*lst_last(t_philo *node);
void    add_nextback(t_philo **head);
void    print_msg(t_philo *philo, char *msg);
void    lst_addback(t_philo **head, t_philo *new);
t_philo *lst_new(t_global *g, int id);
t_philo *linked_list(t_global *g);
int     checking(t_philo *philo);
long    get_current();

#endif