#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    long int H{0},x{0};  //H is for storing the bits of the string
    for(auto val : s){
        x = 1;
        x = x<<(val-97);  //left shift all bits of x by the position of char(like a=1, b= 2 ... y=25, z=26)
        if(x&H > 0){  //MASKING technique, if it comes 1, it means there is already 1 in H at that position
            cout << val << " has duplicates" << endl;
        }
        else{
            H = x|H;  //MERGING technique, it is not 1, so make it 1
        }
    }
    return 0;
}