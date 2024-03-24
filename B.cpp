#include <bits/stdc++.h>
using namespace std;

#define db(v) for (auto x: v) cout<<x<<" "; cout<<endl;
#define dbii(v) for (auto x: v) cout<<x.first<<" "<<x.second<<endl;

vector<int> ans(100010);

// Function to build the longest prefix suffix (lps) array for the pattern
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int patternLen = pattern.length();
    int len = 0; // Length of the previous longest prefix suffix

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < patternLen) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<vector<int>> adj(100010);

// Function to perform pattern searching using the KMP algorithm
void KMPSearch(const string& text, const string& pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();

    // Create lps array to store the longest prefix suffix values
    vector<int> lps(patternLen, 0);

    // Preprocess the pattern to build the lps array
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]
    //cout<<pattern<<endl;
    //vector<int> vv;
    while (i < textLen) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == patternLen) {
            //cout << "index " << i - j << endl;
            int pos = i - j;
            
            // ==============================
            adj[pos].push_back(patternLen+pos);
            // ==============================
            
            
            j = lps[j - 1];
        } else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    //db(vv);
}

int main() {
	/*
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern to search: ";
    cin >> pattern;*/
    int n; cin>>n;
    vector<string> v(n);
    for (int i = 0; i <n; i++)
    {
    	cin>>v[i];
    }
    string s; cin>>s;
    for (int i = 0; i < n; i++)
    {
    	KMPSearch(s,v[i]);
    }
   // sort(vv.begin(), vv.end());
   // cout<<vv.size()<<endl;
    //dbii(vv);
    
    queue<int> q; q.push(0);
    vector<int> visited(100010,0);
	visited[0] = 1;
    while (!q.empty())
    {
    	int ve = q.front(); q.pop();
    	for (auto u: adj[ve])
    	{
    		if (!visited[u])
    		{
    			visited[u] = 1;
    			q.push(u);
    		}
    	}
    }
    cout<<(visited[s.length()]?"YES":"NO")<<endl;

    return 0;
}