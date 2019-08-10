/******************************************************************************************************************************
 * ICPC 4007 - Counting Squares
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=2008
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class par{
	private:

	public:
		int x;
		int y;

		par(int a,int b){
			x=a;
			y=b;
		}

		void print();

};

bool compare(const par& a, const par& b) {
	if(a.x==b.x)return b.y < a.y;
	return a.x < b.x;
}

void par::print(){
	printf("[%d,%d]\n",this->x,this->y);
}

int main(){
	vector<par> lineas;
	string h;
	int px,py,ax,ay;
	int n,k;
	int i,j;
	int sum;
	int casos;
	getline(cin,h);
	casos=(h[0]-48);
	for(i=0;i<casos;i++){
		getline(cin,h);
		n=h.size();
		px=0;
		py=0;
		ax=0;
		ay=0;
		for(j=0;j<n;j++){
			if(h[j]=='U')py++;
			else if (h[j]=='D')py--;
			else if (h[j]=='L')px--;
			else if (h[j]=='R')px++;
			else {
				break;
			}
			if(ay==py)
                if(px<ax){
                    lineas.push_back(par(px,py));
                }
                else {
                    lineas.push_back(par(ax,py));
                }
            ax=px;
            ay=py;
        }

		sort(lineas.begin(),lineas.end(),compare);
		k=lineas.size();
		sum=0;
		for(j=0;j<k;j=j+2){
			sum=sum+(lineas[j].y-lineas[j+1].y);
		}
		printf("case %d: %d\n",i+1,sum);
		lineas.clear();
	}
}
