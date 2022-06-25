vector<string> split(string& str) {
    vector<string> temp;
    int pos = str.find(" ");
    while (pos != string::npos) {
        temp.push_back(str.substr(0, pos));
        str = str.substr(pos + 1);
        pos = str.find(" ");
    }
    temp.push_back(str);
    
    return temp;
}
