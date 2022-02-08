#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
	int abc[26] = {0};
	vector<int>container;
	bool gotit = false;

	for(size_t i = 0; i < s.size(); ++i) {
		++abc[s[i] - 'a'];
	}

	for(int i = 0; i < 26; ++i) {
		if(abc[i] > 0) {
			container.push_back(abc[i]);
		}
	}

	sort(container.begin(), container.end());

	for(size_t i = 0; i < container.size()-1; ++i) {
		if(container[i] != container[i+1]) {
			if(gotit)
				return "NO";
			else
				gotit = true;
		}
	}

	return "YES";
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
