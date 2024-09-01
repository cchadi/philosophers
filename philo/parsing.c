#include "philosophers.h"

t_global *parsing(char **av)
{
    int i;
    int nbr;
    t_global *philo;
    
    philo = malloc(sizeof(t_global));
    i = 1;
    while(av[i])
    {
        nbr = ft_atoi(av[i]);
        if (nbr != -1 && nbr >= 0 && i < 5)
            i++;
        else if (nbr != -1 && nbr > 0 && i == 5)
            i++;
        else
            return (NULL);
    }
    philo->n_philo = ft_atoi(av[1]);
    philo->t_die = ft_atoi(av[2]);
    philo->t_eat = ft_atoi(av[3]);
    philo->t_sleep = ft_atoi(av[4]);
    if (av[5])
        philo->nbr_to_eat = ft_atoi(av[5]);
    return (philo);
}
