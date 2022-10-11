/********************************************************************************************


**     FILENAME      :         participant_corner.c
**
**    DESCRIPTION    :      This File contains  the menu list for Participant Corner which contains functions like Grab A token,
**                                      Cancel A Token, Check Lottery, View Allotment Details .
**
**  DATE            NAME              REASON
**--------------------------------------------------------------------
**  04/10/2022      Username       Creation of File, Creating MENU List.
**
*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include "functions.h"


/*******************************************************************************************

**
**  FUNCTION NAME   : Participant_Corner
**  DESCRIPTION     : In this function it displays the menu list for Participant corner
**  RETURN          : Return EXIT_SUCCESS
**

*******************************************************************************************/

pthread_mutex_t accum_mutex = PTHREAD_MUTEX_INITIALIZER;
int Participant_Corner()
{
        int choice_sub1=0;
        pthread_t th;
        if(date==0)
        {
                printf("Tokens are not generated yet and lottery date not announced\n");
        }
        else
        {
                printf("\n    Reminder: The lottery is on %d of this month!        ",date);
        }
        while(choice_sub1!=5)
        {

                printf("\n              Participant Corner");
                printf("\n------------------------------------------------");
                printf("\n1.Grab a Token \n2.Cancel Token \n3.Check Lottery \n4.View Allotment Details\n5.Back to Main Menu");
                printf("\nEnter your choice: ");
                scanf("%d",&choice_sub1);
                switch(choice_sub1)
                {
                        case 1: pthread_create(&th, NULL,(void *)grab_token,NULL);
                                pthread_join(th,NULL);
                                choice_sub1=0;
                                break;
                        case 2: cancel_token();
                                choice_sub1=0;
                                break;
                        case 3: Lottery_Confirmation();
                                choice_sub1=0;
                                break;
                        case 4: view_allotment_details();
                                choice_sub1=0;
                                break;
                        case 5:
                                break;
                        default:
                                printf("Invalid choice");
                }
        }
        return  EXIT_SUCCESS;
}


/*******************************************************************************************************

**
**  FUNCTION NAME   : grab_token
**  DESCRIPTION     : In this function the participant grabs a token id to enter in the lottery process
**  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
**

*******************************************************************************************************/


int grab_token()
{

        if(date!=0)
        {
                int code;
                int token;
                printf("Enter Family Id: ");
                scanf("%d",&code);
                for(ptr1=start1;(ptr1) && ptr1->family_id!=code;ptr1=ptr1->next);
                if(!ptr1)
                {
                        printf("\nParticipant not exist with this family id\n\n");
                        return EXIT_FAILURE;
                }
                if(ptr1->token_no!=0)
                {
                        printf("\nYou have already grabbed a token\n\n");
                        return EXIT_FAILURE;
                }
                token=deque();
                if(token!=0)
                {
                        pthread_mutex_lock(&accum_mutex);
                        ptr1->token_no=token;
                        printf("\nYour Token number is %d\n\n",token);
                        pthread_mutex_unlock(&accum_mutex);
                }
                else
                {
                        printf("No token is available\n");
                        return EXIT_FAILURE;
                }
        }
        else
        {
                printf("Tokens are not generated yet\n");
                return EXIT_FAILURE;
        }
        return  EXIT_SUCCESS;
}



/*******************************************************************************************************

**
**  FUNCTION NAME   : cancel_token
**  DESCRIPTION     : In this function the participant cancels a token
**  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
**

*******************************************************************************************************/

int cancel_token()
{
   int today_date;
        printf("Enter today's date (1-31): ");
        scanf("%d",&today_date);
        if(today_date<date-2)
        {
                int code;
                printf("Enter Family Id: ");
                scanf("%d",&code);
                for(ptr1=start1;(ptr1) && ptr1->family_id!=code;ptr1=ptr1->next);
                if(!ptr1)
                {
                        printf("\nParticipant not exist with this family id\n\n");
                        return EXIT_FAILURE;
                }
                if(ptr1->token_no==0)
                {
                        printf("\nYou have not grabbed a token\n\n");
                        return EXIT_FAILURE;
                }
                if((strcmp(ptr1->participated_in_lottery,"YES")==0))
                {
                        printf("\nYou have already participated in lottery\nNow you cannot cancel your token\n\n");
                        return EXIT_FAILURE;
                }
                if(ptr1->token_no!=0 && (strcmp(ptr1->participated_in_lottery,"NO")==0))
                {
                        enque(ptr1->token_no);
                        ptr1->token_no=0;
                        printf("\nYour token has been cancelled successfully\n\n");
                }
        }
        else
        {
                printf("\nSorry,token can be cancelled only 2 before the lottery date\n");
                return EXIT_FAILURE;
        }
        return  EXIT_SUCCESS;
}


/*******************************************************************************************************

**
**  FUNCTION NAME   : Lottery_Confirmation
**  DESCRIPTION     : In this function the participant confirms the lottery by payment.
**  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
**

*******************************************************************************************************/

int Lottery_Confirmation()
{
        int code;
        printf("Enter Family Id: ");
        scanf("%d",&code);
        for(ptr1=start1;(ptr1) && ptr1->family_id!=code ;ptr1=ptr1->next);
        if(!ptr1)
        {
                printf("\nParticipant with this family id does not exist\n\n");
                return EXIT_FAILURE;
        }
        if(ptr1->token_no==0)
        {
                printf("\nPartcipant has not grabbed the token\n\n");
                return EXIT_FAILURE;
        }
        if(code!=lottery_no)
        {
                printf("You have not won the lottery, please try again later");
                return EXIT_FAILURE;
        }
        else
        {
                char Payment_Confirmation;
                printf("\nCongratulations,You have won the lottery for plot_no: %d\n",p_no);
                printf("\nPlease confirm your allotment by paying 50000\n");
                sleep(10);
                getchar();
                printf("\nPlease confirm your payment-Y/N: ");
                scanf("%c",&Payment_Confirmation);
                if(Payment_Confirmation=='Y')
                {
                        ptr1->plot_no=p_no;
                        for(ptr=start;(ptr) && ptr->plot_no!=p_no;prev=ptr,ptr=ptr->next);
                        ptr1->size=ptr->size;
                        ptr1->remaining_amount=(ptr->price-50000);
                        strcpy(ptr->allot,"YES");
                        printf("Plot with plot no %d is succesfully allocated to you\n",p_no);
                }
                else
                {
                        printf("\nYour allotment is cancelled.\n");
                        printf("\nPlot %d is up for lottery again.\n",p_no);
                        printf("\nPlease contact the ZDA Authority.\n");
                        ptr1->token_no=0;      // token number is nullified.

                }
        }
        strcpy(ptr1->participated_in_lottery,"YES");
        return  EXIT_SUCCESS;
}



/*******************************************************************************************************

**
**  FUNCTION NAME   : view_allotment_details
**  DESCRIPTION     : In this function the participant grabs a token id to enter in the lottery process
**  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
**

*******************************************************************************************************/

int view_allotment_details(){
        if(!start1)
        {
                printf("\nNo Participant has been added by ZDA Authority\n\n");
                return EXIT_FAILURE;
        }
        int code;
        printf("Enter Family Id: ");
        scanf("%d",&code);
        for(ptr1=start1;(ptr1) && ptr1->family_id!=code ;ptr1=ptr1->next);
        if(!ptr1)
        {
                printf("\nParticipant with this family id does not exist\n\n");
                return EXIT_FAILURE;
        }
        printf("                                   ALLOTMENT DETAILS              \n");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("\nSerial_No     Name   Family_id   Token    Plot_no    Plot_size     Remaining_Amount    Participated_in_Lottery\n");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        int count=1;
        printf("\n%5d     %-10s    %8d     %5d    %5d    %5d      %8.2lf    %-5s\n\n",count,ptr1->name,ptr1->family_id,ptr1->token_no,ptr1->plot_no,ptr1->size,ptr1->remaining_amount,ptr1->participated_in_lottery);
        return  EXIT_SUCCESS;
}
