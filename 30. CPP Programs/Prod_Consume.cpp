#include <bits/stdc++.h>
using namespace std;
//Producer generates and puts the data into the buffer.
//Consumer consumes the data.
//Initialise the mutual exclusion to 1
int mutual_exclusion = 1;
//Initialise Number of Full Slots as 0
int full = 0;
//Number of empty slots is the size of the buffer
int empty;
//Mutual Exclusion, Full and Empty are semaphores
//Initialise the Current Item in the Buffer
int current_item = 0;
//Decrease by 1
int wait(int);
//Increase by 1
int signal(int);
//Function to Produce an item and it to the buffer
void producer();
//Function to Consume an item and remove it from the buffer
void consumer();
int main()
{
//Current Choice
int current_choice;
cout << "Enter the size of the buffer: ";
cin >> empty;
while (1)
{
cout << "\n-----Menu-----" << endl;
cout << "1. Producer" << endl;
cout << "2. Consumer" << endl;
cout << "3. Exit" << endl;
cout << "\nEnter your choice: ";
cin >> current_choice;
switch (current_choice)
{
case 1:
if ((mutual_exclusion == 1) && (empty != 0))
producer();
else
cout << "\nBuffer is full!" << endl;
break;
case 2:
if ((mutual_exclusion == 1) && (full != 0))
consumer();
else
cout << "\nBuffer is empty!" << endl;
break;
case 3:
exit(0);
break;
}
}
return 0;
}
//Decrease by 1
int wait(int slot)
{
return (--slot);
}
//Increase by 1
int signal(int slot)
{
return (++slot);
}
//Function to Produce an item and it to the buffer
void producer()
{
//Consumer Processes shouldn't interfere
mutual_exclusion = wait(mutual_exclusion);
//Empty Space in the Buffer Decreases by 1
empty = wait(empty);
//Put the Item in the Buffer
current_item++;
cout << "\nProducer produces the item " << current_item << endl;
//Consumer Process can act now
mutual_exclusion = signal(mutual_exclusion);
//Buffer is full by 1 unit
full = signal(full);
}
//Function to Consume an item and remove it from the buffer
void consumer()
{
//Producer Process cannot interfere
mutual_exclusion = wait(mutual_exclusion);
//Empty Space in the Buffer Increases by 1
full = wait(full);
//Remove the item from the buffer
cout << "\nConsumer consumes item " << current_item << endl;
current_item--;
//Producer Process can now act
mutual_exclusion = signal(mutual_exclusion);
//Buffer is empty by 1 unit
empty = signal(empty);
}