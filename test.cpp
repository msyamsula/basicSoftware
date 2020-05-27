#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
/*
 * Complete the 'configureProjectPresentation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY friendships
 */

vvl graph;
vl visited;
vl invited;

vector<int> configureProjectPresentation(int n, vector<vector<int>> friendships) {
    graph.resize(0); graph.resize(n);
    ll m = friendships.size();
    visited.resize(0); visited.assign(n, 0);
    invited.resize(0); invited.assign(n, 0);
    for(ll i=0; i<m; i++){
        ll u = friendships[i][0], v = friendships[i][1];
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    queue<ll> q; q.push(0);
    visited[0] = 1;
    invited[1] = 0;
    invited[0] = 0;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(ll v : graph[u]){
            if (visited[v] == 0 && v != 1){
                // cout << v+1 << endl;
                visited[v] = 1;
                q.push(v);
                invited[v] = 1;
            }
        }
    }
    
    // for(ll num : invited){
    //     cout << num << ' ';
    // }
    // cout << endl;
    
    visited.resize(0); visited.assign(n, 0);
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(ll v : graph[u]){
            if (visited[v] == 0 && v != 0){
                visited[v] = 1;
                q.push(v);
                invited[v] = 0;
            }
        }
    }
    
    vector<int> ans;
    for(ll i=1; i<n; i++){
        if(invited[i]) ans.push_back(i+1);
    }
    
    if (ans.empty()) return {-1};
    
    return ans;

}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> freiendships(m);

        for (int i = 0; i < m; i++) {
            freiendships[i].resize(2);

            string freiendships_row_temp_temp;
            getline(cin, freiendships_row_temp_temp);

            vector<string> freiendships_row_temp = split(rtrim(freiendships_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int freiendships_row_item = stoi(freiendships_row_temp[j]);

                freiendships[i][j] = freiendships_row_item;
            }
        }

        vector<int> result = configureProjectPresentation(n, freiendships);

        for (int i = 0; i < (int)result.size(); i++) {
            cout << result[i];

            if (i != (int)result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    // fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
