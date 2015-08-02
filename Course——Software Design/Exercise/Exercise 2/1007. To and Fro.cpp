// Problem#: 1007
// Submission#: 2944977
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;//nΪ��Ҫ������ĸ�������������Ϊ0���ʾ������� 
	string word;//������ʱ����������ַ��� 
    
	cin >> n;
    
	while (n != 0) // ��������nΪ0������ѭ�� 
	{
          //�����ַ��� 
		  cin >> word;
          int m = word.size()/n; //���������ַ�����Сȷ������m 
          
		  char letters[m][n];//�����ȡ�ַ������ַ����� ������ 
          
		  int k = 0; 
		  for (i = 0; i < m; i++) //�������Һʹ����������ȡ�ַ�����ÿ���ַ� 
		  {
              if (i % 2 == 0) //�жϵ�i����0��ʼ������������ż�� 
			  {
                 for (j = 0; j < n; j++) //iΪ�������������Ҷ�ȡ 
				 {
                     letters[i][j] = word[k++];
                 }
              } 
			  else 
			  {
                 for (j = n-1; j >= 0; j--) //iΪż�������������ȡ 
				 {
                     letters[i][j] = word[k++];
              	 }
              }
          }
          //�������е��ַ���������һ��һ����� 
		  for (j = 0; j < n; j++)
		  {
              for (i = 0; i < m; i++)
			  {
                  cout << letters[i][j];
              }
          }
          cout << endl;
          
		  cin >> n;
    }
    return 0;
}
