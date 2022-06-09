#include <iostream>
#include<math.h>
#define PI 3.14
using namespace std;
class circle {
   protected:  
     double radius;

   public:
      circle():radius(0){
      };  ///circle;
      
      circle(double tradius):radius(tradius){};//circle 
      circle(circle &re){
          radius=re.radius; //this
      }
      ~circle(){
        cout<<"dispose circle cconstructor"<<endl;
        delete &radius;
        //cout<<radius;//cannot be printed
      }
      double getRadius(){return radius;};
      void setLength(double tradius){
        radius=tradius;
      }
      double Area(double r){
        return pow(r,2)*PI;
      }
      void prdouble(){
          cout<<"radius="<<radius<<endl;
      }
};
class sphere: protected circle{
   public:
      sphere():circle(){};//sphere s1;
      sphere(double tr):circle(tr){}
      sphere(sphere &s):circle(s.radius){}

      double Perimeter(double tr){
        return 2*PI*tr;
      }
      double Volume(double tr){
          return (double)4/3*tr*Area(tr);
      }
      double Surface(double tr){
        //return 4*PI*pow(tr,2);
        return 2*tr*Perimeter(tr);
      }
      void prdouble(){
          double v=Volume(radius);
          double a=Surface(radius);
          cout<<"Volume:="<<v<<"\nSuirface="<<a<<endl;

      }

};
/*
circle::~circle() {
   cout<<"goodbye circle";
   //delete radius;
}
sphere::~sphere() {
   cout<<"goodbye sphere";
   //delete radius;
}
*/
int main(){
    double r=5;
  
    //circle c1(5);
    //c1.prdouble();
    sphere s1(r);
    sphere s2(r);
    s1.prdouble();



  return 0;
}


