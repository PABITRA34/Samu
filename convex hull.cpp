/*
Given random points in a 2-D plane, construct a convex polygon with minimum area of covering and 
which encompasses all the given points.
*/

/*
Erric cp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct p{
  ll x,y;
  void ip(){
    cin>>x>>y;
  }
  p operator -(const p& b) const{
     return p{x-b.x,y-b.y};
  }
  void operator -=(const p& b){
    x-=b.x;
    y-=b.y;
  }
  ll operator *(const p& b) const{
    return (ll)x*b.y -(ll)y*b.x;
  }
  ll triangle(const p& b,const p& c) const{// 'this' means myself
    return (b- *this) * (c - *this);
  }
   bool operator <(const p& b) const{
   return make_pair(x,y) < make_pair(b.x,b.y);// first compares on bases of x 
  }                                      // if tie bt x then acc to y
};
 
void solve(){// tc o(n*log(n))
  int n;cin>>n;
vector<p>points(n);
    for(p& pol:points){
        pol.ip();
    }
    sort(points.begin(),points.end());// sorting os reruied to move in a ssequential manner
    vector<p>hull;
    //  repeat the below segment of code twice - one for upper half and ohter for lower half using loop and updadate the while lopp cond
for(int i=0;i<2;i++){
   const int s=hull.size();
for(auto C:points){//hull.size()>=2(for upper half)
  while((int)hull.size()-s >= 2){// because first points will always lead to convex polygon
  p A=hull.end()[-2];// trick to access the indices/eles  like python 
  p B=hull.end()[-1];
  if(A.triangle(B,C)<=0){// B is on left of C    
    //  good and need not do any deletions
    break;
    }
    hull.pop_back();
  }
 hull.push_back(C);
}
hull.pop_back();// delete  the right most point as it is counted twice
 reverse(points.begin(),points.end());// just reverse the points for the lower half for the polygon
  }
 cout<<hull.size()<<"\n";
 for(auto pts:hull){
  cout<<pts.x<<" "<<pts.y<<"\n";
 }
}
int main(){  
        solve();
    
    return 0;
}

*/
#include<bits/stdc++.h>
int cou = 0;

struct Point{
    int x, y;
};
 
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}

bool cmp(Point &a, Point &b){
    if(a.x==b.x&&a.y==b.y)
        cou++;
    
    if(a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

bool myFunc(Point &a, Point &b){
    return (a.x==b.x && a.y==b.y);
}    
 
void convexHull(Point *points, int n){
    cou = 0;
    if (n < 3){
        cout << "-1";
        return;    
    } 
    
    vector<Point> hull;
    
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 
    int p = l, q;
    do{
        hull.push_back(points[p]);
        
        q = (p+1)%n;
        
        for (int i = 0; i < n; i++)
        {
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
        p = q;
 
    } while (p != l); 
    
    sort(hull.begin(), hull.end(), cmp);
    
    auto ip = unique(hull.begin(), hull.end(), myFunc); 
    
    hull.resize(std::distance(hull.begin(), ip)); 
    
    if(n < 4 && cou > 0 || hull.size() < 3){
        cout << "-1";
        return;
    }
    else{
        for (int i = 0; i < hull.size(); i++){
            if(i != hull.size() - 1)
                cout << hull[i].x << " " << hull[i].y << ", ";
            else
                cout << hull[i].x << " " << hull[i].y; 
        }        
    }
}
 
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        Point *points = new Point[n];

        for(int i=0; i<n; i++){
            cin >> points[i].x >> points[i].y;                
        }
        
        convexHull(points, n);
        cout << "\n";
    }
    return 0;
}
