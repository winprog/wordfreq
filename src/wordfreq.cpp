#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#if WIN32
extern "C" {
#include "getopt.h" 
}
#else
#include <unistd.h>
#endif


using namespace std;

typedef pair<string, int> WordPair;

bool cmp(const WordPair &lhs, const WordPair &rhs)
{
	return (lhs.second != rhs.second) ? (lhs.second > rhs.second) : (lhs.first != rhs.first ? lhs.first > rhs.first : false);
}

int main(int argc, char *argv[])
{
	// cin, cout redirection.
	int ch;
	char *infile = NULL;
	char *outfile = NULL;
	streambuf *inback = NULL;
	streambuf *outback = NULL;
	ifstream fin;
	ofstream fout;

	while ((ch = getopt(argc, argv, "i:o:")) != -1)
	{
		switch (ch)
		{
		case 'i':
			infile = optarg;
			break;
		case 'o':
			outfile = optarg;
			break;
		}
	}

	if (infile != NULL)
	{
		fin.open(infile);
		inback = cin.rdbuf();
		cin.rdbuf(fin.rdbuf());
	}

	if (outfile != NULL)
	{
		fout.open(outfile);
		outback = cout.rdbuf();
		cout.rdbuf(fout.rdbuf());
	}

	// read input words.
	string word;
	map<string, int> word_map;
	while (cin >> word)
	{
		if (word_map[word] == 0)
		{
			word_map[word] = 1;
		}
		else
		{
			++word_map[word];
		}
	}

	// sort by freq and name.
	vector<WordPair> sort_words(word_map.begin(), word_map.end());
	sort(sort_words.begin(), sort_words.end(), cmp);

	for (vector<WordPair>::iterator it = sort_words.begin(); it != sort_words.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}

	// restore cin and cout.
	if (inback != NULL)
	{
		cin.rdbuf(inback);
	}

	if (outback != NULL)
	{
		cout.rdbuf(outback);
	}
    return 0;
}
