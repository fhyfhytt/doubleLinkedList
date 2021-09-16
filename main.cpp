#include <iostream>
#include<cstdlib>
using namespace std;
//双向链表
typedef struct student
        : public error_code {
    int number;
    string name;
    string sex;
} student;

typedef struct listPoint
{
    student * information;
    listPoint *next;
    listPoint *last;
} listPoint;
class List {
private:
    listPoint * head;
    listPoint * tail;
    int length;
public:
    List(int length){
        this->length=length;
        head=new listPoint();
        head->last=NULL;
        tail=head;
        for(int i=0;i<length;i++){
            listPoint* temp=new listPoint();
            cout << "please enter the no" << i + 1 << " Node's data:\n";
            temp->information=input();
            temp->next=NULL;
            temp->last=tail;
            tail->next=temp;
            tail=temp;
        }

    };
    ~List()
    {
        listPoint * q;
        listPoint * p = head->next;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            delete q;
        }
        p = NULL;
        q = NULL;
    };
    student * input (){
        student *stu=new student();
        try{
        cout<<"input the number :\n";
        cin>>stu->number;
        cout<<"input the name   :\n";
        cin>>stu->name;
        cout<<"input the sex    :\n";
        cin>>stu->sex;
        cout<<"----------------------------------"<<endl;
        }catch(exception err){
            cout<<err.what()<<endl;
        }
        return stu;
    }
    void traverseList()//正向遍历
    {
        listPoint * p = head->next;
        while (p != NULL)
        {
            cout << p->information->number << endl;
            cout << p->information->name << endl;
            cout << p->information->sex << endl;
            cout<<"----------------------------------"<<endl;
            p = p->next;
        }
    }
    void traverseListReturn()//逆向遍历
    {
        listPoint * p = tail;
        while (p->last != NULL)
        {
            cout << p->information->number << endl;
            cout << p->information->name << endl;
            cout << p->information->sex << endl;
            cout<<"----------------------------------"<<endl;
            p = p->last;
        }
    }
    student getItemInList(int position)//查找指定位置的节点
    {
        listPoint * p = head->next;
        if (position > length || position <= 0)
        {
            cout << "over stack !" << endl;
            return *new student();
        }
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        return *p->information;
    }
    void deleteList(int position)//删除指定位置的节点
    {
        listPoint * p = head->next;
        if (position > length || position <= 0)
        {
            cout << "over stack !" << endl;
            return;
        }
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        p->last->next = p->next;
        p->next->last = p->last;
        delete p;
        length--;
    }

    void clearList()//清空
    {
        listPoint * q;
        listPoint * p = head->next;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            delete q;
        }
        p = NULL;
        q = NULL;
    }
    void insertList( int position)//插入数据
    {
        listPoint * p = head->next;
        if (position > length || position <= 0)
        {
            cout << "over stack !" << endl;
            return;
        }
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        listPoint * temp = new listPoint();
        temp->information=input();
        temp->next = p;
        temp->last = p->last;
        p->last->next = temp;
        p->last = temp;
        length++;
    }
    void changeList(student * student1, int position)//修改链表中指定位置的节点
    {
        listPoint * p = head->next;
        if (position > length || position <= 0)
        {
            cout << "over stack !" << endl;
            return;
        }
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        p->information = student1;
    }
    void sortList()     //冒泡排序
    {
        listPoint * p = new listPoint();
        listPoint * q = new listPoint();
        student * temp;
        for (p = head->next; p->next != NULL; p = p->next)
        {
            for (q = p->next; q != NULL; q = q->next)
            {
                if (q->information->number < p->information->number)
                {
                    temp = q->information;
                    q->information = p->information;
                    p->information = temp;
                }
            }
        }
    }
    void sortListByInsertWay()        //插入排序
    {
        if (head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        listPoint * p2 = head->next->next;
        listPoint * p1 = head;
        head->next->next = NULL;
        while (p2)
        {
            listPoint * pN = p2->next;
            while (p1->next)
            {
                if (p2->information->number < p1->next->information->number)
                {
                    p2->next = p1->next;
                    p2->last = p1;
                    p1->next->last = p2;
                    p1->next = p2;
                    break;
                }
                p1 = p1->next;
            }
            if (p1->next == NULL)
            {
                p2->next = NULL;
                p2->last = p1;
                p1->next = p2;
            }
            p2 = pN;
        }

        //重新查找pTail的位置
        listPoint * pt = head;
        while (pt->next)
        {
            pt = pt->next;
        }
        tail = pt;
    }

};
int main() {
    List l(3);
    l.traverseList();
    cout << "AFTER SORT------------------------------------------------------" << endl;
    //    l.sortList();             //冒泡排序
    l.sortListByInsertWay();    //插入排序
    l.traverseList();
    cout << "AFTER INSERT-----------------------------------------------------" << endl;
    l.insertList(1);
    l.traverseList();
    cout << "AFTER DELETE-----------------------------------------------------" << endl;
    l.deleteList(3);
    l.traverseList();
    cout << "Return Traverse---------------------------------------------" << endl;
    l.traverseListReturn();
    cout << "Find the Second Node's data:" << l.getItemInList(2).number << endl;
    return 0;
}
