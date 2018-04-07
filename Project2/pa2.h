#include <iostream>
#define nullptr nullptr

struct Node { 
//Declaring new node
    Node * next = nullptr;
    int data;
};

class LinkedList{ 
    //Declaring new node
    Node * first = nullptr;
    
    public:
    //Declaring methods public
        void print();
        int get(std::size_t i);
        void switchValue(int index, int data);
        void add(int input);
        void kill(int data);
        int fCount();
        int wFit(int pageSize);
        int bFit(int pageSize);
};