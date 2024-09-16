#include "philosophers.h"

int    checking(t_philo *philo)
{
    t_philo *head;

    printf("checker enter to checking\n");
    head = philo;
    while(1)
    {
        pthread_mutex_lock(&head->dead_flag);
        if (head->is_dead == 1)
        {
            printf("is dead\n");
            pthread_mutex_unlock(&head->dead_flag);
            break ;
        }
        else if (head->is_dead == 2)
        {
            pthread_mutex_unlock(&head->dead_flag);
            break ;
        }
        pthread_mutex_unlock(&head->dead_flag);
        head = head->next;
    }
    printf("checker exit from checking\n");
    return (0);
}
