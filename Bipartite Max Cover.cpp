#include<iostream>
using namespace std;

#define M 6
#define N 6

bool Check(int a[][N],int m[],bool c[], int u) //Finds a vertice for set A to match with
{
  for(int i=0;i<N;i++)
  {
    if(a[u][i] && !c[i])
    {
      c[i]=true;
      if(m[i]<0 || Check(a,m,c,m[i])) //Recursively calls the function to backtrack and find for other combinations
      {
        m[i]=u;
        return true;
      }
    }
  }
  return false;
}

int BMC(int a[][N])
{
    int match[N],result=0;
    bool check[N]; //Array to keep track whether the vertices in set B have been checked for respective set A vertice

    for(int i=0;i<N;i++)
    {
      match[i]=-1;
      check[i]=false;
    }

    for(int i=0;i<M;i++) //Tries to find a match for every vertice in set A
    {
      if(Check(a,match,check,i))
        result++;
    }

    return result;
}

int main()
{
    int a[M][N]; //M represents the number of vertices in set A and N in set B
    cout<<"Enter the adjacency matrix\n";

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<BMC(a);
    return 0;
}#include<iostream>
using namespace std;

#define M 5
#define N 5

bool Check(int a[][N],int m[],bool c[], int u) //Finds a vertice for set A to match with
{
  for(int i=0;i<N;i++)
  {
    if(a[u][i] && !c[i])
    {
      c[i]=true;
      if(m[i]<0 || Check(a,m,c,m[i])) //Recursively calls the function to backtrack and find for other combinations
      {
        m[i]=u;
        return true;
      }
    }
  }
  return false;
}

int BMC(int a[][N],int match[])
{
    int result=0;
    bool check[N]; //Array to keep track whether the vertices in set B have been checked for respective set A vertice

    for(int i=0;i<N;i++)
    {
      match[i]=-1;
    }

    for(int i=0;i<M;i++) //Tries to find a match for every vertice in set A
    {
      for(int j=0;j<N;j++)
        check[j]=false;

      if(Check(a,match,check,i))
        result++;
    }

    return result;
}

int main()
{
    int a[M][N],match[N]; //M represents the number of vertices in set A and N in set B
    cout<<"Enter the adjacency matrix with rows representing vertices of set A and columns representing vertices of set B\n";

    for(int i=0;i<M;i++)
    {
        cout<<"Row "<<i+1<<endl;
        for(int j=0;j<N;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<endl<<"The maximum number of matching is: "<<BMC(a,match)<<endl;
    cout<<endl<<"Final Matching:"<<endl;
    for(int i=0;i<N;i++)
    {
      if(match[i]!=-1)
        cout<<match[i]<<" --> "<<i<<endl;
    }
    return 0;
}
