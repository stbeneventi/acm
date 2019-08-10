/*************************************************************************************************************************
 * 2062 - Easier Done than Said?
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=63
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 * Description:
 *   Este problema se resolvio utilizando una flag para optimizar un poco el problema, con el fin de no entrar en todos
 * los ciclos de comprobacion. Para resolver el problema se definieron 3 casos: El largo del string es 1, el largo del
 * string es 2, o el largo del string es mayor que 2. Para el primer caso, siguiendo las reglas enunciadas en el problema
 * basta con que la letra fuese vocal, para el segundo caso se evalua que exista al menos una vocal y que si son iguales
 * ambos caracteres que sean "ee" o bien "oo", para el tercer caso se emplea un ciclo, primero, se revisa si hay una
 * vocal, de ser así, se continua y se comprueba que el primer par de caracteres de ser iguales sean "ee" o bien "oo",
 * finalmente se entra en un ciclo que toma de 3 caracteres (aumentando de uno en uno) y hace 2 comprobaciones, primero
 * que los 3 caracteres no sean consonantes, ni vocales, luego se comprueba que las 2 ultimas de las 3 letras, de ser
 * iguales sean "ee" o "oo". (notar que se puede hacer esto ya que la primera comprobacion es hecha antes de entrar al
 * ciclo). Luego de esto se imprime si es un password valido o no.
 *
 *
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool checkVocal(char c){
	bool flag = false;

	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')flag=true;

	return flag;
}

main(){

	string linea;

	bool flag;

	int i;

	while(1){

		getline(cin,linea);

		if(linea=="end")break;

		flag = false;

		if(linea.size()==1){

			flag = false;
			if(checkVocal(linea[0]))flag = true;

		}
		else if(linea.size()==2){

			flag = false;
			if(!flag && checkVocal(linea[0]))flag = true;
			if(!flag && checkVocal(linea[1]))flag = true;

			if(flag && linea[0]==linea[1] && linea[0]!='e' && linea[0]!='o')flag = false;

		}
		else{

			flag = false;

			for(i=0;i<linea.size();i++){
				if(checkVocal(linea[i])){flag = true; break;}
			}

			if(flag && linea[0]==linea[1] && linea[0]!='e' && linea[0]!='o')flag = false;

			if(flag){

				for(i=0;i<linea.size()-2;i++){

					bool b1,b2,b3;
					b1 = checkVocal(linea[i]);
					b2 = checkVocal(linea[i+1]);
					b3 = checkVocal(linea[i+2]);

					if(b1==b2 && b2==b3){flag = false; break;}

					if(linea[i+1]==linea[i+2] && linea[i+1]!='e' && linea[i+1]!='o'){flag = false; break;}

				}
			}
		}

		if(flag)cout << "<" << linea << ">" << " is acceptable." << endl;
		else cout << "<" << linea << ">" << " is not acceptable." << endl;

	}
}
