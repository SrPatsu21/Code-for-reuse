#ifndef NULL
#define NULL ((void *)0)
#endif

#include "List.h"
#include "Tree.h"

#define ASCII_SIZE 256
#define VOID_CHAR '\0'

int* setPriorityArray(FILE* file)
{
    int* priority = (int*) malloc((sizeof(int)*ASCII_SIZE));
    for (size_t i = 0; i < ASCII_SIZE; i++)
    {
        priority[i] = 0;
    }
    while (!feof(file))
    {
        char c = fgetc(file);
        priority[c]++;
    }
    return priority;
};

LIST* createListOfPriority(int* array)
{
    LIST* list = createList();
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (0 < array[i])
        {
            addHead(list, createNewTree(i, array[i]));
        }        
    }
    quickSort(list);
    return list;
};

TREE* createTreeBasedOnPriority(LIST* list)
{
    TREE* root;
    while (1 < list->size)
    {
        if (2 <= list->size)
        {
            root = createNewTree(0, 0);
            insertOnTree(root, list->head->tree, list->head->prox->tree);
            removeHead(list);
            removeHead(list);
            addTail(list, root);
            quickSort(list);
        }
    }
    return root;
}

void printTree(TREE* tree, int level)
{
    if (tree == NULL)
    {
        return;
    }
    level += 10;

    printTree(tree->right, level);

    printf("\n");
    for (int i = 10; i < level; i++) {
        printf(" ");
    }

    if ('\n' == tree->varchar)
    {
        printf("(%i \\n)", tree->priority);
    }else if (' ' == tree->varchar)
    {
        printf("(%i esp)", tree->priority);
    }else
    {
        printf("(%i %c)", tree->priority, tree->varchar);
    }
    printTree(tree->left, level);
};

void setCodifyTable(char table[ASCII_SIZE][(ASCII_SIZE/2)], TREE* tree, int i, char c[(ASCII_SIZE/2)])
{
    if (tree != NULL)
    {
        if (tree->right == NULL && tree->left == NULL)
        {
            for (int j = 0; j < (ASCII_SIZE/2); j++)
            {
                table[((int) tree->varchar)][j] = c[j];
            }
        }else
        {
            char copy1[(ASCII_SIZE/2)];
            char copy2[(ASCII_SIZE/2)];
            for (size_t j = 0; j < (ASCII_SIZE/2); j++)
            {
                copy2[j] = c[j];
                copy1[j] =  c[j];
            }
            i++;
            copy1[i] = '0';
            setCodifyTable(table, tree->left, i, copy1);
            copy2[i] = '1';
            setCodifyTable(table, tree->right, i, copy2);
        }
    }
};
//! make all values of char vet null
void nullVetChar(char c[(ASCII_SIZE/2)], int size)
{
    for (int i = 0; i < size; i++)
    {
        c[i] = VOID_CHAR;
    }
    
};
//! make all values of char array null
void nullArrayChar(char c[ASCII_SIZE][(ASCII_SIZE/2)], int h, int l)
{
    for (int j = 0; j < h; j++)
    {    
        for (int i = 0; i < l; i++)
        {
            c[j][i] = VOID_CHAR;
        }
    }
};

void printArray(char c[ASCII_SIZE][(ASCII_SIZE/2)], int h, int l)
{
    int count= 0;
    printf("\n");
    for (int j = 0; j < h; j++)
    {    
        if (3 < count)
        {
            printf("\n");
            count = 0;
        }else
        {
            count++;
        }
        printf("(%i | ", j);
        for (int i = 0; i < l; i++)
        {
            printf("%c", c[j][i]);
        }
        printf(")  ");
    }
    printf("\n");
};

void zipFile(FILE* f2read, FILE* f2write, char table[ASCII_SIZE][(ASCII_SIZE/2)])
{
    // int char1 = 0;
    // int count = 0;
    // while (!feof(f2read))
    // {
    //     char* input = table[((int)fgetc(f2read))];
    //     for (int j = 0; VOID_CHAR != input[j]; j++)
    //     {
    //         if ('1' == input[j])
    //         {
    //             char1 += 1;
    //         }
    //         char1 = char1 << 1;
    //         count++;
    //         if (7 == count)
    //         {
    //             char c = (char)char1;
    //             fwrite(&c, 1, 1, f2write);
    //             char1 = 0;
    //             count = 0;
    //         }
            
    //     }
    // }
    // if (0 != count)
    // {
    //     char c = (char)char1;
    //     fwrite(&c, 1, 1, f2write);
    //     char1 = 0;
    //     count = 0;
    // }

    /*
    * by char
    */
    while (!feof(f2read))
    {
        int i = ((int)fgetc(f2read));
        if (i > 0)
        {
            for (int j = 0; VOID_CHAR != table[i][j]; j++)
            {
                if ('1' == table[i][j])
                {
                    fputc('1', f2write);
                }else if ('0' == table[i][j])
                {
                    fputc('0', f2write);
                }
            }
        }
    }
}

void unzipFile(FILE* fzip, FILE* funzip, TREE* tree)
{
    // int helper = 0;
    // TREE* aux = tree;
    // while (!feof(fzip))
    // {  
    //     fread(&helper, 1, 1, fzip);
    //     for (size_t i = 0; i < 8; i++)
    //     {
    //         if (aux->left == NULL || aux->right == NULL)
    //         {
    //             fputc(aux->varchar, funzip);
    //             aux = tree;
    //         }
    //         if (helper&256)
    //         {
    //             aux = aux->right;
    //         }else
    //         {
    //             aux = aux->left;
    //         }
    //         helper = helper << 1;
    //     }
    // }

   /*
   * by char
   */
    TREE* aux = tree;
    char helper = '\0';
    while (!feof(fzip))
    {  
        if (NULL == aux->left || NULL == aux->right)
        {
            fputc(aux->varchar, funzip);
            aux = tree;
        }
        helper = fgetc(fzip);
        if ('1' == helper)
        {
            aux = aux->right;
        }else if ('0' == helper)
        {
            aux = aux->left;
        }
    }
};

int main(void)
{
    FILE* f2read = fopen("./files/1text.txt", "r");
    FILE* f2write = fopen("./files/2compacted", "w");
    int* priority = setPriorityArray(f2read);
    LIST* list = createListOfPriority(priority);
    TREE* tree = createTreeBasedOnPriority(list);
    printTree(tree, 0);

    char table[ASCII_SIZE][(ASCII_SIZE/2)];
    nullArrayChar(table, ASCII_SIZE, (ASCII_SIZE/2));
    char c[(ASCII_SIZE/2)];
    nullVetChar(c, (ASCII_SIZE/2));

    printf("\n");
    setCodifyTable(table, tree, -1, c);
    printArray(table, ASCII_SIZE, (ASCII_SIZE/2));

    /*
    * write file
    */
    rewind(f2read);
    rewind(f2read);
    zipFile(f2read, f2write, table);
    /*
    *   close file
    */ 
    fclose(f2read);
    fclose(f2write);
    /*
    * unzip
    */
    FILE* funzip = fopen("./files/3unzip.txt", "w");
    f2write = fopen("./files/2compacted", "r");
    rewind(f2write);
    rewind(funzip);
    unzipFile(f2write, funzip, tree);
    /*
    *   close file
    */ 
    fclose(f2write);
    fclose(funzip);
    /*
    *   free tree and list
    */
   freeTree(tree);
   freeList(list);
}