//QUEUE IMPLEMENTED AS A SINGLY LINKED LIST
//unfinished interface


#include <iostream>

using namespace std;
///////////////////////////////////
struct node
{
   int data;
   node *next;
};
////////////////////////////////////
class list
{
private:
   node *head, *tail;
   static int count;

public:
   list() // constructor //init()
   {
      head = NULL;
      tail = NULL;
   }
   void enqueue(int value);
   void display();
   bool dequeue();
   bool empty();
   bool contains(int value);
   void showCount();
   int interface(list& q);
};
////////////////////////////////////

int list::count = 0;

/////////////////////////////////////
void list::enqueue(int value)
{
   node *temp = new node;
   temp->data = value;
   temp->next = NULL;

if(head == NULL)
{
   head = temp;
   tail = temp;
   temp = NULL;
}
else
{
   tail->next = temp;
   tail = temp;
//   delete temp;
}
list::count += 1;

}
///////////////////////////////////
void list::display()
{
   node *temp = new node;
   temp = head;
while(temp != NULL)
{
   cout << temp->data << "\t";
   temp = temp->next;
}
cout << endl;

}
//////////////////////////////////
bool list::dequeue()
{
   if(head == NULL) return false;
   if(head == tail)
   {
      head = tail = NULL;
      list::count -= 1;
      return true;
   }
   else
   {
      head = head->next;
      list::count -= 1;
      return true;
   }
   
}

//////////////////////////////////
bool list::empty()
{
   if(head == NULL && tail == NULL)
      return true;
   else return false;
}

//////////////////////////////////
bool list::contains(int value)
{
   if(empty()) return false;
   node *temp = new node;
   temp = head;
   while(temp != NULL && temp->data != value)
   {
      temp = temp->next;
   }
   if(temp == NULL) return false;
   else return true;
}

/////////////////////////////

void list::showCount()
{
cout << count;
}

///////////////////////////////

int list::interface(list& q)
{
   //list q;
   int ans;
   cout << "\tQUEUE\n\n\tWhat do you want to do?\n";
   cout << "1 enqueue\n2 dequeue\n3 is full\n4 show commands\n" <<
           "5 search for a value\n6 how many elements\n" <<
            "7 show queue\n8 quit\n\n";
while(true)
{
   cout << "[> ] "; cin >> ans;
   switch(ans)
   {
   case 1:
   int val1;
   cout << "[Value]: "; cin >> val1;
   q.enqueue(val1);
   break;
   case 2:
   if(!q.dequeue())
      {
      cout << "The queue has already been empty" << endl;
      break;
      }
   break;
   case 3:
   if(!q.empty())
      {
      cout << "The queue is full" << endl;
      break;
      }
   else
      {
      cout << "The queue is empty" << endl;
      break;
      }
   case 4:
   cout << "\n1 enqueue\n2 dequeue\n3 is full\n4 show commands\n" <<
           "5 searxh for a value\n6 show how many elements\n" <<
           "7 show queue\n8 quit\n\n";
   break;
   case 5:
   int val2;
   cout << "[Value]: "; cin >> val2;
   if(q.contains(val2))
      {
      cout << val2 << " is in the queue" << endl;
      break;
      }
   else
      {
      cout << val2 << " is not in the queue" << endl;
      break;
      }
   case 6:
   cout << "The queue has "; showCount(); cout  << " elements now" << endl;
   break;
   case 7:
   cout << "Your queue:" << endl;
   q.display();
   break;
   case 8:
   return 0;
   default:
   cout << "Incorrect input" << endl;
   break;
   } 
}
}


///////////////////////////////

int main()
{

list q;
q.interface(q);
delete &q;

return 0;
}
