#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>


# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define MAX_PHILO 200

struct s_data;
struct s_philo;


typedef struct s_philo
{
    int             id_phil;
    int             nb_meals;
    int             id_l_fork;
    int             id_r_fork;
    long long int   t_last_meal;
    struct s_data  *data;
    pthread_t       id_thread;
}   t_philo;

typedef struct s_data
{
    int             nb_philo;
    int             time_die;
    int             time_eat;
    int             time_sleep;
    int             nb_eat;
    bool            is_dead;
    bool            rem_eat;
    int             rest_eat;
    long long int   init_time;
    t_philo   philo_data[MAX_PHILO];
    pthread_mutex_t mutex_fork[MAX_PHILO];
    pthread_mutex_t mutex_write;
    pthread_mutex_t mutex_eat;
}   t_data;

int             only_digit(char *arg, int arg_num);
int             is_int(char *arg, int arg_num);
int             to_int(char *arg, int arg_num);
int             is_valid(char *arg, int arg_num);
void            erreur_case(int erreur_num, int arg_num);
t_philo         init_data(int argc, char **argv);
void            init_philo(t_philo *philo);
long long int   get_time();

#endif