/******************************************************************************************************************************
 * ICPC 2483 - House Numbering
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=484
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b;
	int i,set=0;
	int numero,precio;
	char palabra[8];
	char c;

	scanf("%c",&c);
	while (1){
		if(c=='#'){
			break;
		}
		else {
				set++;
				printf("Set %d\n",set);
				while(c!=' '){
					scanf("%c",&c);
				}
				scanf("%c",&c);
				i=0;
				while(c!=' '){
					palabra[i]=c;
					scanf("%c",&c);
					i++;
				}
				palabra[i]=c;
				a=atoi(palabra);
				scanf("%c",&c);
				i=0;
				while(c!='\n'){
					palabra[i]=c;
					scanf("%c",&c);
					i++;
				}
				palabra[i]=c;
				b=atoi(palabra);
				scanf("%c",&c);
				while(c!='#' && c!='C'){
					i=0;
					while(c!='\n'){
						palabra[i]=c;
						scanf("%c",&c);
						i++;
					}
					palabra[i]=c;
					numero=atoi(palabra);
					precio=0;
					while(numero!=0){
						if(numero%2==0)precio=precio+a;
						else precio=precio+b;
						numero=numero/2;
					}
					printf("%d\n",precio);
					scanf("%c",&c);
			}
		}
	}
}
