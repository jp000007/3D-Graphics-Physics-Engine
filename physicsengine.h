//
//  main.cpp
//  HW4 pt2
//
//  Created by Jamie Parra on 6/18/21.
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


//Doubly Linked List, memory storage;
class NewNode
{
    private:
    Node* next;
    Node* prev;
    Node* head; //pointer to head
    Node* rear; //pointer to rear
    Node* new_Node;
    int data;
};

class Node
{
    private:
    //create Node poiners for next and previous Nodes and data insertion.
    Node* next;
    Node* prev;
    Node* head; //pointer to head
    Node* rear; //pointer to rear
    Node* new_Node;
    int data;
    
    public:
    void Insert_front(int data);
    void Insert_rear(int data);
    void Remove_front(int data);
    void Remove_rear(int data);
    void Size();
    void MakeEmpty();
    void display_data();

};
void Node::Insert_front(int data)
{
    Node* new_Node = new Node; //create new Node
    new_Node->data = data; //insert data, first data is from private struct Node, second is local variable
    new_Node->next = head; //Pass previous Node address from head to NEXT of new Node.
    new_Node->prev = NULL; //assign the front (previous) NULL. The list is always NULL moving left.
    //if head is not null (meaning NOT the first Node or list is not empty)
    if (head != NULL)
    {
        head->prev = new_Node; //then pass NEW head address to the previous Node
    }

    head = new_Node; //assign new Node address to head

    
}
void Node::Insert_rear(int data)
{
    Node* new_Node = new Node; //Create new Node
    new_Node->data = data; //Insert data, the newNode data is private, second is local variable.
    new_Node->next = NULL; //Assign next of new Node to NULL as it is at the rear with NULL always at the right.
    Node* rear = head; // assign rear of Node to head
    //if head is NULL the list is empty and make new Node the head
    if(head == NULL)
    {
        new_Node->prev = NULL;
        head = new_Node;
        return;
        
    }
    // traverse the list until next is NULL, once null then rear is at the rear most Node (right)
    while (rear->next != NULL)
        {
            rear = rear->next;
        }
    //assign NEXT of the last Node with new Node address (to its right)
    rear->next = new_Node;
    //assign PREV of new Node address to the previous Node (to its left)
    new_Node->prev = rear;
    return;

}


void Node::Remove_front(int data)
{
    //traverse until head is at front (far left of list)
    while (head->prev != NULL)
        {
            head = head->prev;
        }
    //temp copies location of first Node from head
    Node* temp = head;
    head = head->next;
    delete temp;
    head->prev = NULL;
}


void Node::Remove_rear(int data)
{
    Node* temp1 = head;
    Node* temp2 = head;

    //traverse until head is at rear (far right of list)
    while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
    //temp copies location of new last Node from temp1
    temp2 = temp1->prev;
    temp2->next = NULL;
    //move REAR to previous Node (on the left)
    delete temp1;
    //make the next of REAR NULL on the last Node (to the right)
    temp1 = NULL;

}

void Node::Size()
{
    //temp moves through all nodes from head to rear (right to left) adding to size for the total node count
    int size = 0;
    Node* temp = head;
    
    while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
    
    printf("There are %d Nodes in the list", size);


}

void Node::MakeEmpty()
{
    {
 
    //create temp to delete each Node (copied from head, from left to right)
    Node* temp = head;
 
    while (temp != NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    //reset head once all Nodes have been deleted
    head = NULL;
}
}
void Node::display_data()
{
    while (head->prev != NULL)
        {
            head = head->prev;
        }
    //temp copies location of first Node from head
    printf("The data in Nodes from beginning to end are:");
    Node* temp = head;
    int info;
    while (temp != NULL)
    {
        info = temp->data;
        printf(" %d", info);
        temp = temp->next;
    }
    
}




class test_case
{
    private:
    Node nd;

    public:
    test_case(int n): nd(){}

    void test_add_front(int n);
    void test_add_rear(int n);
    void test_remove_front(int n);
    void test_remove_rear(int n);

};  
//adds n number of nodes to the front
void test_case::test_add_front(int n)
{
    for (int x = 0; x < n; x++){
    nd.Insert_front(x);
}
nd.display_data();
}

//adds n number of nodes to the rear
void test_case::test_add_rear(int n)
{
    for (int x = 0; x < n; x++){
    nd.Insert_rear(x);
}
nd.display_data();
}
//removes n number of nodes from front
void test_case::test_remove_front(int n)
{
    for (int x = 0; x < n; x++){
    nd.Remove_front(x);
}
nd.display_data();
}
//removes n number of nodes from rear
void test_case::test_remove_rear(int n)
{
    for (int x = 0; x < n; x++){
    nd.Remove_rear(x);
}
nd.display_data();
}



class file
{
    private:
       //declaring variables
    char file_name_one[100];
    char file_name_two[100];
    char str[500];
    int Next_line_number = 0;

    public:
    void transfer_files();

};
    void file::transfer_files()
{
    //asking user for two file names and saving them to variables
    printf("Enter input filename: ");
    scanf("%s", file_name_one);
    printf("Enter output filename: ");
    scanf("%s", file_name_two);

    
    //create two files with the variable names recieved from user
    FILE *ki;
    ki = fopen(file_name_one, "r");
    FILE *ko;
    ko = fopen(file_name_two, "w");
    
    if (ko == NULL || ki == NULL)
        printf("Couldn't open the file.\n");
    else
        {
            //tranfer from input to output file and add number to each line
            while( !feof(ki))
        {
            fgets(str, 500, ki);
            printf("%s", str);
            fprintf(ko,"%d.  %s\n",Next_line_number++, str);
        }
    }
    //close both files
    fclose(ki);
    fclose(ko);
    printf("infile data transfered");
    
}



//this program creates a payment schedule for a loan of any length, interest, and loan amount. A class is created for the Loan data and variables and functions are made public to be able to change any lending algorithms. The first member function LoanData is used to input the loan terms amount, length, and interest, then derives the monthly payment. The second member function calculates the balance after a payment is made. The third member fucntion creates a balance sheet for 4 setrs of information for each payment until the loan is payed off. The fourth member function creates a timeline of payments until the loan is payed off depending on the payment amount.

//creating class to keep loan variables private and be used only in accordance with their class funtions.
class LoanData
{
   private:
      double   Bal;
      double    n;
      double    i;
      double    A;
       double    p;
    double x;
    double pay;
    double beginning_balance;
    double ending_balance;
    double Payment;
    double interest_paid;
    double principle_paid;
    
public:
               LoanData(double p, double n, double i);
      void    MakePayment(double pay);
      void    PrintAmortizationSchedule();
      void     PrintPayOffTimeReport(double p, double i);
};

//first member fuction assigning parameters to variables and payment algorithm.
LoanData::LoanData(double p, double n, double i)
{
    x = (i/100)/12;
    n = n*12;
    A = p*(x*(pow(1+x, n)/(pow(1+x, n)-1)));
    Bal = p;
}
//Second member functiopn using variables from first member functions to balance after a payment is made.
void LoanData::MakePayment(double pay)
{
    Bal = (1+x)*Bal - pay;
}
//Third member function to create a chart for balance before and after payment, payment, interest for each billing cycle until the balanmce is 0.
void LoanData::PrintAmortizationSchedule()
{
    printf("Beggining Bal     Interest Paid     Principle Paid     Ending Bal\n");
    beginning_balance = Bal;
    while (beginning_balance > 0)
    {
        if (((x+1)*beginning_balance) > A)
        {
            Payment = A;
        }
    else
    {
        Payment = (x+1)*beginning_balance;
    }
    interest_paid = x*beginning_balance;
    principle_paid = A - interest_paid;
    ending_balance = ((x+1)*beginning_balance) - A;
    printf("%.2lf           %.2lf           %.2lf           %.2lf\n",beginning_balance ,interest_paid ,principle_paid ,ending_balance);
    beginning_balance = ending_balance;
    }
}

//Fourth member function to determine the months required to pay off loan with desired payment ammount.
void LoanData::PrintPayOffTimeReport(double p, double i)
{
    for(n=6; n<360; n++)
    {
        A = p*(i*(pow(1+i, n)/(pow(1+i, n)-1)));
        printf("%.0f   %.2f\n",n ,A );
    }
}


