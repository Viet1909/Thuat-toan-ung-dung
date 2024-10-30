#include<bits/stdc++.h>
using namespace std;

int n;

int sap_xep_khoang(vector<pair<int, int>>& intervals){
    sort(intervals.begin(), intervals.end(), [](pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    });
    int count = 0;
    int lastEnd = -1;
    for (auto& interval : intervals) {
        if (interval.first >= lastEnd) {
            count++;
            lastEnd = interval.second;
        }
    }

    return count;
}

int main(){
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for(int i = 0; i< n;i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    cout << sap_xep_khoang(intervals) << endl;
    return 0;
}