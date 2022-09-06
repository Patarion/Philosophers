#include "Philo.h"

void erreur_case(int erreur_num, int arg_num)
{
    if (erreur_num == 1)
    {
        printf("Le nombre d'argument est invalide\n");
        printf("Veuillez en fournir entre 4 et 5\n");
    }
    else if (erreur_num == 2)
        printf("L'argument suivant contient des caractères invalides : %d\n", arg_num);
    else if (erreur_num == 3)
        printf("L'argument suivant est hors interger : %d\n", arg_num);
    else if (erreur_num == 4)
        printf("L'argument suivant est nul ou négatif : %d\n", arg_num);
    else if (erreur_num == 5)
        printf("Une erreur innatendue est survenue\n");
    else if (erreur_num == 6)
        printf("Le nombre de philosophe est invalide\n");
    exit(EXIT_FAILURE);
}