#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "Book.hpp"
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include"Statistics.hpp"

// 定义图书信息管理
class BookManager
{
private:
  string BM_account = "123456";
  string BM_password = "123456";
  vector<Book> books;            // 图书信息数组
  string filename = "Stack.txt"; // 保存图书信息的文件名

public:
  // 管理员验证
  void SignIn();
  // 添加图书信息
  void addBook();
  // 查找图书信息
  void findBook();
  void findBookByName();
  void findBookByAuthor();
  void findBookByISBN();
  void findBookByPublisher();
  // 删除图书信息
  void deleteBook();
  // 修改图书信息
  void modifyBook();
  void modifyBookMenu();             // 修改图书信息的菜单
  void modifyBookName(int num);      // 修改图书名
  void modifyBookPublisher(int num); // 修改图书出版社
  void modifyBookISBN(int num);      // 修改图书ISBN号 「注：修改后的ISBN号不能与现有图书重复」
  void modifyBookInventory(int num); // 修改图书库存量
  void modifyBookPrice(int num);     // 修改图书价格
  // 显示所有图书信息
  void showAllBooks();
  // 按价格排序
  void sortByPrice();
  // 按图书库存量排序
  void sortByInventory();
  // 按作者进行统计
  void showAllBooksByAuthor();
  // 按出版社进行统计
  void showAllBooksByPublisher();
  // 统计书库中的总数量
  void showAllBookNums();
  // 从文件中加载图书信息
  void loadBooks();
  // 将图书信息保存到文件
  void saveBooks();
  // 运行图书信息管理系统
  void run();
  // 购买函数
  void BuyBoook();
};
