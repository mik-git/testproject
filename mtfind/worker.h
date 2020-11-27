#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <map>
#include <vector>
#include <fstream>

class Worker
{
public:
  explicit Worker(const std::string& fileName, const std::string& mask);

  void run();
  void printResult();

private:
  enum Parts  {
    FIRST,
    SECOND,
    ALL
  };

  void fillMapString();
  void fixMaskForRegEx();
  static void findSub( const std::map<int, std::string>& strings, std::string mask, int& count, std::vector<std::string>& result, Parts p = ALL  );

private:
  std::string fileName_;
  std::string mask_;
  std::map<int,std::string> strings_;
  std::vector<std::string> result_;
  int count_ = 0;
  bool fixed_ = false;
};

#endif // WORKER_H
