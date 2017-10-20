#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

//function to utilize iwconfig
string GetStdoutFromCommand(string cmd) {

  string data;
  FILE * stream;
  const int max_buffer = 256;
  char buffer[max_buffer];
  cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");
  if (stream) {
    while (!feof(stream))
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
  }
  return data;
}

//function to check for monitor mode
void MonitorMode(string ls) {

  //string str ();
  string str2 ("Monitor");

  // different member versions of find in the same order as above:
  size_t found = ls.find(str2);
  if (found!=string::npos)
  cout << R"(
          _            __      _       _
     __ _(_)_ __      / _| ___| |_ ___| |__
    / _` | | '__|____| |_ / _ \ __/ __| '_ \
   | (_| | | | |_____|  _|  __/ || (__| | | |
    \__,_|_|_|       |_|  \___|\__\___|_| |_|

          }}}}} INJECTION READY {{{{{
)" << endl;

  else
  cout << R"(
          _            __      _       _
     __ _(_)_ __      / _| ___| |_ ___| |__
    / _` | | '__|____| |_ / _ \ __/ __| '_ \
   | (_| | | | |_____|  _|  __/ || (__| | | |
    \__,_|_|_|       |_|  \___|\__\___|_| |_|

            }}}}} STEALTH MODE {{{{{
)" << endl;

}

int main (){
  string ls = GetStdoutFromCommand("iwconfig");
  MonitorMode(ls);
  cout << ls << endl;

  return 0;
}
