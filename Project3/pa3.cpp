#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctype.h>
#include<valarray>
#include<string.h>
#include "pa3.h"

using namespace std;

/*
 * Blas Kojusner
 * pa3
 */


//print method of Storage class
void Storage::print(){
    //for loop to check value of print
    for(int i = 0; i != 100; ++i){
        cout << vars[i] << " ";
    }
    
    cout << "\n";
}

//add method of Storage class
void Storage::add(string input){
    //for loop to check value of add
    for(int i = 0; i != 100; ++i){
        if(vars[i] == input)
            break;
        
        else if(vars[i] == ""){
            vars[i] = input;
            break;
        }
        
        else
            continue;
    }
}

//method to check case of equals
bool lowCaseEqual(string id){
    //declaring variables
    char temp;
    bool equals = false;
    int tempL = id.length();
    
    //for loop checking boolean of lowCaseEqual
    for(int i = 0; i < tempL; ++i){
        //declaring variable
        temp = id.at(i);
        
        //checking case of value
        if(isupper(temp) == true){
            return false;
        }
        if(temp == '='){
            equals = true;
        }
    }
    
    return equals;
}

//identifier method
string idSearch(string token){
    //declaring variables
    string id = "";
    
    //for loop searching for token
    for(int i = 0; i < token.length(); ++i){
        if(token.at(i) == '='){
            break;
        }
        else
            id = id + token.at(i);
    }
    
    return id;
}

//identifier method part 2
string idSearchInLoop(string token){
    //declaring variable
    string id = "";
    
    //for loop searching for id
    for(int i = 0; i < token.length(); ++i){
        if(islower(token.at(i)))
            id = id + token.at(i);
        else
            continue;
    }
    
    return id;
}

//constant method
string constFinder( string token){
    //declaring variables
    string id = "";
    int constC = 0;
    
    //for loop finding const
    for(int i=0; i < token.length(); ++i){
        //declaring variables
        constC = token.at(i) + 0;
        
        if((48 <= constC) && (constC <= 57)){
            id = id + token.at(i);
        }
    }
    
    return id;
}

//operator method
string opFinder(string token){
    //declaring variable
    string id = "";
    
    //for loop finding operator
    for(int i = 0; i < token.length(); ++i){
        if(token.at(i) == ')'){
            break;
        }
        id = id + token.at(i);
    }
    return id;
}

//delimiter method
string delimFinder(string token){
    //for loop finding delimeter
    for(int i = 0; i < token.length(); ++i){
        if(token.at(i) == ',')
            return ",";
        else if(token.at(i) == ';')
            return ";";       
        else
            continue;
    }
    return "";
}

//main method
int main(){
    //declaring variables
    Storage Keyword;
    Storage Identifiers;
    Storage Constants;
    Storage Operators;
    Storage Delimiter;
    Storage Errors;
    Step step = ID;
    string nextT;
    string fileName;
    int depth = 1;
   
    //taking user input
    cout << "Please enter the name of the input file:";
    cin >> fileName;
    ifstream file;
    file.open(fileName);
    
    //checking to see if file is open
    if(!file.is_open()){
        cout << "Error while opening file\n";
        exit(0);
    }
    
    //while loop to begin reading process
    while(!file.eof()){
        //declaring variable
        file >> nextT;
        
        //switch statements for all cases
        switch(step){
            //begin case
            case BEGIN:
                if(nextT == "BEGIN"){
                    step = ID;
                    Keyword.add(nextT);
                }
                else{
                    Errors.add(nextT);
                    step = ID;
                }
                break;
            
            //identifier case    
            case ID:
                if(nextT == "FOR"){
                    step = PAR;
                    Keyword.add(nextT);
                }        
                else if(lowCaseEqual(nextT)){
                    step = STATEMENT_OP;
                    Operators.add("=");
                    Identifiers.add(idSearch(nextT));
                }
                else{
                    Errors.add(nextT);
                }
                break;
            
            //constant case   
            case CONST:
                Constants.add(constFinder(nextT));
                step = OP;
                break;
            
            //operator case
            case OP:
                if(nextT.at(nextT.length()-1 && nextT.at(nextT.length()-2)) == ')'){
                    Errors.add(")");
                }
                Operators.add(opFinder(nextT));
                step = BEGIN;
                break;
              
            //par case
            case PAR:                
                if(nextT.at(0) == '('){
                    if(nextT.at(1) == '('){
                        step = CONST;
                        Errors.add("(");
                    }
                    if(islower(nextT.at(1))){
                        if(nextT.at(2) == ','){
                            step = CONST;
                        }
                    }
                }
                Identifiers.add(idSearchInLoop(nextT));
                Delimiter.add(delimFinder(nextT));
                break;
             
            //operator statement case
            case STATEMENT_OP:
                Operators.add(nextT);
                step = STATEMENT_ID;
                break;
                
            //identifier statement case
            case STATEMENT_ID:
                if(nextT.at(nextT.length()-1) == ';'){
                    Delimiter.add(";");
                    step = END_ID;
                    Identifiers.add(idSearchInLoop(nextT));
                }
                else{
                    step = STATEMENT_OP;
                    Identifiers.add(nextT);
                }
                break;
            
            //end case    
            case END_ID:
                if(nextT == "END"){
                    step = PAR;
                    Keyword.add(nextT);
                }
                else if(lowCaseEqual(nextT)){
                    step = STATEMENT_OP;
                    Operators.add("=");
                    Identifiers.add(idSearch(nextT));
                }
                else{
                    Errors.add(nextT);
                }
    
        }
   
    }
    
    //printing results
    cout << "The depth of nested loop(s) is " << depth << "\n";
    cout << "Keywords: ";
    Keyword.print();
    cout << "Identifier: ";
    Identifiers.print();
    cout << "Constant: ";
    Constants.print();
    cout << "Operators: ";
    Operators.print();
    cout << "Delimiter: ";
    Delimiter.print();
    cout << "Syntax Error(s): ";
    Errors.print();
    
    //closing file
    file.close();
    
    return 0;
}