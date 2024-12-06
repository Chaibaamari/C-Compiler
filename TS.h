#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for the symbol table
typedef struct TS
{
    char NomEntite[20];
    char CodeEntite[20];
    char Type[20];
    char Const[5];
    struct TS *Next;
} TS;

// Pointer to the head of the linked list
TS *head = NULL;

// Function to insert a new symbol into the symbol table
void InsertI_In_Ts(char *NomEntite, char *CodeEntite, char *Type, bool Const)
{
    TS *current = head;
    // check if we have a varibale  that have already declared
    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            fprintf(stderr, "Error: Variable '%s' is already declared in the same Programme.\n", NomEntite);
            return ;
        }
        current = current->Next;
    }
    // Allocate memory for the new symbol
    TS *newSymbol = (TS *)malloc(sizeof(TS));
    if (newSymbol == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // add New one in Ts table
    strcpy(newSymbol->NomEntite, NomEntite);
    strcpy(newSymbol->CodeEntite, CodeEntite);
    strcpy(newSymbol->Type, Type);
    strcpy(newSymbol->Const, Const ? "true" : "false");

    // Insert the new symbol at the head of the list
    newSymbol->Next = head;
    head = newSymbol;
}

void displaySymbolTable()
{
    printf("\nSymbol Table:\n");
    printf("============================================================================================\n");
    printf("%-20s%-20s%-20s%-10s\n", "NomEntite", "CodeEntite", "Type", "Const");
    printf("============================================================================================\n");

    TS *current = head;
    while (current != NULL)
    {
        printf("%-20s%-20s%-20s%-20s\n", current->NomEntite, current->CodeEntite, current->Type, current->Const);
        current = current->Next;
    }
    printf("============================================================================================\n");
} 

// Function to search for a symbol by its NomEntite and return its position
int searchPositionInTable(char *NomEntite)
{
    int position = 0;
    TS *current = head;

    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            return position;
        }
        current = current->Next;
        position++;
    }

    return -1;
}

void InsertType(char *NomEntite, char *Type)
{
    int position = searchPositionInTable(NomEntite);
    if (position != -1)
    {
        TS *current = head;
        int currentPos = 0;

        while (current != NULL)
        {
            if (currentPos == position)
            {
                strcpy(current->Type, Type);
                return;
            }
            current = current->Next;
            currentPos++;
        }
    }
    else
    {
        printf("Symbol '%s' not found in the symbol table.\n", NomEntite);
    }
}
// we dont need this now 
// int searchFullName(char *NomEntite)
// {
//     TS *current = head;
//     while (current != NULL)
//     {
//         if (strcmp(current->NomEntite, NomEntite) == 0)
//         {
//             return 1;
//         }
//         current = current->Next;
//     }
//     return 0;
// }
int searchFullType(const char *TypeEntite)
{
    TS *current = head;
    while (current != NULL)
    {
        if (strcmp(current->Type, TypeEntite) == 0)
        {
            return 1;
        }
        current = current->Next;
    }
    return 0;
}

// void SymantiquePart_Declaration()
// i wanna create a function here that handle all the Error symantique
/*
like for instence : switch 
                        case: 'double déclaration'
                        case : 'non déclaré'
                        case : compatibilité
                        ......




*/
