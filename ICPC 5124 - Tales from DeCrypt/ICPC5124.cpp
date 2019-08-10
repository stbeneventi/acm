/*************************************************************************************************************************
 * 5124 - Tales from DeCrypt
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=3125
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 * Description:
 *   Este problema no es tan sencillo de resolver como parece, porque ademas de la dificultad que trae por defecto tiene
 * un problema en el input: hay un caracter extra en la segunda linea, lo que produce errores de outputs (eliminando ese
 * caracter no deberia haber problema alguno). La idea es primero implementar el algoritmo de encriptado, para ver como
 * funciona, luego se define la funcion de desencriptacion. No es tan intuitivo, ya que la operacion mod, admite inversa
 * sólo en un dominio reducido, asi que para definir esta desencriptacion se deben examinar un par de elementos para
 * analizar su comportamiento, luego en base a eso, es posible intuir como seria esta operacion, para luego definirla.
 *
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int a,m,s;

int mod(int a,int b){
	if(a==0 || a%b==0)return 0;
	if(a>0)return a%b;
	if(a<0)return a%b+b;
}

double r(){
   double val = (s % m) / double(m);
   s = ( a * s + 1 ) % m;
   return val;
 }

void encrypt(char & c){
	int random;
	if(c<0x20 || c>0x7e)return;
	else{
		random=int(ceil(95-r()*95));
		c = mod(((c-32)+random),95)+32;
	}
}

void decrypt(char & c){
	int random;
	if(c<0x20 || c>0x7e)return;
	else{
		random=int(ceil(95-r()*95));
		c = mod(((c-32)-random),95)+32;
	}
}

main(){

	int i;
	char c;

	scanf("%d %d %d\n",&a,&m,&s);

	string linea;

	while(getline(cin,linea)){

		i=0;
		while(i<linea.size()){
			decrypt(linea[i]);
			i++;
		}
		cout << linea << endl;
	}

}
