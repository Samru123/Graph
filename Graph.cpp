#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void showq(queue <int> gq)
{
    queue <int> g = gq;
    while (!g.empty())
    {
         cout << '\t' << g.front();
         g.pop();
    }
    cout << '\n';
}

void showq(stack <int> gq)
{
    stack <int> g = gq;
    while (!g.empty())
    {
         cout << '\t' << g.top();
         g.pop();
    }
    cout << '\n';
}

typedef struct node
{
    int v1;
    node *next;
}node;
class Graph
{
public:
    int v;

    int visited[10];
    int M[10][10];
    node *hn[10],*cn,*nn;
    queue<int>q;
    stack<int>s;
public:
    Graph()
    {
        for(int i=0;i<10;i++)
        {
            hn[i]=NULL;
        }
        nn=NULL;
        cn=NULL;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                M[i][j]=0;
            }
        }
    }



    void create_adj_matrix()
    {
        int v1,v2,i;
        cout<<"\n Enter  total no of vertices:";
        cin>>v;

        do
        {
            cout<<"\n  Enter starting & end point of edge:";
            cin>>v1>>v2;

            if((v1<0||v1>=v)&&(v2<0||v2>=v))
                cout<<"\n Invalid";

            else
            {
                M[v1][v2]=1;
                M[v2][v1]=1;
                i++;
            }
        }while((v-1)!=i);

    }

    void BFS_Adj_M()
    {
        int j,i,k;
        for(i=1;i<=v;i++)
        {
            visited[i]=0;
        }
        cout<<"\n Enter Starting Vertex";
        cin>>j;

        q.push(j);
        visited[j]=1;

        while(!q.empty())
        {
            j=q.front();
            q.pop();

            cout<<"\n"<<j<<endl;


            for(k=1;k<=v;k++)
            {
                if(M[k][j]==1 && visited[k]==0)
                {    q.push(k);
                visited[k]=1;
                }
            }
        }
    }

    void DFS_M(int k)
    {
        for(int i=1;i<=v;i++)
        {
            visited[i]=0;
        }
        visited[k]=1;
        s.push(k);

        while(!s.empty())
        {
            k=s.top();
            s.pop();


            cout<<"\n"<<k<<endl;
            for(int i=1;i<=v;i++)
            {
                if(M[i][k]==1 && visited[i]==0)
                {
                    s.push(i);
                    visited[i]=1;
                }
            }


        }


    }

    void DFS(int k)
    {

        visited[k]=1;
        cout<<"\n"<<k;

        for(int i=1;i<=v;i++)
        {
            if(visited[i]==0 && M[i][k]==1)
            {
                DFS(i);
            }
        }
    }


    void display()
    {
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
            {
                cout<<M[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }

    void create_list()
    {
        int v1,v2;
        char ch;
        do
        {
            cout<<"\n Enter (v1,v2)of vertices:";
            cin>>v1>>v2;
            nn=new node;
            nn->v1=v1;
            nn->next=NULL;

            if(hn[v2]==NULL)
                hn[v2]=nn;

            else
            {
                cn=hn[v2];
                while(cn->next!=NULL)
                    cn=cn->next;

                cn->next=nn;
            }

            nn=new node;
            nn->v1=v2;
            nn->next=NULL;
            if(hn[v1]==NULL)
                hn[v1]=nn;

            else
            {
                cn=hn[v1];
                while(cn->next!=NULL)
                    cn=cn->next;

                cn->next=nn;
            }

            cout<<"\n Continue?(y/n)";
            cin>>ch;
        }while(ch=='Y'||ch=='y');
    }

    void display_list()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"\n"<<i<<"->";
            cn=hn[i];

            while(cn!=NULL)
            {
                cout<<cn->v1<<"->";
                cn=cn->next;
            }

        }
    }
};

int main()
{
    Graph  g;
    int menu;
    char ans;
    int z,r;
    do
    {
        cout<<"\n Enter choice:1.Create Adj_M 2.BFS 3.DFS(Non) 4.DFS(Rec) 5.Display Matrix 6.Create List 7.Display List:";
        cin>>menu;

        switch(menu)
        {
        case 1:
            g.create_adj_matrix();
            break;

        case 2:
            g.BFS_Adj_M();
            break;

        case 3:
            cout<<"\n Enter vertex:";
            cin>>z;
            g.DFS_M(z);
            break;

        case 4:
            cout<<"\n Enter vertex:";
            cin>>r;
            for(int i=1;i<=g.v;i++)
            {
                g.visited[i]=0;
            }

            g.DFS(r);
            break;

        case 5:
            g.display();
            break;

        case 6:
            g.create_list();
            break;

        case 7:
            g.display_list();
            break;
        }
        cout<<"\n Do u want to contiue?";
        cin>>ans;
    }while(ans=='y'||ans=='Y');

    return 0;
}
