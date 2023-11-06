#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<math.h>
#define ll long long
using namespace std;


int main() {
  
    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, int> >east;
    vector<pair<pair<ll, ll>, int> >north;
    char dir;
    ll x, y;
    for (int i = 0;i < n;i++) {
        cin >> dir >> x >> y;
        if (dir == 'E') {
            east.push_back(make_pair(make_pair(y,x),i ));
        }
        else {
            north.push_back(make_pair(make_pair(x,y),i ));
        }
    }
    int ans[1000] = { 0 };
    int grazed[1000] = { 0 };
    sort(east.begin(), east.end());
    sort(north.begin(), north.end());
    for (int i = 0;i < east.size();i++) {
        for (int j = 0;j < north.size();j++) {
            if (grazed[north[j].second] == 0) {
                if (north[j].first.first > east[i].first.second && north[j].first.second < east[i].first.first) {
                    ll right = north[j].first.first - east[i].first.second;
                    ll up = east[i].first.first - north[j].first.second;
                    if (right > up) {
                        grazed[east[i].second] += right;
                        grazed[east[i].second] *= -1;
                        ans[north[j].second]++;
                        ans[north[j].second] += ans[east[i].second];
                        break;
                    }
                    else if (right < up) {
                        grazed[north[j].second] += up;
                        grazed[north[j].second] *= -1;
                        ans[east[i].second]++;
                        ans[east[i].second] += ans[north[j].second];
                    }
                    
                }
            }
        }
    }
    
    for (int i = 0;i < n;i++) {
        cout << ans[i]<<endl;
    }
    
    return 0;
}