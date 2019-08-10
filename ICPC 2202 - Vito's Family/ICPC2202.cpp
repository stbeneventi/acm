/******************************************************************************************************************************
 * 2202 - Vito's Family
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=203
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void bubbleSort(int v[], int num) {
	int temp,i,j;

	for (i=0;i<num-1;i++) {
		for (j=i+1;j<num;j++){
			if (v[i] > v[j]){
				temp=v[i];
				v[i]=v[j];
				v[j]=temp;
			}
		}
	}
}

int main(){
	int cases,nfam,i=0,j=0,streetn,optimal,sum;
	scanf("%d",&cases);
	int array[1000];
	for(i=0;i<cases;i++){
		scanf("%d",&nfam);
		for(j=0;j<nfam;j++){
			scanf("%d",&streetn);
			array[j]=streetn;
		}
		bubbleSort(array,nfam);
		if(nfam%2==0){
			optimal=array[nfam/2];
		}
		else{
			optimal=array[(nfam-1)/2];
		}
		sum=0;
		for(j=0;j<nfam;j++){
			sum=sum+abs(optimal-array[j]);
		}
		printf("%d\n",sum);
	}
}
