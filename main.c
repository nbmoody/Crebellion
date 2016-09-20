// C For Absolute Beginners Test File
// Created by nathaniel on 9.11.2016
// main.c


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()
{
    //Create the empire.
    char emp[30];
    char city1[30];
    char city2[30];
    char city3[30];
    int c1sd = 10;
    int c2sd = 10;
    int c3sd = 10;
    int c1ang = 1;
    int c2ang = 1;
    int c3ang = 1;
    int soldiers = 0;
    int numsoldiers;
    int done = 0;

    printf("Welcome to your new empire!\n");
    printf("What is the name of your empire? (must be one word)\n");
    scanf(" %s", emp);
    printf("\nYou rule three cities, but you must name them before we continue.\n");
    printf("What would you like to name your first city? (must be one word)\n");
    scanf(" %s", city1);
    printf("\nWhat would you like to name your second city? (must be one word)\n");
    scanf(" %s", city2);
    printf("\nWhat would you like to name your third city? (must be one word)\n");
    scanf(" %s", city3);

    //Initial report on the empire.
    printf("Emperor, all is well in %s. %s, %s, and %s adore your rule and all is at peace.\n\n", emp, city1, city2, city3);

    //Explain the game.
    printf("Your people love you, but will quickly turn away from your benevolent rule.\n");
    printf("To 'remind' them of your love, you must choose how many soldiers to station in each city, each turn.\n");
    printf("You begin with 10 soldiers in each city.\n");
    printf("Each turn you will gain 30 more soldiers to place in your cities.\n");
    printf("If the people in a city grow more angry than the soldiers can control, that city will rebel.\n");
    printf("If any of your cities rebel, your empire will break and your name will be forgotten.\n");
    printf("1 soldier will control 1 point of anger in a city. Each turn you will receive a report,\n");
    printf("and you must decide how many soldiers to distribute to each city.\n");

    //Begin game.
    int roundnum = 0;
    int choice;

    do //Start main game loop (lasts for 100 rounds max).
    {
        roundnum++;
        soldiers += 30;
        done = 0; //serves as a flag for completing the round.


        do {

            //Main menu during each round.
            printf("It is round %d! What would you like to do?\n", roundnum);
            printf("1. Place new soldiers in your cities. (You have %d left)\n", soldiers);
            printf("2. See a report on how many soldiers are in each city.\n");
            printf("3. See a report on how angry your cities are currently.\n");
            printf("4. End the round.\n");
            printf("5. Quit the game.\n");
            scanf(" %d", &choice);
//At some point, create a data-testing loop here to make sure the choice is 1,2,3, or 4

            switch (choice)
            {
                case (1):
                    printf("How many soldiers should be stationed in %s?\n", city1);
                    scanf(" %d", &numsoldiers);
                    if ((soldiers - numsoldiers) <= 0)
                    {
                        c1sd += numsoldiers;
                        soldiers -= numsoldiers;
                    }
                    else
                    {
                        printf("You don't have enough new soldiers to add that many.\n");
                        printf("You only have %d soldiers left to distribute.\n", soldiers);
                    }
                    printf("\n");
                    continue;
                case (2):
                    printf("You currently have:\n");
                    printf("\t%d soldiers in %s.\n", c1sd, city1);
                    printf("\t%d soldiers in %s.\n", c2sd, city2);
                    printf("\t%d soldiers in %s.\n", c3sd, city3);
                    continue;
                case (3):
                    printf("%s's anger level is: %d\n", city1, c1ang);
                    printf("%s's anger level is: %d\n", city2, c2ang);
                    printf("%s's anger level is: %d\n", city3, c3ang);
                    printf("\n");
                    continue;
                case (4):
                    done = 1;
                    break;
                case (5):
                    exit(1); //could add and if/else here to make sure they want to exit.
                default:
                    printf("That is not a valid choice, sorry. Try again!\n\n");
                    continue;
            }
        } while (choice < 1 || choice > 5 && done == 0);

        //Check for rebellion in any city. IF rebellion, end game and show roundnum.
        //Recalculate anger levels, somehow vary.



    } while (roundnum <=100);//End main game loop. ALSO NEEDS TO END IF REBELLION = TRUE!


    return(0);

}
//Every switch action ends a round.
//You can still over-place soldiers in cities ("soldiers" just goes negative for some reason).