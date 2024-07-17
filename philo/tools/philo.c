#include "philo.h"

int main(int ac, char **av)
{
    t_philo *philo;

    if (ac >= 6 && ac <= 7)
    {
        if (check_args(av, &philo) != -1)
        {
            
        }

    }
    write(2, "invalid arguments!", 19);
    return (0);
}