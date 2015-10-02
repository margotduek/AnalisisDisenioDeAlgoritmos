#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>
#include <fstream>
#include "IndexOutOfBoundsException.cpp"

// This class assumes that order is small; as such it uses arrays to store
// data and children. If order were large a list would be prefered.
template <class Record, int order>
class NodeDisk
{

private:
  int count;
  std::string fileName;
  static int id;
  Record data[order - 1];
  std::string children[order];

public:

  NodeDisk();
  NodeDisk(int count, Record *  _data, std::string * _children, std::string);
  virtual ~NodeDisk();

  int getCount(){return count;};
  Record & getData(const int position);
  std::string getChildren(const int position);
  std::string getFileName(){return this->fileName;};

  void setCount(const int count);
  void setData(const int position, Record  record);
  void setChildren(const int position, std::string node);

  void incrementCount(){ setCount(count + 1); };
  void decrementCount(){ setCount(count - 1); }

  void write();

  template <typename T, int n>
  friend std::ostream & operator << (std::ostream & os, NodeDisk<T, n>  & node);

};

template<class Record, int order>
int NodeDisk<Record, order>::id = 0;

template <class Record, int order>
NodeDisk<Record, order>::NodeDisk()
{
  this->fileName = ".node" + std::to_string(++id);
  this->count = 0;

  for (int i = 0; i < order; i++)
    data[i] = 0;

  for (int i = 0; i < order + 1; i++)
    children[i] = "NaN";

  write();
}

template <class Record, int order>
NodeDisk<Record, order>::NodeDisk(int count, Record * _data,
    std::string * _children, std::string fileName)
{
  this->fileName = fileName;
  this->count = count;
  for (int i = 0; i < order - 1; i++)
    this->data[i] = _data[i];
  for (int i = 0; i < order; i++)
    this->children[i] = _children[i];
}

template <class Record, int order>
NodeDisk<Record, order>::~NodeDisk()
{

}

// REQUIRES: None.
// MODIFIES: None.
// EFFECTS: If position is valid, returns pointer to children. Else nullptr.
template <class Record, int order>
std::string NodeDisk<Record, order>::getChildren(const int position)
{
  if (position < order  && position >= 0)
    return this->children[position];
  else
    throw IndexOutOfBoundsException();
}

// REQUIRES: None.
// MODIFIES: None.
// EFFECTS: If position is valid, returns record. Else throw KeyNotFoundException.
template <class Record, int order>
Record & NodeDisk<Record, order>::getData(const int position)
{
  if (position < order - 1 && position >= 0)
    return this->data[position];
  else
    throw IndexOutOfBoundsException();
}

template <class Record, int order>
void NodeDisk<Record, order>::setCount(const int count)
{
  this->count = count;
  write();
}

// REQUIRES: None.
// MODIFIES: this.
// EFFECTS: Returns true if data set was succesful, false otherwise.
template <class Record, int order>
void NodeDisk<Record, order>::setData(const int position, Record record)
{
  if (position < order - 1 && position >= 0)
  {
    this->data[position] = record;
    write();
  }
  else
    throw IndexOutOfBoundsException();
}

// REQUIRES: None.
// MODIFIES: this.
// EFFECTS: Returns true if children set was succesful, false otherwise.
template <class Record, int order>
void NodeDisk<Record, order>::setChildren(const int position, std::string name)
{
  if (position < order && position >= 0)
  {
    this->children[position] = name;
    write();
  }
  else
    throw IndexOutOfBoundsException();
}

template <class Record, int order>
void NodeDisk<Record, order>::write()
{
  ofstream nodeFile;
  nodeFile.open(fileName, std::ofstream::out | std::ofstream::trunc);

  nodeFile << count << " ";
  for (int i = 0; i < order - 1; i++)
  {
    if (data[i] == 0)
    {
    nodeFile << "0 ";
    }
    else
    {
      nodeFile << data[i] << " ";
    }
  }
  for (int i = 0; i < order; i++)
  {
    nodeFile << children[i] << " ";
  }
  nodeFile.close();
}

template <class Record, int order>
std::ostream & operator << (std::ostream & os, NodeDisk<Record, order>  & node)
{
  for (int i = 0; i < order - 1; i++)
  {
    if (i < node.getCount())
      os << node.getData(i) << " ";
  }
  return os;
}


#endif
