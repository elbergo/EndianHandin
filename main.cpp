#include <iostream>
#include <bitset>
#include "fstream"
#include "string"

using namespace std;

int main () {
    string line;
    ifstream inputFile ("../bigEndianInputs.txt");
    ofstream endianOutputFile ("../littleEndianOutputs.txt");
    ofstream midByteOutputFile ("../midByteOutputs.txt");
    if (inputFile.is_open() && endianOutputFile.is_open())
    {
        while ( getline (inputFile,line) ) {
            unsigned short bigEndianValue = stoul(line);
            unsigned char byteLeft = (bigEndianValue>>8);
            unsigned char byteRight = (bigEndianValue & 255);
            unsigned short  littleEndianValue = (byteRight<<8 | byteLeft);
            unsigned char midByteValue = ((littleEndianValue>>4) & 255);
            bitset<16> bev(bigEndianValue);
            bitset<16> lev(littleEndianValue);
            bitset<8> mbv(midByteValue);
            cout << "----------------" << endl;
            cout << "Big Endian Value:\t\t" << line << endl;
            cout << "Big Endian Binary Value:\t" << bev << endl;
            cout << "Little Endian Binary Value:\t" << lev << endl;
            cout << "Little Endian Value:\t\t" << littleEndianValue << endl;
            cout << "Middle Byte Binary Value:\t" << mbv << endl;
            cout << "Middle Byte Value:\t\t"<< (int) midByteValue << endl;
            endianOutputFile << (byteRight << 8 | byteLeft) << endl;
            midByteOutputFile << ((int) midByteValue) << endl;


        }
        inputFile.close();
        endianOutputFile.close();
    }

    else cout << "Unable to open file";

    return 0;
}