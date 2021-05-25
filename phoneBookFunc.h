#ifndef PHONEBOOKFUNC_H_
#define PHONEBOOKFUNC_H_


typedef struct calen
{
    int day;
    int month;
    int year;
}date;
typedef struct con
{
    char firstName[20];
    char lastName[20];
    date dateOBirth;
    char address[40];
    char email[40];
    char phoneNumber[10];
}Conta;

void modify();
void query();
void exitCode();
void printSort();
//void addEntry(int * );
char errorInput( char[] );
void printHelp();
void viewData(Conta,int);
void deleteEntry();
//Conta ** load();
void addRecord();
//Conta *  construct(char *,char *,int ,int,int ,char *,char *,char *);
void save();
void loads();

#endif
