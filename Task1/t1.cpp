#include "../HeaderFile/file.h"
#include <cstdlib>
#define LIMIT 100
void ranDom(int num)
{
    int u;
    cout << "Guess the number between  0 and "<<LIMIT<<" : ";
    cin >> u;
    if (u == num)
    {
        cout << "Bravo You Guessed Correct!!" << endl;
        return;
    }
    if (u > num)
    {
        cout << "Guess is to HIGH!!" << endl;
    }
    else if (u < num)
    {
        cout << "Your Guess is TO LOW!!" << endl;
    }
    
    cout<<string(40,'-')<<endl;
    ranDom(num);
}
int main()
{
    // First The user has to get the Number in range (0,LIMIT)
    // cout<<LIMIT" ";
    srand(time(0)); //This Varies the seed input to random as time varies continuously
    int num = rand() % LIMIT;
    
    ranDom(num);
    return 0;
}