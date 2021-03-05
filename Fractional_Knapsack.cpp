#include <bits/stdc++.h>
#include <time.h>
using namespace std;

struct item
{
    int value, weight;
};

bool cmp(struct item a, struct item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct item arr[], int n)
{

    sort(arr, arr + n, cmp);

    cout <<"Value  Weight  : Fraction"<< endl;
    for (int i = 0; i < n; i++)
    {
    	cout << arr[i].value <<" "<< arr[i].weight<<" : "<< ((double)arr[i].value/arr[i].weight) << endl;
    }


    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {

        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value*((double)remain/(double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main()
{
    srand((int)time(0));
    int W,n;

    cout << "Enter Total Number of Items: ";
    cin>> n;
    cout << "Enter Max Capacity: ";
    cin>> W;

    item arr[n];

    for(int i = 0 ; i < n; i++)
        arr[i]={rand()%((W*10)-100) +100, rand()%(W)};
    for(int i = 0 ; i < n; i++)
        cout<<arr[i].value<<" "<<arr[i].weight<<endl;
    double ans = fractionalKnapsack(W, arr, n);
    cout << "\nMaximum value we can obtain = " << ans <<endl;
    return 0;
}
