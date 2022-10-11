#include <stdio.h>   //It includes all the header files
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <unistd.h>
#include "functions.h"
int add_participant_to_list(int familyid,char str[])
{
    new1=(p *)calloc(1,sizeof(p));
    if(new1==NULL)
    {
                printf("\nMemory cannot be allocated\n\n");
                return 0;
    }
    if(familyid<1000 || familyid>1200)
    {
        printf("Invalid Family ID should be between 1000-1200\n");
        return 0;
    }
    if(start1)
    {
        for(ptr1=start1;(ptr1) && ptr1->family_id!=familyid ;ptr1=ptr1->next);
        if((ptr1) && ptr1->family_id==familyid)
        {
            printf("Duplicate Family Id\n");
            return 0;
        }
    }
    int len=strlen(str);
    if(len<5||len>40)
    {
        printf("Invalid length should be between 5 to 40 characters\n");
        return 0;
    }
    int i=0;
    for( i=0;i<len;i++)
    {
        if(!isalpha(*(str+i)) && !isspace(*(str+i)))
        {
            printf("Name should be of proper convention\n");
            return 0;
        }
    }
    new1->family_id=familyid;
    strcpy(new1->name,str);
    new1->token_no=0;
        new1->remaining_amount=0;
        new1->size=0;
    new1->plot_no=0;
    strcpy(new1->participated_in_lottery,"NO");
    if(start1==NULL) //Inserting record inside the list
    {
        start1=new1;
        new1->next=NULL;
    }
    else if(new1->family_id<start1->family_id)
    {
        new1->next=start1;
        start1=new1;
    }
    else
    {
        for(ptr1=start1;(ptr1) &&  ptr1->family_id<new1->family_id;prev1=ptr1,ptr1=ptr1->next);
        prev1->next=new1;
        new1->next=ptr1;
    }
    return 1;
}

int remove_participant_from_list(int code)
{
    if(!start1)
    {
        printf("\nNo Participant has been added by ZDA Authority\n\n");
        return 0;
    }
    if(code==start1->family_id)
    {
        ptr1=start1;
        start1=start1->next;
        free(ptr1);
        return 1;
    }
    else
    {
        for(ptr1=start1;(ptr1) && ptr1->family_id!=code;prev1=ptr1,ptr1=ptr1->next);
        if(ptr1==NULL)
        {
            printf("\nParticipant not found\n\n");
            return 0;
        }
        prev1->next=ptr1->next;
        free(ptr1);
    }
    return 1;
}

int add_plot_to_list(int pno, int psize, double pprice)
{
    new=(pt *)calloc(1,sizeof(pt));
    if(new==NULL)
    {
        printf("\nMemory cannot be allocated");
        return 0;
    }
    if(pno<1 || pno>100)
    {
        printf("\nInvalid Plot number should be in range of 1-100");
        return 0;
    }
    if(start)
    {
        for(ptr=start;(ptr) && ptr->plot_no!=pno ;ptr=ptr->next);
        if((ptr) && ptr->plot_no==pno)
        {
            printf("\nDuplicate plot number");
            return 0;
        }
    }
    if(psize<100 || psize>10000)
    {
        printf("\nInvalid Plot size,should be in range 100-10000");
        return 0;
    }
    if(pprice<50000.00)
    {
        printf("\nInvalid Plot price, price cannot be less then 50000");
        return 0;
    }
    new->plot_no=pno;
    new->size=psize;
    new->price=pprice;
    strcpy(new->allot,"NO");
    if(!start) //Inserting record inside the list
    {
        start=new;
        new->next=NULL;
    }
    else if(new->plot_no<start->plot_no)
    {
        new->next=start;
        start=new;
    }
    else
    {
        for(ptr=start; (ptr) &&  ptr->plot_no<new->plot_no ;prev=ptr,ptr=ptr->next);
        prev->next=new;
        new->next=ptr;
    }
    return 1;
}