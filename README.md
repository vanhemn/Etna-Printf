# Etna-Printf
 ~TIC-DEVC~
 
Votre projet doit compiler sur Debian.
Vous devez fournir un Makefile qui compilera toutes vos sources.
Votre Makefile doit contenir les régles suivantes :
all, clean, fclean, re
my_printf_static, my_printf_dynamic
.PHONY
 my_printf
Fonctions autorisées :

free(3)
malloc(3)
stdarg (man 3) :
va_start
va_arg
va_end
write(2)
 Attention !
Toute triche équivaut à un -42.
 Consignes :
Vous devez faire votre propre implémentation de printf (man 3 printf). Votre makefile doit permettre de compiler une bibliothèque statique et une bibliothèque dynamique.

Pour cela, vous pouvez utiliser toutes les fonctions dites "utiles" mais tout le reste doit venir de vous.

Makefile :

La règle "my_printf_static" de votre Makefile devra compiler la bibliothèque statique.
La règle "my_printf_dynamic" de votre Makefile devra compiler la bibliothèque dynamique.
La règle "all" de votre Makefile devra compiler les deux bibliothèques. Cette règle devra être exécutée lors d'un "make" simple.
La règle "clean" de votre Makefile devra effacer les fichiers objets (an_object_file.o).
La règle "fclean" de votre Makefile devra effacer les deux bibliothèques et les fichiers objets.
La règle "re" de votre Makefile devra effacer les deux bibliothèques ainsi que les fichiers objets, et ensuite compiler les deux bibliothèques.
Concernant la règle ".PHONY" de votre Makefile, nous vous laissons vous renseigner sur son utilité et usage.
Nom des bibliothèques :

libmy_printf_`uname -m`-`uname -s`.a
libmy_printf_`uname -m`-`uname -s`.so
Pour créer une bibliothèque statique, voir les man de ar et ranlib et pour créer une bibliothèque dynamique, voir l'option -shared de gcc.

Prototype :

                    

                        int my_printf(char *, ...);
                    

                
Dans un premier temps, vous devrez gérer les modificateurs %s, %c, %i et %d :

                    

                        int main(int ac, char **av)
                        {
                            my_printf("1 - une chaine\n");
                            my_printf("2 - %s\n", "une autre chaine");
                            my_printf("3 - %i\n", 42);
                            my_printf("4 - %s %d %s%c", "avec", 4, "parametres", '\n');
                        }
                    

                
                    

                        $> ./a.out
                        1 - une chaine
                        2 - une autre chaine
                        3 - 42
                        4 - avec 4 parametres
                        $>
                    

                
Vous devrez ensuite gérer %o, %u, %x, %X et %% :

                    

                        int main(int ac, char **av)
                        {
                            my_printf("1 - %o\n", 42); /* unsigned octal */
                            my_printf("2 - %u\n", (unsigned int)4200000000); /* unsigned decimal */
                            my_printf("3 - %x\n", 42); /* unsigned hexadecimal */
                            my_printf("4 - %X\n", 42); /* unsigned hexadecimal */
                            my_printf("5 - %d%%\n", 42);
                        }
                    

                
                    

                        $> ./a.out
                        1 - 52
                        2 - 4200000000
                        3 - 2a
                        4 - 2A
                        5 - 42%
                        $>
                    

                
En bonus, vous pourrez aussi gérer les flags de formatage de printf ainsi que %f, %F %e, %E, %g, %G, %a, %A :

                    

                        int main(int ac, char **av)
                        {
                            my_printf("1 - %.5f\n", 4 * cos(2.0)); /* float */
                            my_printf("2 - %e\n", 4 * cos(2.0)); /* double */
                        }
                    

                
                    

                        $> ./a.out
                        1 - -1.66459
                        2 - -1.664587e+00
                        $>
                    

                
 Malus !
Les séries de if / else if, ou encore switch / case pour gérer les modificateurs sont interdites ! Utilisez plutôt des pointeurs sur fonction.
Votre rendu SVN doit être PROPRE. Ce qui veut dire que vous ne rendrez QUE les fichiers nécessaires à votre programme. Pas de fichiers objets ni de fichiers temporaires (a_temp_file.c~) et encore moins de binaires (a.out / libmy.a / libmy.so) !
Tout retour d'appels système autorisés (malloc, open, etc) doit être vérifié.
Bon courage !
