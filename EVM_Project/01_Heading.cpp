#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    FILE *ftr;
    ftr = fopen("Voter_Details.csv", "a+");
    if (ftr == NULL)
    {
        cout << endl << "Error!";
        exit(1);
    }
    else
    {
        cout << endl << "File opened successfully";
    }
    // Printing the Headings in the FILE
    fprintf(ftr, "Name,");
    fprintf(ftr, "Aadhar Number,");
    fprintf(ftr, "Date of Birth,");
    fprintf(ftr, "City,");
    fprintf(ftr, "State,");
    fprintf(ftr, "Voter ID,");
    fprintf(ftr, "Vote\n");
    // For Closing the FILE.
    fclose(ftr);
    return 0;
}
