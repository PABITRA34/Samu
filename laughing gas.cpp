You are busy to promote a newly released film in a movie theatre . the title is 'Biochemical Laughing Bomb' which is about terror. Guerillas drop a biochemical laughing bomb in the middle of a city. once exposed, you have to laugh all your life. The bomb will contaminate four people around it during t second, and another four around each of them during another one second. However, you won't be contaminated if you are not in the adjacent four directions. as the below shows the location of the bomb and affected people , and shows contamination process in seconds and you can figure out that the whole city is contaminated in 8 seconds. In order to protect the city from the epidemic, create a program that figures out when the city will be contaminated by the bomb for the last.

Input
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 30) are given in a row. The row and column of the city, N and M are given by being separated with a blank on the first row of each test case. (1 ≤ N, M ≤ 100) The status within city is given by being separated with a blank from the second row to N number rows. 1 means people exist and 0 means people do not exist. The coordinate of the row and column on which the bomb fall is given by being separated with a blank on the last row.

Output
For each test case, you should print "Case #T" in the first line where T means the case number. For each test case, you should output how long does it take to contaminate al people on the first row of each test case.

//https://www.cnblogs.com/kingshow123/p/practicec1.html
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
typedef struct
{
    int x;
    int y;
    int level;
}data;
int mv[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
//int mv[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int main()
{
    //freopen("test.txt","r",stdin);
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n,m;
        int r,c;
        cin>>n>>m;
        int a[m+1][n+1];
        memset(a,0,sizeof(int)*m*n);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>a[i][j];
            }
        }

        cin>>r>>c;
        data d,d1,d2;
        queue<data> qt;
        int tmx,tmy,tml;
        d.x = c;
        d.y = r;
        d.level = 1;
        qt.push(d);
        a[d.x][d.y] = 2;
        while(!qt.empty())
        {
            d1 = qt.front();
            qt.pop();
            for(int k=0; k<4; k++)
            {
                tmx = d1.x + mv[k][0];
                tmy = d1.y + mv[k][1];
                tml = d1.level + 1;
                if(a[tmx][tmy] == 1)
                {
                    d2.x = tmx;
                    d2.y = tmy;
                    d2.level = tml;
                    a[d2.x][d2.y] = 2;
                    qt.push(d2);
                }
            }
        }
        cout<<"Case #"<<t<<endl;
        cout<<tml-1<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
