![Capture d’écran du 2024-11-15 16-50-56](https://github.com/user-attachments/assets/aa046005-51e6-4051-bbbc-3a80a9dad21e)

Que fait get_next_line ?
-
get_next_line est une fonction qui permet de lire un fichier texte ligne par ligne. Elle retourne la ligne actuelle à chaque appel et passe automatiquement à la suivante.
Qu'est-ce qui est nécessaire pour cette fonction ?

Pour implémenter get_next_line, j'utilise :

    La fonction read de la bibliothèque <unistd.h>, qui me permet de lire des données depuis un fichier ouvert.
    Quelques fonctions utilitaires issues de ma libft pour la gestion des chaînes de caractères.

Quelle est la logique derrière le code ?
-
Prototypage :

    char *get_next_line(int fd);

  Validation des paramètres
  La fonction commence par vérifier la validité des arguments. Cela inclut :
    
        Vérifier que le descripteur de fichier (fd) est valide.
        S'assurer que BUFFER_SIZE est une valeur positive.
        Confirmer que le fichier est lisible en appelant read.
        Si la fonction read retourne une erreur, get_next_line renvoie NULL.

  Lecture des données
  Les données du fichier sont lues dans un buffer statique grâce à une fonction dédiée, read_file :
    
        J’alloue un espace mémoire pour le buffer en fonction de la taille définie par BUFFER_SIZE.
        La fonction read est appelée avec :
            Le descripteur de fichier fd.
            Le buffer alloué.
            Le nombre d’octets à lire (défini par BUFFER_SIZE).

    Cette opération est effectuée dans une boucle jusqu'à ce qu’un caractère de fin de ligne (\n)
    soit rencontré ou que la fin du fichier soit atteinte. Le résultat est stocké dans une chaîne
    de caractères res, qui contient les données lues jusqu’au caractère \n.

  Extraction de la ligne :
    
    Une fois les données lues, j'appelle la fonction line, qui :
        Cherche la position du caractère \n dans la chaîne lue.
        Coupe tout ce qui suit \n pour ne retourner que la ligne (le \n est inclus dans le résultat).

  Préparation pour l’appel suivant :
    
    Avant de retourner la ligne extraite, j'appelle une autre fonction, next,
    qui prépare le buffer statique pour la prochaine lecture :
    Cette fonction "nettoie" le buffer pour ne conserver que les données après le caractère \n.
    Cela permet de garder en mémoire la suite du fichier, prête pour le prochain appel de get_next_line.
    Ce mécanisme empêche la perte de caractères si la lecture précédente s'est arrêtée en plein milieu d'un buffer.

Points importants :
-
  Buffer statique :
    
    Le buffer statique est essentiel au bon fonctionnement de get_next_line,
    car il permet de conserver les données non utilisées entre les appels successifs de la fonction.

  Gestion de la mémoire :
    
    Chaque ligne retournée est allouée dynamiquement et doit être libérée par l'utilisateur
    après utilisation pour éviter les fuites de mémoire.

  Compatibilité avec tous les fichiers :
    
    La fonction est conçue pour gérer les fichiers texte, mais peut également lire d'autres types de fichiers,
    ligne par ligne, tant que le format respecte le principe de délimitation par \n.
