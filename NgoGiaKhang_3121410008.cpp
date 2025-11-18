#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
using namespace std; 
struct  Vehicle{
    int regNumber;
    int type;
};

struct QNode {
    Vehicle data;
    QNode* next;
};
 
// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue{
    QNode *front, *rear;
} ;
 
// A utility function to create a new linked list node.
QNode* newNode(Vehicle v)
{
    struct QNode* temp = (struct QNode*) malloc(sizeof(struct QNode));
    temp->data = v;
    temp->next = NULL;
    return temp;
}
 
// A utility function to create an empty queue
Queue* createQueue()
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
 
// The function to add a key k to q
void enQueue(Queue* q, Vehicle v)
{
    // Create a new LL node
    QNode* temp = newNode(v);
 
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a key from given queue q
Vehicle deQueue(Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front != NULL)
    {
        // Store previous front and move front one node ahead
        struct QNode* temp = q->front;
        Vehicle v = temp->data;
 
        q->front = q->front->next;
 
        // If front becomes NULL, then change rear also as NULL
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
        return v;
    }
}
 
char* Type(int n)
{
	char* a;
	a=new char[10]; 
	switch(n)
	{
		case 1:
		{
			strcpy(a,"container");
			break; 
		}
		case 2:
		{
			strcpy(a,"truck");
			break; 
		} 
		case 3:
		{
			strcpy(a,"coach");
			break; 
		}
		case 4:
			strcpy(a,"car");
			break; 
	}
	return a; 
} 
int count(Queue* q) // count the amount of vehicles in queue 
{
	QNode* p=q->front;
	int d=0; 
	while(p!=NULL)
	{
		p=p->next;
		d++	;
	} 
	return d; 
} 
void output(Queue* q) // output the information of the vehicle get out the queue 
{
	QNode* p=q->front;
	cout<<"There is 1 vehicle going out Tollstation!!!"<<endl; 
	cout<<"Regnumber: \t"<<p->data.regNumber<<endl;
	cout<<"Type: \t \t"<<Type(p->data.type)<<endl; 
	cout<<"///////////////////////////////////////////////"; 
	cout<<endl;
}
void Tollstation()
{
	Queue* q;
    q=createQueue();
    Vehicle v;
    int c=0;  
	srand(time(NULL));    
	cout<<"press ESC to stopped !!!!"<<endl;
    while (c != 27)             // until queue is full 
    { 
    	if(kbhit()){
	 		int c = getch();
			if(c==27)
			{
				cout<<"\nToll station stopped working "<<endl;
				return;
			}
		}
		deQueue(q);
    	int a=rand()%4;
    	if(a<=1)
    	cout<<"There is "<<a<<" vehicle going in to queue "<<endl;
		else cout<<"There are "<<a<<" vehicles going in to queue "<<endl;
    	for(int i=0;i<a;i++)
		{
			Sleep(2000);
    		v.regNumber=rand();
    		cout<<"Regnumber: \t"<<v.regNumber<<endl; 
			v.type=rand()%4 +1;
			cout<<"Type: \t \t"<<Type(v.type)<<endl; 
    		enQueue(q,v);
	 	}
	 	cout<<"===>====>=====>=====>====>====>"<<endl;
	 	if(count(q)!=0 && count(q)<=20)
		{ 
			Sleep(4000);
    		output(q);
    		if(count(q)>1) 
    			cout<<"There are having "<<count(q)<<" vehicles in the queue!!!"<<endl;
    		else 
		 		cout<<"There is having "<<count(q)<<" vehicle in the queue!!!"<<endl;
	 	}
   		else if(count(q)>20)
   		{
			c=27;
		   	cout<<"\nToll station stopped working "<<endl;
   		} 
    }
} 
int main()
{
	Tollstation(); 
	return 0; 
}