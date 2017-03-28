#include "Header/print.cpp"

using namespace std;

class BST
{
    private:
        node *root;
    public:

        BST()
        {
            root=0;
        }

        void addNode(int info)
        {
            node *n=root;
            node *p=0;
            while(n)
            {
                p=n;
                if(n->info<info)
                    n=n->right;
                else n=n->left;
            }
            node *q = new node();
            q->info=info;
            if(p==0)
                root=q;
            else
            {
                if(p->info<info)
                    p->right=q;
                else p->left=q;
            }
        }

        void delNode(int info)
        {
            node *n=root;
            node *p=0;
            while(n && n->info!=info)
            {
                p=n;
                if(n->info<info)
                    n=n->right;
                else if(n->info>info)
                    n=n->left;
            }
            if(n)
            {
                node *s;
                if(n->right && n->left)
                {
                    s=n->right;
                    node *sp=n;
                    while(s->left)
                    {
                        sp=s;
                        s=s->left;
                    }
                    if(sp->right==s)
                       sp->right=s->right;
                    else sp->left=s->right;

                    s->left=n->left;
                    s->right=n->right;

                    if(p && p->right==n)
                        p->right=s;
                    else if(p && p->left==n)
                        p->left=s;
                }
                else if(n->right)
                {
                    s=n->right;
                    if(n==p->right)
                        p->right=s;
                    else p->left=s;
                }
                else if(n->left)
                {
                    s=n->left;
                    if(n==p->right)
                        p->right=s;
                    else p->left=s;
                }
                else
                {
                    if(n==root)
                        root=0;
                    if(n==p->right)
                        p->right=0;
                    else p->left=0;
                }
                if(n==root)
                    root=s;
                delete(n);
            }
            else cout<<"Node does not exist!"<<endl;
        }
        void display()
        {
            printPretty(root,1,0,cout);
        }

};

int main()
{
    int choice,no;
    BST t;
    do
    {
        system("cls");

        cout<<"Enter 1 to Add element"<<endl;
        cout<<"Enter 2 to Delete an element"<<endl;
        cout<<"Enter 3 to Display"<<endl;
        cout<<"Enter 4 to Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                    cout<<"Enter an element : ";
                    cin>>no;
                    t.addNode(no);
                    break;

            case 2:
                    cout<<"Enter an element : ";
                    cin>>no;
                    t.delNode(no);
                    break;

            case 3:
                    cout<<endl;
                    t.display();
                    cout<<endl;
                    break;

            case 4:
                    cout<<"GoodBye!"<<endl;
                    break;

            default:
                    cout<<"Invalid Choice!"<<endl;
                    break;
        }
        getch();
    }while(choice!=4);

    return 0;
}

