#include <iostream>
#include <vector>

using namespace std;

//stack class
class Stack {
    vector <string> vect;
    
    public:
        void push(string data){
            vect.push_back(data);
        }
        
        string pop(){
            string data = vect.back();
            vect.pop_back();
            return data;
        }
        
        int depth(){
            return vect.size();
        }
};

//Storage class
class Storage{
    string vars[100];
    int numVars = 0;
    
    public:
        void add(string input);
        void print();
};

//step class
enum Step{
    BEGIN,
    CONST,
    ID,
    OP,
    PAR,
    STATEMENT_OP,
    STATEMENT_ID,
    END_ID,
};