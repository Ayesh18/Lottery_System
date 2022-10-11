/**********************************************************************************
 *

        FILENAME: file_handling.c
        DESCRIPTION:This file is used to  retrieve and store data from plot and participant file.
        REVISION HISTORY
        DATE            NAME              REASON
        ------------------------------------------------------------------
    04/10/2022      Username          For Creation

 * ********************************************************************************/
#include <stdio.h>   //Including required Header files
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
int list_to_participant_file() // for inserting records in Participant file from list
{
        FILE *fp;                                    //File pointer
        fp=fopen("../data/Participant","wb");                //opening the binary file in write mode
        for(ptr1=start1;(ptr1);ptr1=ptr1->next)      //appending data at the end
        {
                fwrite(ptr1,sizeof(p),1,fp);         //writing in file participant
        }
        fclose(fp);     //closing the file
        return EXIT_SUCCESS;
}



int participant_file_to_list() //For inserting records in list from Participant file
{
        p *last1;                                   //last pointer of participant type structure
        FILE *fp;
        if((fp=fopen("../data/Participant","rb"))==NULL)    //opening the binary file in read mode
        {
                return(1);
        }
        new1=(p *)malloc(sizeof(p));                //Dynamically allocating memory for new1 for participant type structure.
        if(new1==NULL)
        {
                printf("\nMemory cannot be allocated");
                return EXIT_FAILURE;
        }
        fread(new1,sizeof(p),1,fp);                 //reading file
        while(!feof(fp))                            //checking for end of file
        {
                //after reading data from file ,inserting into the linked list
                if(!start1)
                {
                        start1=last1=new1;
                        new1->next=NULL;
                }
                else
                {
                        last1->next=new1;
                        last1=new1;
                        new1->next=NULL;
                }
                new1=(p *)malloc(sizeof(p));
                if(new1==NULL)
                {
                        printf("\nMemory cannot be allocated");
                        return EXIT_FAILURE;
                }
                fread(new1,sizeof(p),1,fp);
        }
        free(new1);
        return EXIT_SUCCESS;
}



int list_to_plot_file() // for inserting records in Plot file from list
{
        FILE *fp;
        fp=fopen("../data/Plot","wb");                //opening a binary file for writing
        for(ptr=start;(ptr);ptr=ptr->next)
        {
                fwrite(ptr,sizeof(pt),1,fp);  //writing a file
        }
        fclose(fp);     // closing the file
        return EXIT_SUCCESS;
}



int plot_file_to_list() //For inserting records in list from Plot file
{
        pt *last;
        FILE *fp;
        if((fp=fopen("../data/Plot","rb"))==NULL)     //opening a binary file for reading
        {
                return EXIT_SUCCESS;
        }
        new=(pt *)malloc(sizeof(pt));         //allocating memory
        if(new==NULL)
        {
                printf("\nMemory cannot be allocated");
                return EXIT_FAILURE;
        }
        fread(new,sizeof(pt),1,fp);
        while(!feof(fp))
        {
                //after reading data from file ,inserting into the linked list
                if(!start)
                {
                        start=last=new;
                        new->next=NULL;
                }
                else
                {
                        last->next=new;
                        last=new;
                        new->next=NULL;
                }
                new=(pt *)malloc(sizeof(pt));
                if(new==NULL)
                {
                        printf("\nMemory cannot be allocated");
                        return EXIT_FAILURE;
                }
                fread(new,sizeof(pt),1,fp);
        }
        free(new);
        return EXIT_SUCCESS;
}
