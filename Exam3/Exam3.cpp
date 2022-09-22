#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n;
	ifstream fin;
	vector<string> library;

	bool in;
	bool in1;
	int size = 0;
	string word;
	vector<string> mistakes;
	string letter;
	int trying = 8;

	fin.open("file.cpp");
	if (!fin)
	{
		cout << "ERROR!";
	}
	while (!fin.eof())
	{
		getline(fin, word);
		library.push_back(word);
		size++;
	}
	fin.close();
	n = rand() % size;
	word = library[n];
	string result;
	cout << word;
	
	for (size_t i = 0; i < word.size(); i++)
	{
		if (i == 0 || i == word.size()-1)
		{
			result.push_back(word[i]);
		}
		else
		{
			result.push_back('_');
		}
	}


    while(mistakes.size() != trying)
	{
		in1 = true;
		in = false;
		for (size_t j = 0; j < result.size(); j++)
		{
			if (result[j] != '_') continue;
			else
			{
				in1 = false;
			}
		}
		if (result.size() == 0)
		{
			in1 = false;
		}
		cout << endl;
		for (size_t j = 0; j < result.size(); j++)
		{
			cout << result[j] << " ";
		}
		cout << "\nMistakes ( " << mistakes.size() << " ):	";
		for (size_t j = 0; j < mistakes.size(); j++)
		{
			cout << mistakes[j];
			if (j != mistakes.size() - 1)
			{
				cout << ", ";
			}
			else
			{
				cout << ". ";
			}
		}
		if (in1 == true)
		{
			cout << "\n\nCongratulations, you won! ";
			return 0;
		}
		while (letter.size() == 0 || letter.size() > 1)
		{
			cout << "\nLetter:	";
			cin >> letter;
		}

		for (size_t j = 0; j < word.size(); j++)
		{
			if (word[j] == letter[0])
			{
				result[j] = word[j];
				in = true;
			}
		}
		if (in == false)
		{
			mistakes.push_back(letter);
		}
		letter.clear();
	}
	cout << "\nYou lose!";
}