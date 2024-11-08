/*
https://www.careercup.com/question?id=5707238197952512
https://practice.geeksforgeeks.org/problems/how-to-solve-this-bfs-problem-asked-in-samsung
https://discuss.codechef.com/t/samsung-question-geeksforgeeks/17092

1 Bsed -> https://sapphireengine.com/@/4q0evk - Ajay Verma
0 Bsed -> https://sapphireengine.com/@/iha4kq - Thusoo
*/

/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.

Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.

Locations are given in the matrix cell form where 1 represents roads and 0 no road. 
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of 
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them

Input - 
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1

Output - 
1
2
2
12
15
4
*/
///
/******************************************************************************


/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>vis, dist, g;
int n, rc;
void reset(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[i][j]=0;
            dist[i][j]=-1;
        }
    }
}
bool safe(int i, int j ){
    return (i>=1 && i<=n && j>=1 && j<=n && vis[i][j]==0 && g[i][j]==1);
}
void bfs(int x,int y){
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    queue< pair< int, pair<int,int>>>q;
    q.push({0,{x,y}});
    vis[x][y]=1;
    dist[x][y]=0;
    while(!q.empty()){
        auto curr= q.front();
        q.pop();
        int i= curr.second.first;
        int j= curr.second.second;
        int dd= curr.first;
        for(int d=0;d<4;d++){
            int ni= i+ dr[d];
            int nj= j+ dc[d];
            if(safe(ni,nj)){
                q.push({dd+1,{ni,nj}});
                vis[ni][nj]=1;
                dist[ni][nj]= dd+1;
            }
        }
    }
    
}
int main()
{
     int t; cin>>t;
     while(t--){
         cin>>n>>rc;
         // clear the previous outputs , otherwise may return previos outputs or random behaviour 
         // whenever using global variables must clear  , it is because of global variables lost one big opportunity
         g.clear();
         vis.clear();
         dist.clear();
          g.resize(n+1, vector<int>(n+1,0));
          vis.resize(n+1, vector<int>(n+1,0));
          dist.resize(n+1, vector<int>(n+1,-1));
         reset();
         
         vector<int>x(rc+1,-1), y(rc+1,-1);
         for(int i=1;i<=rc;i++){
             cin>>x[i]>>y[i];
         }
        
         for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                 cin>>g[i][j];
             }
         }
         int ans=1e9;
         // bfs 
         int cnt=1;
         for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                 if(g[i][j]==1){
                     reset();
                     bfs(i,j);
                     int maxi=-1;
                     for(int k=1;k<=rc;k++){
                        maxi= max(maxi, dist[x[k]][y[k]]);
                     }
                     if(maxi>0 ) ans = min(ans, maxi);
                 }
             }
         }
         
         cout<<ans<<"\n";
     }

    return 0;
}























Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int n, rc; 
int front=-1, rear=-1;
struct queue{
    int r,c;
}q[10000];
int g[22][22], dist[22][22];
int rloc[5][2];
void init(){
    front=-1; rear=-1;
    for(int i=0;i<22;i++){
        for(int j=0;j<22;j++){
            dist[i][j]=0;
        }
    }
    for(int i=0;i<10000;i++){
        q[i].r=0;
        q[i].c=0;
    }
}
void solve(int i, int j, int d){
    int cc=0;
    for(int k=0;k<rc;k++){
        if(dist[rloc[k][0]][rloc[k][1]] >0) cc++;
    }
    if(cc>=rc) return;
    // up call
    if(i-1>=1 && dist[i-1][j]==0 && (g[i-1][j]==1 || g[i-1][j]==3)){
        dist[i-1][j]= d +1;
        rear++;
        q[rear].r=i-1;
        q[rear].c=j;
    }
    // down
        if(i+1<=n && dist[i+1][j]==0 && (g[i+1][j]==1 || g[i+1][j]==3)){
        dist[i+1][j]= d +1;
        rear++;
        q[rear].r=i+1;
        q[rear].c=j;
    }
    // left
        if(j-1>=1 && dist[i][j-1]==0 && (g[i][j-1]==1 || g[i][j-1]==3)){
        dist[i][j-1]= d +1;
        rear++;
        q[rear].r=i;
        q[rear].c=j-1;
    }
    // right
        if(j+1 <=n && dist[i][j+1]==0 && (g[i][j+1]==1 || g[i][j+1]==3)){
        dist[i][j+1]= d +1;
        rear++;
        q[rear].r=i;
        q[rear].c=j+1;
    }
    // recur
    while(front < rear){
        front++;
        int ni= q[front].r, nj= q[front].c;
        solve(ni, nj, dist[ni][nj]);
    }
}
int main()
{
   int t; cin>>t;
   init();
   while(t--){
       cin>>n>>rc;
       for(int i=0;i<rc;i++){
           cin>>rloc[i][0]>>rloc[i][1];
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               cin>>g[i][j];
           }
       }
       // mark metal centres with flg 3 
       for(int i=0;i<rc;i++){
           g[rloc[i][0]][rloc[i][1]]=3;
       }
       int ans=100000000;
       for(int i=1;i<=22;i++){
           for(int j=1;j<=22;j++){
               if(g[i][j]==1){
                   dist[i][j]=1;
                   int maxi=0;
                   init();
                   solve(i,j,1);// start timer by 1
                   for(int k=0;k<rc;k++){
                       if(dist[rloc[k][0]][rloc[k][1]] > maxi) maxi= dist[rloc[k][0]][rloc[k][1]];
                   }
                   ans= min(ans,maxi);
               }
           }
       }
       cout<<ans-1<<"\n";
   }

    return 0;
}




///

#include <stdio.h>
int Answer = 9999;
int region[22][22];
int visited[22][22];
int N, C;
int location[5][2];
int rear = -1;
int front = -1;
struct queue {
    int row;
    int col;
}Q[10000];

void init()
{
    int m,n;
    rear = -1;
    front = -1;
    for(m = 0; m < 22; m++)
    {
        for(n = 0; n < 22; n++)
        {
            visited[m][n] = 0;
        }
    }

    for(m = 0; m < 10000; m++)
    {
        Q[m].row = 0;
        Q[n].col = 0;
    }
}

void discover(int row, int col, int val)
{
    int l, m, k;
    int cnt = 0;

    for(k = 0; k < C; k++)
    {
        if(visited[location[k][0]][location[k][1]] > 0)
            cnt++;
    }
    if(cnt >= C)
        return;

    if((row-1) >= 1 && visited[row-1][col] == 0 && (region[row-1][col] == 1 || region[row-1][col] == 3))
    {
        visited[row-1][col] = val+1;
        ++rear;
        Q[rear].row = row-1;
        Q[rear].col = col;
    }
    if((row+1) <= N && visited[row+1][col] == 0 && (region[row+1][col] == 1 || region[row+1][col] == 3))
    {
        visited[row+1][col] = val+1;
        ++rear;
        Q[rear].row = row+1;
        Q[rear].col = col;
    }
    if((col-1) >= 1 && visited[row][col-1] == 0 && (region[row][col-1] == 1 || region[row][col-1] == 3))
    {
        visited[row][col-1] = val+1;
        ++rear;
        Q[rear].row = row;
        Q[rear].col = col-1;
    }
    if((col+1) <= N && visited[row][col+1] == 0 && (region[row][col+1] == 1 || region[row][col+1] == 3))
    {
        visited[row][col+1] = val+1;
        ++rear;
        Q[rear].row = row;
        Q[rear].col = col+1;
    }
    
    while(front<rear)
    {
        ++front;
        discover(Q[front].row, Q[front].col, visited[Q[front].row][Q[front].col]);
    }

}

int main(void){
    int T, test_case;

    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        int i,j,k;
        int x,y,c;
        int temp = 0;

        Answer = 9999;

        scanf("%d%d", &N, &C);

        for(i = 0; i < C; i++)
        {
            scanf("%d%d", &x, &y);
            location[i][0] = x;
            location[i][1] = y;
        }

        for(i = 1; i <= N; i++)
        {
            for(j = 1; j <= N; j++)
            {
                scanf("%d", &region[i][j]);
            }
        }
        for(k = 0; k < C; k++)
        {
            region[location[k][0]][location[k][1]] = 3;
        }

        init();
        Answer = 9999;
        for(i = 1; i <= N; i++)
        {
            for(j = 1; j <= N; j++)
            {
                init();
                temp = 0;
                if(region[i][j] == 1)
                {
                    visited[i][j] = 1;
                    discover(i, j, 1);
                    for(k = 0; k < C; k++)
                    {
                        if(temp < visited[location[k][0]][location[k][1]])
                            temp = visited[location[k][0]][location[k][1]];
                    }
                    if(Answer > temp)
                        Answer = temp;
                }
                
            }
        }
        printf("#%d %d\n", test_case+1, Answer-1);
    }
    return 0;
}

