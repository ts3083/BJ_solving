#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string a = "안녕하세요";
    vector<string> kor;
    for (int i = 0; i < a.size(); i += 3) {
        kor.push_back(a.substr(i, 3)); 
    }
    cout << kor[0]; // 안
  
    return 0; 
}
