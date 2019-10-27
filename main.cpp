#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main (int argc, char *argv[]) {

  // Getting the PID of the process
  string filename = "/proc/";
  filename.append(argv[1]);
  filename.append("/maps");


  cout << "filename" << filename << endl;
  ifstream map_file;
  map_file.open(filename);

  string line;
  if (map_file.is_open()) {
    cout << "map is open" << endl;
    while (getline(map_file, line)) {
      cout << "line: " << line << std::endl;
    }
  } else {
    cout << "map is closed ?? " << endl;
  }


  map_file.close();
  cout << "debug " << endl;

/*
  char address[1000], perms[1000], offset[1000], dev[1000], inode[1000], pathname[1000];

 
  while (fscanf(f, "%s %s %s %s %s %s", address, perms, offset, dev, inode, pathname) != EOF) {
   cout << "address: " << address << endl;
   cout << "perms: " << perms << endl;

  }

  fclose(f);
  */
}
