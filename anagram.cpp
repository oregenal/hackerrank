#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    size_t size = s.size();
    int counter = 0;
    if(size%2)
        return -1;
    for(size_t i = 0; i < size/2; ++i) {
        bool found = false;
        for(size_t j = i; j < size/2; ++j) {
            if(s[i] == s[size-1-j]) {
                int tmp = s[size-1-i];
                s[size-1-i] = s[size-1-j];
                s[size-1-j] = tmp;
                found = true;
                break;
            }
        }
        if(!found)
            counter++;
    }
    return counter;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
