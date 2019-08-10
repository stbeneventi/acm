/******************************************************************************************************************************
 * ICPC 5006 - Binary Number
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=3007
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int f(int a, int b){
	int dif=0;
	int may,min;
	if(a<b)	{may=b;min=a;}
	else	{may=a;min=b;}
	while(min>0){
		if(may%2!=min%2){
			dif++;
		}
		min=min/2;
		may=may/2;
	}
	while(may>0){
		if(may%2)dif++;
		may=may/2;
	}
	return dif;
}

int main(){

	int casos;
	int n,m;
	int i,j,k;
	int temp;
	vector<int> A;
	vector<int> B;
	int min,mini;

	scanf("%d",&casos);

	for(i=0;i<casos;i++){
		scanf("%d %d",&m,&n);

		for(j=0;j<m;j++){
			scanf("%d",&temp);
			A.push_back(temp);
		}

		sort(A.begin(),A.begin()+m);

		for(j=0;j<n;j++){
			scanf("%d",&temp);
			B.push_back(temp);
		}

		for(j=0;j<n;j++){
			min=10000000;
			for(k=0;k<m;k++){
				temp=f(A[k],B[j]);
				if(temp<min){
					min=temp;
					mini=k;
				}
			}
			printf("%d\n",A[mini]);
		}
		A.clear();
		B.clear();
	}
}
