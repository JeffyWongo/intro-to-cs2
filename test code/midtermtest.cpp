#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int numberOfSentences(ifstream &in)
{
    char mark;
    int sentences = 0;
    while(in >> mark){
        if(mark =='.' || mark == '?' || mark == '!')
        {
            sentences++;
        }
    }
    in.close();
    return sentences;
}

int main() 
{
    ifstream fin("file1.txt");
    cout << numberOfSentences(fin);
    return 0;
}
