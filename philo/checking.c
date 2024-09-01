#include "philosophers.h"

int    checking(t_philo *philo)
{
    t_philo *head;

    head = philo;
    while(1)
    {
        if (head->is_dead == 1)
        {
            printf("philo[%d] is dead\n", head->id);
            break;
        }
        head = head->next;
    }
    return (0);
}
