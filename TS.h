#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TS
{
    char NomEntite[20];
    char CodeEntite[20];
    char Type[20];
    struct TS *Next;
} TS;

// inserer
// afficher
// check if exist or not
TS *head;

// Function to insert into the Symbol Table
void InsertI_In_Ts(char *NomEntite, char *CodeEntite, char *Type)
{
    TS *current = head;

    // Check if the symbol already exists
    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            printf("This symbol: %s already exists in the Symbol Table.\n", NomEntite);
            return;
        }
        current = current->Next;
    }

    // Allocate memory for the new symbol
    TS *NewTS = (TS *)malloc(sizeof(TS));
    if (NewTS == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // Copy the values into the new node
    strcpy(NewTS->NomEntite, NomEntite);
    strcpy(NewTS->CodeEntite, CodeEntite);
    strcpy(NewTS->Type, Type);
    NewTS->Next = head; // Insert at the beginning of the list

    head = NewTS; // Update the head pointer
    // printf("Inserted: Name = %s, Type = %s, Code = %s\n", NomEntite, Type, CodeEntite);
}

// Function to display the Symbol Table
void displaySymbolTable(){
    printf("\nSymbol Table:\n");
    printf("Name\t\tCode\t\tType\n");
    printf("-----------------------------------------\n");

    TS *current = head;
    while (current != NULL)
    {
        printf("%-15s%-15s%-15s\n", current->NomEntite, current->CodeEntite, current->Type);
        current = current->Next;
    }
}
