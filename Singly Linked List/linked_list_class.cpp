#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *link;
};
class linked_list
{   node *head,*tail;
    public:
        linked_list(){
            head=tail=NULL;
        }
        node *creation(){
            node *new_node=new node;
            cout<<"Enter the data : ";
            cin>>new_node->data;
            cout<<endl;
            new_node->link=NULL;
            return new_node;
        }
        void ins_beg(){
            node *new_node = creation();
            if(head==NULL){
                head=new_node;
                tail=new_node;
            }
            else{
                new_node->link=head;
                head=new_node;
            }
        }
        void ins_end(){
            node *new_node = creation();
            tail->link=new_node;
            tail=new_node;
        }
        void ins_spec(){
            int pos;
            node *new_node = creation();
            cout<<"Enter position : ";
            cin>>pos;
            cout<<endl;
            node *prev{NULL},*temp{head};
            while (--pos)
            {
                prev=temp;
                temp=temp->link;
            }
            prev->link=new_node;
            new_node->link=temp;
        }
        int del_beg(){
            int data=-1;
            node *temp{head};
            head=head->link;
            data = temp->data;
            delete temp;
            return data;
        }
        int del_end(){
            int data=-1;
            node *temp{head},*del{tail};
            while(temp!=tail)
                temp=temp->link;
            temp->link=NULL;
            tail=temp;
            data = del->data;
            delete del;
            return data;
        }
        int del_spec(){
            int data=-1,ele;
            cout<<"Enter data to delete : ";
            cin>>ele;
            cout<<endl;
            node *temp{head},*prev{NULL},*next{head->link};
            while(temp->data!=ele && temp!=NULL){
                prev=temp;
                temp=temp->link;
                next=next->link;
            }
            if(temp->data==ele){
                prev->link=next;
                data=temp->data;
                delete temp;
            }
                return data;
        }
        void display_list(){
            node *temp{head};
            while(temp!=NULL){
                cout<<temp->data<<"----->";
                temp=temp->link;
            }
            cout<<endl;
        }
};
int main(){
    linked_list l;
    int choice,sel;
    while (1)
    {
        cout<<"MENU\n"<<"--------\n"<<"1.Insertion\n"<<"2.Deletion\n"<<"3.Display\n"<<"Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:{
            cout<<"  1.At Begining\n"<<"  2.At End\n"<<"  3.At Specific Position\n"<<"Choice : ";
            cin>>sel;
            cout<<endl;
            switch (sel)
            {
            case 1:l.ins_beg();break;
            case 2:l.ins_end();break;
            case 3:l.ins_spec();break;
            default:break;
            }
        }break;
        
        case 2:{
            cout<<"  1.At Begining\n"<<"  2.At End\n"<<"  3.Specific Data\n"<<"Choice : ";
            cin>>sel;
            cout<<endl;
            switch (sel)
            {
            case 1:cout<<"Deleted Element : "<<l.del_beg()<<endl;break;
            case 2:cout<<"Deleted Element : "<<l.del_end()<<endl;break;
            case 3:cout<<"Deleted Element( -1 indicates \" Not Found \") : "<<l.del_spec()<<endl;break;
            default:break;
            }
        }break;
        
        case 3:l.display_list();break;
        
        default:{
            cout<<"Invalid Choice Exiting!!"<<endl;
            exit(0);
        }
            break;
        }
    }
    
    return 0;
}