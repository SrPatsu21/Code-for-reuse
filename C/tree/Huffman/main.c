#include "Tree.h"

FILE* openfile();



FILE* openfile()
{
    FILE* fptr;
 
    fptr = fopen("file.txt", "r");
 
    return fptr;
}

int main(void)
{

}