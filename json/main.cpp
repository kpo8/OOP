#include "json.hpp"
#include "redditClass.hpp"

#include <iterator>
#include <iostream>
#include <string>

int
main(int argc, char* argv[])
{
  std::istreambuf_iterator<char> first(std::cin);
  std::istreambuf_iterator<char> last;
  std::string s(first, last);
  json::Value* val = json::parse(s);
  author Author = val;
  title Title = val;

  cout << Author.getAuthor() << '\n';
  cout << Title.getTitle() << '\n';
  //std::cout << size(val) << ' ' << height(val) << '\n';
  //std::cout << *val << '\n';
}

