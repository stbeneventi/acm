/*************************************************************************************************************************
 * 2014 - Are We There Yet?
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=15
 *
 * Classification: String Processing
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 * Description:
 *   La idea de este problema es que dado un número ubicación de una galleta, un niño se mueve de un casillero a otro,
 * si se acerca a la galleta, se imprime "warmer.", si se aleja se imprime "colder.", si se mantiene se escribe "same."
 * y si la encuentra "found it!". El problema aquí es que el número de pasos que da el niño para encontrar la galleta es
 * indefinido, por lo que, hay que procesar los strings con cuidado, y manejar situaciones límites. Por otra parte, hay
 * una dificultad extra, que sólo hay un salto de línea extra entre los distintos outputs, y no al final. Lo raro aquí
 * es que si esto está incorrecto, el sistema no arroja "Presentation Error", sino "Wrong Answer".
 *
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(){
		int answer;
		int pos,pos_old;
		int dif1,dif2;
		int aux;
		char c;

		char numero[6];

		scanf("%d",&answer);
		while(1){

			pos=0;

			while(1){

				scanf("%c",&c);
				while(c==' '){
					scanf("%c",&c);
				}
				if(c=='\n')break;

				aux=0;
				while(c!=' ' && c!='\n'){
					numero[aux]=c;
					aux++;
					scanf("%c",&c);
				}
				numero[aux]='\0';

				pos_old=pos;
				pos=atoi(numero);

				printf("Moving from %d to %d: ",pos_old,pos);

				if(answer==pos){
					printf("found it!\n");
					break;
				}
				else{
					dif1=abs(answer-pos);
					dif2=abs(answer-pos_old);

					if(dif1<dif2){
						printf("warmer.\n");
					}
					else if (dif1>dif2){
						printf("colder.\n");
					}
					else {
						printf("same.\n");
					}
				}

			}

			scanf("%d",&answer);



			if(answer<=-5280 || answer>=5280)break;

			printf("\n");

		}
}
