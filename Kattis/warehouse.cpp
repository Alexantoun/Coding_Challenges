#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct shipment
{
    int amount;
    string product;
};

int sameCheck(shipment*, int);
void order(shipment*, int);
void alphaOrder (shipment*, int, int, int);

int main()
{
    int numCases, numShipments;
    cin>>numCases;
    for (int j=0;j<numCases;j++)
    {
        cin>>numShipments;
        shipment *delivery;
        delivery = new shipment[numShipments];
        for (int i=0;i<numShipments;i++)
        {
            cin>>delivery[i].product;
            cin>>delivery[i].amount;
        }

        int numItems = sameCheck (delivery, numShipments);
        order (delivery, numShipments);
        cout<<numItems<<endl;
        for(int i=0;i<numShipments;i++)
        {
            if (delivery[i].amount != 0)
                cout<<delivery[i].product<<" "<<delivery[i].amount<<endl;
        }
    }

    return 0;
}

int sameCheck(shipment *delivery, int numShipments)
{
    int item=0;
    for (int i=0;i<numShipments;i++)
    {
        for (int j=i+1;j<numShipments;j++)
        {
            if (delivery[i].product==delivery[j].product)
            {
                delivery[i].amount+=delivery[j].amount;
                delivery[j].amount=0;
            }
        }
    }
    for (int i=0;i<numShipments;i++)
    {
        if (delivery[i].amount != 0)
            item++;
    }
    return item;
}
void alphaOrder (shipment* delivery, int pos1, int pos2, int numShipments)
{
    int i=0, sent=1;
    shipment temp;
    while (sent!=0)
    {
        if (delivery[pos1].product[i]==delivery[pos2].product[i])
            i++;
        else if(delivery[pos1].product[i]>delivery[pos2].product[i])
        {
            temp=delivery[pos2];
            delivery[pos2]=delivery[pos1];
            delivery[pos1]=temp;
            sent =0;
        }
        else
            break;
    }
    return;
}
void order(shipment *delivery, int numShipments)
{
    shipment temp;
    //order by #
    for (int i=0;i<numShipments;i++)
    {
        for (int j=i+1;j<numShipments;j++)
        {
            if (delivery[j].amount > delivery[i].amount)
            {
                temp=delivery[i];
                delivery[i]=delivery[j];
                delivery[j]=temp;
            }
            else if (delivery[j].amount == delivery[i].amount && delivery[j].amount !=0)
            {
                int position1=i, position2=j;
                alphaOrder(delivery, position1, position2, numShipments);
            }
        }
    }
    return;
}
