/*
  PART 三 (15分)
    1) 用 template 改寫 class counter_ptr int_array_cell
*/

#include <iostream>

using namespace std;

// 將原記憶體資料型態由 int 轉為 template
// 函式與 1_ClassVersion.cpp 相同

template <class T>
class int_array_cell
{
private:
  int _counter; // 記錄 cell 被多少指標參考
  T *_memory;   // 指向實際記憶體位置

public:
  // 當 cell 被建構時，其 counter 初始為 1、memory 指向傳入的記憶體位置，並輸出提示訊息
  int_array_cell(T *memory) : _counter(1), _memory(memory)
  {
    cout << "int_array_cell is allocated" << endl;
  }

  // 釋放 cell 參考
  void release()
  {
    if (--_counter == 0) // 釋放一個參考，再確認是否被其他指標參考
    { // 沒有 => 印出提示訊息並將指向的記憶體與 cell 從程式中釋放
      cout << "int_array_cell counter 0: deleted";
      delete _memory, this;
    }
    else
    { // 有 => 印出提示訊息
      cout << "int_array_cell counter is decreased: counter " << this->_counter;
    }
    cout << endl;
  }

  // 增加 cell 參考
  void increase()
  { // 增加一個參考並印出提示訊息
    cout << "int_array_cell counter is increased: counter "
         << ++this->_counter << endl;
  }

  // 取得 cell 被參考的數量
  int getCnt()
  {
    return _counter;
  }

  // 實作[]運算子，提供存取實際記憶體的方法
  T &operator[](int index)
  {
    return this->_memory[index];
  }
};

template <class T>
class counter_ptr
{
private:
  char *_name;                  // 指標名稱
  int_array_cell<T> *_cell_ptr; // 指向 cell 位置

  // 以傳入的記憶體位置建立 cell 並指向它
  void creatCell(T *memory)
  {
    this->_cell_ptr = new int_array_cell<T>(memory);
  }

public:
  // 當指標被建構時，其名稱設為傳入的字串，最後輸出指標狀態
  counter_ptr(char *name, T *memory) : _name(name)
  { // 有傳入記憶體位址便會建立 cell
    this->creatCell(memory);
    print();
  }
  counter_ptr(char *name) : _name(name), _cell_ptr(NULL)
  {
    print();
  }

  // 指標解構會印出提示訊息，並確保記憶體正確被釋放
  ~counter_ptr()
  {
    cout << "counter_ptr " << this->_name << " is deleted" << endl;
    if (this->_cell_ptr) // 確認指標有指向 cell，若有則會將 cell 釋出
      this->_cell_ptr->release();
  }

  // 印出指標狀態
  void print()
  {
    cout << "counter_ptr " << this->_name;
    if (this->_cell_ptr) // 確認指標有指向 cell，若有則印出 cell 共被多少指標參考
      cout << " is assigned to an int_array_cell: counter "
           << this->_cell_ptr->getCnt();
    else
      cout << " is not assigned to an int_array_cell";
    cout << endl;
  }

  // 釋放指標位址，並印出最終狀態
  void release()
  {
    if (this->_cell_ptr) // 確認指標有指向 cell，若有則會將 cell 釋出
    {
      this->_cell_ptr->release();
      this->_cell_ptr = NULL;
    }
    this->print();
  }

  // 實作=運算子，提供更新 cell 的方法，並印出最終狀態
  counter_ptr &operator=(T *memory) // 等號傳入值為記憶體位置
  {
    if (this->_cell_ptr) // 將指標指向的 cell 釋出 (確認指標有指向 cell，若有則會將 cell 釋出)
      this->_cell_ptr->release();
    this->creatCell(memory); // 以傳入的記憶體位置建立 cell
    print();
    return *this;
  }
  counter_ptr &operator=(const counter_ptr &ptr) // 等號傳入值為指標
  {
    if (this->_cell_ptr) // 將指標指向的 cell 釋出 (確認指標有指向 cell，若有則會將 cell 釋出)
      this->_cell_ptr->release();
    this->_cell_ptr = ptr._cell_ptr; // cell 指向與傳入指標相同的 cell
    this->_cell_ptr->increase();     // 增加 cell 的參考
    print();
    return *this;
  }

  // 實作[]運算子，提供存取實際記憶體的方法
  T &operator[](int index)
  {
    return (*this->_cell_ptr)[index];
  }
};
