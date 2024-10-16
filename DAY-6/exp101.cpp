#include <iostream>
using namespace std;

float area (float h, float b){//triangle
    return (0.5*b*h);
}
float area( float radius ){//circle
    return ( 3.14*radius*radius );
}
int area(int a){//square
    return a*a;
}
int area( int side , int height  ){//rectangle
    return ( side * height );
}
int main(){
    int a,br;
    float h,b;
    cout<<"Enter base and height for triangle :"<<endl;
    cin>>b>>h;
    float r;
    cout<<"Enter radius for circle :"<<endl;
    cin>>r;
    cout<<"Enter side for square :"<<endl;
    cin>>a;
    cout<<"Enter breadth for rectangle :"<<endl;
    cin>>br;
cout<<"Area for triangle :"<< area(h,b)<<"\nArea for circle :"<< area(r)<<"\nArea for square :"<< area(a)<<"\nArea for rectangle :"<< area(a,br)<<endl;
    return 0;
}