#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

int isNotAlphaNum(char c)
{
  return !std::isalnum(c);
}

void countWords(std::istream& in, std::map<std::string, int>& words)
{
  std::string line;
  std::string word;
  while (std::getline(in, line))
  {
    std::replace_if(line.begin(), line.end(), isNotAlphaNum, ' ');
    std::istringstream iss(line);
    while (iss >> word)
    {
      words[word]++;
    }
  }
}

int main(int argc, char* argv[])
{
  if (argc < 3)
  {
    std::cerr << "No filename?" << std::endl;
    return -1;
  }

  std::ifstream in(argv[1]);

  if (!in)
  {
    std::cerr << "No data?" << std::endl;
    return -1;
  }

  std::map<std::string, int> words;
  countWords(in, words);

  std::ofstream out(argv[2]);
  for (std::map<std::string, int>::iterator p = words.begin();
      p != words.end(); p++)
  {
    out << " " << " " << " " << p->second << " " << p->first << "\n";
  }

  return 0;
}
