#include <iostream>
#define MAX 5
using namespace std;

class Circular_Queue
{
	private:  
	int *cqueue_arr;  
	int front, rear; 
	public:  
	 Circular_Queue()
	 {
	 	cqueue_arr = new int [MAX]; 
	 	 rear = front = -1; 
	 }
	 
	 void insert(int item) 
{
	if ((front == 0 && rear == MAX-1) || (front == rear+1)) 
	{
		cout<<"Queue Penuh \n";  
		return;
	}
	if (front == -1) 
	 {
	 	front = 0;  
		rear = 0;
	 }
	else
	{
	 	if (rear == MAX - 1)
		rear = 0;
		else
		rear = rear + 1;
	}   
	cqueue_arr[rear] = item ;  
	display();  
}

void del() 
{
	if (front == -1)
	{
		cout<<"Queue elements : Kosong..!\n";
		return ;
	}   
	cout<<"Element deleted from queue is : "<< cqueue_arr[front]<<endl;
	
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if (front == MAX - 1)
		front = 0;
		else
		front = front + 1;
	}
	display();
}

void display() 
{
	int front_pos = front, rear_pos = rear;  
	if (front == -1)   
	{
		cout<<"Queue elements : Kosong..!\n";
		return; 
	}
	cout<<"Queue elements : ";

	 
	if (front_pos <= rear_pos) 
	{
		while (front_pos <= rear_pos)
		{
			cout<<cqueue_arr[front_pos]<<"  ";
			front_pos++;
		}
	}
	else
	{
		while (front_pos <= MAX - 1)
		{
			cout<<cqueue_arr[front_pos]<<"  ";
			front_pos++;
		}
		front_pos = 0;
		while (front_pos <= rear_pos)
		{
			cout<<cqueue_arr[front_pos]<<"  ";
			front_pos++; 
		}
	}
	cout<<endl;
	 
}
};

int main()
{
	int choice, item;  
	Circular_Queue cq;
	
	do
	{
		cout<<"\n1.Insert\n";
		cout<<"2.Delete\n"; 
		cout<<"3.Quit\n";
		cout<<"Input pilihan : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			cout<<"Ketik nilai yang akan di queue : "; 
			cin>>item;     
			cq.insert(item);
			break;  
			case 2:     
			cq.del();   
			break;     
			case 3:  
			break;    
			default:
			cout<<"Pilihan salah.!\n"; 
		}
	}
	while(choice != 3);
	
	return 0;
}
