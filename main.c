#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char cne[20];
    char nom[40];
    char prenom[40];
    float notes[4];
    float moyenne;

} Etudient;
int recherch_par_cne(Etudient *e, int count, char mot[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(e[i].cne, mot) == 0)
        {
            return i;
        }
    }
    return -1;
}
// void Sort_by_cne(Etudient *e,int count,char cne[]){
//     for (int i = 0; i < count; i++)
//     {
//         for (int j = i+1; j < count; j++)
//         {
//             if(c){

//             }
//         }
        
//     }
    
// }
void Afficher_Etudients(Etudient *e, int count)
{
    printf("==================================================================================================================================\n");
    printf("#                                             Les Informations des etudients                                                     #\n");
    printf("==================================================================================================================================\n");
    printf("#        CNE        |        Nom        |        Prenom        |                               Notes                             #\n");
    for (int i = 0; i < count; i++)
    {
        printf("# %-18s| %-18s| %-14s       | ", e[i].cne, e[i].nom, e[i].prenom);
        for (int j = 0; j < 4; j++)
        {
            printf("note %d : %.2f", i + 1, e[i].notes[j]);
            if (j < 3)
                printf(", ");
        }
        printf("  #\n");
    }
    printf("==================================================================================================================================\n");
}

int validition_choix(char prompt[]){
    int choix;
    while (1)
    {
        printf("%s",prompt);
        if (scanf("%d",&choix) == 1)break;
        printf("S'il vous plait saisir le choix number regarder Menu \n");
        while (getchar()!='\n');
             
    }
    return choix;
    
}

void ajouterEtudiant(Etudient **e, int *size, int *count)
{
    if (*count >= *size)
    {
        *size *= 2;
        *e = realloc(*e, *size * sizeof(Etudient));
    }
    int stop = 1;
    while (stop)
    {
        printf("Saisir le CIN de etudient mais s'il vous plait le CIN unique : ");
        scanf("%s", (*e)[*count].cne);
        stop = 0;
        for (int i = 0; i < *count; i++)
        {
            if ((strcmp((*e)[*count].cne, (*e)[i].cne)) == 0)
            {
                printf("CNE deja exist s'il vous plait entre un autre cne diffirent\n");
                stop = 1;
                break;
            }
        }
        if (stop == 0)
        {
            printf("Saisir le nom de etudient : ");
            scanf("%s", (*e)[*count].nom);
            printf("Saisir le prenom de etudient ");
            scanf("%s", (*e)[*count].prenom);
            for (int i = 0; i < 4; i++)
            {
                (*e)[*count].notes[i] = 0;
            }

            (*count)++;
        }
    }
}
void supprimierEtduiant(Etudient **e, int *size, int *count)
{
    char cne[20];
    printf("S il vous plait saisir le CNE de l'etudiant qui Supprimier : ");
    scanf("%s", cne);
    int index = recherch_par_cne(*e, count, cne);
    for (int i = 0; i < *size; i++)
    {
        if ((*e)[i].cne == (*e)[index].cne)
        {
            printf("%s", (*e)[i].cne);

            for (int j = index; j < *size - 1; j++)
            {
                strcpy((*e)[j].cne, (*e)[j + 1].cne);
            }
            (*count)--;
            (*size) -= 2;
        }
    }
}
void modifierEtudient(Etudient **e, int count)
{
    char cne[20];
    printf("Saisir le CEN de etduident qui modfier : ");
    scanf("%s", &cne);
    int index = recherch_par_cne(*e, count, cne);
    for (int i = 0; i < count; i++)
    {
        if ((*e)[index].cne == (*e)[i].cne)
        {
            int choix;

            printf("\n===============================================================\n");
            printf("                      MENU PRINCIPAL                           \n");
            printf("===============================================================\n");
            printf("#  1 # Modifier le CNE                                         #\n");
            printf("#  2 # Modifier le Nom                                         #\n");
            printf("#  3 # Modifier le Prenom                                      #\n");
            printf("#  4 # Modifier les notes                                      #\n");
            printf("#  5 # Modifier Tout les informations                          #\n");
            printf("#  0 # Quitter                                                #\n");
            printf("===============================================================\n\n");
            printf("Saisir le choix qui change : ");
            scanf("%d", &choix);
            switch (choix)
            {
            case 1:
                printf("Saisir la nauvelle Cne de %s : ", (*e)[index].nom);
                scanf("%s", (*e)[index].cne);
                break;
            case 2:
                printf("Saisir la nauvelle Nom de %s : ", (*e)[index].nom);
                scanf("%s", (*e)[index].nom);
                break;
            case 3:
                printf("Saisir la nauvelle Cne de %s : ", (*e)[index].nom);
                scanf("%s", (*e)[index].prenom);
                break;
            case 4:
                for (int i = 0; i < 4; i++)
                {
                    printf("Saisir la nauvelle note %d de l etudient  %s : ", i + 1, (*e)[index].nom);
                    scanf("%f", &(*e)[index].notes[i]);
                }
                break;
            case 5:
                printf("Saisir la nauvelle Cne de %s : ", (*e)[index].cne);
                scanf("%s", (*e)[index].cne);
                printf("Saisir la nauvelle Nom de %s : ", (*e)[index].nom);
                scanf("%s", (*e)[index].nom);
                printf("Saisir la nauvelle Prenom de %s : ", (*e)[index].prenom);
                scanf("%s", (*e)[index].prenom);
                for (int i = 0; i < 4; i++)
                {
                    printf("Saisir la note %d de l'etudient %s :", i + 1, (*e)[index].nom);
                    scanf("%f", &(*e)[index].notes[i]);
                }

                break;

            default:
                break;
            }
        }
    }
}




void saisirNotes(Etudient **e, int count)
{

    char cne[20];
    printf("S il vous plait saisir le CNE de letudiant qui va saisir les notes : ");
    scanf("%s", cne);
    int index = recherch_par_cne(*e, count, cne);
    if (index == -1)
    {
        printf("Etudiant non trouve.\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Saisir la note %d : ", i + 1);
        int success = scanf("%f", &(*e)[index].notes[i]);
        if (success != 1 || (*e)[index].notes[i] < 0 || (*e)[index].notes[i] > 20)
        {
            printf("Saisir la note number ou  entre 0 et 20 !!!!!\n");
            while (getchar() != '\n')
                ;
            i--;
        }
    }
}

float calculerMoyenneEtudiant(Etudient **e, int count, char cne[])
{
    float moyenne = 0;
    int index = recherch_par_cne(*e, count, cne);
    if (index != -1)
    {
        for (int i = 0; i < 4; i++)
        {
            moyenne += (((*e)[index].notes[i]) / 4);
        }
    }
    else
    {
        printf("L'etudient ne trouve pas ");
    }
    return moyenne;
}
void calculerMoyenneGenerale(Etudient **e, int count)
{
    float s = 0;
    float mg;
    for (int i = 0; i < count; i++)
    {
        float moyenne_par_etudient = calculerMoyenneEtudiant(e, count, (*e)[i].cne);
        s += moyenne_par_etudient;
    }

    mg = s / count;
    printf("===============================================================\n");
    printf("#                La Moyenne Generale : %.2f/20               #\n", mg);
    printf("===============================================================\n");
}

void afficherBulletin(Etudient **e, int count)
{
    char cne[20];
    printf("Saisir le cne de l etudient pour afficher sont bulletin : ");
    scanf("%s", cne);
    int index = recherch_par_cne(*e, count, cne);
    float moyenne_g = calculerMoyenneEtudiant(e, count, cne);
    printf("===============================================================\n");
    printf("# Bulletin                   %s %s                            #\n", (*e)[index].nom, (*e)[index].prenom);
    printf("===============================================================\n");
    for (int i = 0; i < 4; i++)
    {
        printf("# note %d  (note/20)                         #      %.2f      #\n", i + 1, (*e)[index].notes[i]);
        printf("===============================================================\n");
    }

    printf("# Moyenne Generale                             #      %.2f   #\n", moyenne_g);
    printf("===============================================================\n");

    if (moyenne_g >= 10)
    {
        printf("# Resultat : Admis                                            #\n");
    }
    else
    {
        printf("# Resultat : Non Admis                                    #\n");
    }

    printf("===============================================================\n");
}


int main()
{
    int size = 2;
    int count = 2;
    Etudient *e = malloc(size * sizeof(Etudient));
    int choix;
    char cne_etud[20];

    strcpy(e[0].cne, "abd2001");
    strcpy(e[0].nom, "abdelilah");
    strcpy(e[0].prenom, "Ouslimane");
    e[0].notes[0] = 12;
    e[0].notes[1] = 11;
    e[0].notes[2] = 10;
    e[0].notes[3] = 11;
    strcpy(e[1].cne, "adil2000");
    strcpy(e[1].nom, "adile");
    strcpy(e[1].prenom, "Ouslimane");
    e[1].notes[0] = 12;
    e[1].notes[1] = 14;
    e[1].notes[2] = 10;
    e[1].notes[3] = 11;
    do
    {

        printf("\n===============================================================\n");
        printf("                      MENU PRINCIPAL                           \n");
        printf("===============================================================\n");
        printf("#  1 # Ajouter un etudiant                                    #\n");
        printf("#  2 # Afficher tous les etudiants                            #\n");
        printf("#  3 # Saisir les notes d un etudiant                         #\n");
        printf("#  4 # Modifier un etudient                                   #\n");
        printf("#  5 # Suppremier un etudiant                                 #\n");
        printf("#  6 # Afficher le bulletin d un etudiant                     #\n");
        printf("#  7 # Calculer la moyenne generale par un etudient           #\n");
        printf("#  8 # Afficher la moyenne generale de classe                 #\n");
        printf("#  0 # Quitter                                                #\n");
        printf("===============================================================\n\n");
        choix = validition_choix("S'il vous plait chaoise une choix : ");
        switch (choix)
        {
        case 1:
            ajouterEtudiant(&e, &size, &count);
            break;
        case 2:
            Afficher_Etudients(e, count);
            break;
        case 3:
            saisirNotes(&e, count);
            break;
        case 4:
            modifierEtudient(&e, count);
            break;
        case 5:
            supprimierEtduiant(&e, &size, &count);
            break;
        case 6:
            afficherBulletin(&e, count);
            break;
        case 7:
        {
            printf("Entre cne de l'etudient qui calculer Moyonne genreal : ");
            scanf("%s", cne_etud);
            float moy = calculerMoyenneEtudiant(&e, count, cne_etud);
            printf("===============================================================\n");
            printf("##      La Moyenne Generale de Etudient est %.2f / 20       ##\n", moy);
            printf("===============================================================\n");
            break;
        }
        case 8:
            calculerMoyenneGenerale(&e, count);
            break;
        case 0:
            exit(1);
        default:
            break;
        }
    } while (choix != 0);
}