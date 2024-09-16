#include "philosophers.h"

void create_threads(t_philo *philo)
{
    t_philo *checker;
    t_philo *head;
    t_philo *tmp;
    int     flag;

    tmp = philo;
    head = philo;
    flag = 1;

    while ((head != tmp) || flag == 1)
    {
        flag = 0;
        pthread_create(&head->philo, NULL, (void *)&routine, head);
        usleep(50);
        head = head->next;
    }
    head = philo;
    while ((head != tmp) || flag == 0)
    {
        flag = 1;
        pthread_detach(head->philo);
        usleep(50);
        head = head->next;
    }
    head = philo;
    checker = lst_new(NULL, -5);
    pthread_create(&checker->philo, NULL, (void *)&checking, head);
    pthread_join(checker->philo, NULL);
    return;
}

void ft_start(t_global *g)
{
    t_philo *head;

    if (!g)
        return;
    head = linked_list(g);
    g->start = get_current();
    create_threads(head);
}
