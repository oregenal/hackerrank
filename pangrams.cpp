#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
	vector<int> abc(26, 0);

	for(size_t i = 0; i < s.size(); ++i) {
		if((s[i] - 'a') >= 0)
			abc[s[i] - 'a']++;
		else if((s[i] - 'A') >= 0)
			abc[s[i] - 'A']++;
	}

	for(size_t i = 0; i < 26; ++i)
		if(abc[i] == 0)
			return "not pangram";


	return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
