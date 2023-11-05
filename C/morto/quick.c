//sort
//find the pivot
// NODE* getPivot(NODE* start, NODE* end)
// {
//     if (start != NULL && end != NULL && start != end)
//     {   
//         NODE* aux = start;
//         NODE* auxt = end;
//         while (aux != auxt && auxt->prox != aux)
//         {
//             aux = aux->prox;
//             auxt = auxt->prev;
//             if (aux->prev == auxt)
//             {
//                 auxt = aux;
//             }
//         }
//         return auxt;
//     }else
//     {
//         return end;
//     }
// }
//start is the initial position 0
//end is the size of the array -1
// void quickSort(NODE* start, NODE* end) 
// {
//     int b1 = 1, b2 = 1, b3 = 1;
//     NODE* i = start;
//     NODE* j = end;
//     NODE* pivot =  end;
//     printf("%s \t%s \t%s\n", i->name, j->name, pivot->name);    
//     //if i > j means that i passed the j pos


//     //evitar j e i = NULL
//     //i <= j ou seja nao pode i > j
//     while (j != i)
//     {       
//         while (isSmaller(i, pivot))
//         {
//             if (i == NULL)
//             {
//                 i = start;
//             }else
//             {
//                 i = i->prox;
//             }
//         }
//         while (isSmaller(pivot, j) && j != i)
//         {
//             if (j == NULL)
//             {
//                 j = end;
//             }else
//             {
//                 j = j->prev;
//             }
//         }
//         //i <= j ou seja nao pode i > j
//         if (j != i)
//         {
//             swap(i, j);
//             //i->prox
//             if (i == NULL)
//             {
//                 i = start;
//             }else
//             {
//                 i = i->prox;
//             }
//             //j->prev
//             if (j == NULL)
//             {
//                 j = end;
//             }else{
//                 j = j->prev;
//             }
//         }
//     }
//     if (j == NULL)
//     {
//         j = end;
//     }
//      if (i == NULL)
//     {
//         i = start;
//     }
//     //start < j
//     if (j != start)
//     {
//         //call int the left side of pivot
//         quickSort(start, j);
//     }
//     //i < end
//     if (i != end)
//     {
//         //call int the right side of pivot
//         quickSort(i, end);
//     }
// }