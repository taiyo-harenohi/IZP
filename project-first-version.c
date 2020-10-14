#include <stdio.h>
#include <stdlib.h>

int getCnum(int maxlength)
{
    // there is always +1 column in the line than there are ':'
    int cnum = 1;
    char str[maxlength];
    int c;
    // reading the first line to get number of columns
    while (c != '\n')
    {
        // reading character by character
        c = fgetc(stdin);
        // converting c into char 
        char convert = c;
        // printing character by character
        printf("%c", convert);
        // if we hit ':' => +1 column
        if (c == ':')
        {
            cnum++;
        }
    }
    return cnum;
}

// Using a lot of functions = first is in a cycle below, 
// where we start making arrays

// reading the whole file until string[i] != '\0'
// putting the characters into array
// after being done, everytime it hits ':' => new column
// everytime it hits '\n' => new row
// putting numbers on the rows AND columns 
// first line = number of columns

// irow R
// puts row before selected row R (while R>0)
void irowR(int r, int cnum, char str[], int maxlength)
{
    // because we went through the first line already in getCnum() function
    int lines = 2;
    // checking if the input of R is a correct number
    if (r > 0)
    {
        while (fgets(str, maxlength, stdin))
        {
            if (lines == r)
            {
                // writes an empty row
                // where cnum is number of columns

                for (int i = 0; i < cnum - 1; i++)
                {
                    printf(":");
                }
                printf("\n");
            }
            printf("%s", str);
            lines++;
        }
    }
    // if it is not r > 0 => ERROR message
    else if (r <= 0)
    {
        printf("Error: Invalid input\n");
        printf("This is not possible; you entered wrong R.\n");
        printf("Try again, please.\n");
        exit(0);
    }
}

// arow
// puts row at the end of the file
void newLine(int r, int cnum)
{
    // until it hits the end of the document while reading it
    // printing all of the rows here
    if (r == 0)
    {
        for (int i = 1; i < cnum; i++)
        {
            printf(":");
        }
        printf("\n");
    }
}

// drow R
// deletes a selected row R (while R>0)
void drowR(int r)
{
    // checking if the input of R is a correct number
    if (r > 0)
    {
        for (int i = 1; i <= r; i++) 
        {
            if (i == r) 
            {
                continue;
            }
            else
            {
                // printing the rest
            }
        }
    }
    // if it is not r > 0 => ERROR message
    else if (r <= 0)
    {
        printf("Error: Invalid input\n");
        printf("This is not possible; you entered wrong R.\n");
        printf("Try again, please.\n");
        exit(0);
    } 
}

// drows N M
// deletes rows from N to M (while N<=M)
void drowsNM(int n, int m)
{
    // if n == m, it calls the method drowR with variable n
    if (n == m)
    {
        drowR(n);
    }
    // if n <= m, it does the correct thing and skips = deletes the rows
    else if (n <= m)
    {
        for (int i = 1; i <= m; i++)
        {
            if (i >= n && i <= m)
            {
                continue;
            }
            else
            {
                // writes the rest of the rows
            }
        }
    }
    else if (n > m)
    {
        printf("Error: Invalid input\n");
        printf("This is not possible; you entered wrong R.\n");
        printf("Try again, please.\n");
        exit(0);
    }
}

// icol C
// puts empty column before chosen C
void icolC(int c)
{
    for (int i = 1; i <= c; i++)
    {
        if (i == c - 1)
        {
            printf(":");   
        }
        else
        {
            // prints the rest of the file
        }
    }
}

// acol 
// puts empty column after the last one
void acol(int column)
{
    // if a character is \n => printing a column
}

// dcol C
// deletes a column number C
void dcolC(int c, int cnum)
{
    for (int i = 1; i <= cnum; i++)
    {
        if (i == c) 
        {
            continue;
        }
        else
        {
            // printing the rest
        }
    }
}

// dcols N M
// deletes columns from N to M (N<=M)
void dcolsNM(int n, int m, int cnum)
{
    // if n == m, it calls the method drowR with variable n
    if (n == m)
    {
        dcolC(n, cnum);
    }
    // if n <= m, it does the correct thing and skips = deletes the rows
    else if (n <= m)
    {
        for (int i = 1; i <= m; i++)
        {
            if (i >= n && i <= m)
            {
                continue;
            }
            else
            {
                // writes the rest of the rows
            }
        }
    }
    // if n is greater than m => error message
    else if (n > m)
    {
        printf("Error: Invalid input\n");
        printf("This is not possible; you entered wrong R.\n");
        printf("Try again, please.\n");
        exit(0);
    }
}

// cset C STR
// into column C input STR

// tolower C
// a string in column C will be in lower case
void tolowerC(int c, char str[])
{
    int j = 0;
    for (int i = 1; i <= c; i++)
    {
        if (i == c)
        {
            while (str[j] != ':')
            {
            if (str[j] >= 'A' && str[j] <= 'Z')
                {
                    str[j] += 32;
                } 
                j++;
            }
        }
    }
    // writes the rest
}

// toupper C
// a string in column C will be in upper case
void toupperC(int c, char str[])
{
    int j = 0;
    for (int i = 1; i <= c; i++)
    {
        if (i == c)
        {
            while (str[j] != ':')
            {
            if (str[j] >= 'a' && str[j] <= 'z')
                {
                    str[j] -= 32;
                } 
                j++;
            }
        }
    }
    // writes the rest
}


// round C
// in a column C rounds number

// int C
// deletes a coma in n.m (1.32; 5.47 etc.)

// copy N M
// copy column N to column M
void copyNM(int n, int m, char str[])
{
    // bigger cycle for reading until the end of the file

    // this cycle is for a one row
    char strN[102];
    char strM[102];
    int j, k = 0;
    for (int i = 1; i <=m; i++)
    {
        if (i == n)
        {
            while (str[j] != ':')
            {
                strN[j] = str[j];
                j++;
            }
        }
        if (i == m)
        {
            while (str[k] != ':')
            {
                strM[k] = strN[k];
                k++;
            }
        }
    }
}

// swap N M
// swaps the columns N and M ??????
// before printing the line, it takes the whole line and splits via ':'
// the program puts it in arrays for every word
// then, it swaps N column and M column

void swapNM (int n, int m, char str[])
{
    for (int i = 1; i <= m; i++)
    {
        while (str[i] != ':')
        {
            if (i == n)
            {

            }
        }
    }
}

// move N M
// move the column N before the column M ?????
// similar to previous one

// csum C N M 
// 

// cavg C N M 
// 

// cmin C N M
// 

// cmax C N M
// 

// ccount C N M
// 

// error function for invalid number
// if n < m etc.
int errorNM()
{
    return 0;
}

int main() 
{
    int line = 0;
    scanf("%d", &line);
    int const maxlenght = 10240;
    char str[maxlenght];

    int cnum = getCnum(maxlenght);
    irowR(2, cnum, str, maxlenght);
    // irowR(int r, char str[], int maxlength)

    /* 
    while (fgets(str, maxlenght, stdin))
    {
        printf("%s", str);
    }
    */
    return 0;
}