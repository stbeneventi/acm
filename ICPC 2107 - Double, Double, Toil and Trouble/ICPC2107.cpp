/*************************************************************************************************************************
 * 2107 - Double, Double, Toil and Trouble
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=108
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 * Description:
 *   Este problema es trivial, solo basta con ingresar todas las variables, y ver si T y V, se encuentran dentro de la
 * region definida por los 2 upper bound, y los 2 lower bound.
 *
 */

#include <iostream>
#include <stdio.h>

using namespace std;


main(){

	bool flag;

	float flba,flbb,flbc;
	float slba,slbb,slbc;
	float fuba,fubb,fubc;
	float suba,subb,subc;
	float T,V;

	int casos;

	scanf("%d",&casos);

	for(int i=1;i<=casos;i++){
		scanf("%f %f %f",&flba,&flbb,&flbc);
		scanf("%f %f %f",&slba,&slbb,&slbc);
		scanf("%f %f %f",&fuba,&fubb,&fubc);
		scanf("%f %f %f",&suba,&subb,&subc);
		scanf("%f %f",&T,&V);

		flag = true;

		if(flag && !(flbc<=flba*T+flbb*V))flag = false;
		if(flag && !(slbc<=slba*T+slbb*V))flag = false;

		if(flag && !(fuba*T+fubb*V<=fubc))flag = false;
		if(flag && !(suba*T+subb*V<=subc))flag = false;

		if(flag)printf("%d SAFE\n",i);
		else printf("%d UNSAFE\n",i);
	}

}
