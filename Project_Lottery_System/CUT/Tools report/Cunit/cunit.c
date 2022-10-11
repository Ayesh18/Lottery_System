#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "CUnit/Basic.h"
#include <ctype.h>
#include <CUnit/CUnit.h>        //ASSERT macros for use in test cases, and includes other framework headers.
#include <CUnit/CUError.h>      //Error handing functions and data types. Included automatically by CUnit.h.
#include <CUnit/TestDB.h>       //Data type definitions and manipulation functions for the test registry, suites, and tests. Included automatically by CUnit.h.
#include <CUnit/TestRun.h>      //Data type definitions and functions for running tests and retrieving results. Included automatically by CUnit.h.
#include <CUnit/Automated.h>    //Automated interface with xml output.
#include <CUnit/Basic.h>        //Basic interface with non-interactive output to stdout.
#include <CUnit/Console.h>      //Interactive console interface.
typedef struct participant  //Structure of participant
{
        int family_id;
        char name[40];
        char participated_in_lottery[3];
        int token_no;
        int plot_no;
        int size;
        double remaining_amount;
        struct participant *next;
}p;
p *new1,*prev1,*start1,*ptr1;

typedef struct plot{      //Structure of plot
        int plot_no;
        int size;
        char allot[3];
        double price;
        struct plot *next;
}pt;
pt *new,*prev,*start,*ptr;     //Pointers to plot type structure

int add_participant_to_list(int familyid,char *str)
{
        new1=(p *)malloc(sizeof(p));
    if(new1==NULL)
    {
                //printf("\nMemory cannot be allocated\n");
                return 0;
    }
    if(familyid<1000 || familyid>1200)
    {
                //printf("\nInvalid Family ID should be between 1000-1200");
        return 0;
    }
    if(start1)
        {
                for(ptr1=start1;(ptr1) && ptr1->family_id!=familyid ;ptr1=ptr1->next);
        if((ptr1) && ptr1->family_id==familyid)
        {
                //printf("\nDuplicate Family Id");
            return 0;
        }
    }
    int len=strlen(str);
    if(len<5||len>40)
    {
        //printf("\nInvalid length should be between 5 to 40 characters");
        return 0;
    }
    int i=0;
    for( i=0;str[i]!='\0';i++)
    {
        if(!isalpha(str[i]) && !isspace(str[i]))
        {
           // printf("Name should be of proper convention\n");
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
        //printf("\nNo Participant has been added by ZDA Authority");
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
           // printf("\nParticipant not found");
            return 0;
        }
        prev1->next=ptr1->next;
        free(ptr1);
    }
    return 1;
}

int add_plot_to_list(int pno, int psize, double pprice)
{
    new=(pt *)malloc(sizeof(pt));
    if(new==NULL)
    {
        //printf("\nMemory cannot be allocated");
        return 0;
    }
    if(pno<1 || pno>100)
    {
        //printf("\nInvalid Plot number should be in range of 1-100");
        return 0;
    }
    if(start)
    {
        for(ptr=start;(ptr) && ptr->plot_no!=pno ;ptr=ptr->next);
        if((ptr) && ptr->plot_no==pno)
        {
            //printf("\nDuplicate plot number");
            return 0;
        }
    }
    if(psize<100 || psize>10000)
    {
        //printf("\nInvalid Plot size,should be in range 100-10000");
        return 0;
    }
    if(pprice<50000.00)
    {
        //printf("Invalid Plot price, price cannot be less then 50000\n");
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

int init_suite_add_participant_to_list(void)
{
        return 0;
}

int clean_suite_add_participant_to_list(void)
{
        return 0;
}

int init_suite_remove_participant_from_list(void)
{
        return 0;
}

int clean_suite_remove_participant_from_list(void)
{
        return 0;
}
int init_suite_add_plot_to_list(void)
{
        return 0;
}

int clean_suite_add_plot_to_list(void)
{
        return 0;
}

void add_participant_to_list_sunnycases(void)
{
        CU_ASSERT_EQUAL(add_participant_to_list(1001,"Sai nath"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1002,"aaaaa"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1003,"bbbbb"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1004,"ccccc"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1005,"ddddd"),1);
}

void add_participant_to_list_rainycases(void)
{
        CU_ASSERT_EQUAL(add_participant_to_list(1006,"Sai"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(1007,"aqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqa"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(123,"bbbbb"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(1002,"ccccc"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(1009,"ddd343d"),0);
}

void remove_participant_from_list_sunnycases(void)
{
        CU_ASSERT_EQUAL(remove_participant_from_list(1001),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1002),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1003),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1004),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1005),1);
}

void remove_participant_from_list_rainycases(void)
{
        CU_ASSERT_EQUAL(remove_participant_from_list(1001),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1002),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1003),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1004),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1005),0);
}


void add_plot_to_list_sunnycases(void)
{
        CU_ASSERT_EQUAL(add_plot_to_list(1,1006,56789),1);
        CU_ASSERT_EQUAL(add_plot_to_list(2,1234,345678),1);
        CU_ASSERT_EQUAL(add_plot_to_list(25,4534,67896),1);
        CU_ASSERT_EQUAL(add_plot_to_list(45,3433,78789),1);
        CU_ASSERT_EQUAL(add_plot_to_list(98,4567,53453),1);
}

void add_plot_to_list_rainycases(void)
{
        CU_ASSERT_EQUAL(add_plot_to_list(1,1006,56789),0);
        CU_ASSERT_EQUAL(add_plot_to_list(101,1234,345678),0);
        CU_ASSERT_EQUAL(add_plot_to_list(88,4534,45000),0);
        CU_ASSERT_EQUAL(add_plot_to_list(35,87,78789),0);
        CU_ASSERT_EQUAL(add_plot_to_list(99,45678,53453),0);
}
int main()
{
        CU_pSuite pSuite1 = NULL;
        CU_pSuite pSuite2 = NULL;
        CU_pSuite pSuite3 = NULL;

        if (CUE_SUCCESS != CU_initialize_registry())
        {
                return CU_get_error();
        }

        pSuite1 = CU_add_suite("suite add participant data...", init_suite_add_participant_to_list, clean_suite_add_participant_to_list);

        if (NULL == pSuite1)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        pSuite2 = CU_add_suite("suite remove participant data...", init_suite_remove_participant_from_list, clean_suite_remove_participant_from_list);

        if (NULL == pSuite2)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        pSuite3 = CU_add_suite("suite add plot data...", init_suite_add_plot_to_list, clean_suite_add_plot_to_list);

        if (NULL == pSuite3)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if ((NULL == CU_add_test(pSuite1, "Test for add_participant_to_list() in sunny cases", add_participant_to_list_sunnycases)) || (NULL == CU_add_test(pSuite1, "Test for add_participant_to_list() in rainy cases", add_participant_to_list_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if ((NULL == CU_add_test(pSuite2, "Test for remove_participant_from_list() in sunny cases", remove_participant_from_list_sunnycases)) || (NULL == CU_add_test(pSuite2, "Test for remove_participant_from_list() in rainy cases", remove_participant_from_list_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if ((NULL == CU_add_test(pSuite3, "Test for add_plot_to_list() in sunny cases", add_plot_to_list_sunnycases)) || (NULL == CU_add_test(pSuite3, "Test for add_plot_to_list() in rainy cases", add_plot_to_list_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}