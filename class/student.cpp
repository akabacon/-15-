#include <iostream>
using namespace std;
class student
{
public:
  int score;
  student(){
    cout << "create constructor" << endl;
  }
  ~student(){
    delete score;
  }

};
int main()
{

  return 0;
}