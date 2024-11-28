#include <iostream>
using namespace std;
class Queue{
    public:
    int size;
    int *arr;
    int front;
    int rear;
    Queue(int size){
        this->size=size;
        front=0;
        rear=0;
        arr=new int[size];
    }
    void push(int x){
        if(size>rear){
            arr[rear]=x;
            rear++;
        }
        else{
            cout<<"Queue full"<<endl;
        }
    }
    void pop(){
        if(front==rear){
            cout<<"Queue empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
        }
    }
    void empty(){
        if(rear==front){
            cout<<"Queue empty"<<endl;
        }
        else{
            cout<<"Not empty"<<endl;
        }
    }
    void frontt(){
        if(front==rear){
            cout<<"Empty queue "<<endl;
        }
        else{
            cout<<arr[front]<<endl;
        }
    }
};
int main (){
    Queue q(6);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.frontt();
    return 0;
}