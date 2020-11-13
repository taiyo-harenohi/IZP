#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlength 10240


// ATTENTION //
/* this program isn't working for multiple commands from "Uprava tabulky";
   it is only able to do one at the time*/


// getCnum
// we get the number of columns out of this function
int getCnum(char delim[], char str[])
{
    // there is always +1 column in the line than there are delims
    int cnum = 0;
    int c;
    int num = 0;
    int delimnum = 0;
    // reading the first line to get number of columns
    while (c != '\n') // have to read it until line => otherwise, there are \n everywhere
    {
        // reading character by character
        c = fgetc(stdin);
        // putting it into an array
        str[num] = c;
        // if str on index num is same as the delims in delim[] array
        for (int i = 0; i < strlen(delim); i++)
        {
            if (str[num] == delim[i])
            {
                // the number of delims increasing
                cnum++;
                // making sure that output delim is the first delim of -d
                if (str[num] != delim[0])
                {
                    str[num] = delim[0];
                    break;
                }
            }
        }
        num++;
    }
    return cnum;
}

// getDelim
// we rewrite (if needed) the delim[n] for delim[0]
void getDelim(char delim[], char str[])
{
    int num = 0;
    // while the line hasn't ended
    while (str[num] != '\0')
    {
        for (int i = 0; i < strlen(delim); i++)
        {
            if (str[num] == delim[i])
            {
                str[num] = delim[0];
            }
        }
        num++;
    }    
}
// irow R
// puts a row before the selected row R
void irowR(int row, int cnum, char str[], char delim[])
{
    // because we will write the first row after the first cycle
    int lines = 2;
    int num = 0;
    if (row == 1)
    {
        for (int i = 0; i < cnum; i++)
        {
            // writing the first item of the delim
            printf("%c", delim[0]);
        }
        printf("\n");
    }
    // printing the first row of stdin
    printf("%s", str);
    // checking if the input of R is a correct number
    if (row >= 1)
    {
        while (fgets(str, maxlength, stdin))
        {
            num = 0;
            // if the number of the current line is the same with selected row R
            if (lines == row)
            {
                // writes an empty row where cnum is the number of columns
                for (int i = 0; i < cnum; i++)
                {
                    printf("%c", delim[0]);
                }
                printf("\n");
            }
            // function for getting the first delim
            getDelim(delim, str);
            printf("%s", str);
            lines++;
        }
    }
}

// arow
// puts row at the end of the file
void arow(int cnum, char str[], char delim[])
{
    int num = 0;
    // printing the first row
    printf("%s", str);

    // reading the whole .txt file 
    while (fgets(str, maxlength, stdin))
    {
        // reading through the line to find the imposter delims
        getDelim(delim, str);
        printf("%s", str);
    }
    // printing the last row 
    for (int i = 0; i < cnum; i++)
    {
        printf("%c", delim[0]);
    }
    printf("\n");
}

// drow R
// deletes a selected row R (while R>0)
void drowR(int row, char str[], char delim[])
{
    int num = 0; 
    // we start from the first line
    int numLines = 1;
    // if selected row == 1, we skip it
    if (row == 1)
    {
        numLines++;
    }
    // otherwise, we print the row and increase num
    else
    {
        // printing the first row
        printf("%s", str);    
        numLines++;    
    }
    // checking if the input of R is a correct number
    if (row >= 1)
    {
        while (fgets(str, maxlength, stdin))
        {
            getDelim(delim, str);
            // if the number of the current line is equal to row
            if (row == numLines)
            {
                // we increase the count of lines and skip it via continue
                numLines++;
                continue;
            }
            printf("%s", str);
            numLines++;
        }
    } 
}

// drows N M
// deletes rows from N to M (while N<=M)
void drowsNM(int n, int m, char str[], char delim[])
{
    // because we already gone through first row => numRow from 2
    int numRow = 2;
    int num = 0;
    // if the first row is written = skips it
    if (n == 1)
    {
        
    }
    else if (n == m)
    {
        drowR(n, str, delim);
    }
    // otherwise, it prints it
    else if (n > 1)
    {
        printf("%s", str);
    }
    // if n <= m, it does the correct thing and deletes the rows
    if (n <= m)
    {
        while (fgets(str, maxlength, stdin))
        {
            num = 0;
            // if the number of rows is within the range of n – m
            if (numRow >= n && numRow <= m)
            {
                numRow++;
                continue;
            }
            else 
            {
                getDelim(delim, str);
            }
            printf("%s", str);
            numRow++;
        }
    }
}

// icol C
// puts empty column before chosen C
void icolC(int column, char delim[], char str[])
{
    int numDelim = 1;
    int num = 0;
    // printing the row, in this case the first one
    while (str[num] != '\0')
    {
        // if column of the table is the same as chosen column
        if (numDelim == column)
        {
            // writes the first item of array
            printf("%c", delim[0]);
            numDelim++;
        }
        // if the item of str[] is the same as the first item of array
        for (int i = 0; i < strlen(delim); i++)
        {
            if (str[num] == delim[i])
            {
                numDelim++;
                str[num] = delim[0];
            }
            
        }
        printf("%c", str[num]);
        num++;
    }
    // if column is greater than 0
    if (column > 0)
    {
        // we use recursive method for the rest of the rows
        while (fgets(str, maxlength, stdin))
        {
            icolC(column, delim, str);
        }
    }
}

// acol 
// puts empty column after the last one
void acol(char str[], char delim[])
{
    int num = 0;
    // other solutions I came up with didn't work, so I used this method
    // if the str[num] is not a letter, delim, number decimal point or \n it prints the new column
    while (str[num] != '\0')
    {
        getDelim(delim, str);
        if (str[num] >= 'a' && str[num] <= 'z')
        {
            
        }
        else if (str[num] >= 'A' && str[num] <= 'Z')
        {

        }
        else if (str[num] >= '0' && str[num] <= '9')
        {

        }
        else if (str[num] == '.' || str[num] == delim[0] || str[num] == '\n' || str[num] == ',' || str[num] == ' ' || str[num] == '-')
        {

        }
        else
        {
            printf("%c", delim[0]);
        }
        printf("%c", str[num]);
        num++;
    }

    while(fgets(str, maxlength, stdin))
    {
        acol(str, delim);
    }
}

// dcol C
// deletes a column number C
void dcolC(int column, int cnum, char delim[], char str[])
{
    int num = 0;
    int numDelim = 1;
    // printing the row, in this case the first one
    while (str[num] != '\0')
    {
        // if it hits the delim, the number of them increases by 1
        for (int i = 0; i < strlen(delim); i++)
        {
            if (str[num] == delim[i])
            {
                numDelim++;
                str[num] = delim[0];
            }
        }
        // if we hit the number of columns => skips it
        if (numDelim == column)
        {
            num++;
            continue;
        }
        printf("%c", str[num]);
        num++;
    }
    // if column is the same as number of the columns + 1, it writes \n
    if (column == cnum + 1)
    {
        printf("\n");
    }

    while (fgets(str,maxlength,stdin))
    {
        dcolC(column, cnum, delim, str);
    }
}

// dcols N M
// deletes columns from N to M (N<=M)
void dcolsNM(int n, int m, int cnum, char delim[], char str[])
{
    int num = 0;
    int numDelim = 1;
    // if n == m, it calls the method dcolC with variable n
    if (n == m)
    {
        dcolC(n, cnum, delim, str);
    }
    // if n <= m, it does the correct thing and skips the rows
    else if (n <= m)
    {
        // printing the first row
        while (str[num] != '\0')
        {
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    numDelim++;
                    str[num] = delim[0];
                }
            }
            // if the number of delims(=columns) is within the range of n and m
            if (numDelim >= n && numDelim <= m)
            {
                num++;
                continue;
            }
            // if the n is first column, it skips the delim
            if (n == 1)
            {
                num++;
                printf("%c", str[num]);
            }
            else
            {
                printf("%c", str[num]);
                num++;           
            }
        }
        // if the m is equal/greater than number of columns
        if (m >= cnum + 1)
        {
            printf("\n");
        }
        while (fgets(str,maxlength,stdin))
        {
            dcolsNM(n, m, cnum, delim, str);
        }
    }
}

// if there are two :: after each other -> it doesn't print the STR
// cset C STR
// into column C input STR
void csetCSTR(int row, int n, int m, int column, int cnum, char delim[], char input[], char str[])
{
    int num = 0;
    int numInput = 0;
    int numDelim = 1;
    // if the row is within the range of n and m
    if (row >= n && row <= m)
    {
        while (str[num] != '\0')
        {
            // reading to get delims and put into str[num] the first one
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] = delim[0];
                    if (column > 1)
                    {
                        printf("%c", str[num]);
                        num++;
                        numDelim++;
                    }
                }               
            }          
            // reading until it reaches the end of the column, if one of the arrays is bigger than the other  
            if (column < cnum + 1)
            {
                while (numDelim == column && str[num] != delim[0])
                {
                    num++;
                }
            }
            else
            {
                while (numDelim == column && str[num] != '\n')
                {
                    num++;
                }        
            }
            // printing input
            while (numDelim == column)
            {
                printf("%c", input[numInput]);
                numInput++;
                if (input[numInput] == '\0')
                {
                    numDelim++;
                }
            }
            printf("%c", str[num]);
            num++;        
        }
        row++;
    }
    else
    {
        getDelim(delim, str);     
        printf("%s", str);
        row++;
    }
    // using recursive function to read every line of the stdin
    while (fgets(str, maxlength, stdin))
    {
        csetCSTR(row, n, m, column, cnum, delim, input, str);
    }
}

// tolower C
// a string in column C will be in lower case
void tolowerC(int row, int n, int m, int column, char delim[], char str[])
{
    int numDelim = 1;
    int num = 0;
    // if row is within the range of n and m
    if (row >= n && row <= m)
    {
        // changing every delim to delim[0]
        while (str[num] != '\0')
        {
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] = delim[0];
                    numDelim++;
                }
            }
            // if we hit the column the user wants
            if (numDelim == column)
            {
                // if str[num] is a letter
                if (str[num] >= 'A' && str[num] <= 'Z')
                {
                    str[num] += 32;
                }
            }
            printf("%c", str[num]);
            num++;
        }
    }
    else
    {
        getDelim(delim, str);
        printf("%s", str);
    }
    // going through every line of stdin
    while (fgets(str, maxlength, stdin))
    {
        row++;
        tolowerC(row, n, m, column, delim, str);
    }
}

// toupper C
// a string in column C will be in upper case
void toupperC(int row, int n, int m, int column, char delim[], char str[])
{
    int numDelim = 1;
    int num = 0;
    if (row >= n && row <= m)
    {
        // changing str[num], which is a delim, to delim[0]
        while (str[num] != '\0')
        {
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] == delim[0];
                    numDelim++;
                }
            }
            // if we have the wanted column
            if (numDelim == column)
            {
                // if str[num] is letter
                if (str[num] >= 'a' && str[num] <= 'z')
                {
                    str[num] -= 32;
                }
            }
            printf("%c", str[num]);
            num++;
        }
    }
    else
    {
        getDelim(delim, str);      
        printf("%s", str);
    }
    // going through the rest of stdin
    while (fgets(str, maxlength, stdin))
    {
        row++;
        toupperC(row, n, m, column, delim, str);
    } 
}

// round C
// in a column C rounds number
void roundC(int row, int n, int m, int column, char delim[], char str[])
{
    int num = 0;
    int numDelim = 1;
    if (row >= n && row <= m)
    {
        while(str[num] != '\0')
        {
            if (numDelim == column)
            {
                // making sure that str[num] is a number
                while ((str[num] >= '0' && str[num] <= '9') || str[num] == '.')
                {
                    // if we hit '.' => we found decimal number
                    if (str[num] == '.')
                    {  
                        // if the number is betweeen 0 and 5 => stays the same
                        if (str[num+1] <= '5' || str[num+1] == '0')
                        {

                        }
                        // if the number is bigger than 5 and 9 => +1
                        else if (str[num+1] > '5' && str[num+1] < '9')
                        {
                            str[num-1] += 1;
                        }
                        // "deleting" the decimal part to make int 
                        while(str[num] != delim[0])
                        {
                            if (str[num] == '\n')
                            {
                                break;
                            }
                            num++;
                        }
                    }
                    printf("%c", str[num]);
                    num++;
                }
            }
            // getting the delim to be delim[0] everywhere
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] == delim[0];
                    numDelim++;
                }
            }
            printf("%c", str[num]);
            num++;
        }
    }
    else
    {
        getDelim(delim, str);     
        printf("%s", str);
    }
    while(fgets(str,maxlength,stdin))
    {
        row++;
        roundC(row, n, m, column, delim, str);
    }
}

// int C
// deletes a coma in n.m (1.32; 5.47 etc.)
void intC(int row, int n, int m, int column, char delim[], char str[])
{
    int num = 0;
    int numDelim = 1;
    if (row >= n && row <= m)
    {
        // reading the line until it hits decimal
        while(str[num] != '\0')
        {
            // if it is destined column
            if (numDelim == column)
            {
                // while str[num] is number
                while ((str[num] >= '0' && str[num] <= '9') || str[num] == '.')
                {
                    // if we hit '.' => decimal part, deleting it
                    if (str[num] == '.')
                    {  
                        while(str[num] != delim[0])
                        {
                            if (str[num] == '\n')
                            {
                                break;
                            }
                            num++;
                        }
                    }
                    // otherwise, printing the rest
                    else
                    {
                        printf("%c", str[num]);
                        num++;
                    }
                }
            }
            // str[num] = delim[0]
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] = delim[0];
                    numDelim++;
                }
            }
            printf("%c", str[num]);
            num++;
        }
    }
    else
    {
        getDelim(delim, str);
        printf("%s", str);
    }
    
    while (fgets(str, maxlength, stdin))
    {
        row++;
        intC(row, n, m, column, delim, str);
    }
}

// copy N M
// copy column N to column M
void copyNM(int row, int nRow, int mRow, int n, int m, char delim[], char str[])
{
    int num = 0;
    int numDelim = 1;
    // integer for items in arrayN
    int numN = 0;
    // arrayN for saving the column we want to copy
    char arrayN[numN];
    if (row >= nRow && row <= mRow)
    {
        while (str[num] != '\0')
        {
            // if we have the n column
            if (numDelim == n)
            {
                // putting the str[num] into arrayN[numN]
                while (str[num] != delim[0])
                {
                    printf("%c", str[num]);
                    arrayN[numN] = str[num];
                    numN++;
                    num++;
                }
            }
            // we have to put numN into 0 => printing it later on
            numN = 0;
            if (numDelim == m)
            {
                // skipping str[num] until we hit delim
                while (str[num] != delim[0])
                {
                    num++;
                }
                // until the arrayN is empty, we print it
                while (arrayN[numN] != '\0')
                {
                    printf("%c", arrayN[numN]);
                    numN++;
                }
            }
            // delim on str[num] = delim[0]
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] = delim[0];
                    numDelim++;
                }
            }
            printf("%c", str[num]);
            num++;
        }   
    }
    else
    {
        getDelim(delim, str);
        printf("%s", str);
    }
    while(fgets(str, maxlength, stdin))
    {
        row++;
        copyNM(row, nRow, mRow, n, m, delim, str);
    }
}

// swap N M
// swaps N and M columns
void swapNM (int row, int nRow, int mRow, int n, int m, char delim[], char str[])
{
    int num = 0;
    int numDelim = 1;
    // integer for arrayN
    int numN = 0;
    // integer for arrayM 
    int numM = 0;
    // array for putting in the column n
    char arrayN[102] = "";
    // array for putting in the column m
    char arrayM[102] = "";
    if (row >= nRow && row <= mRow)
    {
        while (str[num] != '\0')
        {
            // until we hit delim[0]
            if (numDelim == n && str[num] != delim[0])
            {
                // putting into arrayN the column n
                arrayN[numN] = str[num];
                numN++;
            }
            // putting into arrayM the m column
            if (numDelim == m && str[num] != delim[0])
            {
                if (str[num] != '\0')
                {
                        arrayM[numM] = str[num];
                        numM++;
                }   
            }
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] = delim[0];
                    numDelim++;
                }
            }
            num++;
        }
        // everything putting on starting datas
        num = 0; 
        numN = 0;
        numM = 0;
        numDelim = 1;
        while (str[num] != '\0')
        {
            // printing the arrayM/column m into column n
            while (numDelim == n)
            {
                printf("%c", arrayM[numM]);
                numM++;
                if (arrayM[numM] == '\0')
                {
                    break;
                }
            }
            // until we hit the delim = skipping letters
            while (numDelim == n && str[num] != delim[0])
            {
                num++;
            }
            // printing the arrayN/column n into column m
            while (numDelim == m)
            {
                printf("%c", arrayN[numN]);
                numN++;
                if (arrayN[numN] == '\0')
                {
                    break;
                }
            }
            // until we hit delim = skipping letters
            while (numDelim == m && str[num] != delim[0])
            {
                if (str[num] != '\0');
                {
                    num++;
                }
                if (str[num] == '\n')
                {
                    break;
                } 
            }
            printf("%c", str[num]);
            num++;
        }
    }
    else
    {
        getDelim(delim, str); 
        printf("%s", str);
    }
    while (fgets(str, maxlength, stdin))
    {
        row++;
        swapNM(row, nRow, mRow, n, m, delim, str);
    }
}

// move N M
// move the column N before the column M
void moveNM(int row, int nRow, int mRow, int n, int m, char delim[], char str[])
{
    int num = 0;
    int numDelim = 1;
    // arrayN for putting in the datas of column n
    char arrayN[102] = "";
    // integer for arrayN 
    int numN = 0;
    if (row >= nRow && row <= mRow)
    {
        while (str[num] != '\0')
        {
            // if we hit the column n => saving str[num] into arrayN
            if (numDelim == n)
            {
                arrayN[numN] = str[num];
                numN++;
            }
            for (int i = 0; i < strlen(delim); i++)
            {
                if (str[num] == delim[i])
                {
                    str[num] = delim[0];
                    numDelim++;
                }
            }
            num++;
        }
        // reseting datas
        num = 0;
        numDelim = 1;
        numN = 0;
        while(str[num] != '\0')
        {
            // skipping the n column => it is being moved in front of m
            while (numDelim == n)
            {
                num++;
                if (str[num] == delim[0])
                {
                    num++;
                    numDelim++;
                }
            }
            // if we hit the column m, we print the arrayN
            while (numDelim == m && arrayN[numN] != '\0')
            {
                printf("%s", arrayN);
            }
            printf("%c", str[num]);
            num++;
        }
    }
    else
    {
        getDelim(delim, str);   
        printf("%s", str);
    }
    while(fgets(str, maxlength, stdin))
    {
        row++;
        moveNM(row, nRow, mRow, n, m, delim, str);
    }
}

void printTable(char str[])
{
    printf("%s", str);
    while(fgets(str, maxlength, stdin))
    {
        printf("%s", str);
    }
}

// error function 
int errorFun()
{
    fprintf(stderr, "ERROR");
    return 1;
}

int main(int argc, char *argv[]) 
{
    // pointer for delims
    char *delim[1];
    *delim = " ";
    // string used for the whole stdin
    char str[maxlength];
    // number of columns
    int cnum = 0;
    // n and m for Select Row function
    int nRows = 1;
    int mRows = maxlength;
    // number of row
    int row = 1;
    // arrays full of commands used in this program
    char *commandTable[] = {"irow", "arow", "drow", "drows", "icol", "acol", "dcol", "dcols"};
    char *commandData[] = {"cset", "tolower", "toupper", "round", "int", "swap", "copy", "move"};
    // if we find unknownCommand => it changes to 1 and gives us an error function
    int unknownCommand = 0;

    // going through argv to find what is in it
    for (int i = 2; i < argc; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // if we find command that is in commandTable
            if (argv[i] == commandTable[j])
            {
                unknownCommand = 0;
            }
            // if we find command that is in commandData
            else if (argv[i] == commandData[j])
            {
                unknownCommand = 0;
            }
            // if we hit correct number
            else if (atoi(argv[i]) > 0)
            {
                unknownCommand = 0;
            }
            // for some reason, otherwise these two aren't working
            else if (strcmp(argv[i], "arow") == 0)
            {
                unknownCommand = 0;
                break;
            }
            else if (strcmp(argv[i], "acol") == 0)
            {
                unknownCommand = 0;
                break;
            }
            else
            {
                unknownCommand = 1;
            }
        }   
        // ending the cycle sooner, because cset has str coming with it
        if (strcmp(argv[i], "cset") == 0)
        {
            unknownCommand = 0;
            break;
        }
    }
    if (unknownCommand == 1)
    {
        return errorFun();
    }

    for (int i = 0; i < argc; i++)
    {
        // if argv[i] is bigger than approved length
        if (strlen(argv[i]) > 100)
        {
            return errorFun();
        }
        // getting delim and cnum
        if (strcmp(argv[i], "-d") == 0)
        {
           *delim = argv[i+1];
            cnum = getCnum(*delim, str);
        }
        // getting irow
        if (strcmp(argv[i], "irow") == 0)
        {
            int row = atoi(argv[i+1]);
            // making sure we get errors when needed
            if (row > 0)
            {
                irowR(row, cnum, str, *delim); 
            }
            else
            {
                return errorFun();
            }
        }
        // getting arow
        if (strcmp(argv[i], "arow") == 0)
        {
            // if there is number after arow => error
            if (argv[i+1] != NULL)
            {
                return errorFun();
            }
            else
            {
                arow(cnum, str, *delim);   
            }
        } 
        // getting drow
        if (strcmp(argv[i], "drow") == 0)
        {
            int row = atoi(argv[i+1]);
            // if row is greater than 0
            if (row > 0)
            {
                drowR(row, str, *delim);
            }
            else 
            {
                return errorFun();
            }
        }    
        // getting drows
        if (strcmp(argv[i], "drows") == 0)
        {
            int n = atoi(argv[i+1]);
            int m = atoi(argv[i+2]);
            // if n and m is in the right range
            if (n > 0 && n <= m)
            {
                drowsNM(n, m, str, *delim);
            }
            else 
            {
                return errorFun();
            }
        }       
        // getting icol
        if (strcmp(argv[i], "icol") == 0)
        {
            int c = atoi(argv[i+1]);
            // if c is greater than 0
            if (c > 0)
            {
                icolC(c, *delim, str);
            }
            else 
            {
                return errorFun();
            }
        }   
        // getting acol
        if (strcmp(argv[i], "acol") == 0)
        {
            // there cannot be anything after acol command, otherwise => error 
            if (argv[i+1] != NULL)
            {
                return errorFun();
            }
            else
            {
                acol(str, *delim);                
            }            
        }    
        // getting dcol  
        if (strcmp(argv[i], "dcol") == 0)
        {
            int c = atoi(argv[i+1]);
            if (c > 0)
            {
                dcolC(c, cnum, *delim, str);               
            }
            else
            {
                return errorFun();
            }
        }  
        if (strcmp(argv[i], "dcols") == 0)
        {
            int n = atoi(argv[i+1]);
            int m = atoi(argv[i+2]);
            // n and m are in this range
            if ( n > 0 && n <= m)
            {
                dcolsNM(n, m, cnum, *delim, str);
            }
            else
            {
                return errorFun();
            }
        }  
        // SELECTION METHOD STARTING HERE      
        if (strcmp(argv[i], "rows") == 0)
        {
            // making it into two if statements, because it is big af
            if (strcmp(argv[i+3], "irow") == 0 || strcmp(argv[i+3], "arow") == 0 || strcmp(argv[i+3], "drow") == 0 || strcmp(argv[i+3], "drows") == 0)
            {
                return errorFun();
            }               
            else if (strcmp(argv[i+3], "icol") == 0 || strcmp(argv[i+3], "acol") == 0 || strcmp(argv[i+3], "dcol") == 0 || strcmp(argv[i+3], "dcols") == 0)
            {
                return errorFun();
            }       
            else
            {
                if (strcmp(argv[i+1], "-") == 0)
                {
                    // I know this one is wrong, but I don't know how to do it :c
                    if (strcmp(argv[i+2], "-") == 0)
                    {
                        nRows = 1;
                        mRows = maxlength;
                    }
                    // mRow is the input
                    else
                    {
                        nRows = 1;
                        mRows = atoi(argv[i+2]);
                    }
                }
                // nRow is the input
                else if (strcmp(argv[i+2], "-") == 0)
                {
                    nRows = atoi(argv[i+1]);
                    mRows = maxlength;
                }
                // both are input
                else
                {
                    nRows = atoi(argv[i+1]);
                    mRows = atoi(argv[i+2]); 
                }
            }                                                            
        }        
        // getting cset 
        if (strcmp(argv[i], "cset") == 0)
        {
            int c = atoi(argv[i+1]);
            char *input[100];
            *input = argv[i+2];
            if (c <= 0)
            {
                return errorFun();
            }
            // if the length of input is bigger than said
            else if (strlen(*input) > 100)
            {
                return errorFun();
            }
            else
            {
                csetCSTR(row, nRows, mRows, c, cnum, *delim, *input, str);
            }            
        }  
        // getting tolower
        if (strcmp(argv[i], "tolower") == 0)
        {
            int c = atoi(argv[i+1]);
            if (c <= 0)
            {
                return errorFun();
            }
            else 
            {
                tolowerC(row, nRows, mRows, c, *delim, str);
            }
        }
        // getting upper
        if (strcmp(argv[i], "toupper") == 0)
        {
            int c = atoi(argv[i+1]);
            if (c <= 0)
            {
                return errorFun();
            }
            else
            {
                toupperC(row, nRows, mRows, c, *delim, str);
            }
        }
        // getting round
        if (strcmp(argv[i], "round") == 0)
        {
            int c = atoi(argv[i+1]);
            if (c <= 0)
            {
                return errorFun();
            }
            else 
            {
                roundC(row, nRows, mRows, c, *delim, str);
            }
        }
        // getting int
        if (strcmp(argv[i], "int") == 0)
        {
            int c = atoi(argv[i+1]);
            if (c > 0)
            {
                intC(row, nRows, mRows, c, *delim, str);
            }
            else
            {
                return errorFun();
            }
        }    
        // getting copy
        if (strcmp(argv[i], "copy") == 0)
        {
            int n = atoi(argv[i+1]);
            int m = atoi(argv[i+2]);
            // if n and m are in this range
            if (n > 1 && n <= m)
            {
                copyNM(row, nRows, mRows, n, m, *delim, str);
            }
            // printing the stdin without change
            else if (m > cnum || n > cnum || n > m)
            {
                printTable(str);
            }
            else
            {
                return errorFun();
            }
            
        }
        // getting swap
        if (strcmp(argv[i], "swap") == 0)
        {
            int n = atoi(argv[i+1]);
            int m = atoi(argv[i+2]);
            // if n and m is in the range
            if (n <= 0 || m <= 0)
            {
                return errorFun();
            }
            // printing the table without change
            else if (m > cnum || n > cnum || n > m)
            {
                printTable(str);
            }
            else
            {
                swapNM(row, nRows, mRows, n, m, *delim, str);
            }
        }     
        // getting move
        if (strcmp(argv[i], "move") == 0)
        {
            int n = atoi(argv[i+1]);
            int m = atoi(argv[i+2]);
            if (n <= 0 || m <= 0)
            {
                return errorFun();
            }
            else
            {
                moveNM(row, nRows, mRows, n, m, *delim, str);
            }            
        }
    }      
    return 0;
}