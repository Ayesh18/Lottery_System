/**********************************************************************************

	FILENAME: main.c
	DESCRIPTION:This file is used to display the main menu to the user.
   	REVISION HISTORY
	DATE            NAME              REASON
	------------------------------------------------------------------
    04/10/2022      Username          This is done for creation of menu
 

 * ********************************************************************************/

#include <stdio.h>                  //Including required Header file
#include <stdlib.h>                 //Includes standard libraries
#include <string.h>                 //Includes string functions
#include <ctype.h>                  //Includes functions of ctype
#include "functions.h"              //Header file
#include "participant_corner.c"     //Including participant_corner.c file
#include "ZDA_authority.c"	    //Including ZDA_authority.c file
#include "file_handling.c"          //Including file_handling.c file
#define MAXPW 32                    //Define Macro
int main()
{
	char pw[MAXPW] = {0};
	char *pass = pw;
	FILE *fp = stdin;
	ssize_t nchr;
	int choice=0;
	start=new=ptr=prev=NULL;               //initializing pointer for plot structure.
	start1=new1=ptr1=prev1=NULL;           //initializing pointer for participant structure
	plot_file_to_list();                   //brings data from plot file to linked list
	participant_file_to_list();            //brings data from participant file to linked list
	while(choice!=3)
	{
		//Displaying Main Menu
		printf("\n         Main Menu");
		printf("\n-----------------------------\n");
		printf("\n1.Participant Corner\n2.ZDA Authority\n3.Exit");

		printf("\nEnter choice: "); 			//Taking users choice
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: Participant_Corner();   	//Function call for Participant_Corner
				choice=0;
				break;
			case 2:	nchr = getpasswd (&pass, MAXPW, 0, fp);
		                printf ("Enter password: ");
				nchr = getpasswd (&pass, MAXPW,0 , fp);
				if((strcmp(pass,"zx"))==0)
				{
					//system("clear");       //clears the screen
					ZDA_Authority();         //Function call for ZDA_Authority
				}
				else
				{
					printf("You have entered incorrect password");
				}
				//system("clear");
				choice=0;
				break;
			case 3 : break;
			default: printf("Invalid Choice\n");
		}
	}
	if(start)                              //When start is not NULL
		list_to_plot_file();           //Linked list to plot file
	if(start1)                             //When start1 is not NULL
		list_to_participant_file();    //Linked list to participant file
	return EXIT_SUCCESS;
}

