#include <iostream>
#define MAXSIZE 101
using namespace std;

template<typename T>
class Stack
{
  public:
    int top;
    int size;
    T *values;

    Stack()
    {
        size = MAXSIZE;
        values = new T[size];
        top = -1;
    }  

    ~Stack()
    {
        delete[] values;
    }

    void push(T value)
    {
        if(!isfull())
        {
            values[++top] = value;
        }
        else 
        {
            cout << "Stack is Full" << endl;
        }
    }

    void pop()
    {
        if(!isempty())
        {
            top--;
        }
        else 
        {
            cout << "Stack is empty" << endl;
        }
    }

    T Top()
    {
        if(!isempty())
        {
            return values[top];
        }
        else 
        {
            return NULL;
        }
    }

    bool isempty()
    {
        if(top < 0) return true;
        else return false;
    }

    bool isfull()
    {
        if(top + 1 == size) return true;
        else return false;
    }

};

//override cout for Stack
template <typename T>
ostream& operator <<(ostream &out, Stack<T> &st){
    T *temp = st.values;
    out << "--top--" << endl;
    for(int i=st.top; i>=0; i--)
    {
        out << "  " <<temp[i] << endl;
    }
    out << "-bottom-" << endl;
    return out;
}

// 원형 큐
// pop시 자료의 별도 이동 없이 관리가능
template<typename T> 
class Queue
{
    public:
        int front;
        int rear;
        int size;
        T *values;

        Queue()
        {
            size = MAXSIZE;
            values = new T[size];
            front = 0, rear = 0;
        }

        ~Queue()
        {
            delete[] values;
        }

        void push(T value)
        {
            if(!isfull()){
                values[rear] = value;
                rear = (rear + 1) % size;
            
            }
            else cout << "Queue is Full" << endl;
        }

        void pop()
        {
            if(!isempty()){
                front = (front + 1) % size;
            }
            else cout << "Queue is Empty" << endl;
        }

        bool isempty()
        {
            if(rear == front) return true;
            else return false;
        }

        bool isfull()
        {
            if((rear + 1) % size == front) return true;
            else return false;
        }

};

// overrride cout for Queue 
template <typename T>
ostream& operator <<(ostream &out, Queue<T> &q){
    T *temp = q.values;
    out << "front [" ;
    for(int i=q.front; i<q.rear; i++){
        out << temp[i];
        if(i < q.rear-1) out << " | ";
    }
    out << "] rear" << endl;
    return out;
}k

int main()
{
    Queue<int> q;
    Stack<int> st;
    q.push(3);
    cout << q;
    q.push(20);
    cout << q;
    q.push(43);
    cout << q;
    q.pop();
    cout << q;

    st.push(1);
    cout << st;
    st.push(34);
    cout << st;
    st.pop();
    cout << st;
    st.push(333);
    cout << st;
    return 0;
}