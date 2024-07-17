#include "philo.h"

int strict_check(t_philo *philo)
{
    if (philo->n_philo <= 0)
        return (-1);
    // add parsing check
    return (0);
}

int check_args(char **ptr, t_philo *philo)
{
    int i;
    int nbr;

    i = 1;
    while(ptr[i])
    {
        if (ft_atoi(ptr[i]) != -1 && ft_atoi(ptr[i]) >= 0)
            i++;
        else 
            return (-1);
    }
    philo->n_philo = ft_atoi(ptr[1]);
    philo->t_die = ft_atoi(ptr[2]);
    philo->t_eat = ft_atoi(ptr[3]);
    philo->t_sleep = ft_atoi(ptr[4]);
    if (ptr[5])
        philo->optionnel = ft_atoi(ptr[5]);
    if (strict_check(philo) == -1)
        return (-1);
    return (0);
}