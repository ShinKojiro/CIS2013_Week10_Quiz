#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){

    char next;
    string sentence;
    string oSentence;
    int bCount = 0;
    ifstream inSentence;
    ofstream outSentence;

    inSentence.open("SentenceInput.txt");
    if (inSentence.fail()){
        cout << "Input file opening failed.\n";
        exit(1);
    }

    outSentence.open("SentenceOutput.txt");
    if (outSentence.fail()){
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    cout << "Type a sentence, and be sure to include lots of \"b\"'s " << endl;
    cin >> sentence;
    inSentence >> sentence;
    

    while(!inSentence.eof()){
        inSentence.get(next);
        outSentence.put(next);
        if(next == 'b' && bCount / 2 == 0){
            bCount++;
            outSentence << "SIT";   
        } else if(next == 'b' && bCount / 1 == 0){
            bCount++;
            outSentence << "STAND";   
        } 
    }

    outSentence << oSentence;
    cout << oSentence;

    inSentence.close();
    outSentence.close();
}