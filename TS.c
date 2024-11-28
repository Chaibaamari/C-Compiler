#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TS
{
    char NomEntité[20];
    char CodeEntité[20];
    char Type[20];
    char Const;

    struct TS *Next;
} TS;

// inserer
// afficher
// check if exist or not
TS *head;

void InsertI_In_Ts(NomEntité, CodeEntité, Type)
{
    TS *current = head;
    // check if the Symbole Exist Or not
    while (current != NULL)
    {
        if (strcmp(current->NomEntité, NomEntité) == 1)
        {
            printf("this Symbole : %s Is Already Exist in TS", NomEntité);
            return exit;
        }

        current = current->Next;
    }

    TS *NewTS = (TS *)malloc(sizeof(TS));

    strcpy(NewTS->NomEntité, NomEntité);
    strcpy(NewTS->CodeEntité, CodeEntité);
    strcpy(NewTS->Type, Type);
    NewTS->Next = head; // Insert at the beginning of the list

    head = NewTS; // Update the head pointer
    printf("Inserted: %s, Type: %s, Scope: %d\n", NomEntité, CodeEntité, Type);
}

void displaySymbolTable()
{
    printf("\nSymbol Table:\n");
    printf("Name\t\tType\t\tScope\n");
    printf("-----------------------------------------\n");
    TS *current = head;
    while (current != NULL)
    {
        printf("%-15s%-15s%d\n", current->NomEntité, current->CodeEntité, current->Type);
        current = current->Next;
    }
}

