#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */
const int mon7 = 215; //7 months' days

string dayOfProgrammer(int year)
{
    short int feb; //days in february
    if(year < 1918) //julian
        feb = year%4 ? 28 : 29;
    else if(year > 1918) //gregorian
        feb = (!(year%400) || (year % 100 && !(year%4)) ? 29 : 28);
    else //dreaded 1918
        feb = 15;
    feb = 256 - (feb + mon7);
    return to_string(feb) + ".09." + to_string(year);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

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
