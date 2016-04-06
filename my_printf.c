/*
** my_printf.c for Projet_my_printf in /Users/vanhem_n/Documents/printf/my_printf.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 09:05:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 16:35:10 2016 VANHEMELRYCK nathan
*/

#include "include.h"

/* Les fonction de mon printf*/
a_opt tabopt [8] = {
	{'i', &opt_i},
	{'s', &opt_s},
	{'c', &opt_c},
	{'d', &opt_i},
	{'o', &opt_o},
	{'u', &opt_u},
	{'X', &opt_X},
	{'x', &opt_x},
};

/* Donne l'index de la fonction qui correspond a la clef */
int 			heycestquoilakey(char car){
	int 		ir;
	if (car == 's' || car == 'i' || car == 'c' || car == 'd' ||  car == 'o' 
		|| car == 'u' || car == 'X' || car == 'x'){
		for (ir = 0; car != tabopt[ir].key; ir++){
		}

		return (ir);
	}
	return (-1);
}

/* Fonction principale */
int 			my_printf(char* ok, ...) {
	int 		ir;
	void* 		typed;
	va_list 	argptr;
	va_start	(argptr, ok);
	void* 		truck;

	for (ir = 0, typed = ok; ok[ir] != '\0'; ir++){
		if (ok[ir] == '%'){ 
			((ok[ir + 1]) == '%')? my_putchar('%'), ok++ : 0;
			if (heycestquoilakey(ok[ir + 1]) != -1){
				truck = va_arg(argptr,typeof(typed));
				tabopt[heycestquoilakey(ok[ir + 1])].pf((void *)truck);
				ok++;
				typed = truck;
			}
		}
		else
			my_putchar(ok[ir]);
	}
	va_end(argptr);
	return (0);
}

int 		main(void){
	my_printf("1 - une chaine\n");
	my_printf("2 - %s\n", "une autre chaine");
	my_printf("3 - %i\n", 42);
	my_printf("4 - %s %d %s%c", "avec", 4, "parametres", '\n');
	my_printf("1 - %o\n", 42); /* unsigned octal */
	my_printf("2 - %u\n", (unsigned int)4200000000); /* unsigned decimal */
	my_printf("3 - %x\n", 42); /* unsigned hexadecimal */
	my_printf("4 - %X\n", 42); /* unsigned hexadecimal */
	my_printf("5 - %d%%\n", 42);
	return 0;
}