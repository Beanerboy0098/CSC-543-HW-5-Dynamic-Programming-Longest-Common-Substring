/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, aavascript, Pascal, HTML, CSS, aS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream> 
#include <string.h>
using namespace std;

string longestcommonsubstringproc(char* fstring, char* sstring)

{
    int length = strlen(fstring); /*strlen is a string method that returns the length of the string*/
    int table[length + 1][length + 1]; /*Since both strings are the same length, one strings length can help us determine another strings length*/
    int greatestnum = 0; 
    int placement = 0;
    string longestsubstring = "";
                                    /*Establishing variables throughout this method including final substring*/
    
     for(int a = 0; a < (length + 1); a++)
    {
        for(int b = 0; b < (length + 1); b++)
        {
            if(a == 0 || b == 0)              
            {
                table[a][b] = 0;                    
            }                               /*While going through the two strings in question, if either a or b = 0 then the point in the graph is changed to a zero*/
            else if (fstring[a - 1] == sstring[b - 1])/*In order to figure out if a letter matches in the commonsubstring, I implented a condition to determine if a had the same chracter as b if it did then add one to greatestnum then compare it to beforenum, this is so that when the graph is developed dynamically it keeps adding*/
            {
                table[a][b] = table[a - 1][b - 1] + 1;
                int beforeNum = greatestnum;
                greatestnum = max(greatestnum, table[a][b]);
                if(greatestnum > beforeNum)       /*Then if beforenum which keeps track of greatestnum ever changes then it changes placement to equal one less of a's current value*/
                {
                    placement = a - 1;
                }
                
            }
            else
            {
                table[a][b] = 0;
            }
        }
    }
    
    for(int c = 0; c < greatestnum; c++)
    {
        longestsubstring = fstring[placement] + longestsubstring;
        placement--;
    }
    
    
    return longestsubstring;
    /*To finsh the longestsubstring goes through the total number of common chracters and simply adds each chracter into the substring making the longest common substring*/
}


void displaygraph(char x[], char y[], int sizeoffstring, int sizeofsstring, int** graph)

{
    cout << "Graph: \n";
    cout << "  ";
    for (int a = 0; a < sizeoffstring; a++)
    {
        cout << x[a]<< " ";
    }
    cout << "\n";

    for (int i = 0; i < sizeofsstring; i++)
    {
        for (int a = 0; a < sizeoffstring; a++)
        {
            if(a == 0)
            cout << y[i] << " ";
            cout << graph[i][a] << " ";
        }
        cout << "\n";
    }
    
}

int main()
{
    char fstring[] = "ABABC";
    char sstring[] = "BABCA";
    
    int fstringlen = (sizeof(fstring) / sizeof(char)) -1;
    int sstringlen = (sizeof(sstring) / sizeof(char)) -1; /*I essentially had to redo the graph making process twice as I couldn't figure out how to actually print the graph in the string method so I did it in the main method*/
    
    int**graph = new int* [sstringlen];
    for (int b = 0; b < sstringlen; b++)
    {
        graph[b] = new int[fstringlen];
    }
    
    int xgraph = 0;
    int ygraph = 0;
    
    for (int a = 0; a < sstringlen; a++)
    {
        for (int b = 0; b < fstringlen; b++)
        {
            if (sstring[a] == fstring[b])
            {
                if (a == 0 || b == 0)
                    graph[a][b] = 1;
                else
                    graph[a][b] = graph[a - 1][b - 1] + 1;
            }
            else
                graph[a][b] = 0;

            if (graph[a][b] > xgraph)
            {
                xgraph = graph[a][b];
                ygraph = b;
            }
        }
    }
    /*Though a different method, both ways of building the graph are very simalar to one another*/
    displaygraph(fstring, sstring, fstringlen, sstringlen, graph);

    
    string evaulation = longestcommonsubstringproc(fstring, sstring);
    
    int lengthofsubstring = evaulation.length(); /*Figuring out the length of the string*/
    
    cout << "The longest common substring of "  << fstring << " and " << sstring << " is: " << evaulation << " with a length of " << lengthofsubstring << endl;
    
    return 0; 
}

