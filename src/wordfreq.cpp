#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> WordPair;

bool cmp(const WordPair &lhs, const WordPair &rhs)
{
	return (lhs.second != rhs.second) ? (lhs.second > rhs.second) : (lhs.first != rhs.first ? lhs.first > rhs.first : false);
}

int main(int argc, char *argv[])
{
	// read input words.
	string word;
	map<string, int> word_map;
	while (cin >> word)
	{
		if (word_map[word] == NULL)
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
    return 0;
}
