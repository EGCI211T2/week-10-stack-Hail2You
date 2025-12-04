#include<iostream>
using namespace std;
#include<cstring>

#include "queue.h"

int main(int argc, char **argv){
   int i, j;
   int ID, qt, customer = 1, cost, money, payed;
   int ordernum = 1;
   string menu;
   Queue food;

   /*
   //the preview at the beginning
    for(i=1;i<argc;i++) 
    {            
      if(strcmp(argv[i],"x")==0) 
      {  
        ordernum++;
      }
    }
    
    for(i=1;i<ordernum;i++) 
      {
        //cout << "-----------------:" << ordernum;
        cout << "The menu number is: ";
        food.preview();
      }
*/
  

    //each order poping
    for(i=1;i<argc;i++) 
    {
       if(strcmp(argv[i],"x")==0) 
       {
       // pop the order (menu and quantity)
         if(!food.empty())
         {
          int order = food.front();
          food.dequeue();

            if (!food.empty())
            {
                int quantity = food.front();
                food.dequeue();
                     switch (order)
                      {
                      case 1:
                        menu = "Ramen";
                        cost = 100;

                        break;
                      case 2:
                        menu = "Somtum";
                        cost = 20;

                        break;
                      case 3:
                        menu = "Fried Chicken";
                        cost = 50;

                        break;

                      default:
                        menu = "No food, please try again";
                        break;
                    }
                cout << "Customer no: " << customer << endl;
                customer++;
                cout << menu << " qty " << quantity << endl;
                money = cost * quantity;
                cout << "You have to pay "<< money << endl;
                int change = -1;
                while (change < 0)
                {
                  cout << ":Cash:";
                  cin >> payed;
                  change = payed - money;
                  if (change < 0)
                  {
                    cout << "please try again." << endl;
                  }
                }
                cout << "Change is: " << change << endl << endl;
            }
         }
         else
         {
            cout << "Queue is empty, cannot be pop." << endl;
         }
        }
        else
      {
        //when the user is ordering
        if (i + 1 < argc)
        {
          ID = atoi(argv[i]);
          qt = atoi(argv[i+1]);

          food.enqueue(ID);
          food.enqueue(qt);

          i++; //skip the next argument since we already got the quantity
        }
        else
        {
          cout << "Missing quantity for the menu " << argv[i] << endl;
        }
      }
    }

    //print the rest of the order
    cout << endl << "Remaining orders:" << endl;

    while (!food.empty())
  {
    int order = food.front();
    food.dequeue();

     switch (order)
    {
    case 1:
      menu = "Ramen";

      break;
    case 2:
      menu = "Somtum";

      break;
    case 3:
      menu = "Fried Chicken";
      break;

    default:
      menu = "No food, please try again";
      break;
   }

    int quantity = 0;
    if (!food.empty())
    {
      quantity = food.front();
      food.dequeue();
    }
    cout << menu << " x " << quantity << endl;
  }
                  
   

   return 0;
}
