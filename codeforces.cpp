/*Write a program to demonstrate bit-stuffing technique. Assume the flag pattern is 111110. Your
program should stuff bits accordingly and de-stuff the stuffed bit string. The system will identify
the position(s) of bit-stuffing, stuff bit(s) autonomously. User will input data and flag only. The
program will de-stuff the bit(s) when user instruct to the program. */

#include <bits/stdc++.h>
using namespace std;
int main()
{

    string data , stuff , dstuff;
    cout<<"Enter data = ";
    cin>>data;
    string flag = "111110";

    int n = data.size();
    int cnt = 0;
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(data[i] == '1')
        {
            cnt++;
        }
        else
        {
            cnt=0;
        }
        stuff.push_back(data[i]);
        j++;
        if(cnt == 5 and data[i+1] == '1')
        {
            stuff.push_back('0');
            j++;
            cnt=0;
        }
    }

    cout<<"Stuffed data is = "<<flag<<" "<<stuff<<" "<<flag<<endl;


    // doing destuffing
    int m = stuff.size();
    cnt=0;
    for(int i=0; i<m; i++)
    {
        if(stuff[i] == '1')
        {
            cnt++;
        }
        else
        {
            cnt=0;
        }
        dstuff.push_back(stuff[i]);
        if(cnt == 5 and stuff[i+1] == '0')
        {
            i++;
            cnt=0;
        }
    }
    cout<<"Destuffed data is = "<<flag<<" "<<dstuff<<" "<<flag<<endl;

}