/********************************************************************************************
**     FILENAME      :      func.h
**
**    DESCRIPTION    :      This file contains functions used for unit testing.
*****************************************************************************************/
#include "functions.h"
#define SUCCESS 1
#define FAILURE 0
int add_participant_to_list(int familyid,char str[])
{
    new1=(p *)calloc(1,sizeof(p));
    if(new1==NULL)
    {
        //printf("\nMemory cannot be allocated\n\n");
        return FAILURE;
    }
    if(familyid<1000 || familyid>1200)
    {
        //printf("Invalid Family ID should be between 1000-1200\n");
        return FAILURE;
    }
    if(start1)
    {
        for(ptr1=start1;(ptr1) && ptr1->family_id!=familyid ;ptr1=ptr1->next);
        if((ptr1) && ptr1->family_id==familyid)
        {
            //printf("Duplicate Family Id\n");
            return FAILURE;
        }
    }
    int len=strlen(str);
    if(len<5||len>40)
    {
        //printf("Invalid name length, should be between 5 to 40 characters\n");
        return FAILURE;
    }
    int i=0;
    for( i=0;i<len;i++)
    {
        if(!isalpha(*(str+i)) && !isspace(*(str+i)))
        {
            //printf("Name should be of proper convention\n");
            return FAILURE;
        }
    }
    new1->family_id=familyid;
    strcpy(new1->name,str);
    new1->token_no=0;
    new1->remaining_amount=0;
    new1->size=0;
    new1->plot_no=0;
    strcpy(new1->participated_in_lottery,"NO");
    if(start1==NULL)            //Inserting record inside the list
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
    return SUCCESS;
}

int remove_participant_from_list(int code)
{
    if(!start1)
    {
        //printf("\nNo Participant has been added by ZDA Authority\n\n");
        return FAILURE;
    }
    if(code==start1->family_id)
    {
        ptr1=start1;
        start1=start1->next;
        free(ptr1);
        return SUCCESS;
    }
    else
    {
        for(ptr1=start1;(ptr1) && ptr1->family_id!=code;prev1=ptr1,ptr1=ptr1->next);
        if(ptr1==NULL)
        {
            //printf("\nParticipant not found\n\n");
            return FAILURE;
        }
        prev1->next=ptr1->next;
        free(ptr1);
    }
    return SUCCESS;
}

int add_plot_to_list(int pno, int psize, double pprice)
{
    new=(pt *)calloc(1,sizeof(pt));
    if(new==NULL)
    {
        //printf("\nMemory cannot be allocated");
        return FAILURE;
    }
    if(pno<1 || pno>100)
    {
        //printf("\nInvalid Plot number should be in range of 1-100");
        return FAILURE;
    }
    if(start)
    {
        for(ptr=start;(ptr) && ptr->plot_no!=pno ;ptr=ptr->next);
        if((ptr) && ptr->plot_no==pno)
        {
            //printf("\nDuplicate plot number");
            return FAILURE;
        }
    }
    if(psize<100 || psize>10000)
    {
        //printf("\nInvalid Plot size,should be in range 100-10000");
        return FAILURE;
    }
    if(pprice<50000.00)
    {
        //printf("\nInvalid Plot price, price cannot be less then 50000");
        return FAILURE;
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
    return SUCCESS;
}
