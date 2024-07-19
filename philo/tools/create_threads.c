#include "philo.h"

void create_threads(int p_nbr)
{
    pthread_t t[p_nbr];
    int i;

    i = 0;
    while(i < (p_nbr))
    {
        pthread_create(&t[i], NULL, &ft_routine, NULL);
        i++;
    }
    i = 0;
    while(i < (p_nbr))
    {
        pthread_join(t[i], NULL);
        i++;
    }
}