#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#define ll long long
using namespace std;

int main() {
  
    int n;
    cin >> n;
    vector<int>flower(n);
    for (int i = 0;i < n;i++) {
        cin >> flower[i];
    }
    vector<int>prefix(n + 1);
    prefix[0] = 0;
    int tot = 0;
    for (int i = 1;i <= n;i++) {
        tot += flower[i - 1];
        prefix[i] = tot;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            int diff = prefix[i] - prefix[j];
            double average = diff / (double)(i-j);
           
            bool has = false;
            for (int k = j+1;k <= i;k++) {
                if (flower[k-1] == average) {
                    has = true;
                    break;
                }
            }
            if (has)ans++;
        }
    }
    cout << ans << endl;

    
    return 0;
}