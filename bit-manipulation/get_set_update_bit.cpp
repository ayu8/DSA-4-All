#include <iostream>
using namespace std;
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}

int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}
int main()
{
    int n, pos, value;
    cout << "Enter value of nummber : ";
    cin >> n;
    //  cout<<"Enter position at that place want to get bit : ";
    //  cin>>pos;
    //  cout<<"In "<<n<<", bit at "<<pos<<" position is : ";
    //  cout<<getBit(n,pos);

    //  cout<<"Enter position at that place want to set bit : ";
    //  cin>>pos;
    //  cout<<"In "<<n<<", After setting bit at "<<pos<<" position, number become : ";
    //  cout<<setBit(n,pos);

    //  cout<<"Enter position at that place want to clear bit : ";
    //  cin>>pos;
    //  cout<<"In "<<n<<", After clearing bit at "<<pos<<" position, number become : ";
    //  cout<<clearBit(n,pos);

    cout << "Enter position at that place want to update bit : ";
    cin >> pos;
    cout << "Enter bit that want to update with previous bit : ";
    cin >> value;
    cout << "In " << n << ", After updating bit at " << pos << " position, with bit " << value << " number become : ";
    cout << updateBit(n, pos, value);

    return 0;
}
