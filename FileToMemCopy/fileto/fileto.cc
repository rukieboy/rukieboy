//rukieboy FileToMemCpy Test
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{


	FILE    *fp_sour;    // ���� ������ ���� ���� ��Ʈ�� ������
	FILE    *fp_dest;    // ���� ����� ���� ���� ��Ʈ�� ������
	char     buff[1024]; // ���� ������ �б�/���⸦ ���� ����
	size_t   n_size;     // �аų� ���⸦ ���� �������� ����
	
	

	fp_sour  = fopen( "Test.txt"  , "r");
	fp_dest  = fopen( "Output.txt", "w");

	while( 0 < (n_size = fread( buff, 1, 1024, fp_sour)))
	{
		//fwrite( buff, 1, n_size, fp_dest);
		//need to upload 
	}                            

	fclose( fp_sour);
	fclose( fp_dest);
	return 0;


	/*
	   ifstream infile("Test.txt"); 
	   ofstream outfile("output.txt");//for test

	   if(!infile.is_open())
	   {
	   cout << " file error"<<endl;
	   return -1;
	   }


	   char ch;
	   char line[75];
	   int i = 1;

	   while(fin.get(ch))
	   {
	   fin.get(line,75,'.');
	   fout<<"Line "<<i<<" : "<<line<<endl;
	   i++;
	   }

	 */

	/*

	   ifstream *infile_ptr;
	   infile_ptr = &infile;


	   char array[1000];


	   int i = 0;

	   cout << "before while"<<endl;

	   while(!infile.eof())
	   {
	   infile.getline(array,100);
	   cout<< array << endl;
	   outfile<<array<<endl;//for test
	   }
	 */

	/*
	   while(!infile.eof())
	   {
	//infile.getline(array,8);
	//cout<<array<<endl;
	//i= i+8;
	}
	 *?
	 cout << "after while"<<endl;

	 for (int j = 0; j <= i; j++)
	 {

	 cout << array[j];
	 } 

	/*
	ifstream *infile_ptr;
	infile_ptr = &infile;
	int i=0;

	int array[1000];
	memcpy(array,*infile_ptr,8);

	for (int i=0;i<8;++i)
	{

	}


	for (int j = 0; j <= i; j++)
	{

	cout << array[j];
	} 
	 */


}
