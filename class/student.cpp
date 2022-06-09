#include <iostream>
using namespace std;
class student
{
public:
  int score=10;
  student(){
    cout << "create constructor" << endl;
  }
  ~student(){
    cout << "dispose constructor" << endl;
    delete &score;
  }

};
int main()
{
  student st;
  cout<<st.score;
  return 0;
}