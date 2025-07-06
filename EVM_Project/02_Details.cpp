#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int check_DOB(int d, int m, int y)
{
    if (m == 2 && y % 4 == 0 && d > 0 && d <= 29 && y <= (2024 - 18) && y >= (2024 - 100))
    {
        return 1;
    }
    else if (m == 2 && y % 4 != 0 && d > 0 && d <= 28 && y <= (2024 - 18) && y >= (2024 - 100))
    {
        return 1;
    }
    else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 0 && d <= 31 && y <= (2024 - 18) && y >= (2024 - 100)))
    {
        return 1;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 0 && d <= 30 && y <= (2024 - 18) && y >= (2024 - 100)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Voter
{
private:
    char Name[50], City[50], State[50], VID[10];
    long long int Aadhar;
    int Day, Month, Year, Vote;
public:
    int count[9] = {0}, total = 0;
    void vote_entry();
    void display();
};

void Voter ::vote_entry()
{
    FILE *ftr = fopen("Voter_Details.csv", "a+");
    if (!ftr)
    {
        cout << endl << "Error!";
        exit(1);
    }
    // Input Data Statements.
    fflush(stdin);
    cout << endl << "Enter the Name: ";
    cin.getline(Name, 50);
    fprintf(ftr, "%s,", Name);
    //********************************************
    int j;
    do
    {
        fflush(stdin);
        cout << "Enter your Aadhar number: ";
        cin >> Aadhar;
        j = 0;
        for (long long int i = Aadhar; i != 0; i /= 10)
        {
            j++;
        }
        if (j != 12)
        {
            cout << "Invalid Adhaar No.!" << endl;
        }
    } while (j != 12);
    fprintf(ftr, "\t%lld,", Aadhar);
    //********************************************
    do
    {
        cout << "Enter your Day of Birth = ";
        cin >> Day;
        cout << "Enter your Month of Birth = ";
        cin >> Month;
        cout << "Enter your Year of Birth = ";
        cin >> Year;
        if(check_DOB(Day, Month, Year) != 1)
        {
            cout << "Invalid Date of Birth!" << endl;
        }
    } while(check_DOB(Day, Month, Year) != 1);
    fprintf(ftr, "\t%d-%d-%d,", Day, Month, Year);
    //********************************************
    fflush(stdin);
    cout << "Enter your City = ";
    cin.getline(City, 50);
    fprintf(ftr, "\t%s,", City);
    //********************************************
    fflush(stdin);
    cout << "Enter your State = ";
    cin.getline(State, 50);
    fprintf(ftr, "\t%s,", State);
    //********************************************
    do
    {
        fflush(stdin);
        cout << "Enter your Voter ID = ";
        cin >> VID;
        if (strlen(VID) != 10)
        {
            cout << "Invalid Voter Id!\n";
            cout << "Voter Id must Contain only 1st 7 digits with last 3 characters.\n";
        }
    } while (strlen(VID) != 10);
    fprintf(ftr, "\t%s,", VID);
    //********************************************
    cout << endl;
    cout << "Press [1] to Vote Bhatiya Janta Party." << endl;
    cout << "Press [2] to Vote Indian National Congress." << endl;
    cout << "Press [3] to Vote Aam Admi Party." << endl;
    cout << "Press [4] to Vote Bahujan Samaj Party." << endl;
    cout << "Press [5] to Vote Rashtriya Janta Dal." << endl;
    cout << "Press [6] to Vote Nationalist Congress Party." << endl;
    cout << "Press [7] to Vote Shiv Sena." << endl;
    cout << "Press [8] to Vote Samajwadi Party." << endl;
    cout << "Press [9] to Vote None Of The Above." << endl;
    //********************************************
    do
    {
        cout << endl << "Dear, " << Name << " please enter your Vote: ";
        cin >> Vote;
        switch (Vote)
        {
            case 1: count[0]++; fprintf(ftr, "\t%s\n", "BJP"); break;  // Bhatiya Janta Party.
            case 2: count[1]++; fprintf(ftr, "\t%s\n", "INC"); break;  // Indian National Congress.
            case 3: count[2]++; fprintf(ftr, "\t%s\n", "AAP"); break;  // Aam Admi Party.
            case 4: count[3]++; fprintf(ftr, "\t%s\n", "BSP"); break;  // Bahujan Samaj Party.
            case 5: count[4]++; fprintf(ftr, "\t%s\n", "RJD"); break;  // Rashtriya Janta Dal.
            case 6: count[5]++; fprintf(ftr, "\t%s\n", "NCP"); break;  // Nationalist Congress Party.
            case 7: count[6]++; fprintf(ftr, "\t%s\n", "SS"); break;   // Shiv Sena.
            case 8: count[7]++; fprintf(ftr, "\t%s\n", "SP"); break;   // Samajwadi Party.
            case 9: count[8]++; fprintf(ftr, "\t%s\n", "NOTA"); break; // None Of The Above.
            default: cout << "Enter 1 to 9 please !!" << endl;
        }
    } while ((Vote != 1) && (Vote != 2) && (Vote != 3) && (Vote != 4) && (Vote != 5) && (Vote != 6) && (Vote != 7) && (Vote != 8) && (Vote != 9));
    fclose(ftr);
}

void Voter ::display()
{
    int i;
    // Displaying Fair votes and the Ruling Party.
    cout << endl << "Votes : " << endl;
    cout << "Bhatiya Janta Party        : " << count[0] << endl;
    cout << "Indian National Congress   : " << count[1] << endl;
    cout << "Aam Admi Party             : " << count[2] << endl;
    cout << "Bahujan Samaj Party        : " << count[3] << endl;
    cout << "Rashtriya Janta Dal        : " << count[4] << endl;
    cout << "Nationalist Congress Party : " << count[5] << endl;
    cout << "Shiv Sena                  : " << count[6] << endl;
    cout << "Samajwadi Party            : " << count[7] << endl;
    cout << "None Of The Above          : " << count[8] << endl;
    // finds the Party which has maximumm Votes.
    int max = count[0];
    for (i = 0; i < 9; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
        total = total + count[1];
    }
    if (max == count[0])
    {
        cout << endl << "The maximum votes is of Bhatiya Janta Party with " << max << " votes" << endl << endl;
    }
    else if (max == count[1])
    {
        cout << endl << "The maximum votes is of Indian National Congress with " << max << " votes" << endl << endl;
    }
    else if (max == count[2])
    {
        cout << endl << "The maximum votes is of Aam Admi Party with " << max << " votes" << endl << endl;
    }
    else if (max == count[3])
    {
        cout << endl << "The maximum votes is of Bahujan Samaj Party with " << max << " votes" << endl << endl;
    }
    else if (max == count[4])
    {
        cout << endl << "The maximum votes is of Rashtriya Janta Dal with " << max << " votes" << endl << endl;
    }
    else if (max == count[5])
    {
        cout << endl << "The maximum votes is of Nationalist Congress Party with " << max << " votes" << endl << endl;
    }
    else if (max == count[6])
    {
        cout << endl << "The maximum votes is of Shiv Sena with " << max << " votes" << endl << endl;
    }
    else if (max == count[7])
    {
        cout << endl << "The maximum votes is of Samajwadi Party with " << max << " votes" << endl << endl;
    }
    else if (max == count[8])
    {
        cout << endl << "None of the Party has won the Election" << endl << endl;
    }
}

int main()
{
    int choice = 0;
    Voter Votee;
    do
    {
        cout << endl;
        cout << "Enter 1: ";
        cin >> choice;
        switch (choice)
        {
            case 1: Votee.vote_entry(); break;
            case 41: Votee.display(); break;
            case 22: exit(0);
            default: cout << "Plz enter 1 only!" << endl;
        }
    } while (choice != 22);
    return 0;
}
