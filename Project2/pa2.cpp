/*
 * Blas Kojusner
 * 10/23/2017
 */
#include <iostream>
#include "pa2.h"
using namespace std;

void menu() {
//Prints options
    cout << "  1. Add program\n";
    cout << "  2. Kill program\n";
    cout << "  3. Fragmentation\n";
    cout << "  4. Print memory\n";
    cout << "  5. Exit\n";
}

void LinkedList::print(){
//Prints data
    //Variables declared
    Node *crnt = first;
    
    //Loop to print data
    while(crnt){ 
        if((*crnt).data != 0){
            cout<<"P"<<(*crnt).data;
        }
        if((*crnt).data == 0){
            cout<<"Free";
        }
        crnt = (*crnt).next;
    }
    cout<<"\n";
}

int LinkedList::get(size_t i){ 
//Gets size of linked list
    //Variables declared
    Node *crnt = first;
    size_t num = 0;
    
    //Loop while spot and num are not i
    while(crnt && num != i){
        crnt = (*crnt).next;
        num++;
    }
    
    //Loop while crnt is null or equal to i
    if(crnt != NULL || num != i){ 
        cout<<"Index is out of range.";
    }
    
    //Returns crnt as index i
    return (*crnt).data;
}

int pCount(int size){ 
//Gets how many pages are in data
    //Variables declared
    int n = size/4;
    
    if(size%4 != 0){
        n++;
    }
    
    return n;
}

void LinkedList::switchValue(int index, int newdata){ 
//Switches data
    //Variables declared
    Node *crnt = first;
    (*crnt).data = newdata;
    size_t num = 0;
    
    //Loop as spot and num are not index
    while(crnt && num != index){
        crnt = (*crnt).next;
        ++count;
    }

    //Loop if crnt is either null or equal to index
    if(crnt != NULL || num != index){ 
        cout<<"Index is out of range.";
    }
    
    //Returns crnt as index i
    return (*crnt).data;
}

void LinkedList::add(int input){ 
//Adds data to list
    //Variables declared
    Node *crnt = first;
    Node *end = nullptr;
    Node *newNode = new Node(); 
    (*newNode).data = input;
    
    while(crnt){
        end = crnt;
        crnt = (*crnt).next;
    }

    //New node to the end
    if(end){ 
        (*end).next = newNode; 
    }
    else{ 
        first = newNode;
    }
}

void LinkedList::kill(int pNum){ 
//Deletes a page
    //Variables declared
    Node *crnt = first;
    int num = 0;
    
    while(crnt){
        if((*crnt).data == pNum){
            (*crnt).data = 0;
            num++;
        }
        crnt = (*crnt).next;
    }
    
    if(num > 0){
        cout << "Program P" << pNum << " successfully killed, " << num << " page(s) reclaimed.\n";
    }
    if(num == 0){
       cout << "Program P" << pNum << " was not found.\n"; 
    }
}

int LinkedList::fragmentCount(){ 
//Gets fragments on memory
    //Variables declared
    Node *crnt = first;
    int fCount = 0; 
    
    while(crnt){
        if((*crnt).data == 0){
            while(crnt && (*crnt).data == 0){
                crnt = (*crnt).next;
            }
            fCount++;
        }
        crnt = (*crnt).next;
    }
    return fCount;
}

int LinkedList::wFit(int pageSize){ 
//Worst fit method
    //Variables declared
    Node *crnt = first;
    int num = 0;
    int index = 0;
    int size = 0;
    int temp = 1;
    
    while(crnt){
        if((*crnt).data == 0){
            for(int i = 1; crnt && (*crnt).data == 0; i++){
                num++;
                crnt = (*crnt).next;
                temp = i;
            }
            
            if(size < temp && pageSize <= temp){
                size = temp;
                index = num - temp;
            }
        }
        num++;  
        crnt = (*crnt).next;
    }
    
    if(pageSize > size){
        return 65;
    }
    
    return index;
}

int LinkedList::bFit(int pageSize){ 
//Best fit method
    //Variables declared
    Node *crnt = first;
    int num = 0;
    int index = 0;
    int size = 99;
    int temp = 1;
    
    while(crnt){
        if((*crnt).data == 0){
            for(int i = 0; crnt && (*crnt).data == 0; i++){
                num++;
                crnt= (*crnt).next;
                temp = i;
            }
            if(size > temp && pageSize <= temp){
                size = temp;
                index = num - temp;
            }
        }
        num++;
        crnt = (*crnt).next;
    }
    
    if(pageSize > size){
        return 65;
    }
    
    return index;
}

int main(int argc, char ** argv){
//Main method
    menu();
    int mInput;
    cin>>mInput;
    
    for(int i = 1; i < 33; i++){
        free.add(0);
    }
    
    while(mInput != 5){
        cout<<"choice - "<< mInput<<"\n";      
  
        if(mInput == 1){
        //Option 1 - adds program
            cout<<"Program name - P";
            int programName;
            cin>>programName;
            cout<<"Program size (KB) - ";
            int size;
            cin>>size;
            cout<<"\n";
            int pages = pCount(size);
              
            if(argc > 2){
                string arg = argv[1];
                if(arg.compare("worst") == 0){
                    //Worst-fit data method
                    int startingIndex = free.wFit(pages);           
                    if(startingIndex != 65){
                        for(int i = 0; i <pages; i++){
                            free.switchValue(startingIndex + i, programName);                     
                        }
                        cout << "Program " << programName << " added successfully: " << pCount(size) << "page(s) used." <<  "\n";
                    }
                    else{
                        cout << "Error, Not enough memory for Program P" <<programName << "\n";
                    }
                }
                
                if(arg.compare("best") == 0){
                    //Worst-fit data method
                    int startingIndex = free.bFit(pages);
                    if(startingIndex != 65){
                        for(int i = 0; i <pages; i++){
                            free.switchValue(startingIndex + i, programName);                      
                        }                
                        cout << "Program " << programName << " added successfully: " << pCount(size) << "page(s) used." <<  "\n";
                    }
                    else{
                        cout << "Error, Not enough memory for Program P" <<programName << "\n";
                    } 
                }
            }  
        }
        
        else if(mInput == 2){
        //Option 2 - kills program
            cout << "Program name - P";
            int programName;
            cin>>programName;
            free.kill(programName);
        }
        
        else if(mInput == 3){
        //Option 3 - fragments in program
            cout << "There are " << free.fragmentCount() << " fragment(s)" << "\n";
        }
        
        else if(mInput == 4){
        //Option 4 - prints program
            free.print();
        }  
    
        menu();
        cin >> mInput;
    }
    
    cout<<"choice - 5";
}