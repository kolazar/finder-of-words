#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	
	cout << "****-------------------Users that have no accordance in the second file---------------------****" << endl << endl << endl;
	cout << "Wait please until magic is done .... " << endl << endl;
	
	const long int len = 500000; 
	
	int i = 1; 
	string *s; // string which contains the first file
	s = new string[len];

	ifstream file("file1");

	while (getline(file, s[i], ','))
	{

		size_t pos = s[i].find("user");//finding  start position of necessary word
		if (pos == string::npos)
			continue;
		s[i].erase(s[i].begin(), s[i].begin() + pos);// erasing all instead of necessary substring

		i++;
	}

	file.close();

	int j = 1;
	string *s2;// string which contains the second file
	s2 = new string[len];

	ifstream file2("file2");

	while (getline(file2, s2[j], ','))
	{

		size_t pos = s2[j].find("user");
		if (pos == string::npos)
			continue;
		s2[j].erase(s2[j].begin(), s2[j].begin() + pos);

		 j++;
		 
	}

	file2.close();

	bool equal; // variable for cheking strings for equality
	string *temp; // string which contains all necessary words that have no accordance between files
	temp = new string [len]; 
	for(int k=1;k<i;k++)
	{
		for (int y = 1; y < len; y++)
		{
			if (s[k] != s2[y] && s[k] != " ") // checking for equality and empty strings
			{
				equal = true;
			}
			else {
				equal = false;
				break;
			}
		}
		if (equal) {
			temp[k] = s[k];
			cout << temp[k] << endl;
		}
		
	}

	delete[] s;
	delete[] s2;
	delete[]temp;

	system("pause");
	return 0;
}