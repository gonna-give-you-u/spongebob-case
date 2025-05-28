#include <iostream>
#include <vector>

using namespace std;

int main(){
    //give me ideasr (really)
    string stuff;
    string theMode;
    int modeNo;
    cout << "random (r) or alternating (a)? ";
    getline(cin,theMode);
    if (theMode == "r" || theMode == "random"){
        modeNo=0;
    } else if (theMode == "a" || theMode == "alternating"){
        modeNo=1;
    } else{
        cout << "thats not an option\n";
        exit(1);
    }
    cout << "put your text here: ";
    getline(cin,stuff);
    char stuffArray[stuff.length()+1];
    auto daFirst = stuff.begin();
    auto daLast = stuff.end();
    copy(daFirst, daLast, stuffArray);
    stuffArray[stuff.length()]='\0';
    vector<char> outStuff;
    char newChar;
    srand(time(NULL));//random generators are weird

    if (modeNo == 0){
        for (int i=0;i<stuff.length();i++){
            if (rand()%2 == 0){
                newChar = toupper(stuffArray[i]);
            } else {
                newChar = tolower(stuffArray[i]);
            }
            outStuff.push_back(newChar);
        }
    } else if (modeNo == 1){//non-letters are not skipped and i cant be asked to fix that atm
        for (int i=0;i<stuff.length();i++){
            if (i%2==0){
                newChar = toupper(stuffArray[i]);
            } else{
                newChar = tolower(stuffArray[i]);
            }
            outStuff.push_back(newChar);
        }
    } else{
        cout << "idk something went wrong (modeNo isn't 0 or 1)";
    }

    for (int i=0;i<outStuff.size();i++){
        cout << outStuff[i];
    }
    cout << '\n';

    return 0;
}