/*N-queen problem is famous back tracking problem to arrange N queen in N*N row column matrix such that each row and column have one queen
and no queen attack each other */ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int c,vector < vector < string > > &ans,vector<string> &board,int n,vector<int> &ldiagonal,vector<int> &rdiagonal,vector<int> &leftrow)
{
    if(c==n)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(leftrow[row]==0 && ldiagonal[row+c]==0 && rdiagonal[n-1 + c - row]==0)
        {
            board[row][c] = 'Q';
            leftrow[row]=1;
            ldiagonal[row+c]=1;
            rdiagonal[n-1 + c - row]=1;
            solve(c+1,ans,board,n,ldiagonal,rdiagonal,leftrow);
            board[row][c] = '.';
            leftrow[row]=0;
            ldiagonal[row+c]=0;
            rdiagonal[n-1 + c - row]=0;
        }
    }
}
vector<vector<string> > solveNqueen(int n)
{
    vector<vector<string> > ans; //ans it will store all the possibles solutions
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
        board[i]=s;
    vector<int> ldiagonal(2*n-1,0),rdiagonal(2*n-1,0),leftrow(n,0); //all of these are used to perform hashing to reduce time complexity 
    solve(0,ans,board,n,ldiagonal,rdiagonal,leftrow);
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    vector<vector<string> > result = solveNqueen(n);
    cout<<"\nPrinting all possible solution ";
    cout<<endl;
    cout<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout<<"Possible solution - "<<i+1<<endl;
        for(int j=0;j<n;j++)
            cout << result[i][j] <<endl;
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
