#include<iostream>
#include<cstring>

using namespace std;

struct Candy
{
    char Name[50];
    int price;
};


void Highest_Price_Candy(struct Candy* obj, int N)
{
    int maxi = INT_MIN;
    int Max_Price_Candy_Index = 0;
    for(int i = 0; i < N; i++)
    {
        if(obj[i].price >= maxi)
        {
            maxi = obj[i].price;
            Max_Price_Candy_Index = i;
        }
    }

    cout<<"Candies with highest prices: \n";
    for(int i = 0; i < N; i++)
    {
        if(maxi == obj[i].price)
        {
            cout<<obj[i].Name<<"--"<<obj[i].price;
        }
    }
}

void Lowest_Price_Candy(struct Candy* obj, int N)
{
    int mini = INT_MAX;
    int Min_Price_Candy_Index = 0;
    for(int i = 0; i < N; i++)
    {
        if(obj[i].price <= mini)
        {
            mini = obj[i].price;
            Min_Price_Candy_Index = i;
        }
    }

    cout<<"Candies with lowest prices: \n";
    for(int i = 0; i < N; i++)
    {
        if(mini == obj[i].price)
        {
            cout<<obj[i].Name<<"--"<<obj[i].price;
        }
    }
}

void Average_Price(struct Candy* obj, int N)
{
    double avg_price = 0.0f;

    for(int i = 0; i < N; i++)
    {
        avg_price += obj[i].price;
    }

    avg_price = avg_price / N;

    cout<<"Average Price = "<<avg_price;
}

void Price_Collision(struct Candy* obj, int N)
{
    bool found = false;

    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(obj[i].price == obj[j].price && (strcmp(obj[i].Name,obj[j].Name) != 0))
            {
                if(found != true)
                {
                    cout<<"Collision Found\n";
                    found = true;
                }

                cout<<obj[i].Name <<" and "<<obj[j].Name<<"---"<<obj[i].price<<" and "<<obj[j].price;
            }
        }
    }

    if(found == false)
    {
        printf("No collisions found\n");
    }
}

void Duplicate_Names(struct Candy* obj, int N)
{
    for(int i = 0; i < N; i++)
    {
        bool duplicate = false;
        for(int j = 0; j < i; j++)
        {
            if(strcmp(obj[i].Name,obj[j].Name) == 0)
            {
                duplicate = true;
                break;
            }
        }
        if(duplicate == false)
        {
            cout<<obj[i].Name<<endl;
        }
    }
}
int main(void)
{
    int N;
    printf("Enter the number of candies: ");
    scanf("%d",&N);

    struct Candy* obj = new Candy[N];

    for(int i = 0; i < N; i++)
    {
        cout<<"\nEnter Candy "<<i+1 <<" Name: ";
        fgets(obj[i].Name, 50, stdin);
        
        cout<<"\nEnter price: ";
        cin>>obj[i].price;
    }

    // Display

    for(int i = 0; i < N; i++)
    {
        cout<<obj[i].Name<<"--"<<obj[i].price<<endl;
    }

    Highest_Price_Candy(obj,N);
    cout<<endl;

    Lowest_Price_Candy(obj,N);
    cout<<endl;

    Average_Price(obj,N);
    cout<<endl;

    Price_Collision(obj,N);
    cout<<endl;

    Duplicate_Names(obj,N);
    delete[] obj;

    return 0;
}