//
//  main.cpp
//  图书管理系统
//
//  Created by Hope on 2024/3/14.
#include <iostream>
using namespace std;
#include "BookManager.hpp"
#include "Book.hpp"

void Menu()
{
  cout << "===========================" << endl;
  cout << "=========1. 购买图书========" << endl;
  cout << "=========2. 图书管理员登陆===" << endl;
  cout << "=========0. 退   出========" << endl;
  cout << "===========================" << endl;
}

int main()
{

  // 创建管理员对象
  BookManager manager;
  manager.loadBooks(); // 读取文件中的信息 读入书库中
  while (true)
  {
    cout << "欢迎登陆图书管理系统!!" << endl
         << endl;
    int select;
    Menu(); // 显示开始的菜单

    cout << "请输入您的选择：";
    cin >> select;

    switch (select)
    {
    case 1: // 购买图书
      manager.BuyBoook();
      break;
    case 2: // 图书管理员登陆
      manager.SignIn();
      break;
    case 0: // 退出
      exit(0);
      break;
    default:
      cout << "输入错误，请重新输入!" << endl;
      // 按任意键继续 清屏
      break;
    }
  }

  return 0;
}