#include <utility>
#include <xtd/string.hpp>
#include <xtd/parse.hpp>
#include "ooasm.hpp"
#include "cli.hpp"

int main(int argc, char * argv[]) {
  using namespace ooasm;
  xtd::string sParams = "";
  for (int i=1; i<argc ; i++){
    sParams += argv[i];
    sParams += ' ';
  }
  auto oAST = xtd::parser<cli::cmdline, true, cli::WS>::parse(sParams.begin(), sParams.end());
  return 0;
}