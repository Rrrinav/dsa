#include <array>
#include <iostream>
#include <string>

#include "./list.hpp"

struct Node
{
  std::array<Node *, 26> _characters;
  bool _isEnd;

  Node() : _isEnd(false) { _characters.fill(nullptr); }
};

class Trie
{
  Node *_root;

public:
  Trie() : _root(new Node) {}

  void insert(std::string word)
  {
    Node *current = _root;

    for (auto c : word)
    {
      if (current->_characters[c - 'a'] == nullptr)
        current->_characters[c - 'a'] = new Node;

      current = current->_characters[c - 'a'];
    }

    current->_isEnd = true;
  }

  bool search(std::string word)
  {
    Node *current = _root;

    for (auto c : word)
    {
      if (current->_characters[c - 'a'] == nullptr)
        return false;

      current = current->_characters[c - 'a'];
    }

    return current->_isEnd;
  }

  void suggest(std::string word)
  {
    Node *current = _root;

    for (auto c : word)
    {
      if (current->_characters[c - 'a'] == nullptr)
        return;

      current = current->_characters[c - 'a'];
    }

    suggestions_helper(current, word);
  }

  void print_graph_viz()
  {
    std::cout << "digraph Trie{" << std::endl;
    std::cout << "node [shape = circle];" << std::endl;
    print_graph_viz_helper(_root, "");

    std::cout << "}" << std::endl;
  }

private:
  void suggestions_helper(Node *node, const std::string &word)
  {
    if (node->_isEnd == true)
      std::cout << word + '\n';

    for (int i = 0; i < 26; i++)
      if (node->_characters[i] != nullptr)
        suggestions_helper(node->_characters[i], word + char('a' + i));
  }

  void print_graph_viz_helper(Node *root, std::string word)
  {
    if (root->_isEnd)
      std::cout << " \"" << word << "\" [shape = doublecircle label=\"" << word << " \" ];" << std::endl;
    else
      std::cout << " \"" << word << "\" [ label=\"" << word << " \" ];" << std::endl;

    for (int i = 0; i < 26; i++)
    {
      if (root->_characters[i] != nullptr)
      {
        std::string nextword = word + (char)('a' + i);
        std::cout << " \"" << word << "\" -> \"" << nextword << "\";" << std::endl;

        print_graph_viz_helper(root->_characters[i], nextword);
      }
    }
  }
};

int main(int argc, char *argv[])
{
  Trie trie = Trie();
  for (auto veg : veggies) trie.insert(veg);
  trie.print_graph_viz();
}
