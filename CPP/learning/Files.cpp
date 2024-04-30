#include <iostream>
#include <fstream>
using namespace std;

/*
    ofstream	Creates and writes to files
    ifstream	Reads from files
    fstream	    A combination of ofstream and ifstream: creates, reads, and writes to files
*/

int main() 
{
    string txt;
    // Create and open
    ofstream file("filename.txt");

    //write
    file << "Write to the file";

    //close
    file.close();

    //read
    ifstream read_file("filename.txt");


    // Use a while loop together with the getline() function to read the file line by line
    while (getline (read_file, txt)) 
    {
        cout << txt;
    }

    read_file.close();
}