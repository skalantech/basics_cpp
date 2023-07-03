/* Opening a File
Either ofstream or fstream object may be used to open a file for writing
void open(const char *filename, ios::openmode mode);

ios::app: Append mode. All output to that file to be appended to the end.

ios::ate: Open a file for output and move the read/write control to the end of the file.

ios::in: Open a file for reading.

ios::out: Open a file for writing.

ios::trunc: If the file already exists, its contents will be truncated before opening the file.

ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );

fstream  afile;
afile.open("file.dat", ios::out | ios::in );

Closing a File
void close();

Reading from a File
stream extraction operator (>>)
ifstream or fstream object instead of the cin object.

Writing to a File
stream insertion operator (<<)
ofstream or fstream object instead of the cout object.
*/


#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
   char data[100];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // again write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();

   // open a file in read mode.
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   // write the data at the screen.
   cout << data << endl;
   
   // again read the data from the file and display it.
   infile >> data; 
   cout << data << endl; 
  

   // close the opened file.
   infile.close();

   return 0;
}

/*
File Position Pointers

// position to the nth byte of fileObject (assumes ios::beg)
fileObject.seekg( n );

// position n bytes forward in fileObject
fileObject.seekg( n, ios::cur );

// position n bytes back from end of fileObject
fileObject.seekg( n, ios::end );

// position at end of fileObject
fileObject.seekg( 0, ios::end );
*/