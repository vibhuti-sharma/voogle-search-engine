/*****  A SIMPLE SEARCH ENGINE ******
*  Accepts file or foldername and a word to be searched for.
*   - In case of file, it finds the word in given file using special regular
*     expression searchand display the line of occerrence.
*   - In case of folder, it reads each .txt file and tries to find the given word
*     using regular expression search.
*   Also displays total number of occerence of word in each file.
*
*
*   Copyleft © by Vibhuti Sharma :)
*    All rights are not researved.
*/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    //variables
    char word[255];
    char dir[255];
    char f_name[255];
    struct dirent *ep;
    DIR *dp;
    int total_files = 0, total_files_found = 0;

    print_logo();

    if(argc == 2) {
   //     strcpy(dir, argc[1]);
    } else {
        printf("\nEnter the path for search (example: C:\\hello):");
        gets(dir);//gets the directory name from the user
    }

    printf("\n\nEnter the word to be searched for :: \n -> Complete word (example: hello) \n -> Multiple words (example: He wrote) \n -> Wildcards(example: Hel*, He*o)\n\n");
    gets(word);//gets a character from stdin

    if(word[0]=='\0' || strcmp(word, "")==0) {
        do {
            printf("\nError occured while reading the search word. Please enter correct search word:");
            gets(word);//gets a character from stdin
        }while(word[0]=='\0' || strcmp(word, "")==0);
    }

    dp=opendir(dir);//opens the directory stream fr reading

    if(dp!=NULL)
    {
        while(ep=readdir(dp))//reads the current directory from the directory stream
        {
            if(seaach_word(ep->d_name, ".txt")) //function returns 1 if file is of .txt extension
            {
                strcpy(f_name, dir);
                strcat(f_name, "\\");
                strcat(f_name, ep->d_name);
                if(search_file(f_name, word)) {
                    total_files_found = total_files_found + 1;
                }
                total_files = total_files + 1;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
        printf("\nNumber of files searched for word:\t%d", total_files);
        printf("\nNumber of files in which word found:\t%d\n\n", total_files_found);
    }
    else
    {
        search_file(dir, word);
    }
    (void)closedir(dp);//closes the directory stream

    return 0;
}


/**
* Search a word in given file.
* Opens the file and read line by line. For each line it than
* searches the work using search() function.
*/
int search_file(char *file_name,char *word)
{
    char message[150],buffer[150];
    int res=0;
    char ch;
    FILE *fp; //declare a file pointer

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
    printf("\n[%s]", file_name);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
    printf("\n\t");

    fp = fopen(file_name,"r");//read mode
    if(fp == '\0')
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
        printf("\nSorry, the file you mentioned [%s] does not exists.\n\n", file_name);
        return 0;
    }
    while(fgets(buffer,150,fp))//gets a string from a stream
    {
        res = res + search(buffer,word);//function call
    }
    fclose(fp);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);

    if(res == 0)
    {
        puts("\n\tword not found");
    }
    else
    {
        printf("\n\t[Total occurrence of word: %d]", res);
    }

    printf("\n");
    return res;
}



/**
* Search a text in given string. Returns 0 if string
* not found and 1 in case it is found.
* Accepts regular expression like he*lo.
*/
int seaach_word(char *a,char *word)
{

    int i,j,k,x,p,ret=0;
    for(i=0; i<strlen(a); i++)
    {


        for(x=0,j=i,k=0; k<strlen(word); j++,k++)
        {
            if(a[j]==word[k])
            {
                x++;
                continue;
            }
            else if(word[k] == '*')
            {
                for(; j<strlen(a)&&a[j]!=word[k+1]&&a[j]!=32; j++)
                {
                }
                j--;
                x++;
                continue;
            }
            else
                break;
        }
        if(x==strlen(word))
        {
            return 1;


        }
    }

    return 0;
}



/**
* Search a text in given string and prints it in
* highlighted colors in case word is match.
*/
int search(char *a, char *word)
{
    int ret=0;
    int i,j,k,x,p,m=0;

    for(i=0; i<strlen(a); i++)
    {
        for(x=0,j=i,k=0; k<strlen(word); j++,k++)
        {
            if(word[k] == '?' || a[j]==word[k]|| a[j]==word[k]+32)//for matching wildcard '?',exact words and uppercase words
            {
                x++;
                continue;
            }
            else if(word[k] == '*')//for * wildcard(example-hel*)
            {
                for(; j<strlen(a) && a[j] != word[k+1] &&a[j]!=32; j++)
                {
                }
                j--;
                x++;
                continue;
            }
            else
                break;
        }
        if(x==strlen(word))//calculates the lenth of word
        {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);

            //print first part of string in default color
            for(p=m; p<i; p++)
            {
                putch(a[p]);
            }
            //print matched word string in hightlighted color
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
            for(; p<j; p++)
            {
                putch(a[p]);
                m=j;

            }
            ret = ret + 1;
        }

    }
    if(ret > 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
        printf("\n\t");
    }
    return ret;//exits from the current executing function to the calling function,returning the value ret
}

int print_logo()
{

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

 printf("\n\t\t\t__      __               _      ");
 printf("\n\t\t\t\\ \\    / /              | |     ");
 printf("\n\t\t\t \\ \\  / /__   ___   __ _| | ___ ");
 printf("\n\t\t\t  \\ \\/ / _ \\ / _ \\ / _` | |/ _ \\");
 printf("\n\t\t\t   \\  / (_) | (_) | (_| | |  __/");
 printf("\n\t\t\t    \\/ \\___/ \\___/ \\__, |_|\\___|");
 printf("\n\t\t\t                    __/ |       ");
 printf("\n\t\t\t                   |___/       ");
 printf("\n");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);

}
