#include "../philosophers.h"

long    get_current()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == 0)
        return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    else
        perror("gettimeofday");
    return (-1);
}

int is_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->eat_flag);
    if ((get_current() - philo->last_eat) > philo->info->t_die)
    {
        pthread_mutex_unlock(&philo->eat_flag);
        return (1);
    }
    pthread_mutex_unlock(&philo->eat_flag);
    return (0);
}

void    print_msg(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->dead_flag);
    if (philo->is_dead == 0)
    {
        printf("%ld %d %s\n",(get_current() - philo->info->start), philo->id, msg);
    }
    pthread_mutex_unlock(&philo->dead_flag);
    return ;
}