
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #include <ctype.h>
    
    /*Now, we are going to make a simple basic project like a ATM_Machine,
     in this project we are providing service like a atm machine, here user
     create their account and they select a 4 no pin to get access
     their account, in this project user can deposite and withdraw their
     amount and transfer their amount to another account and users edit
     their account info and many more like tha ATM machine.
    */
    
    #define Account_Capacity 10 // Marco name defines that how many persons can create account, it can be changed.
    
    // Account Information structure.
    typedef struct Account_Information
    {
        char name[50];
        int age;
        char gender;
        double cnic;
        char contact[11];
        double accNo;
        int pin;
    } AccInfo; // Alias name.
    
    // Account Deposite Structure.
    typedef struct AccountDeposite
    {
        double accNo;
        int pin;
        float amount;
    } AccDepo; // Alias name.
    
    // This function gets information for creating account.
    void CreateAccount(AccInfo *person)
    {
        printf("\n\t Enter Your Information.");
    
        printf("\n Enter Your Name(Without using space): ");
        scanf("%s", person->name);
    
        printf(" Enter Age: ");
        scanf("%d", &person->age);
    
        printf(" Enter Gender (M or F): ");
        scanf(" %c", &person->gender);
    
        printf(" Enter Your CNIC (enter only numbers): ");
        scanf("%lf", &person->accNo);
    
        printf(" Enter Your Contact No (don't use space): ");
        scanf("%s", person->contact);
    
        printf(" Enter Your Account No (only 8 digits): ");
        scanf("%lf", &person->accNo);
    
        printf(" Select 4 digits PIN (Pin must be unique) ");
        scanf("%d", &person->pin);
    }
    
    //  This function desposites amount to the user account.
    void Deposite(AccDepo account[], AccInfo person[])
    {
        double account_No;
    
        printf("\n Enter Account Number (only 8 digits): ");
        scanf("%lf", &account_No);
    
        for (int i = 0; i < Account_Capacity; i++)
        {
            if (account_No == person[i].accNo)
            {
                account[i].accNo = account_No;
    
                account[i].pin = person[i].pin;
    
                printf("\n Enter Amount to Deposite: ");
                scanf("%f", &account[i].amount);
    
                return;
            }
        }
    
        printf("\n\t>>>>Warning>>>>");
        printf("\n>>>>*Account Does not exist in our data base (first you have to create an account then you can deposit Amount)*<<<<");
    }
    
    //  This function withdraw amount from the user account.
    void withdraw(AccInfo person[], AccDepo account[])
    {
        double account_No;
    
        printf("\n Enter Account Number (only 8 digits): ");
        scanf("%lf", &account_No);
    
        for (int i = 0; i < Account_Capacity; i++)
        {
            if (account_No == person[i].accNo)
            {
                if (account_No == account[i].accNo)
                {
                    int pin;
    
                    for (int j = 0; j < 4; j++)     // User have only 4 times to enter pin, if pin not correct till 4 times, so shut down the ATM.
                    {
                        printf("\n Enter Your 4 digits pin: "); // Check Pin.
                        scanf("%d", &pin);
    
                        if (pin == account[i].pin)
                        {
                            if (account[i].amount >= 100)
                            {
                                float wid = 0.00;
    
                                printf("\n Enter Amount that you want to Withdraw: ");
                                scanf("%f", &wid);
    
                                while (1)
                                {
                                    if (account[i].amount > wid)
                                    {
                                        account[i].amount = (account[i].amount - wid);
    
                                        printf("\n You have received Rs (%.2f) withdraw. ", wid);
                                        printf("\n Your Account No: %.0lf", account[i].accNo);
                                        printf("\n Your Remaining amount is: %.2f.", account[i].amount);
    
                                        return;
                                    }
    
                                    else
                                    {
                                        printf("\n *withdraw ammount must be less than deposite so again Input*: ");
                                        scanf("%f", &wid);
                                    }
                                }
                            }
                            else
                            {
                                printf("\n >>>>*Dear Customer Your Deposite Amount is less than 100, you are not eligible to withdraw<<<<*");
                                return;
                            }
                        }
                        else
                        {
                            printf("\n Wrong PIN (only %d times are left). ", (4 - (i + 1)));
                        }
                    }
                    printf("\n *******Shut Down:******");
                    return;
                }
            }
        }
        printf("\n >>>>*Dear customer your account number does not deposited*<<<<.");
    }
    
    // Transfer function.
    void TransferMoney(AccInfo person[], AccDepo account[])
    {
        double account_No;
    
        printf("\n Enter Account No (only 8 integers): ");
        scanf("%lf", &account_No);
    
        for (int i = 0; i < Account_Capacity; i++)
        {
            if (account_No == person[i].accNo) // If Account Created
            {
                if (account_No == account[i].accNo) // If Account Deposited
                {
                    int pin;
    
                    for (int j = 0; j < 4; j++)     // User have only 4 times to enter pin, if pin not correct till 4 times, so shut down the ATM.
                    {
                        printf("\n Enter your Account (4 digits) Pin: ");
                        scanf("%d", &pin);
    
                        if (pin == account[i].pin)
                        {
                            if(account[i].amount >= 100)
                            {
                                float amount = 0.00;
    
                                printf("\n Enter amount that you want to transfer to the other account: ");
                                scanf("%f", &amount);
    
                                while (1)
                                {
                                    if(account[i].amount > amount)
                                    {
                                        double account_No2;
    
                                        printf("\n Enter account number that recieve the amount (only 8 integers): ");
                                        scanf("%lf", &account_No2);
    
                                        for(int k = 0; k < Account_Capacity; k++)
                                        {
                                            if(person[k].accNo == account_No2)
                                            {
                                                account[i].amount = (account[i].amount- amount);
                                                account[k].amount = amount;
    
                                                printf("\n You have transfered Rs.%.2lf");
                                                printf("\n your account no: %.0lf", account_No);
                                                printf("\n your remaining amount is Rs.%.2f", account[i].amount);
                                                printf("\n this account no (%.0lf) recieved amount Rs.%.2f", account_No2, account[k].amount);
    
                                                return;
    
                                            }
                                        }
                                    }
                                    else
                                    {
                                        printf("\n *Transfer ammount must be less than deposite so again Input*: ");
                                        scanf("%f", &amount);
                                    }
                                }
    
                            }
                            else
                            {
                                printf("\n >>>>*Dear Customer Your Deposite Amount is less than 100, you are not eligible to transfer*<<<<");
                                return;
                            }
    
                        }
                        else
                        {
                            printf("\n Wrong Pin (only (%d) times are left).", (4 - (j + 1)));
                        }
                    }
                    printf("\n *******Shut Down:******");
                    return;
                }
            }
        }
    }
    
    int main()
    {
        // Using Dynamic Array.
        // Person Array that stores persons account information.
        AccInfo *person;
        person = (AccInfo *)calloc(Account_Capacity, sizeof(AccInfo));
    
        // Using Dynamic Array.
        // account Array that stores deposite record.
        AccDepo *account;
        account = (AccDepo *)calloc(Account_Capacity, sizeof(AccDepo));
    
        int element = 0; // this variable switches the account.
    
        while (1)
        {
            printf("\n\n\t\t >>>>> Welcome to the ATM Service >>>>>");
            printf("\n**********************");
            printf("\n\t\t 1.Create Account.\n\t\t 2.Deposite Amount.\n\t\t 3.Withdraw Amount.\n\t\t 4.Transfer Money.\n\t\t 5.Exit ATM Services.\n");
    
            int no;
    
            printf("\n Enter which service do you want: (1, 2, 3, 4, 5): ");
            scanf("%d", &no);
    
            switch (no)
            {
            case 1:
                printf("\t Welcome to the Create Account Portal.\n");
                CreateAccount(&person[element]);
                element++;
                break;
    
            case 2:
                printf("\n\t Welcome to the Deposite Portal.\n");
                Deposite(account, person);
                break;
    
            case 3:
                printf("\n\t Welcome to the Withdraw Portal.\n");
                withdraw(person, account);
                break;
    
            case 4:
                printf("\n\t Welcome to the Transfer Mobey Portal.\n");
                TransferMoney(person, account);
                break;
                
            case 5:
                printf("\nt>>>>>>>>> Exist Atm Service >>>>>>>>>");
                printf("\n***********************************");
                exit(0);
    
            default:
                printf("\n\t invalid input.");
                printf("\n**********************");
                break;
            }
        }
    
        free(person);
        free(account);
        return 0;
    }