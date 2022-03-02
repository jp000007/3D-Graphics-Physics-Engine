#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>
#include "physicsengine.h"
using namespace std;




int main(int argc, const char * argv[]) {
    LoanData lory(100000, 30, 6);
    lory.MakePayment(650);
    lory.PrintAmortizationSchedule();
    lory.PrintPayOffTimeReport(100000, 0.005);
    

    transfer_files();

    test_case case_one(0);

    case_one.test_add_front(5);
    case_one.test_add_rear(5);
    case_one.test_remove_front(2);
    case_one.test_remove_rear(3);

           BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
 
    b.Inorder(root);
    return 0;
};

     
