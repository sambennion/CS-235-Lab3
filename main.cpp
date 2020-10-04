#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
using namespace std;

map<list<string>, vector<string>> createMap(vector<string> tokens, const int M){
     map<list<string>, vector<string>> wordmap;
    list<string> state;
    for (int i = 0; i < M; i++) {
        state.push_back("");
        }
                            
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
     }
    return wordmap;
}
int main(int argc, char *argv[]){
    const int M = 2;
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
    ofstream mapfile(filename + "_map.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
        setfile << ' ' << *it;
    }
    for(auto& itr: tokens){
        vectfile << itr << endl;
    }
    map<list<string>, vector<string>> wordmap;
    wordmap = createMap(tokens, M);
    
   srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
    list<string> state;
    for (int i = 0; i < M; i++) {
    state.push_back("");
    }
    for (int i = 0; i < 200; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind]<<" ";
    mapfile << wordmap[state][ind] << " ";
    state.push_back(wordmap[state][ind]);
    state.pop_front();
    }
    cout << endl;
}

