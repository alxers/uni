#include <iostream>
  
using namespace std; 
  
#define MAX 1000 
  
class Stack { 
    int top; 
  
public: 
    int a[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x);
    bool operator+(int num);
    int pop(); 
    int operator--(int); 
    bool isEmpty();
    int size();
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
}

bool Stack::operator+(int num)
{
    this->push(num);
}

int Stack::operator--(int)
{
    this->pop();
}

int Stack::size()
{
    return top + 1;
}

Stack removeOdd(Stack st)
{
    int initialStackSize = st.size();
    int currItem;
    Stack newStack;
    for (int i = 1; i < initialStackSize; i++)
    {
        currItem = st.pop();
        if (i % 2 != 0)
        {
            cout << "New stack: " << i << endl;
            newStack.push(currItem);
        }
    }
    return newStack;
}

 
int main() 
{ 
    // Stack s; 
    // s.push(10); 
    // s.push(20); 
    // s + 30;
    // cout << s.pop() << " Popped from stack\n";
    // cout << s-- << " Popped from stack\n";

    Stack *s[3];
    s[0] = new Stack();
    s[1] = new Stack();
    s[2] = new Stack();

    s[0]->push(6);
    s[0]->push(5);
    s[0]->push(4);
    s[0]->push(3);
    s[0]->push(2);
    s[0]->push(1);

    Stack newStack = removeOdd(*s[0]);
    // cout << s[0]->size() << endl;
    cout << newStack.size() << endl;
  
    return 0; 
} 
