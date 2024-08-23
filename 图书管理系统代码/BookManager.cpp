//
//  BookManager.cpp
//  图书管理系统
//
//  Created by Hope on 2024/3/14.
//

#include "BookManager.hpp"
#include "Book.hpp"

// 按任意键继续 清屏
void CLEAR()
{
  cout << "请按任意键继续...." << endl;

  cin.get();
  cin.get();

  system("clear");
}

// 管理员验证
void BookManager::SignIn()
{
  while (true)
  {
    string account, password;
    cout << "请输入账号:";
    cin >> account;
    cout << "请输入密码:";
    cin >> password;

    if (account == this->BM_account && password == this->BM_password)
    {
      CLEAR();
      this->run(); // 进入管理员系统
      CLEAR();
      return;
    }
    else
    {
      cout << "登陆账号或密码错误，请重新登陆!!" << endl;
      CLEAR(); // 清屏
    }
  }
}

// 添加图书
void BookManager::addBook()
{
  while (true)
  {
    bool result = true;
    string name, author, publisher, ISBN;
    int inventory;
    double price;
    cout << "请输入ISBN号：";
    cin >> ISBN;
    cout << "请输入书名：";
    cin >> name;
    cout << "请输入作者名：";
    cin >> author;
    cout << "请输入出版单位：";
    cin >> publisher;
    cout << "请输入价格：";
    cin >> price;
    cout << "请输入库存量:";
    cin >> inventory;

    for (int i = 0; i < books.size(); i++) // 保证ISBN号的唯一性
    {
      if (ISBN == books[i].getISBN())
      {
        result = false;
      }
    }

    if (result)
    {
      Book book(name, publisher, ISBN, author, inventory, price);
      books.push_back(book); // 将图书加入图书信息数组中

      saveBooks(); // 将信息保存至文件中
      cout << "添加成功！" << endl;
      CLEAR();
      break;
    }
    else
    {
      cout << "你输入的ISBN号已经存在,请重新输入!!" << endl;
      CLEAR();
    }
  }
}

// 将图书信息保存至文件
void BookManager::saveBooks()
{
  ofstream file(filename);

  if (file.is_open())
  {
    // 先清空文件，然后在重新写入文件
    file.open(filename, ofstream::out | ofstream::trunc);
    file.close();

    file.open(filename);

    for (int i = 0; i < books.size(); i++)
    {
      file << books[i].toString() << endl;
    }
    file.close();
  }
}

void findBookMenu()
{
  cout << "==============================" << endl;
  cout << "==========1. 按书名查询=========" << endl;
  cout << "==========2. 按ISBN号查询=======" << endl;
  cout << "==========3. 按作者查询=========" << endl;
  cout << "==========4. 按出版社查询========" << endl;
  cout << "==========0. 退     出 =========" << endl;
  cout << "==============================" << endl;
}
// 查找图书信息
void BookManager::findBook()
{
  while (true)
  {
    int select;
    findBookMenu();
    cout << "请输入您的选择:";
    cin >> select;

    switch (select)
    {
    case 1: // 按书名查询
      findBookByName();
      break;
    case 2: // 按ISBN号查询
      findBookByISBN();
      break;
    case 3: // 按作者查询
      findBookByAuthor();
      break;
    case 4: // 按出版社查询
      findBookByPublisher();
      break;
    case 0: // 退出
    {
      CLEAR();
      return;
    }
    break;
    default:
    {
      cout << "输入有误请重新输入!!" << endl;
      CLEAR();
    }
    break;
    }
  }
}

// 查找图书信息 -- 书名查找
void BookManager::findBookByName()
{
  string name;
  cout << "请输入要查找的书名：";
  cin >> name;
  vector<Book> results; // 因为图书可能重名但作者不一样，所以用数组来存

  for (int i = 0; i < books.size(); i++)
  {
    if (books[i].getname() == name)
    {
      results.push_back(books[i]); // 将图书推入result数组中
    }
  }

  if (results.size() != 0)
  {
    for (int i = 0; i < results.size(); i++)
    {
      cout << "ISBN号:" << results[i].getISBN() << "\t"
           << "图书名:" << results[i].getname() << "\t"
           << "作者:" << results[i].getauthor() << "\t"
           << "出版社:" << results[i].getpublisher() << "\t"
           << "价格:" << results[i].getprice() << "\t"
           << "库存量:" << results[i].getinventory() << endl;
    }
    CLEAR();
  }
  else
  {
    cout << "未找到该图书!" << endl;
    CLEAR();
  }
}

// 查找图书信息 -- 作者名查找
void BookManager::findBookByAuthor()
{
  string author;
  cout << "请输入要查找的作者名:";
  cin >> author;
  vector<Book> results;

  for (int i = 0; i < books.size(); i++)
  {
    if (books[i].getauthor() == author)
    {
      results.push_back(books[i]);
    }
  }

  if (results.size() != 0)
  {
    for (int i = 0; i < results.size(); i++)
    {
      cout << "ISBN号:" << results[i].getISBN() << "\t"
           << "图书名:" << results[i].getname() << "\t"
           << "作者:" << results[i].getauthor() << "\t"
           << "出版社:" << results[i].getpublisher() << "\t"
           << "价格:" << results[i].getprice() << "\t"
           << "库存量:" << results[i].getinventory() << endl;
    }
    CLEAR();
  }
  else
  {
    cout << "未找到该图书!" << endl;
    CLEAR();
  }
}

// 查找图书信息 -- 通过ISBN号
void BookManager::findBookByISBN()
{
  string ISBN;
  cout << "请输入要查找的ISBN号:";
  cin >> ISBN;
  vector<Book> results;

  for (int i = 0; i < books.size(); i++)
  {
    if (books[i].getISBN() == ISBN)
    {
      results.push_back(books[i]);
      break; // 因为ISBN号唯一，所以找到后直接退出 节约时间
    }
  }

  if (results.size() != 0)
  {
    cout << "ISBN号:" << results[0].getISBN() << "\t"
         << "图书名:" << results[0].getname() << "\t"
         << "作者:" << results[0].getauthor() << "\t"
         << "出版社:" << results[0].getpublisher() << "\t"
         << "价格:" << results[0].getprice() << "\t"
         << "库存量:" << results[0].getinventory() << endl;
    CLEAR();
  }
  else
  {
    cout << "未找到该图书!" << endl;
    CLEAR();
  }
}

// 查找图书信息 -- 通过出版社查找
void BookManager::findBookByPublisher()
{
  string publisher;
  cout << "请输入要查找的出版社名:";
  cin >> publisher;
  vector<Book> results;

  for (int i = 0; i < books.size(); i++)
  {
    if (books[i].getpublisher() == publisher)
    {
      results.push_back(books[i]);
    }
  }

  if (results.size() != 0)
  {
    for (int i = 0; i < results.size(); i++)
    {
      cout << "ISBN号:" << results[i].getISBN() << "\t"
           << "图书名:" << results[i].getname() << "\t"
           << "作者:" << results[i].getauthor() << "\t"
           << "出版社:" << results[i].getpublisher() << "\t"
           << "价格:" << results[i].getprice() << "\t"
           << "库存量:" << results[i].getinventory() << endl;
    }
    CLEAR();
  }

  else
  {
    cout << "未找到该图书!" << endl;
    CLEAR();
  }
}

// 删除图书信息
void BookManager::deleteBook()
{
  string ISBN;
  cout << "请输入要删除的ISBN号：";
  cin >> ISBN;

  for (int i = 0; i < books.size(); i++)
  {
    if (books[i].getISBN() == ISBN)
    {
      books.erase(books.begin() + i);
      saveBooks(); // 更新文件
      cout << "删除成功！" << endl;
      CLEAR();
      return;
    }
  }
  cout << "未找到该图书信息！" << endl;
  CLEAR();
}

// 修改图书信息的菜单
void BookManager::modifyBookMenu()
{
  cout << "=============================" << endl;
  cout << "=========1. 修改书名 =========" << endl;
  cout << "=========2. 修改出版社 =======" << endl;
  cout << "=========3. 修改ISBN号 =======" << endl;
  cout << "=========4. 修改库存量 =======" << endl;
  cout << "=========5. 修改价格 =========" << endl;
  cout << "=========0. 退   出  =========" << endl;
  cout << "=============================" << endl;
}

// 修改图书信息
void BookManager::modifyBook()
{
  string ISBN;
  cout << "请输入要修改的ISBN号：";
  cin >> ISBN;
  for (int i = 0; i < books.size(); i++)
  {
    if (books[i].getISBN() == ISBN)
    {
      while (true)
      {
        int select;
        modifyBookMenu(); // 显示修改菜单
        cout << endl;
        cout << "请输入您的选择:";
        cin >> select;

        switch (select)
        {
        case 1: // 修改书名
          modifyBookName(i);
          break;
        case 2: // 修改出版社
          modifyBookPublisher(i);
          break;
        case 3: // 修改ISBN号
          modifyBookISBN(i);
          break;
        case 4: // 修改库存量
          modifyBookInventory(i);
          break;
        case 5: // 修改价格
          modifyBookPrice(i);
          break;
        case 0:
        {
          CLEAR();
          return;
        }
        break;
        default:
        {
          cout << "输入有误,请重新输入!!" << endl;
          // 清屏 按任意键继续
          CLEAR();
        }
        break;
        }
      }
    }
  }

  cout << "未找到该图书!" << endl;
  CLEAR();
}

// 修改图书名
void BookManager::modifyBookName(int num)
{
  string newname;
  cout << "请输入要修改的新书名:";
  cin >> newname;

  books[num].modifyBookName(newname);
  saveBooks(); // 保存文件

  cout << "修改成功!" << endl;
  CLEAR();
}

// 修改图书出版社
void BookManager::modifyBookPublisher(int num)
{
  string newpublisher;
  cout << "请输入新的出版社:";
  cin >> newpublisher;

  books[num].modifyBookPublisher(newpublisher);
  saveBooks();

  cout << "修改成功!!" << endl;
  CLEAR();
}

// 修改图书ISBN号 「注：修改后的ISBN号不能与现有图书重复」
void BookManager::modifyBookISBN(int num)
{
  while (true)
  {
    string newISBN;
    cout << "请输入新的ISBN号:";
    cin >> newISBN;
    bool result = true;

    // 判断输入的ISBN号是否与库存中重复
    for (int i = 0; i < books.size(); i++)
    {
      if (newISBN == books[i].getISBN())
      {
        result = false;
      }
    }

    if (result) // 不重复
    {
      books[num].modifyBookISBN(newISBN);
      saveBooks();

      cout << "修改成功!!" << endl;
      CLEAR();
      break;
    }
    else
    {
      cout << "输入的ISBN号与库存中重复,请重新输入!!" << endl;
      CLEAR();
    }
  }
}

// 修改图书库存量
void BookManager::modifyBookInventory(int num)
{
  int newinventory;
  cout << "请输入新的库存量:";
  cin >> newinventory;

  books[num].modifyBookInventory(newinventory);
  saveBooks();

  cout << "修改成功！！" << endl;
  CLEAR();
}

// 修改图书价格
void BookManager::modifyBookPrice(int num)
{
  double newprice;
  cout << "请输入新的价格:";
  cin >> newprice;

  books[num].modifyBookPrice(newprice);
  saveBooks();

  cout << "修改成功!!" << endl;
  CLEAR();
}

void showAllBookMenu()
{
  cout << "==========================" << endl;
  cout << "======1. 按图书价格显示======" << endl;
  cout << "======2. 按图书库存显示======" << endl;
  cout << "======3. 按作者显示库存======" << endl;
  cout << "======4. 按出版社显示库存====" << endl;
  cout << "======5. 统计图书总量=======" << endl;
  cout << "======0. 退        出======" << endl;
  cout << "==========================" << endl;
}
// 显示所有图书信息
void BookManager::showAllBooks()
{
  while (true)
  {
    int select;
    showAllBookMenu();
    cout << "请输入您的选择:";
    cin >> select;

    switch (select)
    {
    case 1:
      sortByPrice();
      break;
    case 2:
      sortByInventory();
      break;
    case 3: // 按作者进行统计
      showAllBooksByAuthor();
      break;
    case 4: // 按出版社进行统计
      showAllBooksByPublisher();
      break;
    case 5: // 统计书库中总量
      showAllBookNums();
      break;
    case 0:
    {
      CLEAR();
      return;
    }
    break;
    default:
    {
      cout << "输入错误,请您重新输入!!" << endl;
      CLEAR();
    }
    break;
    }
  }
}

// 按图书价格排序
bool cmpprice(Book a, Book b) { return a.getprice() > b.getprice(); }
void BookManager::sortByPrice()
{
  vector<Book> result;
  result = books;

  sort(result.begin(), result.end(), cmpprice); // 按价格升序排列

  // 输出显示
  for (int i = 0; i < result.size(); i++)
  {
    result[i].print();
  }
  CLEAR();
}

// 按图书库存量排序
bool cmpinventory(Book a, Book b) { return a.getinventory() > b.getinventory(); }
void BookManager::sortByInventory()
{
  vector<Book> result;
  result = books;

  sort(result.begin(), result.end(), cmpinventory); // 按库存量升序排列

  // 输出显示
  for (int i = 0; i < result.size(); i++)
  {
    result[i].print();
  }
  CLEAR();
}

// 排序
bool cmpnum(Statistics a, Statistics b) { return a.getnum() > b.getnum(); }
// 按作者进行统计
void BookManager::showAllBooksByAuthor()
{
  vector<Statistics> results;

  for (int i = 0; i < books.size(); i++)
  {
    bool re = true;
    string name = books[i].getauthor();
    int num = 0;

    for (int j = 0; j < results.size(); j++)
    {
      if (name == results[j].getname())
      {
        re = false;
        break;
      }
    }

    if (re)
    {
      for (int g = 0; g < books.size(); g++)
      {
        if (name == books[g].getauthor())
        {
          num += books[g].getinventory();
        }
      }

      Statistics p(name, num);
      results.push_back(p);
    }
  }

  sort(results.begin(), results.end(), cmpnum);

  for (int i = 0; i < results.size(); i++)
  {
    results[i].PrintAuthor();
  }
  CLEAR();
}

// 按出版社进行统计
void BookManager::showAllBooksByPublisher()
{
  vector<Statistics> results;

  for (int i = 0; i < books.size(); i++)
  {
    bool re = true;
    string name = books[i].getpublisher();
    int num = 0;

    for (int j = 0; j < results.size(); j++)
    {
      if (name == results[j].getname())
      {
        re = false;
        break;
      }
    }

    if (re)
    {
      for (int g = 0; g < books.size(); g++)
      {
        if (name == books[g].getpublisher())
        {
          num += books[g].getinventory();
        }
      }

      Statistics p(name, num);
      results.push_back(p);
    }
  }

  sort(results.begin(), results.end(), cmpnum);

  for (int i = 0; i < results.size(); i++)
  {
    results[i].PrintPublisher();
  }
  CLEAR();
}

// 统计书库中的总数量
void BookManager::showAllBookNums()
{
  int num = 0;
  for (int i = 0; i < books.size(); i++)
  {
    num += books[i].getinventory();
  }
  cout << "图书总数为:" << num << endl;

  CLEAR();
}

// 从文件中加载图书信息
void BookManager::loadBooks()
{
  ifstream inFile(filename);

  if (inFile.is_open())
  {
    string line;                  // 用来存储从文件中读取的每一行。
    while (getline(inFile, line)) // getline() 函数从 inFile 中读取一行，并将其存储在 line 变量中。
    {                             // getline() 函数会返回一个输入流，如果成功读取一行，那么这个输入流在进行布尔检查时会被解析为true
      int start = line.find(":");
      int end = line.find("\t");
      string ISBN = line.substr(start + 1, end - start - 1); // 截取ISBN号
      line = line.substr(end + 1);

      start = line.find(":");
      end = line.find("\t");
      string name = line.substr(start + 1, end - start - 1); // 截取书名
      line = line.substr(end + 1);

      start = line.find(":");
      end = line.find("\t");
      string author = line.substr(start + 1, end - start - 1); // 截取作者名
      line = line.substr(end + 1);

      start = line.find(":");
      end = line.find("\t");
      string publisher = line.substr(start + 1, end - start - 1); // 截取出版社名
      line = line.substr(end + 1);

      start = line.find(":");
      end = line.find("\t");
      double price = stod(line.substr(start + 1, end - start - 1)); // 截取价格 stod将string转换为double类型
      line = line.substr(end + 1);

      start = line.find(":");
      end = line.find("\t");
      int inventory = stoi(line.substr(start + 1, end - start - 1)); // 截取库存量 stoi将string转换为int类型

      Book book(name, publisher, ISBN, author, inventory, price); // 创建book类对象
      books.push_back(book);                                      // 插入书库中
    }

    inFile.close(); // 关闭文件
  }
}

// 购买函数
void BookManager::BuyBoook()
{
  while (true)
  {
    bool result = false;
    int num; // 记录购买书在books中的下标
    string ISBN;
    cout << "请输入要够买的书的ISBN号:" << endl;
    cin >> ISBN;

    for (int i = 0; i < books.size(); i++)
    {
      if (ISBN == books[i].getISBN())
      {
        result = true; // 书库中存在该书
        num = i;
        break; // 节约时间，因为ISBN号唯一
      }
    }

    if (result) // 如果书库中存在该书
    {
      int amount;
      cout << "这是您要购买书的信息，请确认:" << endl;
      books[num].print(); // 显示书籍信息
      cout << endl;
      cout << "请输入购买数量:";
      cin >> amount;
      if (books[num].getinventory() >= amount) // 库存足够
      {
        books[num].modifyBookInventory(books[num].getinventory() - amount); // 更新库存量
        saveBooks();                                                        // 更新文件数据
        cout << "购买成功!!" << endl;
        CLEAR();
        return;
      }
      else
      {
        cout << "购买失败，库存不足!" << endl;
        CLEAR();
        break;
      }
    }
    else
    {
      cout << "该书不存在!!" << endl;
      CLEAR();
      break;
    }
  }
}

// 管理员系统菜单
void BookManagerMenu()
{
  cout << "=======================" << endl;
  cout << "=======1. 添加图书======" << endl;
  cout << "=======2. 查询图书======" << endl;
  cout << "=======3. 修改图书======" << endl;
  cout << "=======4. 删除图书======" << endl;
  cout << "=======5. 统计图书======" << endl;
  cout << "=======0. 退   出======" << endl;
  cout << "=======================" << endl;
}

// 运行管理员系统
void BookManager::run()
{
  while (true)
  {
    int select;
    BookManagerMenu();
    cout << "请输入您的选择:";
    cin >> select;

    switch (select)
    {
    case 1: // 添加图书
      addBook();
      break;
    case 2: // 查询图书
      findBook();
      break;
    case 3: // 修改图书
      modifyBook();
      break;
    case 4: // 删除图书
      deleteBook();
      break;
    case 5: // 统计图书
      showAllBooks();
      break;
    case 0: // 退出
      return;
    default:
    {
      cout << "输入错误，请重新输入" << endl;
      CLEAR();
    }
    break;
    }
  }
}