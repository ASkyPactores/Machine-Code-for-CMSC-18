#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//function prototypes
void printTree();
void playSong();
void printLyrics(char num[]);

//Function to print the main menu to the screen
void mainMenu() {
    int i, j, spc; //variables initialization

    //Prints hollow rectangle to contain texts
    for (i=1; i<=15; i++){
        //places "Happy Holidays!" at the center
        if (i==7) {
            printf("*\t");
            for (spc=0; spc<=3; spc++) { //prints 3 spaces before the text
                printf(" ");
            }
            printf("HAPPY HOLIDAYS!\t");
            for (spc=0; spc<=6; spc++) { //prints 6 spaces after the text
                printf(" ");
            }
            printf("*\n");
        }
        if (i==9) {
            printf("*  Please input your desired action:   *\n"); //prompts user to input action.
        }
        if (i==10) { //prints list of valid actions
            printf("*\t1. Print a Christmas Tree      *\n");
            printf("*\t2. Play Karaoke\t\t       *\n");
        }
        if (i==13) {
            printf("*    Press esc key to exit program.    *\n");
        }
        for (j=1; j<=40; j++){
            if(i==1||i==15||j==1||j==40){ //prints '*' to form the border of the hollow rectangle
                printf("*");
            }
            else{
                printf(" "); //prints space inside the hollow rectangle
            }
        }
    printf("\n");
    }
}

int main() {
    system("color 02"); //changes the font color in the console to green

    //Infinite loop while the input is invalid
    while (1) {
    mainMenu(); //calls the mainMenu function to display the main menu
    printf("Action: ");
    char inp = getch(); //records keyboard input without pressing enter
    if (inp == '1') {
        printTree(); //calls function to print christmas tree when user presses '1'
    }
    else if (inp == '2') {
        playSong(); //calls function to play song when the user presses '2'
    }
    else if (inp == 27) { //program exits when the esc key is pressed
        system("cls"); //clear console
        printf("\nExiting Program...\n");
        exit(0); //zero exit value denotes that the program exits normally
    }
    else { //prompts user to input desired action again
        system("cls");
        printf("\nInput not recognized. Try again:\n\n");
        }
    }
    return 0;
}

//Function to display a christmas tree accompanied with a background music
void printTree() {
    system("cls"); //clears the previously printed texts
    int numrow = 12, j, i; //variable initialization
    printf("\n"); //pushes the tree one line downwards

    //Loop which prints the triangular christmas tree
    for(i=1; i<=numrow; i++)
        {
            if (i == 8) { //prints the text at the middle of the tree
                printf("\n\t\tHAPPY HOLIDAYS!!\n\n");
                i++;
			}
            for(j=1;j<=numrow-i; j++)
            {
                printf("  ");
            }
            for(j=1; j<=2*i-1; j++)
            {
                printf("@*");
            }
            printf("\n");
        }

    //Loop to print the base of the christmas tree
    for(i=1; i<5; i++)
    {
        for(j=1; j<=21; j++) //prints spaces to align the base at the center
        {
            printf(" ");
        }
        printf(" *** \n");
    }

    //Play background music
    PlaySound(TEXT("themesong.wav"), NULL, SND_ASYNC); //play music using PlaySound
    system("pause"); //needed to play song. It runs windows commandline pause program. It can to be terminated by pressing any key to continue the program
    printf("\nStopping song. Please wait for a moment.\n");
    PlaySound(TEXT("STOPPED"), NULL, SND_APPLICATION); //stops music
    printf("\nPress any key to go back. Press esc key to exit program"); //prompts the user an option to go back to main menu or exit program.
    char inp = getch(); //records user input without them pressing enter
    if (inp == 27) { //program exits when the esc key is pressed
        system("cls"); //clears console
        printf("\nExiting Program...\n");
        exit(0);
    }
    else {//when any key (except the esc key) is pressed, main function is called to go back to main menu
        system("cls");
        main();
    }
}

//Function to play music
void playSong() {
    system("cls"); //clears console of any text
    int choice;
    char suf[2], songName[] = "song";
    start: //label where the flow of the program jumps to when the goto statement is encountered
        printf("\n  Welcome! Feel free to sing along to the songs below.\n");
        printf("-------------------------------------------------------");
        printf("\nSelection:");
        printf("\n\t1. Silent Night \n\t2. Amazing Grace \n\t3. It's Beginning to Look a Lot Like Christmas"); //prompts list of songs
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        itoa(choice, suf, 10); //converts the integer number stored in variable 'choice' into a string
        system("cls"); //clears the console of any texts

        //Print title of lyrics if choice is valid
        if (choice == 1)
            printf("\nSilent Night Lyrics:\n\n");
        else if (choice == 2)
            printf("\nAmazing Grace Lyrics:\n\n");
        else if (choice ==3)
            printf("\nIt's Beginning to Look a Lot Like Christmas Lyrics:\n\n");
        else {
            printf("\nInvalid Choice. Try Again:\n");
            goto start;
        }

    printLyrics(suf); //calls function to print lyrics and passess the character stored in suf to the function

    strcat(songName, suf); //concatenate "song" with number choice
    strcat(songName, ".wav"); //concatenate songName, which is now song[number choice], with ".wav" to form a recognizable filename
    PlaySound(TEXT(songName), NULL, SND_ASYNC); //play music using PlaySound
    system("pause"); //needed to play song. It runs windows commandline pause program. It can to be terminated by pressing any key to continue the program
    printf("\nStopping song. Please wait for a moment.\n");
    PlaySound(TEXT("STOPPED"), NULL, SND_APPLICATION); //stops playing song

    printf("\nPress any key to go back to main menu. Press esc to exit program"); //Prompts the user an option to go back to main menu or exit program.
    char inp = getche(); //records keyboard input without pressing enter
    if (inp == 27) { //program exits when the esc key is pressed
        system("cls");
        printf("\nExiting Program...\n");
        exit(0); //zero exit value to denote that the program exits normally
    }
    else { //clears console of any texts and calls main function to go back to main menu
        system("cls");
        main();
    }
}

//Function to print lyrics
void printLyrics(char num[]) {
    system("color F1"); //changes console background color to white (F) and the text color to blue (1)

    /* Variables initialization.
    lyricsName contains the filename prefix which is "songlyrics".
    An array of size 200 is initialized to contain a line of characters from the text file later on. */
    char lyricsName[] = "songlyrics", line[200];

    strcat(lyricsName, num); //concatenate filename prefix to num which contains a character passed from the playSong function
    strcat(lyricsName, ".txt"); //concatenate lyricsName and ".txt" to form a recognizable filename
    FILE *file; //declares pointer of type FILE

    file = fopen(lyricsName, "r"); //opens text file for reading

    //Tests if file is present or not. Print song lyrics if it is present, else the program exits
    if (file != NULL) {
        while(fgets(line, sizeof(line), file)) { //while loop to print every line in the text file
            printf("\t%s", line);
        }
        printf("\n\n");
    }
    else {
        perror("\nCannot locate File"); //prompts error when file is not located
        exit(1); //exits program with a non-zero number when file is not located
    }
    fclose(file); //closes opened file
}
