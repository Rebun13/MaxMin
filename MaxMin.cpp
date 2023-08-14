#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <sstream>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);
int subMaxMinAlt(vector<int> current, vector<int> remaining, int k);

/*
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

string vectorToString (vector<int> v) {
    stringstream ss;
    for (auto it = v.begin(); it != v.end(); it++)    {
        if (it != v.begin()) {
            ss << " ";
        }
        ss << *it;
    }
    return ss.str();
}

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int maxmin = INT_MAX;
    for (int i = 0; i < arr.size() - k + 1; i++) {
        int newMaxmin = arr[i + k - 1] - arr[i];
        if(newMaxmin < maxmin) maxmin = newMaxmin;
    }
    return maxmin;
}

int maxMinAlt(int k, vector<int> arr) {
    return subMaxMinAlt(vector<int> {}, arr, k);
}

int subMaxMinAlt(vector<int> current, vector<int> remaining, int k) {
    int maxmin = INT_MAX;
    if(k == 1) {
        for(int i : remaining) {
            current.push_back(i);
            cout << "NEW: " << vectorToString(current) << endl;
            int newMaxmin = *(max_element(current.begin(), current.end())) - *(min_element(current.begin(), current.end()));
            if(newMaxmin < maxmin) {
                cout << vectorToString(current) << " : " << *max_element(current.begin(), current.end()) << " / " << *min_element(current.begin(), current.end()) << " - " << newMaxmin << endl;
                maxmin = newMaxmin;
            }
            current.pop_back();
        }
    } else {
        for(int i = 0; i < remaining.size() - k + 1; i++) {
            current.push_back(remaining[i]);
            int newMaxmin = subMaxMinAlt(
                current,
                vector<int>(remaining.begin() + i + 1, remaining.end()),
                k - 1
            );
            if(newMaxmin < maxmin) maxmin = newMaxmin;
            current.pop_back();
        }        
    }
    return maxmin;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(),
        s.end()
    );

    return s;
}
