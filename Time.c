#include "Philo.h"

long long int get_time()
{
    struct timeval  temps;
    long long int   ms_temps;

    gettimeofday(&temps, NULL);
    temps.tv_sec = temps.tv_sec * 1000;
    temps.tv_usec = temps.tv_usec / 1000;
    ms_temps = temps.tv_sec + temps.tv_usec;
    return(ms_temps);
}

void    smart_sleep(long long time, t_data *data)
{
    long long int   c_time;

    c_time = get_time();
    while(data->is_dead != true)
    {
        if ((c_time - get_time()) >= time)
            break ;
        usleep(50);
    }
}