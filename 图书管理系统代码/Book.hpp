#pragma once
#include <iostream>
using namespace std;
#include <string>

class Book
{
private:
    string B_name;      // 书名
    string B_publisher; // 出版单位
    string B_ISBN;      // ISBN号
    string B_author;    // 作者名
    int B_inventory;    // 库存量
    double B_price;     // 价格

public:
    // 构造函数
    Book(string name, string publisher, string ISBN, string author, int inventory, double price);
    // 获取图书名
    string getname();
    // 获取图书ISBN号
    string getISBN();
    // 获取图书作者名
    string getauthor();
    // 获取图书出版单位
    string getpublisher();
    // 获取图书价格
    double getprice();
    // 获取图书库存量
    int getinventory();
    // 打印图书信息
    void print();
    // 修改图书名
    void modifyBookName(string name);
    // 修改图书出版社
    void modifyBookPublisher(string publisher);
    // 修改图书ISBN号 「注：修改后的ISBN号不能与现有图书重复」
    void modifyBookISBN(string ISBN);
    // 修改图书库存量
    void modifyBookInventory(int inventory);
    // 修改图书价格
    void modifyBookPrice(double price);
    // 将图书信息转为字符串
    string toString();
};
