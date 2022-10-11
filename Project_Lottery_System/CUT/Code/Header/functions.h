/********************************************************************************************
**     FILENAME      :         functions.h
**
**    DESCRIPTION    :      This File contains structure definitions and all funcions prototypes.

*****************************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define UPPER 110
#define LOWER 100
int lottery_no=0;
int p_no=0;
int date=0;
#include <stddef.h>
typedef struct queue
{
        int token;
        struct queue *next;
}q1;

q1 *front,*rear,*new_queue,*ptr_queue;
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
p *new1,*prev1,*start1,*ptr1;  //Pointers to participant type structure

typedef struct plot{      //Structure of plot
        int plot_no;
        int size;
        char allot[3];
        double price;
        struct plot *next;
}pt;
pt *new,*prev,*start,*ptr;     //Pointers to plot type structure

int Participant_Corner();       //To display participant menu
int ZDA_Authority();            //To display ZDA Authority menu
int initialize_tokens();         //To initialize tokens in a queue
int Generate_Winning_Lottery(); //To generate winning Lottery
int Get_Winning_Lottery(); //To get the winning family id
void enque(int);                //To insert into queue
int deque();                    //to delete from queue
int grab_token();               //To grab a lottery token
int cancel_token();             //To cancel a lottery token
int Lottery_Confirmation();   //To participate in lottery
int view_allotment_details();   //To view allotment details
void add_plot();                        //To add plot
int edit_plot();                //To edit plot
int delete_plot();              //To delete plot
int view_plot_details();        //To view plot details
void add_participant();         //To add participant
int edit_participant();         //To edit participant details
void remove_participant();       //To remove participant details
int view_participant_details(); //To view participant details
int view_lottery_report();      //To view lottery report
int list_to_plot_file();        //List to plot file
int list_to_participant_file(); //List to participant file
int plot_file_to_list();        //Plot file to list
int participant_file_to_list(); //Participant file to list
int maintain_participant_db();  //To display participant menu
int maintain_plot_db();         //To display plot men
ssize_t getpasswd (char **pw, size_t sz, int mask, FILE *fp);  //Password function
#endif