#include "philo.h"

int main(int ac, char **av)
{
    t_philo *philo;

    if (ac >= 5 && ac <= 6)
    {
        if (check_args(av, &philo) != -1)
        {
            ft_routine(philo);
        }

    }
    write(2, "invalid arguments!\n", 20);
    return (0);
}