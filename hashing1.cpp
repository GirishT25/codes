#include<iostream>
using namespace std;
#define MAX 10
class Hash
{
 struct node
 {
  int roll_no;
  char name[20];
  struct node *next;
 };
node* ht[MAX];
public: 
 Hash()
 {
 int i;
 for(i=0;i<MAX;i++)
    ht[i]=NULL;
 }
   void insert();
   void deleter();
   void display();
   void search();
 };
void Hash::display()
{
 node *ptr;
 int i;
 cout<<"HASH TABLE\n";
cout<<"Index\t"<<"Record {Roll No Name}\n";
 for(i=0;i<MAX;i++)
 {
  ptr=ht[i];
  cout<<"\n"<<i<<"::\t";
     while(ptr!=NULL)
   {
    cout<<ptr->roll_no<<"\t";
    cout<<ptr->name;
    cout<<"\t";
    ptr=ptr->next;
     } 
 }
}
void Hash::insert()
{
 int addr;
 node *ptr,*temp;
 cout<<"Enter Roll no::";
 temp=new node;
 cin>>temp->roll_no;
 cout<<"Enter Name::"; 
 cin>>temp->name;
 addr=temp->roll_no % MAX;//Mapped Location
 //get memory for the  new node
  temp->next=NULL;
 if(ht[addr]==NULL)
{   
    ht[addr]=temp;
 }
else
  {
   //locate the last node of the linked list
   
    ptr=ht[addr];
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    ptr->next=temp; 
cout<<"collision occur at "<<addr<<" postion ";
}
}
void Hash::search()
{
 int addr,key;
node *ptr;
 cout<<"\nEnter the element to be searched:";
 cin>>key;
 addr=key%MAX;
 ptr=ht[addr];
 while(ptr!=NULL && key!=ptr->roll_no)
{   ptr=ptr->next;}
  if(key==ptr->roll_no)
   {
    cout<<ptr->roll_no<<"  "<<ptr->name<<"\nKey Found at location::"<<addr;
   // break;
   }
}
void Hash::deleter()
{
 int addr,key;
 node *ptr,*temp,*prev;
 cout<<"Enter Roll no for record to be deleted::";
 cin>>key;
 addr=key % MAX;//Mapped Location
 prev=ptr=ht[addr];
 if(ptr->roll_no==key)
{
prev=prev->next;
ht[addr]=prev;
delete(ptr);
}
else
{
 while(ptr->next!=NULL && ptr->roll_no!=key)
 {
  prev=ptr;
  ptr=ptr->next;
 }
if(ptr->roll_no==key)
{
 prev->next=ptr->next;
 delete(ptr);
}
}
}

 //Main Function//
int main()
{
      Hash h;
     
     int choice;
     while (1)
     {
         cout<<"\n----------------------"<<endl;
         cout<<"Operations on Hash Table"<<endl;
         cout<<"\n----------------------"<<endl;
         cout<<"1.Insert element into the table"<<endl;
         cout<<"2.Search element from the key"<<endl;
         cout<<"3.Delete element at a key"<<endl;
         cout<<"4.Display"<<endl;
         cout<<"Enter your choice: ";
         cin>>choice;
         switch(choice)
         {
         case 1:
             h.insert();
             break;
         case 2:
           	h.search();
                break;
         case 3:
             h.deleter();
             break;
         case 4:
             h.display();
        default:
           cout<<"\nEnter correct option\n";
        }
}
}