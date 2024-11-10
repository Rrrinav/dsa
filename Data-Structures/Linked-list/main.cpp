// Linked list
#include <iostream>

struct Node
{
  int data;
  Node *next;

  Node() : data(0), next(nullptr) {}
  Node(int data) : data(data), next(nullptr) {}
  Node(int data, Node *next) : data(data), next(next) {}
};

class Linked_list
{
  Node *head;

  Linked_list() : head(nullptr) {}

  ~Linked_list() { clear(); }

  void insert(int data)
  {
    Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;
  }

  void delete_node(int data)
  {
    Node *current = head;
    Node *previous = nullptr;
    while (current)
    {
      if (current->data == data)
      {
        if (previous)
          previous->next = current->next;
        else
          head = current->next;
        delete current;
        return;
      }
      previous = current;
      current = current->next;
    }
  }

  void print()
  {
    Node *current = head;
    while (current)
    {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << "\n";
  }

  void clear()
  {
    while (head)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  bool empty() { return head == nullptr; }

  void reverse()
  {
    Node *previous = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current)
    {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }
    head = previous;
  }
};
