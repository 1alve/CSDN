#pragma once
#include<iostream>
using namespace std;
#include<string>

class Statistics
{
public:
  string name;
  int num;

    Statistics();
  Statistics(string a,int b);

  string getname();
  int getnum();
  void PrintAuthor();
  void PrintPublisher();
};