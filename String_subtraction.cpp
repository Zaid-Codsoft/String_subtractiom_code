// Name: zaid, Section SE-A , DS , Roll No : 22i-2513

#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Nodee {
    T data;
    Nodee* next;
    Nodee(T data) : data(data), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
    Nodee<T>* head;

    LinkedList() : head(nullptr) {}

    void insert(T data) {
        if (!head) {
            head = new Nodee<T>(data);
        }
        else {
            Nodee<T>* Curr = head;
            while (Curr->next) {
                Curr = Curr->next;
            }
            Curr->next = new Nodee<T>(data);
        }
    }
    Nodee<T>*  deleteFromStart() {
        
        if (head == nullptr) {
            cout << "Linked list is empty. Nothing to delete." << endl;
            return nullptr;
        }

       
        Nodee<T>* P = head;

       
        head = head->next;

        
        delete P;
        return head;
    }
    

    LinkedList<T> ArthOper() {
        char has='\0';
        LinkedList<T> result;
        LinkedList<T> result2;
        LinkedList<T> result3;
        Nodee<T>* Current = head;
        while (Current) {
            if (Current->data == '+') {
                Current = Current->next;
                Nodee<T>* nextNode = Current->next;
                
                while (nextNode && nextNode->data != '-') {
                    if (Current->data == '#') {
                        has = Current->data;
                        Current = nextNode;
                        nextNode = nextNode->next;
                    }
                    else {
                        result.insert(Current->data);
                        Current = nextNode;
                        nextNode = nextNode->next;
                    }
                    

                }
                if (Current->data=='#') {
                    has = Current->data;
                    insert(has);
                }
                else if (!Current && Current->data) {
                    result.insert(Current->data); 
                }

            }
            
            else if (Current->data == '-') {
               
                Current = Current->next;
               
                while (Current) {
                    if (Current->data == '#') {
                        has = Current->data;
                 
                    }

                   
                   
                   
                    else if(Current->data != '#'){
                       
                        result2.insert(Current->data);

                    }
                   else{}
                      
                    Current = Current->next;
               }
                if (Current == nullptr) {
                    result3 = removingString(result, result2);
                    result3.insert(has);
                    cout << "\n-------\n";
                    cout<<result3.head->data;
                    cout << "\n-------\n";
                    return result3;
                }
            }

            else if (Current->data == '#') {
                 has = Current->data;
            }
            else {
                result.insert(Current->data);
            }
            if (Current == nullptr) {
                result.insert(has);
                return result;
            }

            Current = Current->next;
        }
        result.insert(has);
        return result;
    }
};
template<typename T>
LinkedList<T> removingString(LinkedList<T> &result, LinkedList<T> &result2) {
    Nodee<T>* current = result.head;
    Nodee<T>* current1 = result2.head;
    LinkedList<T> newresult;
    bool chec = true;
    while (current1&&current) {
        if (current1->data == '#') {
            current1 =current1->next;
        }
        else if (current->data == '#') {
            current = current->next;
        }
        if (current1->data != current->data) {
            chec = false;
            break;
        }
        
        current = current->next;
        current1 = current1->next;
    }
    if (current == nullptr && current1!=nullptr) {
        current = result2.head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }
        return result;
    }
    if (chec == true) {
       
        while (current) {
            newresult.insert(current->data);

            current = current->next;
        }
       
        return newresult;
    }
    else {
        current = result2.head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }
        return result;
    }
    

}
int main() {
    
    LinkedList<char> N1;
    string str1 = "#abc+cba#";
    for (char c : str1) {
        N1.insert(c);
    }
    LinkedList<char> Result1 = N1.ArthOper();
    string ResultS1;
    Nodee<char>* Current1 = Result1.head;
    string adda = str1 + " = ";
    while (Current1) {
        ResultS1 += Current1->data;
        Current1 = Current1->next;
    }
    cout << "Addition result : " <<adda+ ResultS1 << endl;

   
    LinkedList<char> N2;
    string str2 = "#aBAC-aBAC##";
    for (char c : str2) {
        N2.insert(c);
    }
    LinkedList<char> Result2 = N2.ArthOper();
    string ResultS2;
    Nodee<char>* Current2 = Result2.head;
    while (Current2) {
        ResultS2 += Current2->data;
        Current2 = Current2->next;
    }
    cout << "Subtraction Result : " <<str2+" = "+ ResultS2 << endl;

    return 0;
}
