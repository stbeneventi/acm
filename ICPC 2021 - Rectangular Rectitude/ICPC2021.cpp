/******************************************************************************************************************************
 * ICPC 2021 - Rectangular Rectitude
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=22
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Block{
	private:
		int color;
		int x;
		int y;
	public:
		Block(int c, int x, int y){
			this->x = x;
			this->y = y;
			this->color = c;
		}
		int getX(){
			return this->x;
		}
		int getY(){
			return this->y;
		}
		int getColor(){
			return this->color;
		}
		void setColor(int c){
			this->color = c;
		}
};

class Canvas{
	private:
		int min_x;
		int min_y;
		int max_x;
		int max_y;
		int canvas[200][200];

	public:

		Canvas(){
			this->min_x = 200;
			this->min_y = 200;
			this->max_x = 0;
			this->max_y = 0;
			for(int i=0;i<200;i++){
				for(int j=0;j<200;j++){
					canvas[i][j] = 0;
				}
			}
		}

		int getNumberOfBlocks(int color){
			int ncolor = 0;
			for(int i=this->min_x;i<this->max_x;i++){
				for(int j=this->min_y;j<this->max_y;j++){
					if(this->canvas[i][j] == color){
						ncolor++;
					}
				}
			}
			return ncolor;
		}

		void paintRectangle(int color, int x1, int y1, int x2, int y2){
			if(x1 > x2){
				swap(x1,x2);
			}
			if(y1 > y2){
				swap(y1,y2);
			}
			x1 = x1 + 100;
			x2 = x2 + 100;
			y1 = y1 + 100;
			y2 = y2 + 100;
			//this is to optimizing cycles
			if(x1<this->min_x){
				this->min_x = x1;
			}
			if(y1<this->min_y){
				this->min_y = y1;
			}
			if(x2>this->max_x){
				this->max_x = x2;
			}
			if(y2>this->max_y){
				this->max_y = y2;
			}

			for(int i=x1;i<x2;i++){
				for(int j=y1;j<y2;j++){
					this->canvas[i][j]=color;
				}
			}

		}

		void printCanvas(){
			for(int j=this->max_y-1;j>=this->min_y;j--){
				for(int i=this->min_x;i<this->max_x;i++){
						cout << canvas[i][j];
				}
				cout << endl;
			}
		}

};

main(){
	int nRects,color;
	int col,x1,x2,y1,y2;
	int dataset = 1;
	cin >> nRects >> color;
	while(nRects!=0){
		Canvas cv;
		for(int i = 0 ; i < nRects ; i++){
			cin >> col >> x1 >> y1 >> x2 >> y2;
			cv.paintRectangle(col,x1,y1,x2,y2);
		}
		cout << "The area of color " << color << " in dataset " << dataset << " is: " << cv.getNumberOfBlocks(color) << endl;
		dataset++;
		cin >> nRects >> color;
	}

}
