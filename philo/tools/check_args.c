#include "philo.h"

int check_args(char **av, t_philo **philo)
{
    int i;
    int nbr;

    i = 1;
    while(av[i])
    {
        nbr = ft_atoi(av[i]);
        if (nbr != -1 && nbr >= 0 && i < 5)
            i++;
        else if (nbr != -1 && nbr > 0 && i == 5)
            i++;
        else
            return (-1);
    }
    (*philo)->n_philo = ft_atoi(av[1]);
    (*philo)->t_die = ft_atoi(av[2]);
    (*philo)->t_eat = ft_atoi(av[3]);
    (*philo)->t_sleep = ft_atoi(av[4]);
    if (av[5])
        (*philo)->nbr_to_eat = ft_atoi(av[5]);
    return (0);
}
