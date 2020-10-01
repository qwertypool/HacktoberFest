#include<bits/stdc++.h>
using namespace std;
int target;
// custom comparator for sorting on the basis of length
bool cmp(string a,string b){
    return a.length()<b.length();
}

// checking the position if it is safe or not
bool isSafe(int row,int col,vector<vector<int>> &maze,vector<vector<bool>> &visited){
    if(col==-1||row==-1||row==5||col==5||visited[row][col]||maze[row][col]==0){
        return false;
    }
    return true;
}

// finding the path
void path_find(int row,int col,string &path,vector<string> &paths,vector<vector<int>> &maze,vector<vector<bool>> &visited){
    if(col==-1||row==-1||row==5||col==5||visited[row][col]||maze[row][col]==0){
        return;
    }
    if(maze[row][col]==target){
        paths.push_back(path);
        return;
    }
    visited[row][col]=true;
    if(isSafe(row+1,col,maze,visited)){
        path.push_back('D');
        path_find(row+1,col,path,paths,maze,visited);
        path.pop_back();
    }
    if(isSafe(row-1,col,maze,visited)){
        path.push_back('U');
        path_find(row-1,col,path,paths,maze,visited);
        path.pop_back();
    }
    if(isSafe(row,col+1,maze,visited)){
        path.push_back('R');
        path_find(row,col+1,path,paths,maze,visited);
        path.pop_back();
    }
    if(isSafe(row,col-1,maze,visited)){
        path.push_back('L');
        path_find(row,col-1,path,paths,maze,visited);
        path.pop_back();
    }
    visited[row][col]=false;
}

// solve_maze that takes the maze and the number of row columns
void solve_maze(vector<vector<int>> maze,int n,int m){
    vector<string> paths;
    string path;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    path_find(0,0,path,paths,maze,visited);
    cout<<"The matrix:\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<"\n";
    }
    sort(paths.begin(),paths.end(),cmp);
    cout<<"Shortest path: "<<paths[0]<<"\n";
    cout<<"Other paths:\n";
    for(int i=0;i<paths.size();i++){
        cout<<paths[i]<<"\n";
    }
    return;
}

// main
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,i,j;
    cin>>n>>m>>target;
    vector<vector<int>> maze(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    solve_maze(maze,n,m);
    return 0;
}
// end of main
