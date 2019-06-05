#include <iostream>
#include <vector>

using std::cout;
using std::vector;

struct Point{

	int x,y;
};

int orientation(Point p,Point q,Point r){

	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x)*(r.y - q.y);

	if(val == 0) 
		return 0;

	return (val > 0) ? 1 : 2;

}
vector<Point> convex_hull(Point points[],int n){


	vector<Point> v;
	if(n < 3){
		
		v.push_back((Point){0,0});
		return v;
	}

	int l = 0;

	for(int i = 1; i < n; i++)
		if(points[i].x < points[l].x)
			l = i;

	int p = l,q;

	do{

		v.push_back(points[p]);

		q = (p+1) % n;

		for(int i = 0; i < n; i++)
			if(orientation(points[p],points[i],points[q]) == 2)
				q = i;
		
		p = q;

	}while(p != l);

	return v;

}
int main(void){


	Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 


     int n = sizeof(points)/sizeof(points[0]);

     vector<Point> p = convex_hull(points,n);


     cout << "Convex hull for the set of points is\n";

     for(int i = 0; i < p.size(); i++)
     	cout << p[i].x << "," << p[i].y << "\n";


	return 0;
}