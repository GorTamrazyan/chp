#include <iostream>
#include "LZ77.cpp"

using namespace std;

int 
main() 
{
    string text = "ABABABABABvvvvvAB";
    int bufferSize = 6;

    LZ77 lz77(bufferSize);
    cout << "Text: " << text << endl;

    lz77.compress(text);

    cout << "Tokens: " << endl;
    lz77.printTokens();

    string decompressed = lz77.decompress();
    cout << "Decompressed text: " << decompressed << endl;

    return 0;
}