#include "worker.h"
#include <iostream>
#include <string>
#include <fstream>

const int kOneGb = 1024 * 1024 * 1024 ;
const int kMaxMask = 100;

std::ifstream::pos_type filesize(const std::string& fileName)
{
    std::ifstream in(fileName, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

int main(int argc, char *argv[])
{
  if ( argc < 3 ) {
    std::cout << "Too few arguments" << std::endl;
    return 1;
  }
  std::string fileName{argv[1]};
  std::string mask{argv[2]};// присваиваем "в лоб" по условию тестового

  if ( mask.size() > kMaxMask) {
    std::cout << "Mask is too long" << std::endl;
    return 1;
  }

  if (filesize(fileName) > kOneGb) {
    std::cout << "Filesize is too big" << std::endl;
    return 1;
  }

  Worker w{fileName,mask};
  w.run();
  w.printResult();

  return 0;
}
