#include "Tree.h"

int openfile();



int openfile()
{
    FILE* fptr;
 
    fptr = fopen("file.txt", "r");
 
    return fptr;
}

int main(void)
{

}