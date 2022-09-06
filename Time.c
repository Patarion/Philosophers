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
