#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int ReadMap(char lines[5][12], int *row, int *column)
{
    int i, j;
    char defaultFilename[] = "testcase01.txt", filename[100];
    FILE *f;
    printf("Please enter map filename: (default = %s)\n", defaultFilename);
    gets(filename);
    if (filename[0] == 0)
        strcpy(filename, defaultFilename);
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }
    for (i = 0; i < 5;i++)
        fgets(lines[i], 12, f);
    fclose(f);
    for (i = 0; i < 5;i++)
        for (j = 0;j < 10;j++)
            if (lines[i][j] == '0')
            {
                lines[i][j] = '1';
                *row = i;
                *column = j;
                return -1;
            }
    printf("Start position (0 character) not found!");
    return 0;
}
void ShowMap(char lines[5][12], int row, int column, char* message)
{
    int i, j;
    system("cls");
    printf("Press ESC to exit.\n\n");
    for (i = 0;i < 5;i++)
    {
        for (j = 0; j < 10;j++)
            if ((i == row) && (j == column))
                printf("0");
            else
                printf("%c", lines[i][j]);
        printf("\n");
    }
    printf("\n%s\n", message);
    strcpy(message, "");
}
int IsAnyFoodExists(char lines[5][12])
{
    int i, j;
    for (i = 0;i < 5;i++)
        for (j = 0; j < 10;j++)
            if (lines[i][j] == '*')
                return -1;
    return 0;
}
int TryMove(char lines[5][12], int row, int column, char *message)
{
    if ((row < 0) || (row >= 5) || (column < 0) || (column >= 10))
    {
        strcat(message, "\nOut of border!");
        return 0;
    }
    if (lines[row][column] == '#')
    {
        strcat(message, "\nYou can't move to right! There is an obstacle.");
        return 0;
    }
    if (lines[row][column] == '*')
    {
        strcat(message, "\nPacman ate food!");
    }
    lines[row][column] = '1';
    return -1;
}
int main()
{
    char lines[5][12];
    char message[100];
    int ch, row, column;
    strcpy(message, "Welcome!");
    if (ReadMap(lines, &row, &column) != 0)
    {
        do
        {
            ShowMap(lines, row, column, message);
            if (IsAnyFoodExists(lines) == 0)
            {
                printf("Nothing to eat\n");
                break;
            }
            ch = getch();
            if ((ch == 0) || (ch == 224))
                ch = getch();
            if (ch == 27) /* ESC */
                break;
            if (ch == 72) /* Up Arrow */
            {
                strcpy(message, "User: Up Arrow");
                if (TryMove(lines, row - 1, column, message))
                    row--;
            }
            else if (ch == 80) /* Down Arrow */
            {
                strcpy(message, "User: Down Arrow");
                if (TryMove(lines, row + 1, column, message))
                    row++;
            }
            else if (ch == 75) /* Left Arrow */
            {
                strcpy(message, "User: Left Arrow");
                if (TryMove(lines, row, column - 1, message))
                    column--;
            }
            else if (ch == 77) /* Right Arrow */
            {
                strcpy(message, "User: Right Arrow");
                if (TryMove(lines, row, column + 1, message))
                    column++;
            }
        }
        while (1);
    }
    printf("\nPress ENTER key to continue.");
    getchar();
    return 0;
}

