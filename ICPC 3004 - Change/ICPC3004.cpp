/******************************************************************************************************************************
 * ICPC 3004 - Change
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=1005
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main(int argc,char **argv){

	int d1,d2;
	int cuesta,ofrece,dec,dif;
	bool space;

	while(true){

		scanf("%d.%d",&d1,&d2);
		cuesta=d1*100+d2;

		scanf("%d.%d",&d1,&d2);
		ofrece=d1*100+d2;

		if(cuesta == 0 && ofrece == 0){
			break;
		}

		dec = cuesta%10;

		cuesta = cuesta - dec;

		switch(dec){
			case 0:
			case 1:
			case 2:
				dec = 0;
				break;
			case 3:
			case 4:
			case 6:
			case 7:
				dec = 5;
				break;
			case 8:
			case 9:
				dec = 10;
				break;
		}

		cuesta = cuesta + dec;

		dif = ofrece - cuesta;

		if(dif < 0)
			cout << "Not enough money offered.";
		else {
			if(dif == 0)
				cout << "Exact amount.";
			else{
				int n;
				if(dif>=2000){
					n = dif/2000;
					cout << "$20*"<<n;
					dif = dif - n*2000;
					if(dif>0)cout << " ";
				}
				if(dif>=1000){
					n = dif/1000;
					cout << "$10*"<<n;
					dif = dif - n*1000;
					if(dif>0)cout << " ";
				}
				if(dif>=500){
					n = dif/500;
					cout << "$5*"<<n;
					dif = dif - n*500;
					if(dif>0)cout << " ";
				}
				if(dif>=200){
					n = dif/200;
					cout << "$2*"<<n;
					dif = dif - n*200;
					if(dif>0)cout << " ";
				}
				if(dif>=100){
					n = dif/100;
					cout << "$1*"<<n;
					dif = dif - n*100;
					if(dif>0)cout << " ";
				}
				if(dif>=50){
					n = dif/50;
					cout << "50c*"<<n;
					dif = dif - n*50;
					if(dif>0)cout << " ";
				}
				if(dif>=20){
					n = dif/20;
					cout << "20c*"<<n;
					dif = dif - n*20;
					if(dif>0)cout << " ";
				}
				if(dif>=10){
					n = dif/10;
					cout << "10c*"<<n;
					dif = dif - n*10;
					if(dif>0)cout << " ";
				}
				if(dif>=5){
					n = dif/5;
					cout << "5c*"<<n;
					dif = dif - n*5;
					if(dif>0)cout << " ";
				}
			}
		}

	cout << endl;

}
return 0;
}
