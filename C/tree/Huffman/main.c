#include "Tree.h"

FILE* openFile();



FILE* openFile()
{
    FILE* fptr;
 
    fptr = fopen("text.txt", "r");
 
    return fptr;
}

FILE* writeFile()
{
    FILE* fptr;
 
    fptr = fopen("compacted.txt", "w");
 
    return fptr;
}

int main(void)
{

}