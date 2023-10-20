#include <stdio.h>
// #include <string.h>
#include <ctype.h>

void initNumArray(int arrayNum[], int arraySize);
void initCharArray(char arrayChar[], int arraySize);

void sortNumAsc(int arrayNum[], int size);
void sortNumDesc(int arrayNum[], int size);

void sortCharAsc(char arrayChar[], int size);
void sortCharDesc(char arrayChar[], int size);

void printNumArray(int arrayNum[], int size, char sortBy);
void printCharArray(char arrayChar[], int size, char sortBy);

int main()
{
    int arraySize;
    char arrayType;
    char sortBy;

    do
    {
        printf("Insert array size: "); // insert array size greater than 0
        scanf("%d", &arraySize);
    } while (arraySize <= 0);

    int arrayNum[arraySize];
    char arrayChar[arraySize];

    // Insert array type
    do
    {
        printf("Insert array type Numeric(N)/Char(C): ");
        scanf("%c"); // clean input buffer
        scanf("%c"); // clean input buffer
        scanf("%c", &arrayType);
        arrayType = toupper(arrayType);
        if (arrayType == 'N' || arrayType == 'C')
        {
            break;
        }
    } while (arrayType != 'N');

    if (arrayType == 'N')
    {
        initNumArray(arrayNum, arraySize);
    }
    else if (arrayType == 'C')
    {
        initCharArray(arrayChar, arraySize);
    }

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
        if (arrayType == 'N')
        {
            sortNumAsc(arrayNum, arraySize);
        }
        else
        {
            sortCharAsc(arrayChar, arraySize);
        }
        break;
    case 'D':
        if (arrayType == 'N')
        {
            sortNumDesc(arrayNum, arraySize);
        }
        else
        {
            sortCharDesc(arrayChar, arraySize);
        }
        break;
    default:
        break;
    }

    if (arrayType == 'N')
    {
        printNumArray(arrayNum, arraySize, sortBy);
    }
    else
    {
        printCharArray(arrayChar, arraySize, sortBy);
    }

    return 0;
}

void initNumArray(int arrayNum[], int arraySize)
{

    int elementInput;

    // Insert element array
    for (int j = 0; j < arraySize; j++)
    {
        printf("Insert element #%d: ", j);
        scanf("%d", &elementInput);
        arrayNum[j] = elementInput;
    }

    // Print inserted array
    printf("> Array: [ ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", arrayNum[i]);
    }
    printf("]");
}

void initCharArray(char arrayChar[], int arraySize)
{

    int elementInput;

    // Insert element array
    for (int j = 0; j < arraySize; j++)
    {
        printf("Insert element #%d: ", j);
        scanf("%c");
        scanf("%c");
        scanf("%c", &elementInput);
        arrayChar[j] = elementInput;
    }

    // Print inserted array
    printf("> Array: [ ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%c ", arrayChar[i]);
    }
    printf("]");
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

void sortCharAsc(char arrayChar[], int size)
{
    for (int i = 0; i < size - 1; i++)
    { // outer loop untuk tiap elemen di array (e1, e2, e3, ... , dst)
        for (int j = 0; j < size - i - 1; j++)
        { // inner loop untuk perbandingan dengan elemen di sebelahnya
            if (arrayChar[j] > arrayChar[j + 1])
            {
                int temp = arrayChar[j];
                arrayChar[j] = arrayChar[j + 1];
                arrayChar[j + 1] = temp;
            }
        }
    }
}

void sortCharDesc(char arrayChar[], int size)
{
    for (int i = 0; i < size - 1; i++)
    { // outer loop untuk tiap elemen di array (e1, e2, e3, ... , dst)
        for (int j = 0; j < size - i - 1; j++)
        { // inner loop untuk perbandingan dengan elemen di sebelahnya
            if (arrayChar[j] < arrayChar[j + 1])
            {
                int temp = arrayChar[j];
                arrayChar[j] = arrayChar[j + 1];
                arrayChar[j + 1] = temp;
            }
        }
    }
}

void printNumArray(int arrayNum[], int size, char sortBy)
{
    if (sortBy == 'A')
    {
        printf("> Sorted array (Ascending): [ ");
    }
    else
    {
        printf("> Sorted array (Descending): [ ");
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrayNum[i]);
    }

    printf("]");
}

void printCharArray(char arrayChar[], int size, char sortBy)
{
    if (sortBy == 'A')
    {
        printf("> Sorted array (Ascending): [ ");
    }
    else
    {
        printf("> Sorted array (Descending): [ ");
    }

    for (int i = 0; i < size; i++)
    {
        printf("%c ", arrayChar[i]);
    }

    printf("]");
}