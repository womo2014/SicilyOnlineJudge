#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int girl[5000] = {0, };
	int score[5000];
	//��¼���� 
	for ( int i = 0; i < n; i++ )
		cin >> score[i];
	//һ�θ��������� 
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			if ( score[i] < score[j] )
				girl[i]++;
	//������ǵ����� 
	for ( int i = 0; i < n; i++ )
		cout << girl[i]+1 << endl;
	
	return 0;
}
