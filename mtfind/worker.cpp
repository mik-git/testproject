#include "worker.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <regex>
#include <set>

const std::set<char> kSpecSymbols{'.','*','+','^','$','|', '\\'};

Worker::Worker(const std::string& fileName, const std::string& mask) :
  fileName_{fileName},
  mask_{mask}
{

}

void Worker::run()
{
  count_ = 0;
  result_.clear();

  fillMapString();
  fixMaskForRegEx();
  std::thread tr1(findSub, std::ref(strings_), mask_, std::ref(count_),std::ref(result_), Parts::FIRST);
  std::thread tr2(findSub, std::ref(strings_), mask_, std::ref(count_),std::ref(result_), Parts::SECOND);
  tr1.join();
  tr2.join();
}

void Worker::printResult()
{
  std::cout << count_ << std::endl;
  for ( const auto& s : result_ ) {
    std::cout << s << std::endl;
  }
}

void Worker::fillMapString()
{
  strings_.clear();
  std::ifstream inFStream{fileName_};
  for (int i = 1; !inFStream.eof();  i++ ) {
    std::string line;
    std::getline(inFStream, line);
    if ( line.empty() ) {
      continue;
    }
    strings_.insert( std::make_pair(i,line) );
  }
}

void Worker::fixMaskForRegEx()
{
  if ( fixed_ ) {
    return;
  }
  for ( int i = mask_.size(); i>=0 ;i--) {
    char& s = mask_[i];
    auto res = kSpecSymbols.find(s);
    if (res != kSpecSymbols.end()) {
      mask_.insert(i, 1, '\\');
      i--;
    }
    else if (s == '?') {
      mask_.replace(i,1,".");
    }
  }
  fixed_ = true;
//  std::cout << "result mask: " << mask_ << std::endl;
}

void Worker::findSub( const std::map<int, std::string>& strings, std::string mask, int& count, std::vector<std::string>& result, Worker::Parts p )
{
  int inCount = 0;
  std::vector<std::string> inResult;
  std::map<int, std::string>::const_iterator begin;
  std::map<int, std::string>::const_iterator end;
  switch (p) {
    case ALL: {
      begin = strings.begin();
      end = strings.end();
      break;
    }
    case FIRST: {
      begin = strings.begin();
      end = begin;
      std::advance(end, int(strings.size()/2));
      break;
    }
    case SECOND: {
      begin = strings.begin();
      std::advance(begin, int(strings.size()/2));
      end = strings.end();
    }
  }
  for( ; begin != end; begin++) {
    std::regex rg{mask};
    std::smatch match;
    auto res = std::regex_search(begin->second, match, rg);
    if ( res ) {
      inCount++;
      std::string str;
      str+= std::to_string(begin->first) + " " +  std::to_string(match.position(0)) + " " + match[0].str(); // 0 так как только одно входжение на строку
      inResult.push_back(str);
    }
  }
  std::mutex tr;
  tr.lock();
  count += inCount;
  result.insert(result.end(), inResult.begin(), inResult.end());
  tr.unlock();
}
