#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
using namespace std;

int main(int argc, char *argv[]){
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(filename);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	        tokens.push_back(nopunct);
		    unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
    ofstream setfile(filename + "_set.txt");
    ofstream vectfile(filename + "_vector.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
        cout << ' ' << *it;
        setfile << ' ' << *it;
    }
    for(auto& itr: tokens){
        vectfile << itr << endl;
    }
    cout << endl;
}

    