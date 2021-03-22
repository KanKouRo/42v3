// Rush 01

#include <stdlib.h>
#include <unistd.h>

#define N 4

// Longueur d'une chaîne de caractères
int slen(const char* str)
{
    // Trouve la longueur de la chaîne (jusqu'au caractère 0)
    int len = 0;
    const char* c = str;
    while (*c != 0) {
        c++;
        len++;
    }

    return len;
}

// Fonction "print" simple
void print(const char* str)
{
    // Le file descriptor (fd) de stdout est 0.
    write(0, str, slen(str));
}

// Compte le nombre de caisses visibles selon le pas.
// Fonctionne autant à la verticale qu'à l'horizontale, tout est réglé par le
// pas.
// Voir les fonctions suivantes pour des exemples.
int vue(int* debut, int pas)
{
    int  max = 0;                           // Valeur la plus haute
    int  c   = 0;                           // Combien ont été vues
    int* fin = debut + N * pas;             // Quand arrêter (N éléments * pas)

    // On passe case par case et on fait le suivi de la plus haute valeur.
    // Si la case est plus grande, on met à jour la limite (max) et on
    // compte une caisse visible (c).
    for (int* i = debut; i != fin; i += pas) {
        int v = *i;
        if (v > max) {
            max = v;
            c++;
        }
    }

    return c;
}

int vue_c_u(int* map, int col)
{
    // Pour les vues verticales du haut tvers le bas, on fait un pas de N, donc
    // on "saute" une rangée à la fois.
    // On commence à la case "col" de la première rangée.
    return vue(&map[col], N);
}

int vue_r_l(int* map, int row)
{
    // Pour les vues horizontales de gauche à droite, on avance de 1 tout
    // simplement.
    // On Commence à la première case de la rangée (donc row * N cases après
    // le début de la carte).
    return vue(&map[row*N], 1);
}

int vue_c_d(int* map, int col)
{
    // Pour les vues verticales du bas vers le haut, on fait un pas de -N.
    // On commence à la case col de la dernière rangée (donc (N-1)*N cases
    // après la première).
    return vue(&map[(N-1)*N+col], -N);
}

int vue_r_r(int* map, int row)
{
    // Pour les vues horizontales de droite à gauche, on commence à la
    // dernière case de la rangée, donc N*row + (N-1) cases après le début.
    // Attention au -1 : il ne faut pas commencer au-delà de la rangée,
    // surtout la dernière.
    // Ex. : pour la rangée 1 (index 0), la dernière case est à la position 3,
    // et non 4.
    return vue(&map[row*N+(N-1)], -1);
}


// Fonction qui valide si une carte est valide selon les vues données.
// Retourne 0 si c'est valide, -1 sinon.
int valid_map(int* map, int* vues)
{
    // Pointeurs vers les groupes spécifiques.
    int* vues_c_u = &vues[0];   // colXup
    int* vues_c_d = &vues[N];   // colXdown
    int* vues_r_l = &vues[2*N]; // rowXleft
    int* vues_r_r = &vues[3*N]; // rowXright

    for(int i = 0; i < N; ++i) {
        if (vue_c_d(map, i) != vues_c_d[i]) {
            //print("Valid Error c_d\n");
            return -1;
        }
    }

    for(int i = 0; i < N; ++i) {
        if (vue_c_u(map, i) != vues_c_u[i]) {
            //print("Valid Error c_u\n");
            return -1;
        }
    }

    for(int i = 0; i < N; ++i) {
        if (vue_r_r(map, i) != vues_r_r[i]) {
            //print("Valid Error r_r\n");
            return -1;
        }
    }

    for(int i = 0; i < N; ++i) {
        if (vue_r_l(map, i) != vues_r_l[i]) {
            //print("Valid Error r_l\n");
            return -1;
        }
    }

    return 0;
}

// Fait la conversion d'une chaîne en vues.
int parse_vues(const char* arg, int* vues)
{
    // 1. Est-ce que la chaîne reçue contient le bon nombre de caractères ?
    // (16 + 15 pour les espaces) ?
    if (slen(arg) != (2*4*N - 1)) {
        print("Error slen\n");
        return -1;
    }

    // La variable c pointera vers le caractère à analyser.
    // Note: argv[1] est la chaîne de l'argument, argv[1][0] est le premier 
    // caractère de la chaîne, mais &argv[1][0] est l'adresse mémoire de ce
    // caractère.
    // Note: dans cette fonction arg devrait correspondre à argv[0].
    // Comme on initialise un pointeur (const char* et non const char), on a
    // besoin d'une adresse.

    const char* c = &arg[0];
    for (int i = 0; i < N*4; i++) {
        vues[i] = *c - 48; // 48 étant la valeur décimale de "0".
        c += 2;
        // Petit rappel sur les pointeurs : *c représente le contenu pointé par
        // c et faire c += 2 revient à avancer le pointeur de 2 caractères.
    }

    return 0;
}

    
int tests()
{
    // Carte de l'annexe 3:
    int testmap[16] = {
        1, 2, 3, 4,
        2, 3, 4, 1,
        3, 4, 1, 2,
        4, 1, 2, 3
    };

    // Vues qu'on aurait reçues (col_up, col_down, row_left, row_right):
    int vues[16] = {
        4, 3, 2, 1,
        1, 2, 2, 2,
        4, 3, 2, 1,
        1, 2, 2, 2
    };

    print("Test valid...\n");
    if (valid_map(testmap, vues) != 0) {
        print("error valid\n");
        return -1;
    }

    // Test pour la conversion.
    print("Test conv...\n");
    const char* arg = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    int test_vues[16];
    if (parse_vues(arg, test_vues) != 0) {
        print("error parse length\n");
        return -1;
    }

    for (int i = 0; i < 16; ++i) {
        if (test_vues[i] != vues[i]) {
            print("error parse v\n");
            return -1;
        }
    }

    print("All tests OK.\n");
    return 0;
}

// Chemin inverse de ce qui est fait dans parse_map.
// On ajoute la valeur de "0" pour écrire un caractère.
// NOTE : On suppose que la valeur est de 0 à 9, sinon on écrit X.
void print_number(int i)
{
    char c[2] = "X";
    c[0] = 48 + i;
    print(c);
}

int main(int argc, char** argv)
{
    print("Rush01\n");

    // Facultatif : quelques tests pour s'assurer que tout fonctionne
    // correctement.
    if (tests() != 0) {
        print("Error - tests didn't pass\n");
        return -1;
    }

    int* map = (int*)malloc(N*N*sizeof(int));
    map[0] = 1;

    // Le défi additionnel est de partitionner le contenu des vues.
    // En effet, comme l'argument est entouré de "", il est reçu comme une seule
    // chaîne (mais sans les guillemets !).
    // Il faut donc séparer chaque item séparé d'un espace.
    // Au moins, c'est un caractère par item.
    
    // 1. Est-ce qu'on a le bon nombre d'arguments (2, rush-01 et la chaîne
    // "...").
    if (argc != 2) {
        print("Error argc\n");
        return -1;
    }

    // Affiche le contenu du premier argument après la commande (facultatif):
    print("argv[1]: ");
    print(argv[argc-1]);
    print("\n");

    // Maintenant on peut convertir. On commence au premier caractère
    // (donc argv[1][0]) et on avance de 2 à chaque fois.
    // (Voir la fonction parse_vues plus haut).
    // Il faut comprendre que la valeur 1 et le caractère "1" ne sont pas la
    // même chose. 
    // Cependant, le caractère a aussi une valeur numérique (en ASCII: 49).
    // Comme les caractères 0 à 9 se suivent, on peut soustraire la valeur
    // numérique du caractère 0 et obtenir la "vraie" valeur représentée par le
    // caractère.
    // Note: on stocke toutes les vues dans un seul tableau, et on pointera à
    // l'intérieur de celui-ci pour la suite.
    int vues[N*4];
    parse_vues(argv[1], vues);
   
    // 5. Nous avons maintenant nos spécifications (les vues), il faut être en
    // mesure de valider une carte.
    // C'est le rôle de la fonction valid_map.
    // Par exemple, on peut la tester avec le contenu actuel de "map".
    // Comme on a aucune idée du contenu de la carte présentement vu que c'est
    // un espace de mémoire alloué, mais non-initialisé, on peut être certain
    // que ça ne passera pas.
    // Note: retourner 0 quand tout est bon est une convention.
    // On utilise d'autre valeurs pour spécifier qu'est-ce qui n'a pas
    // fonctionné exactament.
    // Donc si ce n'est pas 0, c'est qu'il y a eu un problème.
    if (valid_map(map, vues) != 0) {
        print("Invalid initial map (normal)\n");
    }

    for (int i = 0; i < (N*N); ++i) {
        map[0] = 0;
    }
    if (valid_map(map, vues) != 0) {
        print("Invalid zeroed map (normal)\n");
    }

    // Vidons la carte et refaisons le test.
    // Ça ne sera pas plus valide, mais c'est surtout pour comprendre ce qui se
    // passe.
    
    // Vous remarquerez qu'on n'utilise pas de tableau à 2 dimensions. On
    // utilise plutôt un tableau "plat" qu'on parcours en (i,j): i étant la
    // rangée de 0 à N-1 (donc 3), et j la colonne de 0 à N-1.
    // donc, la case 0 représente la coordonnée (0,0), la case 3 la coordonnée
    // (0, 3) (rangée 0, colonne 3 : première rangée, dernière colonne), la case
    // 5 la coordonnée (1,1), etc.


    // C'est ici que le travail commence - il faut changer le contenu de map,
    // vérifier si le contenu est valide, puis continuer jusqu'à obtenir un
    // résultat valide.
    // Beaucoup d'approches possibles. Par exemple, il y a 12 possibilités de
    // séquences (colonnes ou rangées). 
    // On peut commencer à la première rangée, trouver la séquence qui répond à
    // la vue, puis passer à la seconde.
    // Ça impliquera probablement des appels de fonctions récursives pour
    // parcourir l'arbre des possibilités.
    
    // Test rapide : on met un 2 à la case (1,1) pour vérifier la sortie:
    map[4] = 2;

    // Fin: on imprime la carte en cours.
    // TODO: Supprimer les messages en extra et n'écrire que "Error" s'il y a un
    // problème.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (N-1); ++j) {
            print_number(map[i*N + j]); 
            print(" ");
        }
        print_number(map[i*N + (N-1)]); // Dernier caractère de la rangée i.
        print("\n");
    }

    free(map); // On libère la mémoire allouée (semi-facultatif car ce sera
               // fait à la fin du programme, mais une bonne pratique)
    return 0;
}
