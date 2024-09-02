#include "philosophers.h"

void init_chopsticks(t_philo *head)
{
    t_philo *tmp;
    int flag;

    flag = 1;
    tmp = head;
    while ((head != tmp) || flag == 1)
    {
        flag = 0;
        pthread_mutex_init(&head->chopstick, NULL);
        pthread_mutex_init(&head->deadlock, NULL);
        head = head->next;
    }
    return;
}

void create_threads(t_philo *philo)
{
    t_philo *checker;
    t_philo *tmp;
    t_philo *head;
    int flag;

    flag = 1;
    tmp = philo;
    head = philo;
    while ((head != tmp) || flag == 1)
    {
        flag = 0;
        pthread_create(&head->philo, NULL, (void *)&routine, head);
        usleep(500);
        head = head->next;
    }
    flag = 1;
    while ((head != tmp) || flag == 1)
    {
        flag = 0;
        pthread_detach(head->philo);
        head = head->next;
    }
    checker = lst_new(NULL, -5);
    pthread_create(&checker->philo, NULL, (void *)&checking, head); 
    pthread_join(checker->philo, NULL);
    printf("finish\n");
    return;
}

void ft_start(t_global *g)
{
    t_philo *head;

    if (!g)
        return;
    head = linked_list(g);
    init_chopsticks(head);
    create_threads(head);
}
