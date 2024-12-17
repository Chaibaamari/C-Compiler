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
    char Const[20];
    struct TS *Next;
} TS;
// Define the FormatType structure
typedef struct FormatType
{
    char specifier[100]; // Format specifier (e.g., "%d")
    char type[100];      // Corresponding type (e.g., "Integer", "Float")
} FormatType;

// Create an array of FormatType mappings
FormatType formatTypes[] = {
    {"%d", "Integer"}, // Integer format specifier
    {"%f", "Float"},   // Float format specifier
};


// Pointer to the head of the linked list
TS *head = NULL;

// Function to insert a new symbol into the symbol table
void InsertI_In_Ts(char *NomEntite, char *CodeEntite, char *Type, char *Const)
{
    TS *current = head;
    // check if we have a varibale  that have already declared
    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            return;
        }
        if(current->Next == NULL) break;
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
    strcpy(newSymbol->Const, Const);

    // Insert the new symbol at the head of the list
    newSymbol->Next = NULL;
    if(head == NULL){
        head = newSymbol;
    } else {
        current->Next = newSymbol;
    }
}
void setConst_Finel(char *NomEntite)
{
    TS *current = head;
    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            if (strcmp(current->Type, "/") == 0)
            {
                strcpy(current->Const, "Oui");
                return;
            }
        }
        current = current->Next;
    }
}

void Modify_Const(char *NomEntite){
    TS *current = head;
    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            if (strcmp(current->Const, "Oui") == 0)
            {
                printf("Error Symantique : You Can't change the const '%s' Value\n" , NomEntite);
                return;
            }
        }
        current = current->Next;
    }
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

int searchFullType(const char *NomEntite)
{
    TS *current = head;
    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            if(strcmp(current->Type , "/") == 0){
                return 0;
            }
            return 1;
        }
        current = current->Next;
    }
    return -1;
}

void handleDeclaration(char *identifier, char *type)
{
    if (searchFullType(identifier) == 0){
        InsertType(identifier, type);
    }else{
        printf("Error: Variable '%s' is already declared in the same Programme.\n", identifier);
    }
}
void Non_declare(char *NomEntite , int nbLigne)
{
    if (searchFullType(NomEntite) == 0)
    {
        printf("Error Symantique : variable '%s' non declare a la  ligne '%d' \n", NomEntite , nbLigne);
    }
}

void divide_zero(int divider , int nb_Ligne){
    if(divider == 0){
        printf("Erreur Semantique: Division par zero dans la ligne %d \n", nb_Ligne);
    }else{
        return;
    }
}
char *getType(char *NomEntite){
    char *TYPE = NULL;
    TS *current = head;
    while (current != NULL)
    {
        if (strcmp(current->NomEntite, NomEntite) == 0)
        {
            TYPE = current->Type;
            return TYPE;
        }
        current = current->Next;
    }
    return TYPE;
}
void Incompatible_type(char *type1, char *type2  , int nbLigne){
    if(strcmp(type1 , type2) != 0){
        printf("Error Symantique : Incompatible Type '%s' <> '%s' At Line '%d'\n", type1, type2 , nbLigne);
    }
}

int CheckForm(char string[])
{
    int taille = strlen(string);
    int nbrFormat = 0;
    int i;
    for ( i = 0; i < taille; i++)
    {
        if (string[i] == '%')
        {
            if (i + 1 < taille)
            {
                if (string[i + 1] == 'd' || string[i + 1] == 'f' || string[i + 1] == 's')
                {
                    nbrFormat++;
                }
                else
                {
                    printf("Invalid format specifier detected: %c\n", string[i + 1]);
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
    }
    return nbrFormat;
}
int checkCompatibleFormat(char format[], char NomEntite[])
{
    TS *current = head;
    char cpy[100];                     // Use a larger buffer for the format string
    int position = searchPositionInTable(NomEntite); // Assuming this function searches for the entity
    int i, j;

    // If position is not valid, return -1 immediately
    if (position == -1)
    {
        return -1; // Entity not found in the table
    }

    int TPR = strlen(format);
    for (i = 0; i < TPR; i++)
    {
        if (format[i] == '%') // Format specifier found
        {
            // Handle format specifiers
            if (format[i + 1] == 'd')
            {
                strcpy(cpy, "%d");
            }
            else if (format[i + 1] == 'f')
            {
                strcpy(cpy, "%f");
            }
            else if (format[i + 1] == 's')
            {
                strcpy(cpy, "%s");
            }
            else
            {
                // Invalid format specifier
                return -1;
            }

            // Now compare the format specifier with the entity's type
            while (current != NULL)
            {
                if (strcmp(current->NomEntite, NomEntite) == 0)
                {
                    // Iterate over the FormatType array to find the matching type
                    for (j = 0; j < sizeof(formatTypes) / sizeof(formatTypes[0]); j++)
                    {
                        if (strcmp(cpy, formatTypes[j].specifier) == 0)
                        {
                            // Compare the corresponding type with the entity's type
                            if (strcmp(formatTypes[j].type, current->Type) == 0)
                            {
                                return 1; // Compatible format
                            }
                            else
                            {
                                return 0; // Incompatible format
                            }
                        }
                    }
                }
                current = current->Next; // Move to the next entity in the list
            }
        }
    }

    // If no compatible format found
    return -1;
}

void SymantiqueFormatage(char NomEntite1[] , char NomEntite2[] , int nbLigne){
    if (CheckForm(NomEntite1) == 0)
    {
        printf("Error Symantique : Foramatage Non valid a la ligne '%d'\n", nbLigne);
    }
    else
    {
        Non_declare(NomEntite2 , nbLigne);
        if (checkCompatibleFormat(NomEntite1, NomEntite2) == 1)
        {
            printf("elle est valid");
            }
            else
            {
                printf("Error Symantique : compatible de Foramatage Non valid a la ligne '%d'\n", nbLigne);
            }
    }
}
