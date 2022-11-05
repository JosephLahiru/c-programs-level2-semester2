### Question 01:

## Consider a banking system that maintains customer’s account balance with two operations deposit (amount) and withdraw (amount). Assume that two people share a bank account and they can deposit and withdraw concurrently. 

## Create a multithreaded C Program to handle this scenario according to the following instructions. 

### Note: Balance of the account should be shared by both deposit and withdraw operations. 

## a)	Create a separate function to perform the deposit operation. The function should take the amount that is to be deposited as the input argument and update the account balance. Finally print the message, “You have deposited: <amount> “, to the screen. Prototype of the function is given below. 

`void *deposit(void *amount);`
	
## b)	Create another function to perform the withdraw operation. The function should take the amount that is to be withdrawn as the input argument and update the account balance if the amount is less than the current balance. Finally print the message, “You have withdrawn: <amount> “, to the screen. If the amount is larger than the current balance, print “No sufficient amount available to withdraw”. Prototype of the function is given below. 

`void *withdraw(void *amount);`

## c)	Display a menu as given below to allow the user to select the necessary operation. For implementation use switch-case. 

``` ---- Banking System ---- 
1. Deposit 
2. Withdraw 
3. Check Balance 
4. Exit 
---------------------------- 
Enter Option: 
---------------------------- 

```

### When user selects, 
-	Option 1: Take the deposit amount from the user keyboard. Create a new thread to invoke the deposit function. 
-	Option 2: Take the withdraw amount from the user keyboard. Create a new thread to invoke the withdraw function. 
-	Option 3: Display the current account balance. 
-	Option 4: Exit from the program. 

### Finally, 
-	Display an error message if there is any invalid option entered by the user. 

## d)	Synchronize the deposit and withdraw operations using semaphores to prevent data inconsistency (while one person is updating the balance, other one should not be able to update it). 
