#include "philosophers.h"

void    to_sleep(t_philo *philo)
{
    if (philo->philo_eat == philo->info->nbr_to_eat)
        return ;
    print_msg(philo, "is sleeping");
    usleep(philo->info->t_sleep * 1000);
    print_msg(philo, "is thinking");
    usleep(100);
}

void    to_eat(t_philo *philo)
{
    if (philo->philo_eat == philo->info->nbr_to_eat)
    {
        pthread_mutex_lock(&philo->dead_flag);
        philo->is_dead = 2;
        pthread_mutex_unlock(&philo->dead_flag);
        return ;
    }
    if (is_dead(philo) == 0)
    {
        pthread_mutex_lock(&philo->chopstick);
        print_msg(philo, "has taken one fork");
        pthread_mutex_lock(&philo->next->chopstick);
        print_msg(philo, "has taken one fork");
        print_msg(philo, "is eating");
        usleep(philo->info->t_eat * 1000);
        pthread_mutex_unlock(&philo->chopstick);
        pthread_mutex_unlock(&philo->next->chopstick);
        philo->philo_eat++;
        pthread_mutex_lock(&philo->eat_flag);
        philo->last_eat = get_current();
        pthread_mutex_unlock(&philo->eat_flag);
    }
    else
    {
        pthread_mutex_lock(&philo->dead_flag);
        philo->is_dead = 1;
        pthread_mutex_unlock(&philo->dead_flag);
        return ;
    }
}

void    *routine(t_philo *philo)
{
    printf("philo[%d] enter to routine\n", philo->id);
    while(1)
    {
        to_eat(philo);
        to_sleep(philo);
    }
    return (NULL);
}
