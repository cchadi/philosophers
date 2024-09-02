#include "philosophers.h"

int    checking(t_philo *philo)
{
    t_philo *head;

    head = philo;
    while(1)
    {
        pthread_mutex_lock(&head->deadlock);
        if (head->is_dead == 1)
        {
            break;
        }
        pthread_mutex_unlock(&head->deadlock);
        head = head->next;
    }
    return (0);
}
