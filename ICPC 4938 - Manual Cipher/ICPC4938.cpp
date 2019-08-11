/*************************************************************************************************************************
 * 4938 - Manual Cipher
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=2939
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv){

string codeword;
getline(cin,codeword);

int n = (codeword.size()-1)/2;
int code[n];
for(int i=0;i<n;i++){
    code[i] = codeword[i+n+1]-'0';
}

while(!cin.eof()){
    string encrypt;
    getline(cin,encrypt);
    int size = encrypt.size();
    if(size==0)
        continue;
    for(int i=0,cycle=0;i<size;cycle=(cycle+1)%n){
        for(int j=0;j<code[cycle]&&i<size;j++,i++){
            char c = ' ';
            char e = encrypt[i];
            if(e == ' ')
               e = 'Z' + 1;
            if(codeword[cycle] <= e)
                c = (e-codeword[cycle])+'a';
            else
                c = e - 'A' + 2 + ('Z' - codeword[cycle])+'a';
            if(c == 'z'+1)
                c = ' ';
            if(!cin.eof() || i!=size-1 || j!=code[cycle]-1 )
                cout << c;
         }
    }
    cout << endl;
}
return 0;
}
