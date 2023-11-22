/*
  PART 三 (15分)
    1) 用 template 改寫 class counter_ptr int_array_cell
*/

#include <iostream>

using namespace std;

template <class T>
class int_array_cell
{
private:
  int _counter = 1;
  T *_memory;

public:
  int_array_cell(T *memory) : _memory(memory)
  {
    cout << "int_array_cell is allocated" << endl;
  }

  void free()
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

  T &operator[](int index)
  {
    return this->_memory[index];
  }
};

template <class T>
class counter_ptr
{
private:
  char *_name;
  int_array_cell<T> *_cell_ptr;

  void setMemory(T *memory)
  {
    this->_cell_ptr = new int_array_cell<T>(memory);
  }

public:
  counter_ptr(char *name, T *memory) : _name(name)
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
      this->_cell_ptr->free();
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
    this->_cell_ptr->free();
    this->_cell_ptr = NULL;
    this->print();
  }

  counter_ptr<T> &operator=(T *memory)
  {
    this->_cell_ptr->free();
    this->setMemory(memory);
    print();
    return *this;
  }

  counter_ptr<T> &operator=(const counter_ptr<T> &ptr)
  {
    if (this->_cell_ptr)
      this->_cell_ptr->free();
    this->_cell_ptr = ptr._cell_ptr;
    this->_cell_ptr->increase();
    print();
    return *this;
  }

  T &operator[](int index)
  {
    return (*this->_cell_ptr)[index];
  }
};
