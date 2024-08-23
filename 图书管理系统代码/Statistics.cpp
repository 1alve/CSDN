#include "Statistics.hpp"

Statistics::Statistics(string a, int b)
{
  this->name = a;
  this->num = b;
}

string Statistics::getname()
{
  return this->name;
}
int Statistics::getnum()
{
  return this->num;
}

void Statistics::PrintAuthor()
{
  cout << "作者: " << this->name << "\t"
       << "数量: " << this->num << endl;
}

void Statistics::PrintPublisher()
{
  cout << "出版社: " << this->name << "\t"
       << "数量: " << this->num << endl;
}