#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



//la definition des structures
typedef struct
{
    int j;
    int m;
    int a;

} date;
typedef struct
{
    int id;
    char nom[30];
    char prenom[30];
    int mdp;
} Utilisateur;

typedef struct
{
    int id;
    char marque[30];
    char modele[30];
    char couleur[30];
    int  l;

} Voiture;
typedef struct
{
    int cin;
    char nom[30];
    char prenom[30];
    int  voiture;
    date d;
    int nbre;

} Client;



//procedure connexion
void connexion(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void Quitter(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void deconnexion(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
//les procedures du menu 0
void menu0(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu1(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu2(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
//les procedures du menu 1
void menu1_affichage(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu1_modification(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu1_retour(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
//les procedures du menu 2
void menu2_afficher_location(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu2_ajouter_location(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu2_afficher_hystorique(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);



//procedures de modification MENU1
void menu1_modification_ajout(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu1_modification_supprission(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);
void menu1_modification_modification(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp);



//constructeur pour les structures
Utilisateur utilisateur(int id,char nom[],char prenom[],int mdp)
{
    int i;
    Utilisateur u;
    u.id=id;
    for(i=0; i<strlen(nom); i++)
        u.nom[i]=nom[i];
    for(i=0; i<strlen(prenom); i++)
        u.prenom[i]=prenom[i];
    u.mdp=mdp;
    return(u);
}
Voiture voiture(int id,char marque[],char modele[],char couleur[])
{
    int i;
    Voiture v;
    v.id=id;
    for(i=0; i<strlen(marque); i++)
        v.marque[i]=marque[i];
    for(i=0; i<strlen(modele); i++)
        v.modele[i]=modele[i];
    for(i=0; i<strlen(couleur); i++)
        v.couleur[i]=couleur[i];
    v.l=0;
    return(v);
}
Client client(int cin,char nom[],char prenom[],int voiture,int a,int m,int j)
{
    int i;
    Client v;
    v.cin=cin;
    for(i=0; i<strlen(nom); i++)
        v.nom[i]=nom[i];
    for(i=0; i<strlen(prenom); i++)
        v.prenom[i]=prenom[i];
    v.voiture=voiture;
    v.d.a=a;
    v.d.m=m;
    v.d.j=j;
    return(v);
}




void connexion(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    system("cls");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int user=0,mdp=0;
    int i;
    printf("           *****LOCATION VOITURE*****\n\n\n");
    printf("   1-CONNEXION\n");
    printf("   0- QUITTER\n\n\n");
    printf("          Aujourd'hui c'est le: %d-%d-%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    do
    {
        scanf("%i",&i);
        if(i>1 || i<0)
            printf("Choix incorrecte!\n");
    }
    while(i<0 || i>1);
    if(i==0)
    {
        Quitter(utp,vtp,vtn,cp,cnp);
    }
    else if(i==1)
    {


        int j,v=0,vv=0;
        do
        {
            printf("   VEUILLER ENTRER VOTRE USER\n");
            scanf("%i",&user);
            for(j=0; j<5; j++)
            {
                if(user==(*(utp+j)).id)
                {
                    v=1;
                }
            }
            if(v==0)
            {
                printf("   USER INCORRECT\n");
            }

        }
        while(v!=1);
        int a=0;
        do
        {
            a++;
            printf("   VEUILLER ENTRER VOTRE MOT DE PASS\n");
            scanf("%i",&mdp);
            for(j=0; j<5; j++)
            {
                if(user==(*(utp+j)).id && mdp==(*(utp+j)).mdp)
                {
                    vv=1;
                }
            }
            printf("Incorrect %i/3\n",a);
        }
        while(a!=3 && vv!=1);
        if(vv==1)
            menu0(utp,vtp,vtn,cp,cnp);
        else
            connexion(utp,vtp,vtn,cp,cnp);
    }
}

void deconnexion(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    connexion(utp,vtp,vtn,cp,cnp);
}

void menu0(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    system("cls");
    int i;
    printf("           *****MENU PRINCIPALE*****\n\n\n");
    printf("   1- ESPACE VOITURE\n");
    printf("   2- ESPACE LOCATION\n");
    printf("   3- DECONNEXION\n");

    do
    {
        scanf("%i",&i);
        if(i != 1 || i != 2 || i != 3)
            printf("Choix incorrecte!\n");
    }
    while(i<1 || i>3);
    if(i==1)
    {
        menu1(utp,vtp,vtn,cp,cnp);
    }
    else if(i==2)
    {
        menu2(utp,vtp,vtn,cp,cnp);
    }
    else if(i==3)
    {
        deconnexion(utp,vtp,vtn,cp,cnp);
    }

}

void menu1(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    int i;
    system("cls");
    printf("           *****ESPACE VOITURE*****\n\n\n");
    printf("   1- LISTE DES VOITURES\n");
    printf("   2- MODIFICATION D'UNE VOITURE\n");
    printf("   0- RETOUR\n");


    do
    {
        scanf("%i",&i);
        if(i<0 || i>2 )
            printf("Choix incorrecte!\n");
    }
    while(i<0 || i>2 );
    if(i==1)
    {
        menu1_affichage(utp,vtp,vtn,cp,cnp);
    }
    else if(i==2)
    {
        menu1_modification(utp,vtp,vtn,cp,cnp);

    }

    else if(i==0)
    {
        menu1_retour(utp,vtp,vtn,cp,cnp);

    }
}

void menu2(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    int i;
    system("cls");
    printf("           *****ESPACE LOCATION*****\n\n\n");
    printf("   1- AFFICHER LES VOITURES LOUEES\n");
    printf("   2- AJOUTER UNE LOCATION\n");
    printf("   3- AFFICHER LES DATES DE RENDU \n");
    printf("   0- RETOUR\n");
    do
    {
        scanf("%i",&i);
        if(i<0 || i>3)
        {
            printf("Choix incorrecte!\n");
        }
    }
    while(i<0 || i>3);
    if(i==1)
    {

        menu2_afficher_location(utp,vtp,vtn,cp,cnp);


    }
    else if(i==2)
    {
        menu2_ajouter_location(utp,vtp,vtn,cp,cnp);

    }
    else if(i==3)
    {
        menu2_afficher_hystorique(utp,vtp,vtn,cp,cnp);

    }
    else if(i==0)
    {
        menu0(utp,vtp,vtn,cp,cnp);
    }

}

void Quitter(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    int i;
    system("cls");
    printf("           *****Quitter*****\n\n\n");
    printf("       VOULEZ VOUS QUITTER ?   \n");

    printf("   1- CONFIRMER\n");
    printf("   2- ANNULER\n");
    do
    {
        scanf("%i",&i);
        if(i<1 || i>2)
        {
            printf("Choix incorrecte!\n");
        }
    }
    while(i<1 || i>2);
    if(i==1)
    {

        printf("     **************************************\n");
        printf("     ****  ***************  ***********  **\n");
        printf("     ****  ****************  *********  ***\n");
        printf("     ****  *****************  *******  ****\n");
        printf("     ****  ******************  *****  *****\n");
        printf("     ****  *******************  ***  ******\n");
        printf("     ****  ********************     *******\n");
        printf("     ****          *************   ********\n");
        printf("     **************************** *********\n");



    }
    else if(i==2)
    {
        connexion(utp,vtp,vtn,cp,cnp);

    }
}

void menu1_affichage(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    system("cls");
    printf("           *****LISTE DES VOITURES*****\n\n\n");

    int i;
    for(i=0; i<*vtn; i++)
    {
        printf("%i :matricule: %i | marque: %s | modele: %s | couleur: %s \n",i,(*(vtp+i)).id,(*(vtp+i)).marque,(*(vtp+i)).modele,(*(vtp+i)).couleur);
    }


    printf("\n");
    printf("   0- RETOUR\n");
    int j;
    do
    {
        scanf("%i",&j);
        if(j!=0 )
            printf("Choix incorrecte!\n");
    }
    while(j!=0);
    if(j==0)
    {
        menu1(utp,vtp,vtn,cp,cnp);
    }
}
void menu1_modification(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    int i;
    system("cls");
    printf("           *****MODIFICATION VOITURE*****\n\n\n");
    printf("   1- AJOUTER UNE VOITURE\n");
    printf("   2- SUPPRIMER UNE VOITURE\n");
    printf("   3- MODIFIER UNE VOITURE\n");
    printf("   4- RETOUR\n");
    do
    {
        scanf("%i",&i);
        if(i<1 || i>4 )
            printf("Choix incorrecte!\n");
    }
    while(i<1 || i>4);
    if(i==1)
    {
        menu1_modification_ajout(utp,vtp,vtn,cp,cnp);
    }
    else if(i==2)
    {
        menu1_modification_supprission(utp,vtp,vtn,cp,cnp);

    }
    else if(i==3)
    {
        menu1_modification_modification(utp,vtp,vtn,cp,cnp);
    }
    else if(i==4)
    {
        menu1(utp,vtp,vtn,cp,cnp);

    }

}
void menu1_payment(Utilisateur* utp,Voiture* vtp,int* vtn)
{

}
void menu1_retour(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    menu0(utp,vtp,vtn,cp,cnp);
}
void menu1_modification_ajout(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    system("cls");
    printf("           *****AJOUT VOITURE*****\n\n\n");
    int v;
    int j;
    int i=*vtn;



    do
    {
        v=1;
        printf("DONNER MATRICULE DU VOITURE FORMAT(****)\n");
        scanf("%i",&(*(vtp+i)).id);

        for(j=0; j<*vtn; j++)
        {
            if((*(vtp+i)).id==(*(vtp+j)).id)
                v=0;
        }
        if(v==0)
            printf("Voiture existe deja\n");
        else if((*(vtp+i)).id<=0 || (*(vtp+i)).id>9999)
            printf("Matricule incorrect\n");
    }
    while((*(vtp+i)).id<=0 || (*(vtp+i)).id>9999 || v==0);
    printf("Donner la marque du voiture \n");
    scanf("%s",&(*(vtp+i)).marque);
    printf("Donner le modele du voiture \n");
    scanf("%s",&(*(vtp+i)).modele);
    printf("Donner la couleur du voiture \n");
    scanf("%s",&(*(vtp+i)).couleur);
    (*(vtp+i)).l=0;
    printf("\n");
    system("cls");
    *vtn=*vtn+1;

    printf("\n VOITURE AJOUTE!!!!\n\n\n");
    printf("   1- AJOUTER UNE AUTRE VOITURE\n");
    printf("   0- RETOUR\n");
    int r;
    do
    {
        scanf("%i",&r);
        if(r<0 || r>1 )
            printf("Choix incorrecte!\n");
    }
    while(r<0 || r>1 );
    if(r==0)
    {
        menu1_modification(utp,vtp,vtn,cp,cnp);
    }
    else if (r==1)
        menu1_modification_ajout(utp,vtp,vtn,cp,cnp);
};
void menu1_modification_supprission(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    int i;
    system("cls");
    printf("           *****SUPPRISSION D'UNE VOITURE*****\n\n\n");
    printf("   LISTE DES VOITURES:\n");
    if(*vtn!=0)
    {

        int j;
        for(j=0; j<*vtn; j++)
        {
            printf("%i :matricule: %i | marque: %s | modele: %s | couleur: %s \n",j,(*(vtp+j)).id,(*(vtp+j)).marque,(*(vtp+j)).modele,(*(vtp+j)).couleur);
        }


        printf("\n");
        printf("   ENTRER MATRICULE D'UNE VOITURE\n");
        int v=0;
        do
        {
            scanf("%i",&i);
            for(j=0; j<*vtn; j++)
                if(i==(*(vtp+j)).id)
                    v=1;

            if(v==0)
                printf("Matricule non trouve\n");


        }
        while(i<0 || i>9999 || v==0);
        j=0;
        do
        {
            v=1;
            int k;
            if(i == (*(vtp+j)).id)
            {
                v=0;
                for(k=j; k<(*(vtn)); k++)
                {

                    (*(vtp+k)).id=(*(vtp+k+1)).id;


                }

            }
            j++;

        }
        while(j != (*vtn) && v!=0);
        (*vtn)=(*vtn)-1;

        int k;
        printf("   VOITURE SUPPRIMER!!\n");

        printf("   VOULEZ VOUS SUPPRIMER UNE AUTRE VOITURE\n");
        printf("   1- SUPPRIMER\n");
        printf("   0- RETOUR\n");

        do
        {
            scanf("%i",&k);
            if(k<0 || k>1 )
                printf("Choix incorrecte!\n");
        }
        while(k<0 || k>1);
        if(k==1)
        {
            menu1_modification_supprission(utp,vtp,vtn,cp,cnp);
        }
        else if(k==0)
        {
            menu1_modification(utp,vtp,vtn,cp,cnp);

        }
    }
    else
    {
        int k;
        printf("T'AS PAS DES VOITURES!\n");
        printf("   0- RETOUR\n");
        do
        {
            scanf("%i",&k);
            if(k!=0)
                printf("Choix incorrecte!\n");
        }
        while(k!=0);
        if(k==0)
            menu1_modification(utp,vtp,vtn,cp,cnp);

    }
};
void menu1_modification_modification(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{

    int i;
    system("cls");
    printf("           *****MODIFICATION D'UNE VOITURE*****\n\n\n");
    printf("   LISTE DES VOITURES:\n");
    if(*vtn!=0)
    {

        int j;
        for(j=0; j<*vtn; j++)
        {
            printf("%i :matricule: %i | marque: %s | modele: %s | couleur: %s \n",j,(*(vtp+j)).id,(*(vtp+j)).marque,(*(vtp+j)).modele,(*(vtp+j)).couleur);
        }


        printf("\n");
        printf("   ENTRER MATRICULE D'UNE VOITURE\n");
        int v=0,id=0;
        do
        {
            scanf("%i",&i);
            for(j=0; j<*vtn; j++)
                if(i==(*(vtp+j)).id)
                {
                    v=1;
                    id=j;
                }

            if(v==0)
                printf("Matricule non trouve\n");


        }
        while(i<0 || i>9999 || v==0);
        printf("   CHOISISSEZ LE CHAMP\n");
        printf("   1- MATRICULE\n");
        printf("   2- MARQUE\n");
        printf("   3- MODELE\n");
        printf("   4- COULEUR\n");

        do
        {
            scanf("%i",&i);
            if(i<1 || i>4)
                printf("Choix incorrecte!\n");
        }
        while(i<1 || i>4);
        if(i==1)
        {
            int n=0,b;
            do
            {
                b=0;

                printf("DONNER LA NOUVELLE VALEUR FORMAT (****)\n");
                scanf("%i",&n);
                for(j=0; j<*vtn; j++)
                {
                    if(n==(*(vtp+j)).id)
                        b=1;
                }
                if(b==1)
                    printf("MATRICULE EXISTE!\n");

            }
            while(b!=0);
            (*(vtp+id)).id=n;

            int k;
            printf("   VOITURE MODIFIER!!\n");

            printf("   VOULEZ VOUS MODIFIER UNE AUTRE VOITURE\n");
            printf("   1- MODIFIER\n");
            printf("   0- RETOUR\n");

            do
            {
                scanf("%i",&k);
                if(k<0 || k>1 )
                    printf("Choix incorrecte!\n");
            }
            while(k<0 || k>1);
            if(k==1)
            {
                menu1_modification_modification(utp,vtp,vtn,cp,cnp);
            }
            else if(k==0)
            {
                menu1_modification(utp,vtp,vtn,cp,cnp);

            }
        }
        else if(i==2)
        {


            printf("DONNER LA NOUVELLE VALEUR \n");
            scanf("%s",&(*(vtp+id)).marque);

            int k;
            printf("   VOITURE MODIFIER!!\n");

            printf("   VOULEZ VOUS MODIFIER UNE AUTRE VOITURE\n");
            printf("   1- MODIFIER\n");
            printf("   0- RETOUR\n");

            do
            {
                scanf("%i",&k);
                if(k<0 || k>1 )
                    printf("Choix incorrecte!\n");
            }
            while(k<0 || k>1);
            if(k==1)
            {
                menu1_modification_modification(utp,vtp,vtn,cp,cnp);
            }
            else if(k==0)
            {
                menu1_modification(utp,vtp,vtn,cp,cnp);

            }
        }
        else if(i==3)
        {


            printf("DONNER LA NOUVELLE VALEUR \n");
            scanf("%s",&(*(vtp+id)).modele);


            int k;
            printf("   VOITURE MODIFIER!!\n");

            printf("   VOULEZ VOUS MODIFIER UNE AUTRE VOITURE\n");
            printf("   1- MODIFIER\n");
            printf("   0- RETOUR\n");

            do
            {
                scanf("%i",&k);
                if(k<0 || k>1 )
                    printf("Choix incorrecte!\n");
            }
            while(k<0 || k>1);
            if(k==1)
            {
                menu1_modification_modification(utp,vtp,vtn,cp,cnp);
            }
            else if(k==0)
            {
                menu1_modification(utp,vtp,vtn,cp,cnp);

            }
        }
        else if(i==4)
        {

            printf("DONNER LA NOUVELLE VALEUR \n");
            scanf("%s",&(*(vtp+id)).couleur);


            int k;
            printf("   VOITURE MODIFIER!!\n");

            printf("   VOULEZ VOUS MODIFIER UNE AUTRE VOITURE\n");
            printf("   1- MODIFIER\n");
            printf("   0- RETOUR\n");

            do
            {
                scanf("%i",&k);
                if(k<0 || k>1 )
                    printf("Choix incorrecte!\n");
            }
            while(k<0 || k>1);
            if(k==1)
            {
                menu1_modification_modification(utp,vtp,vtn,cp,cnp);
            }
            else if(k==0)
            {
                menu1_modification(utp,vtp,vtn,cp,cnp);

            }
        }


    }
    else
    {
        int k;
        printf("T'AS PAS DES VOITURES!\n");
        printf("   0- RETOUR\n");
        do
        {
            scanf("%i",&k);
            if(k!=0)
                printf("Choix incorrecte!\n");
        }
        while(k!=0);
        if(k==0)
            menu1_modification(utp,vtp,vtn,cp,cnp);

    }




};

void menu2_afficher_location(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    system("cls");
    printf("           *****LISTE DES VOITURES LOUEES*****\n\n\n");

    int i;
    for(i=0; i<*vtn; i++)
    {
        if((*(vtp+i)).l!=0)
            printf("%i :matricule: %i | marque: %s | modele: %s | couleur: %s \n",i,(*(vtp+i)).id,(*(vtp+i)).marque,(*(vtp+i)).modele,(*(vtp+i)).couleur);
    }


    printf("\n");
    printf("   0- RETOUR\n");
    int j;
    do
    {
        scanf("%i",&j);
        if(j!=0 )
            printf("Choix incorrecte!\n");
    }
    while(j!=0);
    if(j==0)
    {
        menu2(utp,vtp,vtn,cp,cnp);
    }
};
void menu2_ajouter_location(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp)
{
    system("cls");
    printf("           *****AJOUTER UNE LOCATION*****\n\n\n");

    int i;
    for(i=0; i<*vtn; i++)
    {
        if((*(vtp+i)).l==0)
            printf("%i :matricule: %i | marque: %s | modele: %s | couleur: %s \n",i,(*(vtp+i)).id,(*(vtp+i)).marque,(*(vtp+i)).modele,(*(vtp+i)).couleur);
    }

    int v,k;
    int j;
    i=*vtn;
    k=*cnp;
    int voiture;

    do
    {
        v=0;
        printf("Donner matricule du voiture a louer FORMAT(****)\n");
        scanf("%i",&voiture);

        for(j=0; j<*vtn; j++)
        {
            if(voiture==(*(vtp+j)).id)
            {

               v=1;
            (*(vtp+j)).l=1;}
        }
        if(v==0)
            printf("Voiture n'existe pas\n");

    }
    while(v!=1);
    printf("Donner cin du client \n");
    scanf("%i",&(*(cp+k)).cin);
    printf("Donner le nom du client \n");
    scanf("%s",&(*(cp+k)).nom);
    printf("Donner le prenom du client \n");
    scanf("%s",&(*(cp+k)).prenom);
    printf("Donner le nombre du jour \n");
    scanf("%i",&(*(cp+k)).nbre);
    (*(cp+k)).voiture=voiture;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    (*(cp+k)).d.a=tm.tm_year + 1900;
    (*(cp+k)).d.m=tm.tm_mon + 1;
    (*(cp+k)).d.j=tm.tm_mday;



    printf("\n");
    *cnp=*cnp+1;

    printf("\n CLIENT AJOUTER!!!!\n\n\n");
    printf("   1- AJOUTER UN AUTRE CLIENT\n");
    printf("   0- RETOUR\n");
    int r;
    do
    {
        scanf("%i",&r);
        if(r<0 || r>1 )
            printf("Choix incorrecte!\n");
    }
    while(r<0 || r>1 );
    if(r==0)
    {
        menu2(utp,vtp,vtn,cp,cnp);
    }
    else if (r==1)
        menu2_ajouter_location(utp,vtp,vtn,cp,cnp);
};
void menu2_afficher_hystorique(Utilisateur* utp,Voiture* vtp,int* vtn,Client* cp,int* cnp){

 system("cls");
    printf("           *****DATE *****\n\n\n");

    int i;
    for(i=0; i<*cnp; i++)
    {
            printf("nom: %s  prenom: %s | voiture: %i `| doit rendre la voiture apres %i jours de cette date %d %d %d \n",(*(cp+i)).nom,(*(cp+i)).prenom,(*(cp+i)).voiture,(*(cp+i)).nbre,(*(cp+i)).d.a,(*(cp+i)).d.m,(*(cp+i)).d.j);
    }


    printf("\n");
    printf("   0- RETOUR\n");
    int j;
    do
    {
        scanf("%i",&j);
        if(j!=0 )
            printf("Choix incorrecte!\n");
    }
    while(j!=0);
    if(j==0)
    {
        menu2(utp,vtp,vtn,cp,cnp);
    }





};

int main()
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,15*16+1);

//declaration des tableaux
    Utilisateur ut[2];
    Utilisateur* utp;
    utp=&ut;
    Client client[100];
    int nombrec=0;
    int* cnp=&nombrec;
    Client* cp;
    cp=&client;
     int nombrev=8;
    int* vtn=&nombrev;
    Voiture vt[1000];
    Voiture* vtp;
    vtp=&vt;
    //initialisations

    *(utp)=utilisateur(1,"ghazali","sabri",1234);
    (*(utp+1))=utilisateur(2,"ghazali","sabri",1212);

    *(vtp)=voiture(1110,"renault","symbole","Rouge");
    *(vtp+1)=voiture(1234,"renault","symbole","Rouge");
    *(vtp+2)=voiture(8585,"renault","symbole","Rouge");
    *(vtp+3)=voiture(5252,"renault","symbole","Bleu");
    *(vtp+4)=voiture(9632,"renault","symbole","Rouge");
    *(vtp+5)=voiture(1235,"renault","symbole","Vert");
    *(vtp+6)=voiture(9874,"renault","symbole","Rouge");
    *(vtp+7)=voiture(5698,"renault","symbole","Jaune");



    connexion(utp,vtp,vtn,cp,cnp);





}
