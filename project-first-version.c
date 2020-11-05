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
    while (c != '\n')
    {
        // reading character by character
        c = fgetc(stdin);
        // putting it into an array
        str[num] = c;
        num++;
    }

    num = 0;
    // getting cnum = number of columns
    while (str[num] != '\0')
    {
        if (str[num] == delim[0])
        {
            cnum++;
        }
        num++;
    }
    return cnum;
}

// irow R
// puts row before selected row R (while R>0)
void irowR(int r, int cnum, char str[], char delim[])
{
    // because we will write the first row after this cycle
    int lines = 2;
    int num = 0;
    if (r == 1)
    {
        for (int i = 0; i < cnum; i++)
        {
            printf("%c", delim[0]);
        }
        printf("\n");
    }
    // printing the first row
    printf("%s", str);
    // checking if the input of R is a correct number
    if (r > 1)
    {
        while (fgets(str, maxlength, stdin))
        {
            if (lines == r)
            {
                // writes an empty row
                // where cnum is number of columns
                for (int i = 0; i < cnum; i++)
                {
                    printf("%c", delim[0]);
                }
                printf("\n");
            }
            printf("%s", str);
            lines++;
        }
    }
}

// arow
// puts row at the end of the file
void arow(int cnum, char str[], char delim[])
{
    // printing the first row
    printf("%s", str);

    // reading the whole .txt file 
    while (fgets(str, maxlength, stdin))
    {
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
void drowR(int row, char str[])
{
    int num = 1;
    if (row == 1)
    {
        num++;
        // leaving otherwise an empty branch, because we are not printing the row
    }
    else
    {
        // printing the first row
        printf("%s", str);    
        num++;    
    }
    // checking if the input of R is a correct number
    if (row > 1)
    {
        while (fgets(str, maxlength, stdin))
        {
            if (row == num)
            {
                num++;
                continue;
            }
            printf("%s", str);
            num++;
        }
    } 
}

// DOESNT WORK FOR THE FIRST LINE 
// drows N M
// deletes rows from N to M (while N<=M)
void drowsNM(int n, int m, char str[])
{
    // printing the first row
    printf("%s", str);
    // declaring an array
    char newstr[maxlength];
    int num = 2;
    // if n == m, it calls the method drowR with variable n and str
    if (n == m)
    {
        drowR(n, str);
    }
    // if n <= m, it does the correct thing and deletes the rows
    else if (n <= m)
    {
        while (fgets(newstr, maxlength, stdin))
        {
            // the function deletes the columns in range n – m
            if (num >= n && num <= m)
            {
                num++;
                continue;
            }
            printf("%s", newstr);
            num++;
        }
    }
}

// icol C
// puts empty column before chosen C
void icolC(int column, char delim, char str[])
{
    int c;
    int numDelim = 1;
    int num = 0;
    // printing the first row
    while (str[num] != '\0')
    {
        if (numDelim == column)
        {
            printf("%c", delim);
            numDelim++;
        }
        if (str[num] == delim)
        {
            numDelim++;
        }
        printf("%c", str[num]);
        num++;
    }
    numDelim = 1;
    if (column > 0)
    {
        while ((c = fgetc(stdin)) != EOF)
        {
            if (c != '\0')
            {
                if ((c == delim) && (numDelim < column))
                {
                    numDelim++;
                }
                if (column == numDelim)
                {
                    printf("%c", delim);
                    numDelim++;
                }
            }
            else if (c == '\n')
            {
                numDelim = 1;
            }
            printf("%c", c);
        }
    }
}

// acol 
// puts empty column after the last one
void acol(int cnum, char str[], char delim)
{
    int num = 0;

    while (str[num] != '\0')
    {
        if (str[num] >= 'a' && str[num] <= 'z')
        {
            
        }
        else if (str[num] >= 'A' && str[num] <= 'Z')
        {

        }
        else if (str[num] >= '0' && str[num] <= '9')
        {

        }
        else if (str[num] == '.' || str[num] == delim || str[num] == '\n')
        {

        }
        else
        {
            printf("%c", delim);
        }
        printf("%c", str[num]);
        num++;
    }

    while(fgets(str, maxlength, stdin))
    {
        num = 0;
        while (str[num] != '\0')
        {
            if (str[num] >= 'a' && str[num] <= 'z')
            {
                
            }
            else if (str[num] >= 'A' && str[num] <= 'Z')
            {

            }
            else if (str[num] >= '0' && str[num] <= '9')
            {

            }
            else if (str[num] == '.' || str[num] == delim || str[num] == '\n')
            {

            }
            else
            {
                printf("%c", delim);
            }
            printf("%c", str[num]);
            num++;
        }    
    }
}

// dcol C
// deletes a column number C
void dcolC(int column, int cnum, char delim, char str[])
{
    char newstr[maxlength];
    int num = 0;
    int numColumn = 1;

    // printing the first row
    while (str[num] != '\0')
    {
        if (str[num] == delim)
        {
            numColumn++;
        }
        if (numColumn == column)
        {
            num++;
            continue;
        }
        if (column == 1)
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
    if (column == cnum + 1)
    {
        printf("\n");
    }

    while (fgets(newstr,maxlength,stdin))
    {
        num = 0;
        numColumn = 1;
        while (newstr[num] != '\0')
        {
            if (newstr[num] == delim)
            {
                numColumn++;
            }
            if (numColumn == column)
            {
                num++;
                continue;
            }
            if (column == 1)
            {
                num++;
                printf("%c", newstr[num]);
            }
            else
            {
                printf("%c", newstr[num]);
                num++;           
            }
        }
        if (column == cnum + 1)
        {
            printf("\n");
        }
    }
}

// dcols N M
// deletes columns from N to M (N<=M)
void dcolsNM(int n, int m, int cnum, char delim, char str[])
{
    char newstr[maxlength];
    int num = 0;
    int numColumn = 1;
    // if n == m, it calls the method dcolC with variable n
    if (n == m)
    {
        dcolC(n, cnum, delim, str);
    }
    // if n <= m, it does the correct thing and skips (=deletes) the rows
    else if (n <= m)
    {
        // printing the first row
        while (str[num] != '\0')
        {
            if (str[num] == delim)
            {
                numColumn++;
            }
            if (numColumn >= n && numColumn <= m)
            {
                num++;
                continue;
            }
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
        if (m == cnum + 1)
        {
            printf("\n");
        }

        while (fgets(newstr,maxlength,stdin))
        {
            num = 0;
            numColumn = 1;
            while (newstr[num] != '\0')
            {
                if (newstr[num] == delim)
                {
                    numColumn++;
                }
                if (numColumn >= n && numColumn <= m)
                {
                    num++;
                    continue;
                }
                if (n == 1)
                {
                    num++;
                    printf("%c", newstr[num]);
                }
                else
                {
                    printf("%c", newstr[num]);
                    num++;           
                }
            }
            if (m == cnum + 1)
            {
                printf("\n");
            }
        }
    }
}

// NOT DONE FOR FIRST COLUMN -> when empty, it doesnt fill it
// cset C STR
// into column C input STR
void csetCSTR(int column, int cnum, char delim, char STR[], char str[])
{
    int num = 0;
    int numSTR = 0;
    int numDelim = 1;
    // for the first row
    while (str[num] != '\0')
    {
        if (str[num] == delim)
        {
            printf("%c", str[num]);
            num++;
            numDelim++;
        }
        if (column < cnum)
        {
            while (numDelim == column && str[num] != delim)
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
        
        while (numDelim == column)
        {
            printf("%c", STR[numSTR]);
            numSTR++;
            if (STR[numSTR] == '\0')
            {
                numDelim++;
            }
        }
        printf("%c", str[num]);
        num++;        
    }

    while (fgets(str, maxlength, stdin))
    {
        numDelim = 1;
        num = 0;
        numSTR = 0;
        while (str[num] != '\0')
        {
            if (str[num] == delim)
            {
                printf("%c", str[num]);
                num++;
                numDelim++;
            }
            else if (str[0] == delim && column == 1)
            {
                
            }
            if (column < cnum)
            {
                while (numDelim == column && str[num] != delim)
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
            
            while (numDelim == column)
            {
                printf("%c", STR[numSTR]);
                numSTR++;
                if (STR[numSTR] == '\0')
                {
                    numDelim++;
                }
            }
            printf("%c", str[num]);
            num++; 
        }
    }
}

// tolower C
// a string in column C will be in lower case
void tolowerC(int column, char delim, char str[])
{
    int numDelim = 1;
    int num = 0;
    char newstr[maxlength];
    while (str[num] != '\0')
    {
        if (str[num] == delim)
        {
            numDelim++;
        }
        if (numDelim == column)
        {
            if (str[num] >= 'A' && str[num] <= 'Z')
            {
                str[num] += 32;
            }
        }
        printf("%c", str[num]);
        num++;
    }

    while (fgets(newstr, maxlength, stdin))
    {
        num = 0;
        numDelim = 1;
        while (newstr[num] != '\0')
        {
            if (newstr[num] == delim)
            {
                numDelim++;
            }
            if (numDelim == column)
            {
                if (newstr[num] >= 'A' && newstr[num] <= 'Z')
                {
                    newstr[num] += 32;
                }
            }
            printf("%c", newstr[num]);
            num++;
        }
    }
}

// toupper C
// a string in column C will be in upper case
void toupperC(int column, char delim, char str[])
{
    int numDelim = 1;
    int num = 0;
    char newstr[maxlength];
    while (str[num] != '\0')
    {
        if (str[num] == delim)
        {
            numDelim++;
        }
        if (numDelim == column)
        {
            if (str[num] >= 'a' && str[num] <= 'z')
            {
                str[num] -= 32;
            }
        }
        printf("%c", str[num]);
        num++;
    }

    while (fgets(newstr, maxlength, stdin))
    {
        num = 0;
        numDelim = 1;
        while (newstr[num] != '\0')
        {
            if (newstr[num] == delim)
            {
                numDelim++; 
            }
            if (numDelim == column)
            {
                if (newstr[num] >= 'a' && newstr[num] <= 'z')
                {
                    newstr[num] -= 32;
                }
            }
            printf("%c", newstr[num]);
            num++;
        }
    } 
}

// round C
// in a column C rounds number
void roundC(int column, char delim, char str[])
{
    int num = 0;
    int numDelim = 1;

    while(str[num] != '\0')
    {
        if (numDelim == column)
        {
            while ((str[num] >= '0' && str[num] <= '9') || str[num] == '.')
            {
                if (str[num] == '.')
                {  
                    if (str[num+1] <= '5' || str[num+1] == '0')
                    {

                    }
                    else if (str[num+1] > '5')
                    {
                        str[num-1] += 1;
                    }
                    while(str[num] != delim)
                    {
                        num++;
                    }
                }
                else
                {
                    printf("%c", str[num]);
                    num++;
                }
            }
        }
        if (str[num] == delim)
        {
            numDelim++;
        }
        printf("%c", str[num]);
        num++;
    }

    while(fgets(str,maxlength,stdin))
    {
        num = 0;
        numDelim = 1;
        while(str[num] != '\0')
        {
            if (numDelim == column)
            {
                while ((str[num] >= '0' && str[num] <= '9') || str[num] == '.')
                {
                    if (str[num] == '.')
                    {  
                        if (str[num+1] <= '5' || str[num+1] == '0')
                        {

                        }
                        else if (str[num+1] > '5')
                        {
                            str[num-1] += 1;
                        }
                        while(str[num] != delim)
                        {
                            num++;
                        }
                    }
                    else
                    {
                        printf("%c", str[num]);
                        num++;
                    }
                }
            }
            if (str[num] == delim)
            {
                numDelim++;
            }
            printf("%c", str[num]);
            num++;
        }
    }
}

// int C
// deletes a coma in n.m (1.32; 5.47 etc.)
void intC(int column, char delim, char str[])
{
    int num = 0;
    int numDelim = 1;
    while (str[num] != '\0')
    {
        while (numDelim == column)
        {
            if (str[num] == '.')
            {
                while (str[num] != delim)
                {
                    num++;
                }
            }
            else if (str[num] == delim)
            {
                printf("%c", str[num]);
                num++;
                numDelim++;
                break;
            }            
            else 
            {
                printf("%c", str[num]);
                num++;
            }
        }
        if (str[num] == delim)
        {
            numDelim++;
        }
        printf("%c", str[num]);
        num++;
    }
    
    while (fgets(str, maxlength, stdin))
    {
        num = 0;
        numDelim = 1;
        while (str[num] != '\0')
        {
            while (numDelim == column)
            {
                if (str[num] == '.')
                {
                    while (str[num] != delim)
                    {
                        num++;
                    }
                }
                else if (str[num] == delim)
                {
                    printf("%c", str[num]);
                    num++;
                    numDelim++;
                    break;
                }            
                else 
                {
                    printf("%c", str[num]);
                    num++;
                }
            }
            if (str[num] == delim)
            {
                numDelim++;
            }
            printf("%c", str[num]);
            num++;
        }
    }
}

// NOT WORKING FOR LAST COLUMN
// copy N M
// copy column N to column M
void copyNM(int n, int m, char delim, char str[])
{
    int num = 0;
    int numDelim = 1;
    int numN = 0;
    int numM = 0;
    char arrayN[numN];

    while (str[num] != '\0')
    {
        if (numDelim == n)
        {
            while (str[num] != delim)
            {
                printf("%c", str[num]);
                arrayN[numN] = str[num];
                numN++;
                num++;
            }
        }
        numN = 0;
        if (numDelim == m)
        {
            while (str[num] != delim)
            {
                num++;
            }
            while (arrayN[numN] != '\0')
            {
                printf("%c", arrayN[numN]);
                numN++;
            }
        }
        if (str[num] == delim)
        {
            numDelim++;
        }
        printf("%c", str[num]);
        num++;
    }   
    printf("%s\n", arrayN);
    printf("%d\n", numDelim);
    printf("%s", str);
}

// NOT WORKING FOR LAST COLUMN
// swap N M
// swaps N and M columns
void swapNM (int n, int m, char delim, char str[])
{
    int num = 0;
    int numDelim = 1;
    int numN = 0;
    int numM = 0;
    char arrayN[102] = "";
    char arrayM[102] = "";

    while (str[num] != '\0')
    {
        if (numDelim == n && str[num] != delim)
        {
            arrayN[numN] = str[num];
            numN++;
        }

        if (numDelim == m && str[num] != delim)
        {
            if (str[num] != '\0')
            {
                    arrayM[numM] = str[num];
                    numM++;
            }   
        }
        if (str[num] == delim)
        {
            numDelim++;
        }
        num++;
    }
    num = 0; 
    numN = 0;
    numM = 0;
    numDelim = 1;
    while (str[num] != '\0')
    {
        while (numDelim == n)
        {
            printf("%c", arrayM[numM]);
            numM++;
            if (arrayM[numM] == '\0')
            {
                break;
            }
        }
        while (numDelim == n && str[num] != delim)
        {
            num++;
        }
        while (numDelim == m)
        {
            printf("%c", arrayN[numN]);
            numN++;
            if (arrayN[numN] == '\0')
            {
                break;
            }
        }
        while (numDelim == m && str[num] != delim)
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
        if (str[num] == delim)
        {
            numDelim++;
        }
        printf("%c", str[num]);
        num++;
    }
    while (fgets(str, maxlength, stdin))
    {
        char arrayN[102] = "";
        char arrayM[102] = "";
        num = 0; 
        numN = 0;
        numM = 0;
        numDelim = 1;
        while (str[num] != '\0')
        {
            if (numDelim == n && str[num] != delim)
            {
                arrayN[numN] = str[num];
                numN++;
            }

            if (numDelim == m && str[num] != delim)
            {
                if (str[num] != '\0')
                {
                        arrayM[numM] = str[num];
                        numM++;
                }   
            }
            if (str[num] == delim)
            {
                numDelim++;
            }
            num++;
        }
        num = 0; 
        numN = 0;
        numM = 0;
        numDelim = 1;
        while (str[num] != '\0')
        {
            int len = 0;
            while (numDelim == n)
            {
                printf("%c", arrayM[numM]);
                numM++;
                if (arrayM[numM] == '\0')
                {
                    break;
                }
            }
            while (numDelim == n && str[num] != delim)
            {
                num++;
            }
            while (numDelim == m)
            {
                printf("%c", arrayN[numN]);
                numN++;
                if (arrayN[numN] == '\0')
                {
                    break;
                }
            }
            while (numDelim == m && str[num] != delim)
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
            if (str[num] == delim)
            {
                numDelim++;
            }
            printf("%c", str[num]);
            num++;
        }
    }
}

// move N M
// move the column N before the column M
void moveNM(int n, int m, char delim, char str[])
{
    int num = 0;
    int numDelim = 1;
    char arrayN[102] = "";
    int numN = 0;

    while (str[num] != '\0')
    {
        if (numDelim == n)
        {
            arrayN[numN] = str[num];
            numN++;
        }
        if (str[num] == delim)
        {
            numDelim++;
        }
        num++;
    }
    num = 0;
    numDelim = 1;
    numN = 0;
    while(str[num] != '\0')
    {
        while (numDelim == n)
        {
            num++;
            if (str[num] == delim)
            {
                num++;
                numDelim++;
            }
        }
        while (numDelim == m && arrayN[numN] != '\0')
        {
            printf("%c", arrayN[numN]);
            numN++;
        }
        if (str[num] == delim)
        {
            numDelim++;
        }
        printf("%c", str[num]);
        num++;
    }

    while(fgets(str, maxlength, stdin))
    {
        num = 0;
        numDelim = 1;
        numN = 0;
        char arrayN[102] = "";
        while (str[num] != '\0')
        {
            if (numDelim == n)
            {
                arrayN[numN] = str[num];
                numN++;
            }
            if (str[num] == delim)
            {
                numDelim++;
            }
            num++;
        }
        num = 0;
        numDelim = 1;
        numN = 0;
        while(str[num] != '\0')
        {
            while (numDelim == n)
            {
                num++;
                if (str[num] == delim)
                {
                    num++;
                    numDelim++;
                }
            }
            while (numDelim == m && arrayN[numN] != '\0')
            {
                printf("%c", arrayN[numN]);
                numN++;
            }
            if (str[num] == delim)
            {
                numDelim++;
            }
            printf("%c", str[num]);
            num++;
        }        
    }
}

int whichFunNM(int n, int m)
{

}

// choosing which function will be called with all columns used
int whichFun()
{

}

void selectionRows(int n, int m)
{
    if (n != 0 && m != 0)
    {
        if (n <= m)
        {
            whichFunNM(n, m);
        }
    }
    else 
    {
        whichFun();
    }
}

// error function 
int errorFun()
{
    //stderr = "Wrong Input. Try again!";
    return 1;
}

int main(int argc, char *argv[]) 
{
    int line = 3;
    int column = 2;
    char *delim[102];
    char str[maxlength];
    int n = 1;
    int m = 4;
    char STR[100] = "Cvikaaa";
    int cnum = 0;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-d") == 0)
        {
           *delim = argv[i+1];
        }
        if (strcmp(argv[i], "irow") == 0)
        {
            cnum = getCnum(*delim, str);
            int row = atoi(argv[i+1]);
            irowR(row, cnum, str, *delim); 
        }
        if (strcmp(argv[i], "arow") == 0)
        {
            cnum = getCnum(*delim, str);
            arow(cnum, str, *delim);   
        } 
        if (strcmp(argv[i], "drow") == 0)
        {
            cnum = getCnum(*delim, str);
            int row = atoi(argv[i+1]);
            drowR(row, str);
        }    
        if (strcmp(argv[i], "drows") == 0)
        {
            
        }       
        if (strcmp(argv[i], "icol") == 0)
        {
            
        }   
        if (strcmp(argv[i], "acol") == 0)
        {
            
        }      
        if (strcmp(argv[i], "dcol") == 0)
        {
            
        }  
        if (strcmp(argv[i], "dcols") == 0)
        {
            
        }                        
    }

    // arow(cnum, str, delim);
    // drowR(line, str);
    // drowsNM(n, m, str);
    // icolC(column, delim, str);
    // acol(cnum, str, delim);
    // dcolC(column, cnum, delim, str);
    // dcolsNM(n, m, cnum, delim, str);
    // tolowerC(column, delim, str);
    // toupperC(column, delim, str);
    // roundC(column, delim, str);
    // csetCSTR(column, cnum, delim, STR, str);
    // intC(column, delim, str);
    // copyNM(n, m, delim, str);
    // swapNM(n, m, delim, str);
    // moveNM(n, m, delim, str);



    return 0;
}