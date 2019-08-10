/******************************************************************************************************************************
 * ICPC 5006 - Binary Number
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=1046
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc,char **argv){

int day=1, gold;
int diat=0;
while(true){
    gold = 0;
    diat = 0;
    cin >> day;
    if(day == 0)
	break;
    if(day == 1){
       gold = 1;
    }else if(day == 2){
       gold = 3;
   }else{
    for(int i = 1; i < day;i++) {
      for(int j=1;j<=i;j++){
	      gold += i;
		  diat++;
		  if(diat==day)break;
 	   }
		  if(diat==day)break;
    }
}
    printf("%d %d\n",day,gold);
}

return 0;
}
