#include<bits/stdc++.h>
using namespace std;
using ll=long long;
typedef struct log1{
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
}log1;

ll time_to_second(const string &time_str) {
    stringstream ss(time_str);
    ll h, m, sec;
    char kitu;

    if (ss >> h >> kitu >> m >> kitu >> sec) {
        return h * 3600 + m * 60 + sec;
    } else {
        return -1;
    }
}

bool checkphonenumber(const string &s){
    if(s.size() != 10) return false;
    for(char c : s){
        if(!isdigit(c)) return false;
    }
    return true;
}

int main(){
    string line;ll i=0;
    //vector<log1> calllog;
    unordered_map<string,ll> number_from;
    unordered_map<string,ll> cnt_time_call;
    bool ok = false;
    log1*calllog=(log1*)malloc(1000001*sizeof(log1));
    while(getline(cin,line) && line != "#"){
        stringstream ss(line);
        string command, from_number, to_number, date, from_time, end_time;
        ss >> command >> from_number >> to_number >> date >> from_time >> end_time;
        if(command == "call" && checkphonenumber(from_number) && checkphonenumber(to_number)){
            log1 new_call;
            new_call.from_number = from_number;
            new_call.to_number = to_number;
            new_call.date = date;
            new_call.from_time = from_time;
            new_call.end_time = end_time;
            //calllog.push_back(new_call);
            calllog[i++]=new_call;
            number_from[from_number]++;
            cnt_time_call[from_number] += time_to_second(end_time) - time_to_second(from_time);
            ok=true;
        }
    }

    while(getline(cin,line) && line != "#"){
        stringstream ss(line);
        string command, data;
        ss >> command >> data;
        if(command == "?check_phone_number"){
            cout << (ok ? "1" : "-1") << endl;
        } else if(command == "?number_calls_from"){
            cout << number_from[data] << endl;
        } else if(command == "?number_total_calls"){
            cout << i << endl;
        } else if(command == "?count_time_calls_from"){
            cout << cnt_time_call[data] << endl;
        }
    }
    free(calllog);
    return 0;
}