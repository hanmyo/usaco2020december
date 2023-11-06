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
  
    ll num[7] = {};
    for (int i = 0;i < 7;i++) {
        cin >> num[i];
    }
    sort(num, num + 7);
    for (int i = 0;i < 4;i++) {
        for (int j = i + 1;j < 5;j++) {
            for (int k = j + 1;k < 6;k++) {
                if (num[i] + num[j] + num[k] == num[6]) {
                    cout << num[i] <<' '<< num[j]<<' ' << num[k] << endl;
                }
            }
        }
    }


    
    return 0;
}