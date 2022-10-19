#include <iostream>
#include <cstring>
using namespace std;

struct node{
    char data;
    node* next = NULL;
};

class linkedList{
    private:
        node* head;
    public:
        linkedList(){ head = NULL; }
        linkedList(char knew) {
            head = new node;
            head->data = knew;
            head->next = NULL;
        }

        void push(char val){
            node* newNode = new node;
            newNode->data = val;
            if(head == NULL){
                head = newNode;
                return;
            }
            node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;

        }

        void printList(){
            node* curr = head;
            while(curr != NULL){
                cout<<curr->data;
                curr = curr->next;
            }
            cout<<endl;
        }

        char pop(){
            char curr = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            return curr;
        }

        bool emptyList(){
            return (head == NULL);
        }

        bool inList(char value){
            node* curr = head;
            while(curr!=NULL){
                if (curr->data == value)
                    return true;
                curr = curr->next;
            }
            return false;
        }
};

int main()
{
    //Reading in the password!
    linkedList password;
    char in;
    cin>>in;
    do{
        password.push(in);
        cin.get(in);
    }while(in != ' ');

    //Reading & testing 'message'
    char front;
    while(cin>>in){
        if(isalpha(in) && password.inList(in)){
            front = password.pop();
            if(front!=in){
                cout<<"FAIL"<<endl;
                return 0;
            }
        }
        if (cin.peek() == '\n' || password.emptyList())
            break;
    }
    if(password.emptyList())
        cout<<"PASS"<<endl;
    else
        cout<<"FAIL"<<endl;
    return 0;
}
