// Maps, Linked Lists, Stacks and Queues

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    Node(){
        data = 0;
        next = NULL;
    }
};

class Linked_List{
    public:
    Node* head = NULL;

    void traverse(){
        cout<<"Traversing... "<<endl;
        if(head==NULL) cout<<"Empty list"<<endl;
        else{
            Node *temp = head;
            int i = 0;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                cout<<" - "<<i++<<" "<<temp->next<<endl;
                temp = temp->next;
                // if(temp==NULL) break;
            }
            cout<<endl;
        }
    }
    void insert_end(int data){
        Node *n = new Node(data, NULL);
        insert_node_end(n);
    }
    void insert_front(int data){
        Node *n = new Node(data, NULL);
        insert_node_front(n);
    }
    void insert_node_end(Node *n){
        if(head==NULL){
            head = n;
            n->next = NULL;
        }
        else{
            Node *temp = head;
            while(temp->next!=NULL) temp = temp->next;
            temp->next = n;
            n->next = NULL;
        }
    }
    void insert_node_front(Node *n){
        if(head == NULL){
            head = n;
            n->next = NULL;
        }
        else{
            n->next = head;
            head = n;  
        }
    }
    void insert_at(int pos, int data){
        
        Node *temp = head; pos--;
        int temp_data;
        while(pos>0){
            if(temp->next == NULL)
                break;
            temp = temp->next;
            pos--;
        }
        temp_data = temp->data;
        temp->data = data;
        Node *n = new Node(temp_data, temp->next);
        temp->next = n;
    }
    void delete_front(){
        if(head == NULL) cout<<"Empty List";
        else head = head->next;
    }
};

class stack_using_ll{
    public:
    Linked_List *s;

    void push(int data){
        // if(s->head == NULL) s->insert_end(data);
        // else s->insert_front(data);
        s->insert_front(data);
    } 
    
    void pop(){
        // if(s->head == NULL) cout<<"Empty Stack"<<endl;
        s->delete_front();
    }

    int top(){
        return s->head->data;
    }

    void show(){
        s->traverse();
        return;
    }
};

class functions{
    public:
    void show_msq(stack<int> s1){    
        while (!s1.empty()) {
            cout << ' ' << s1.top();
            s1.pop();
        }
        cout<<endl;
    }
    void show_msq(queue<int> q1){    
        while (!q1.empty()) {
            cout << ' ' << q1.front();
            q1.pop();
        }
        cout<<endl;
    }
    void show_msq(stack<char> s1){    
        while (!s1.empty()) {
            cout << ' ' << s1.top();
            s1.pop();
        }
        cout<<endl;
    }
    void show_msq(map<int, int> m1){
        cout << "\tKEY\tELEMENT\n";
        for (auto itr = m1.begin(); itr != m1.end(); ++itr) {
            cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
        cout << endl;
    }
    
};

int main()
{   
    functions fn;

    // Stacks //

    // empty() – Returns whether the stack is empty – Time Complexity : O(1) 
    // size() – Returns the size of the stack – Time Complexity : O(1) 
    // top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
    // push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
    // pop() – Deletes the top most element of the stack – Time Complexity : O(1) 
    // swap() - Sswap the contents of one stack with another stack of same type but the size may vary.
    // emplace() - Insert a new element into the stack (top of the stack)
    cout<<"Stacks: "<<endl<<endl;
    stack<int> s1, s2;
    s1.push(21); s1.push(22); s1.push(24); s1.emplace(100); s1.push(25); s1.pop();
    s2.push(1); s2.push(2); s2.push(3); s2.push(4); s2.swap(s1); 
    cout<<"Size of stack 1: "<<s1.size()<<", and stack 2: "<<s2.size()<<endl;
    cout<<"Stack 1: "; fn.show_msq(s1);
    cout<<"Stack 2: "; fn.show_msq(s2);

    // Applications of Stacks //

    cout<<"Reversing a string: "<<endl;
    string str = "Hello World";
    stack<char> s3;
    for(auto i:str) s3.push(i);
    str.clear();
    while(!s3.empty()){
        str.push_back(s3.top());
        s3.pop();
    }
    cout<<str<<endl;

    // bool isValid(string s) {
    //     stack<char> s1;
    //     for(auto i:s){
    //         switch(i){
    //             case '(':
    //                 s1.push(i);
    //                 break;
    //             case '{':
    //                 s1.push(i);
    //                 break;
    //             case '[':
    //                 s1.push(i);
    //                 break;
    //             case ')':
    //                 if(!s1.empty() && s1.top()=='(') s1.pop();
    //                 else return false;    
    //                 break;  
    //             case '}':
    //                 if(!s1.empty() && s1.top()=='{') s1.pop();
    //                 else return false;    
    //                 break;
    //             case ']':
    //                 if(!s1.empty() && s1.top()=='[') s1.pop();
    //                 else return false;    
    //                 break;   
    //         }
    //     }
    //     return s1.empty();
    // }
    cout<<"Infix to Postfix Conversion: "<<endl;

    cout<<endl;

    // Queues //

    // empty() – Returns whether the queue is empty.
    // size() – Returns the size of the queue.
    // queue::swap() in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
    // queue::emplace() in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.
    // queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
    // push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.
    
    cout<<"Queues: "<<endl<<endl;
    queue<int> q1, q2;
    q1.push(21); q1.push(22); q1.push(24); q1.emplace(100); q1.push(25); q1.pop();
    q2.push(1); q2.push(2); q2.push(3); q2.push(4); q2.swap(q1); 
    cout<<"Size of queue 1: "<<q1.size()<<", and queue 2: "<<q2.size()<<endl;
    cout<<"Stack 1: "; fn.show_msq(q1);
    cout<<"Stack 2: "; fn.show_msq(q2);
    cout<<endl;

    // Linked Lists //

    Node *node1 = new Node(10, NULL);
    Node *node2 = new Node(30, NULL);
    Linked_List list1;
    cout<<"Linked List: "<<endl<<endl;
    list1.traverse();
    list1.insert_end(5); 
    list1.insert_front(200); list1.insert_end(100); list1.insert_node_front(node1); list1.insert_node_end(node2);
    list1.traverse();
    list1.insert_at(5, 999); 
    list1.delete_front();
    list1.traverse();
    cout<<endl;

    // Stack using Linked List //
    // Node* temp = NULL;
    // temp->next = NULL;
    // cout<<temp->next;
    cout<<"Stack using Linked Lists: "<<endl<<endl;
    stack_using_ll s4;
    s4.push(24); s4.push(48);
    // s4.pop(); 
    // s4.show();
    cout<<s4.top()<<endl;
    s4.push(24); s4.push(48);
    s4.show();

    // Maps //

    // begin() – Returns an iterator to the first element in the map
    // end() – Returns an iterator to the theoretical element that follows last element in the map
    // size() – Returns the number of elements in the map
    // max_size() – Returns the maximum number of elements that the map can hold
    // empty() – Returns whether the map is empty
    // pair insert(keyvalue, mapvalue) – Adds a new element to the map
    // erase(iterator position) – Removes the element at the position pointed by the iterator
    // erase(const g)– Removes the key value ‘g’ from the map
    // clear() – Removes all the elements from the map

    map<int, int> m1;
    cout<<"Maps: "<<endl<<endl;
    // insert elements in random order
    m1.insert(pair<int, int>(1, 40)); m1.insert(pair<int, int>(2, 30)); m1.insert(pair<int, int>(3, 60)); 
    m1.insert(pair<int, int>(4, 20)); m1.insert(pair<int, int>(5, 50)); m1.insert(pair<int, int>(6, 50));
    cout<<"M1: "<<endl;
    fn.show_msq(m1);    
    // assigning the elements from m1 to m2
    map<int, int> m2(m1.begin(), m1.end());
    // remove all elements up to
    // element with key=3 in m2
    m2.erase(m2.begin(), m2.find(3));
    cout<<"M2 after removing elements upto key 3: "<<endl;
    fn.show_msq(m2);
  
    // cout << num << " removed \n";

  
    // lower bound and upper bound for map m1 key = 5
    cout << "m1.lower_bound(5) : "
         << "\tKEY = ";
    cout << m1.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << m1.lower_bound(5)->second << endl;
    cout << "m1.upper_bound(5) : "
         << "\tKEY = ";
    cout << m1.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << m1.upper_bound(5)->second << endl;
    
    // Other functions of map:

    // map insert() in C++ STL– Insert elements with a particular key in the map container. .
    // map count() function in C++ STL– Returns the number of matches to element with key value ‘g’ in the map.
    // map equal_range() in C++ STL– Returns an iterator of pairs. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to k.
    // map erase() function in C++ STL– Used to erase element from the container.
    // map rend() function in C++ STL– Returns a reverse iterator pointing to the theoretical element right before the first key-value pair in the map(which is considered its reverse end).
    // map rbegin() function in C++ STL– Returns a reverse iterator which points to the last element of the map.
    // map find() function in C++ STL– Returns an iterator to the element with key value ‘g’ in the map if found, else returns the iterator to end.
    // map crbegin() and crend() function in C++ STL– crbegin() returns a constant reverse iterator referring to the last element in the map container. crend() returns a constant reverse iterator pointing to the theoretical element before the first element in the map.
    // map cbegin() and cend() function in C++ STL– cbegin() returns a constant iterator referring to the first element in the map container. cend() returns a constant iterator pointing to the theoretical element that follows last element in the multimap.
    // map emplace() in C++ STL– Inserts the key and its element in the map container.
    // map max_size() in C++ STL– Returns the maximum number of elements a map container can hold.
    // map upper_bound() function in C++ STL– Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will go after the element with key value ‘g’ in the map
    // map operator= in C++ STL– Assigns contents of a container to a different container, replacing its current content.
    // map lower_bound() function in C++ STL– Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will not go before the element with key value ‘g’ in the map.
    // map emplace_hint() function in C++ STL– Inserts the key and its element in the map container with a given hint.
    // map value_comp() in C++ STL– Returns the object that determines how the elements in the map are ordered (‘<' by default).
    // map key_comp() function in C++ STL– Returns the object that determines how the elements in the map are ordered (‘<' by default).
    // map::size() in C++ STL– Returns the number of elements in the map.
    // map::empty() in C++ STL– Returns whether the map is empty.
    // map::begin() and end() in C++ STL– begin() returns an iterator to the first element in the map. end() returns an iterator to the theoretical element that follows last element in the map
    // map::operator[] in C++ STL– This operator is used to reference the element present at position given inside the operator.
    // map::clear() in C++ STL– Removes all the elements from the map.
    // map::at() and map::swap() in C++ STL– at() function is used to return the reference to the element associated with the key k. swap() function is used to exchange the contents of two maps but the maps must be of same type, although sizes may differ.
    
    cout<<endl;

    cout<<"end";   
    return 0;
    // https://www.geeksforgeeks.org/commonly-asked-data-structure-interview-questions-set-1/
    // https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
}