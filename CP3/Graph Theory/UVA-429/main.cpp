#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cmp(string s1, string s2) {
    int cnt = 0;
    if(s1.size() != s2.size()) return false;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) cnt++;
        if(cnt > 1) return false;
    }
    if(cnt) return true;
}

vector < vector<string> > rep;
map <string, int> mp;
bool vis[300];

int main()
{
    ofstream fp;
    fp.open("test.txt");

    int test;
    cin>>test;

    for(int t = 1; t <= test; t++) {
        string s;
        int l = 0;
        while(cin>>s && s != "*") {
            vector <string> temp;
            temp.push_back(s);
            for(int i = 0; i < l; i++) {
                if(cmp(rep[i][0], s)) {
                    rep[i].push_back(s);
                    temp.push_back(rep[i][0]);
                }
            }
            rep.push_back(temp);
            mp[s] = l;
            l++;
        }

        cin.ignore();
        while(getline(cin, s) && s.size()) {
            stringstream ss(s);
            string s1, s2;
            ss>>s1>>s2;


            queue <pair<string, int> > q;
            q.push(make_pair(s1, 0));
            vis[mp[s1]] = true;

            string str;
            int cnt, r;
            while(!q.empty()) {
                str = q.front().first, cnt = q.front().second, r = mp[str];
                if(str == s2) break;
                q.pop();

                for(int i = 1; i < rep[r].size(); i++) {
                    if(!vis[mp[rep[r][i]]]) {
                        // cout<<endl<<str<<" "<<mp[str]<<" "<<rep[r][i]<<" "<<cnt+1<<endl;
                        vis[mp[str]] = 1;
                        q.push(make_pair(rep[mp[str]][i], cnt+1));
                    }
                }
            }

            cout<<s1<<" "<<s2<<" "<<cnt<<endl;
            for(int i = 0; i < 300; i++) vis[i] = 0;
        }
        if(t != test) cout<<endl;
        //clearing
        mp.clear();
        rep.clear();
    }
}
