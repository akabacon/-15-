#include<iostream>
using namespace std;

class myClass
{
public:
   int d[10];
   myClass() {
      cout << "create constructor!" << endl;
   }

   ~myClass() {
      cout << "dispose constructor!" << endl;
   }
};

void print(myClass x)
{
    for(int i=0; i<10; i++)
        cout << x.d[i] << " ";
    cout << endl;
}

int main()
{
    myClass obj1; //產生物件，應執行 constructor

    print(obj1);

    for(int i=0; i<10; i++)
        obj1.d[i]=i;
 
    myClass obj2=obj1; //產生物件，應執行 constructor
    print(obj2);
    
    return 0; //obj1 與 obj2 生命週期結束，應執行 destructor
}