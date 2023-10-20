#include <stdio.h>
// #include <string.h>
#include <ctype.h>

void sortNumAsc(int arrayNum[], int size);
void sortNumDesc(int arrayNum[], int size);
void printArray(int arrayNum[], int size, char sortBy);

int main()
{
    int arraySize;

    do
    {
        printf("Insert arrayNum size: ");  // insert array size greater than 0
        scanf("%d", &arraySize);
        scanf("%c");
    } while (arraySize <= 0);



    int arrayNum[arraySize];
    int elementInput;
    char sortBy;

    // Insert element array
    for (int j = 0; j < arraySize; j++)
    {
        printf("Insert element #%d: ", j);
        scanf("%d", &elementInput);
        arrayNum[j] = elementInput;
    }

    // Print inserted array
    printf("Array: [ ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", arrayNum[i]);
    }
    printf("]");

    // Insert sorting type
    do
    {
        printf("\nInsert sorting type Ascending(A)/Descending(D): ");
        scanf("%c"); // clean input buffer
        scanf("%c"); // clean input buffer
        scanf("%c", &sortBy);
        sortBy = toupper(sortBy);
        if (sortBy == 'A' || sortBy == 'D')
        {
            break;
        }
    } while (sortBy != 'A');

    // Invoke function sort by type
    switch (sortBy)
    {
    case 'A':
        sortNumAsc(arrayNum, arraySize);
        break;
    case 'D':
        sortNumDesc(arrayNum, arraySize);
        break;
    default:
        break;
    }

    printArray(arrayNum, arraySize, sortBy);

    return 0;
}

void sortNumAsc(int arrayNum[], int size)
{

    for (int i = 0; i < size - 1; i++)
    { // outer loop untuk tiap elemen di array (e1, e2, e3, ... , dst)
        for (int j = 0; j < size - i - 1; j++)
        { // inner loop untuk perbandingan dengan elemen di sebelahnya
            if (arrayNum[j] > arrayNum[j + 1])
            {
                int temp = arrayNum[j];
                arrayNum[j] = arrayNum[j + 1];
                arrayNum[j + 1] = temp;
            }
        }
    }
}

void sortNumDesc(int arrayNum[], int size)
{

    for (int i = 0; i < size - 1; i++)
    { // outer loop untuk tiap elemen di array (e1, e2, e3, ... , dst)
        for (int j = 0; j < size - i - 1; j++)
        { // inner loop untuk perbandingan dengan elemen di sebelahnya
            if (arrayNum[j] < arrayNum[j + 1])
            {
                int temp = arrayNum[j];
                arrayNum[j] = arrayNum[j + 1];
                arrayNum[j + 1] = temp;
            }
        }
    }
}

void printArray(int arrayNum[], int size, char sortBy)
{
    if (sortBy == 'A')
    {
        printf("Sorted arrayNum (Ascending): [ ");
    }
    else
    {
        printf("Sorted arrayNum (Descending): [ ");
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrayNum[i]);
    }

    printf("]");
}