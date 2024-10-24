#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <functional>
#include <map>
using namespace std;

void initializeRandom() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

int randomm(int max) {
    return floor(static_cast<double>(rand()) / RAND_MAX * (max + 1));
}

int randomm(int min, int max) {
    return floor(static_cast<double>(rand()) / RAND_MAX * (max - min + 1)) + min;
}

string generateKey(int length, string characters) {
    string key = "";
    for (int i = 0; i < length; i++) {
        key += characters[randomm(characters.size() - 1)];
        //cout<<characters[randomm(characters.size() - 1)]<<endl;
    }
    return key;
}

struct FunctionInfo {
    function<void()> func;
    int argCount;
};

void m1(int x) {
    cout << x << endl;
}

void m2(int x, int y) {
    cout << x << " " << y << endl;
}

void m3(int x, int y, int z) {
    cout << x << " " << y << " " << z << endl;
}

int main() {
    //Завдання 1 і 2
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    cout<<generateKey(16, characters) << endl;

    //Завдання 3
    string IP;
    cout<<"ВВедіть IP адресу: ";
    cin>>IP;
    vector<int>ip;
    for (int i=0; i<IP.size(); i++){
        if (IP[i] == '.'){
            ip.push_back(stoi(IP.substr(0, i)));
            IP.erase(0, i+1);
            i=0;
        }
    }
    ip.push_back(stoi(IP));
    int sum=0;
    ip[0]=ip[0]<<8;
    ip[0]=ip[0]<<8;
    ip[0]=ip[0]<<8;
    ip[1]=ip[1]<<8;
    ip[1]=ip[1]<<8;
    ip[2]=ip[2]<<8;
    sum+=ip[0]+ip[1]+ip[2]+ip[3];
    cout<<"-> "<<sum<<endl;

    //Завдання 4
    map<string, FunctionInfo> iface;
    iface["m1"] = { []() { m1(0); }, 1 };
    iface["m2"] = { []() { m2(0, 0); }, 2 };
    iface["m3"] = { []() { m3(0, 0, 0); }, 3 };

    vector<vector<string>> result;
    for (const auto& [name, info] : iface) {
        result.push_back({ name, to_string(info.argCount) });
    }

    for (const auto& entry : result) {
        cout << "[" << entry[0] << ", " << entry[1] << "]" << endl;
    }

    return 0;
}
