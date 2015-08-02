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
    int n;//n为所要构造字母矩阵的列数，若为0则表示输入结束 
	string word;//用于暂时储存输入的字符串 
    
	cin >> n;
    
	while (n != 0) // 如果输入的n为0，跳出循环 
	{
          //输入字符串 
		  cin >> word;
          int m = word.size()/n; //根据输入字符串大小确定行数m 
          
		  char letters[m][n];//定义读取字符串的字符数组 （矩阵） 
          
		  int k = 0; 
		  for (i = 0; i < m; i++) //从左向右和从右向左交替读取字符串的每个字符 
		  {
              if (i % 2 == 0) //判断第i（从0开始）是奇数还是偶数 
			  {
                 for (j = 0; j < n; j++) //i为奇数，从左向右读取 
				 {
                     letters[i][j] = word[k++];
                 }
              } 
			  else 
			  {
                 for (j = n-1; j >= 0; j--) //i为偶数，从右向左读取 
				 {
                     letters[i][j] = word[k++];
              	 }
              }
          }
          //将矩阵中的字符从左向右一列一列输出 
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
