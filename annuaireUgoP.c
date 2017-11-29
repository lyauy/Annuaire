#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Personne//initialisation de la structure
{
    char prenom[75];
    char nom[150];
    int numtel;
    char adresse[300];
};

struct Personne contact[50]; /* ----- A modifier ----- */

int main()
{
    int choix, n;
    do{
    printf("Choisissez ce que vous voulez faire : \n1. Affichage \n2. Ajout \n3. Suppression \n4. Modification \n5. Quitter \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        if( contact[0].nom[0] == NULL)//condition pour empecher d'afficher si les contacts n'ont pas été créés
        {
            printf("---Veuillez tout d'abord saisir les contacts avant de vouloir les afficher.---\n\n");
        }
        else
        {   printf ("Affichage des contacts.\n\n"); /* ----- Affichage des contacts par ordre alpha non réussi ----- */
            AffichageContact(&n);} //appel de la procedure pour l'affichage
        break;
    case 2:
        printf("Ajout d'un contact.\n");
        AjoutContact(&n);//appel de la procedure pour l'ajout du contact
        break;
    case 3:
        printf("Suppression d'un contact.\n");
        Suppcontact(&n);
        break;
    case 4:
        printf("Modification du numero de telephone d'un contact.\n");
        ModifNumTel();//appel de la procedure pour la modification du numero de tel
        break;
    case 5:
        printf("Application en fermeture..\n");
        break;//fermeture de l'application
    default:
        printf("Choix incorrect ! Relancement du menu..\n");
        break;//une option si l'utilisateur se trompe dans son choix
    }
    }while(choix != 5);
    return 0;
}

void AjoutContact(int *n)
{
    int i,choix,num;
    printf("1. Nouvelle liste 2. Rajouter un contact dans la liste (la liste doit deja etre cree)\n");
    scanf("%d", &choix);//création d'une nouvelle liste ou ajout d'un contact

    if (choix == 1){//choix 1. creation d'une nouvelle liste
    printf("Veuillez saisir le nombre de contact a creer.\n");
    scanf("%d", n);
    fflush(stdin);
    for(i=0; i<*n; i++)
    {
        printf("Entrez les informations du candidat n%d :\n", i+1);
        do{
        printf("Entrez le nom : ");
        fflush(stdin);
        fgets(contact[i].nom, sizeof contact[i].nom, stdin);//saisie du nom
        }while (strlen(contact[i].nom) < 3 );//controle de la taille du nom
        printf("Entrez le prenom [optionnel] : ");
        fgets (contact[i].prenom, sizeof contact[i].prenom, stdin);//saisie du prenom
        printf("Entrez le numero de telephone : ");
        scanf("%d", &contact[i].numtel);//saisie du num de tel
        printf("Entrez l'adresse du contact [optionnelle, ne rien saisir si on ne possede pas l'adresse.]");
        fflush(stdin);
        fgets(contact[i].adresse, sizeof contact[i].adresse, stdin);//saisie de l'adresse
    }
}
    else if ( choix == 2)
    {
        printf("veuillez saisir dans a quel numero de la liste le contact doit etre assigne.\n");
        scanf("%d", &num);//creation du contact
        printf("Entrez les informations du candidat n%d :\n", num);
        do{
        printf("Entrez le nom : ");
        fflush(stdin);
        fgets(contact[num-1].nom, sizeof contact[num-1].nom, stdin);//saisie du nom
        }while (strlen(contact[num-1].nom) < 3 );
        printf("Entrez le prenom [optionnel] : ");//saisie du prenom
        fgets (contact[num-1].prenom, sizeof contact[num-1].prenom, stdin);
        printf("Entrez le numero de telephone : (sans saisir le 1er 0) ");
        scanf("%d", &contact[num-1].numtel);//saisie du numero de tel
        printf("Entrez l'adresse du contact [optionnelle, ne rien saisir si on ne possede pas l'adresse.]");
        fflush(stdin);
        fgets(contact[num-1].adresse, sizeof contact[num-1].adresse, stdin);//saisie de l'adresse
        if (*n != 0)//incrementation du *n pour l'affchage
        *n = *n+1;
    }
}

void AffichageContact(int *n)
{
    int i;
    for (i = 0; i < *n; i++)
    {
        contact[i].nom[0] = toupper(contact[i].nom[0]); //fonction pour placer une majuscule
        contact[i].prenom[0] = toupper(contact[i].prenom[0]); //fonction pour placer une majuscule
        if (contact[i].nom[0] != NULL && contact[i].prenom[0] != NULL)//affichage du nom et prenom s'ils ne sont pas nuls
        printf("    .Nom du contact %d : %s    .Prenom du contact %d : %s",i+1 ,contact[i].nom,i+1, contact[i].prenom, i+1);
        if ( contact[i].numtel != NULL)//affichage du numero du tel
        {printf("    .Numero de telephone du contact %d : 0%d\n", i+1, contact[i].numtel);}
        if (contact[i].adresse[0] != NULL)//affichage de l'adresse s'il n'est pas nul
        {
            printf("    .Adresse du contact %d : %s", i+1,contact[i].adresse);
        }
        printf("\n");
    }
}

void ModifNumTel()
{
    int num;
    do {
    printf("Selectionnez le numero du contact pour modifier son numero de telephone.\n");
    scanf("%d", &num);//saisie du contact pour lesquel la modification doit etre apportée
    } while (num == 0);
    printf("Entrez le numero de telephone : ");
    scanf("%d", &contact[num-1].numtel);//saisie du numero de tel modifié
}

void Suppcontact(int *n)
{
    int i=0,num=0;
    printf("Selectionnez le numero du contact a supprimer.\n");
    scanf("%d", &num);
    for (i=0;i<*n;i++)
    {
        contact[num-1].nom[i] = contact[num].nom[i];
        contact[num-1].prenom[i] = contact[num].prenom[i] ;
        contact[num-1].numtel = contact[num].numtel ;
        contact[num-1].adresse[i] = contact[num].adresse[i];
    }
    *n = *n - 1;
}
