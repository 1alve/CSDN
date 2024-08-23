#include "Book.hpp"

// 构造函数
Book::Book(string name, string publisher, string ISBN, string author, int inventory, double price)
{
    this->B_name = name;
    this->B_publisher = publisher;
    this->B_ISBN = ISBN;
    this->B_author = author;
    this->B_inventory = inventory;
    this->B_price = price;
};

// 打印图书信息
void Book::print()
{
    cout << "ISBN号:" << this->B_ISBN << "\t";
    cout << "书名：" << this->B_name << "\t";
    cout << "作者名：" << this->B_author << "\t";
    cout << "出版社：" << this->B_publisher << "\t";
    cout << "价格：" << this->B_price << "\t";
    cout << "库存量:" << this->B_inventory << endl;
};

// 将图书信息转为字符串
string Book::toString()
{
    string str = "ISBN号:" + this->B_ISBN + "\t" + "书名:" + this->B_name + "\t" + "作者:" + this->B_author + "\t" + "出版社:" + this->B_publisher + "\t" + "价格:" + to_string(this->B_price) + "\t" + "库存量:" + to_string(this->B_inventory);
    return str;
};

// 获取图书名
string Book::getname()
{
    return this->B_name;
}

// 获取图书ISBN号
string Book::getISBN()
{
    return this->B_ISBN;
}

// 获取图书作者名
string Book::getauthor()
{
    return this->B_author;
}

// 获取图书出版单位
string Book::getpublisher()
{
    return this->B_publisher;
}

// 获取图书价格
double Book::getprice()
{
    return this->B_price;
}

// 获取图书库存量
int Book::getinventory()
{
    return this->B_inventory;
}

// 修改图书名
void Book::modifyBookName(string name)
{
    this->B_name = name;
}
// 修改图书出版社
void Book::modifyBookPublisher(string publisher)
{
    this->B_publisher = publisher;
}
// 修改图书ISBN号 「注：修改后的ISBN号不能与现有图书重复」
void Book::modifyBookISBN(string ISBN)
{
    this->B_ISBN = ISBN;
}
// 修改图书库存量
void Book::modifyBookInventory(int inventory)
{
    this->B_inventory = inventory;
}
// 修改图书价格
void Book::modifyBookPrice(double price)
{
    this->B_price = price;
}