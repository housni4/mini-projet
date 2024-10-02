#include<stdio.h>
#include<string.h>

int main() {
    char titre[100][20];
    char auteur[100][100];
    float prix[100];
    int quantite[100];
    int choix;
    int stock = 0;
    do {
    printf("Systeme de Gestion de stock dans une Librairie\n");
    printf("1 : Ajouter un livre \n");
    printf("2 : Voir tous les livres \n");
    printf("3 : Rechercher un livre par son titre \n");
    printf("4 : Mettre a jour la quntite de livres \n");
    printf("5 : Supprimer le livre de l'inventaire \n");
    printf("6 : Afficher le nombre totel de livres \n");
    printf("7 : Quitter \n");
    
 
 printf("CHOISIR UN NOMBRE\t");
 scanf("%d",&choix);
    switch (choix) {
        case 1: {
                printf("Entrer le titre du livre: \n");
                scanf("%s", titre[stock]);
                printf("Entrer l'auteur du livre:\n");
                scanf("%s", auteur[stock]);
                printf("Entrer le prix du livre:\n");
                scanf("%f", &prix[stock]);
                printf("Entrer la quantite en stock:\n");
                scanf("%d", &quantite[stock]);
                stock++;
                printf("Livre ajoute avec succes.\n");
                break;
            }
        case 2: {
            for (int i = 0; i < stock; i++) {
            printf("\n     Le Livre numero %d\n",i+1);
            printf("Le titre du livre %d   :\t%s\n",i+1,titre[i]);
            printf("L'author du livre %d   :\t%s\n",i+1,auteur[i]);
            printf("Le prix du livre %d    :\t%.2f\n",i+1,prix[i]);
            printf("La quantite du livre %d:\t%d\n",i+1,quantite[i]);
                }
                break;
            }
            case 3: {
                char recherche[100];
                printf("Entrer le titre du livre � rechercher: ");
                scanf("%s", recherche);
                int found = 0;
                for (int i = 0; i < stock; i++) {
                    if (strcmp(recherche, titre[i]) == 0) {
                        printf("Livre trouve :\n");
                        printf("Titre: %s\n", titre[i]);
                        printf("Auteur: %s\n", auteur[i]);
                        printf("Prix: %.2f\n", prix[i]);
                        printf("Quantit�: %d\n\n", quantite[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Le Livre ne trouve pas.\n");
                }
                break;
            }
            case 4: {
                char recherche[100];
                printf("Entrer le titre du livre a changer: ");
                scanf("%s", recherche);
                int found = 0;
                for (int i = 0; i < stock; i++) {
                    if (strcmp(recherche, titre[i]) == 0) {
                        printf("Entrer la nouvelle quantite: ");
                        scanf("%d",&quantite[i]);
                        printf("La Mise a jour de la quantite est valide.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Le livre ne trouve pas.\n");
                }
                break;
            }
            case 5: {
                char recherche[100];
                printf("Entrez le titre du livre a supprimer: ");
                scanf("%s", recherche);
                int found = 0;
                for (int i = 0; i < stock; i++) {
                    if (strcmp(titre[i], recherche) == 0) {
                        for (int j = i; j < stock; j++) {
                            strcpy(titre[j],titre[j+1]);
                            strcpy(auteur[j],auteur[j+1]);
                            prix[j] = prix[j+1];
                            quantite[j] = quantite[j+1];
                        }
                        stock--;
                        printf("Le livre est supprime avec succes !\n");
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Le livre ne trouve pas.\n");
                }
                break;
            }
            case 6: {
                int total = 0;
                for (int i = 0; i < stock; i++)
                {
                    total = total + quantite[i];
                }
                printf("Nombre total de livres en stock est: %d\n", total);
                break;
            }
            case 7:
                printf("Ferme du programme.\n");
                break;
            default:
                printf("Le choix invalide pouvez vous reessayer.\n");
        }
    } while (choix != 7);
    return 0;
}
