#include <iostream>
#include <cstring>
using namespace std;
	char out[10];
	bool b[10] = {0,};
void perm(char a[],int k){
	int len=strlen(a);


	if(k==len){
		for (int i=0; i<len; i++){
			cout << out[i];
		}
		cout << endl;
		return;
	}
	else{
		for(int j=0; j<len; j++){
			if (b[j]==1){
				continue;
			}
			out[k] =	a[j];
			b[j]=1;
			perm(a,k+1);
			b[j]=0;
		}
	}
} 

int main(){
	char m[10];
	cin >> m;
	int k=0;
	perm(m,k);
	return 0;
} 
