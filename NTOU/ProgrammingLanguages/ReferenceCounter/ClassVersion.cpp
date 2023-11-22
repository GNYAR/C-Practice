#include <iostream>

using namespace std;

class int_array_cell
{
private:
  int _counter;
  int *_memory;

public:
  int_array_cell(int *memory) : _counter(1), _memory(memory)
  {
    cout << "int_array_cell is allocated" << endl;
  }

  void release()
  {
    if (--_counter == 0)
    {
      cout << "int_array_cell counter 0: deleted";
      delete _memory, this;
    }
    else
    {
      cout << "int_array_cell counter is decreased: counter " << this->_counter;
    }
    cout << endl;
  }

  void increase()
  {
    cout << "int_array_cell counter is increased: counter "
         << ++this->_counter << endl;
  }

  int getCnt()
  {
    return _counter;
  }

  int &operator[](int index)
  {
    return this->_memory[index];
  }
};

class counter_ptr
{
private:
  char *_name;
  int_array_cell *_cell_ptr;

  void setMemory(int *memory)
  {
    this->_cell_ptr = new int_array_cell(memory);
  }

public:
  counter_ptr(char *name, int *memory) : _name(name)
  {
    this->setMemory(memory);
    print();
  }

  counter_ptr(char *name) : _name(name), _cell_ptr(NULL)
  {
    print();
  }

  ~counter_ptr()
  {
    cout << "counter_ptr " << this->_name << " is deleted" << endl;
    if (this->_cell_ptr)
      this->_cell_ptr->release();
  }

  void print()
  {
    cout << "counter_ptr " << this->_name;
    if (this->_cell_ptr)
      cout << " is assigned to an int_array_cell: counter "
           << this->_cell_ptr->getCnt();
    else
      cout << " is not assigned to an int_array_cell";
    cout << endl;
  }

  void release()
  {
    this->_cell_ptr->release();
    this->_cell_ptr = NULL;
    this->print();
  }

  counter_ptr &operator=(int *memory)
  {
    this->_cell_ptr->release();
    this->setMemory(memory);
    print();
    return *this;
  }

  counter_ptr &operator=(const counter_ptr &ptr)
  {
    if (this->_cell_ptr)
      this->_cell_ptr->release();
    this->_cell_ptr = ptr._cell_ptr;
    this->_cell_ptr->increase();
    print();
    return *this;
  }

  int &operator[](int index)
  {
    return (*this->_cell_ptr)[index];
  }
};

int main()
{

  // PART 一  (35分)

  counter_ptr b("b", new int[10]);
  // 需要撰寫 counter_ptr constructor(建構子) 接受兩個參數
  // stdout 輸出: int_array_cell is allocated
  // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1

  {
    b = new int[100];
    // 需要撰寫 counter_ptr operator=
    // stdout 輸出: int_array_cell counter 0: deleted
    // stdout 輸出: int_array_cell is allocated
    // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1

    counter_ptr a("a");
    // 需要撰寫 counter_ptr constructor(建構子) 接受一個參數
    // stdout 輸出: counter_ptr a is not assigned to an int_array_cell

    a = b;
    // 需要撰寫 counter_ptr operator=
    // stdout 輸出: int_array_cell counter is increased: counter 2
    // stdout 輸出: counter_ptr a is assigned to an int_array_cell: counter 2
  }
  // a leaves it scope:
  // 需要撰寫 counter_ptr destructor
  // stdout 輸出: counter_ptr a is deleted
  // stdout 輸出: int_array_cell counter is decreased: counter 1

  // PART 二  (35分)

  for (int i = 0; i < 10; i++)
    b[i] = i;
  // 需要撰寫 counter_ptr operator[] 寫值(回傳資料的參考 return type: int &)

  for (int i = 0; i < 10; i++)
    cout << b[i] << ' ';
  // 需要撰寫 counter_ptr operator[] 讀值(回傳資料)
  cout << endl;
  // stdout 輸出: 0 1 2 3 4 5 6 7 8 9

  counter_ptr c("c");
  // stdout 輸出: counter_ptr c is not assigned to an int_array_cell

  c = b;
  // stdout 輸出: int_array_cell counter is increased: counter 2
  // stdout 輸出: counter_ptr c is assigned to an int_array_cell: counter 2

  b.release();
  // 需要撰寫 counter_ptr release function: 不使用記憶體
  // stdout 輸出: int_array_cell counter is decreased: counter 1
  // stdout 輸出: counter_ptr b is not assigned to an int_array_cell

  return 0;
}
// c leaves it scope:
// 需要撰寫 counter_ptr destructor
// stdout 輸出: counter_ptr c is deleted
// stdout 輸出: int_array_cell counter 0: deleted
// stdout 輸出: counter_ptr b is deleted
