#include "philosophers.h"

int    is_dead(t_philo *philo)
{
    if ((get_current() - philo->last_eat) > philo->info->t_die)
        return (1);
    return (0);
}

void    to_sleep(t_philo *philo)
{
    pthread_mutex_lock(&philo->chopstick);
    printf("philo[%d] is sleeping\n", philo->id);
    pthread_mutex_unlock(&philo->chopstick);
    usleep(philo->info->t_sleep * 1000);
}

void    to_eat(t_philo *philo)
{
    if (philo->last_eat != 0 && is_dead(philo) == 1)
    {
        pthread_mutex_lock(&philo->deadlock);
        philo->is_dead = 1;
        printf("philo[%d] is dead\n", philo->id);
        pthread_mutex_unlock(&philo->deadlock);
    }
    else
    {
        printf("philo[%d] is thinking\n", philo->id);
        
        pthread_mutex_lock(&philo->chopstick);
        pthread_mutex_lock(&philo->next->chopstick);

        printf("philo[%d] is eating\n", philo->id);
        usleep(philo->info->t_eat * 1000);

        pthread_mutex_unlock(&philo->next->chopstick);
        pthread_mutex_unlock(&philo->chopstick);

        printf("philo[%d] Finished eating\n", philo->id);
        philo->last_eat = get_current();
    }
}

void    *routine(t_philo *philo)
{
    while(1)
    {
        to_eat(philo);
        to_sleep(philo);
    }
    return (NULL);
}
