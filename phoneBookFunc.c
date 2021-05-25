#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int noOfEntries = 0;
int justSaved = 1;

typedef struct calen // date structure
{
    int day;
    int month;
    int year;
} date;

typedef struct con  //type defined struct for contacts
{
    char firstName[40];
    char lastName[40];
    date dateOBirth;
    char address[60];
    char email[60];
    char phoneNumber[30];
} Conta;

Conta Contacts[300];

int   subString(  char x[],   char y[]  )    //gives 1 if y is a part of x
{
    int i, j, flag=0;
    for(i=0; i< strlen(x)  &&  flag == 0 ; i++)
    {
        if(x[i] == y[0])
        {
            flag = 1;
            for(j=0 ; j<strlen(y) ; j++)
            {
                if(x[i+j] != y[j])
                {
                    flag=0;
                }
            }
        }
    }
    return flag;
}

int comparatorString(const void * p, const void *q) //WIP
{
    Conta *pp = (Conta*)p, *pq = (Conta*)q;
    return stricmp(pp->lastName,pq->lastName);
}

int comparatorAge(const void * p, const void *q)//WIP
{
    Conta *pp = (Conta*)p, *pq =(Conta*)q;
    double ppAge=(pp->dateOBirth.year)*1000+(pp->dateOBirth.month)*100+pp->dateOBirth.day;
    double pqAge=(pq->dateOBirth.year)*1000+(pq->dateOBirth.month)*100+pq->dateOBirth.day;
    if(pqAge<ppAge)
        return 1;
    if(ppAge<pqAge)
        return -1;
    return 0;
}

void valiName(char * p)
{
    int i,flag=0;
    scanf("%s",p);
    while(1)
    {
        flag = 0 ;
        for(i=0; i<strlen(p); i++)
        {
            if(!(p[i]<='z' && p[i] >='a') && !(p[i]<='Z' && p[i] >='A'))
            {
                flag =1;
            }
        }
        if(!flag)
            return;
        else
            printf("Invalid Name\n");
        scanf("%s",p);
    }

}

void valiaddress(char * p)
{
    int i,flag=0;
    gets(p);
    while(1)
    {
        flag = 0 ;
        for(i=0; i<strlen(p); i++)
        {
            if( p[i] == ',' )
            {
                flag =1;
            }
        }
        if(!flag)
            return;
        else
            printf("No ',' allowed \nInvalid Address \n");
        scanf("%s",p);
    }

}

int valiyear ()
{
    int temp;
    char year[7];
    scanf("%s",year);
    temp=atoi(year);
    while(temp < 1900 || temp >2019)
    {
        printf("Invalid year\n");
        scanf("%s",year);
        temp=atoi(year);
    }
    return temp;
}

int validay(int year,int month) // validates the day
{
    char x[4];
    scanf("%s",x);
    int temp= atoi(x);
    if(month == 1 ||month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 ||month == 12 )
    {
        while(temp>31 || temp<1)
        {
            printf("Invalid Day\n");
            scanf("%s",x);
            temp= atoi(x);
        }
    }
    else if (month != 2)
    {
        while(temp>30 || temp<1)
        {
            printf("Invalid Day\n");
            scanf("%s",x);
            temp= atoi(x);
        }
    }
    else if (year % 4 == 0)
    {
        while(temp>29 || temp<1)
        {
            printf("Invalid Day\n");
            scanf("%s",x);
            temp= atoi(x);
        }
    }
    else
    {
        while(temp>28 || temp<1)
        {
            printf("Invalid Day\n");
            scanf("%s",x);
            temp= atoi(x);
        }
    }
    return temp;
}

int valimonth()//validates the month
{
    int temp;
    char month[4];
    scanf("%s",month);
    temp=atoi(month);
    while(temp < 1 || temp >12 )
    {
        printf("Invalid Month\n");
        scanf("%s",month);
        temp=atoi(month);
    }
    return temp;
}

int Emailcheck(char * p)
{
    char *z,*q;
    int i,len = strlen(p);
    for( i=0 ; i<len;i++)
        if(p[i] == ',')
        {
            printf("No ',' allowed\n");
            return 0;
        }
    if(strchr(p,'@') )
    {
        if(strchr(p,'.'))
        {
            z=strchr(p,'@');
            q=strchr(p,'.');
            while( ++z != q )
            {
                if(!(*z <='z' && *z >='a') && !(*z<='Z' && *z >='A'))
                {
                    printf("Invalid domain\n");
                    return 0;
                }
            }
            if(!strcmp(q,".com"))
            return 1;
            else
            {
                printf("Invalid upper domain\n");
                return 0;
            }
        }else
        printf("No dot found\n");
        return 0;
    }
    else
        printf("No @ sign\n");
    return 0;
    /*for(i=0 ;  p[i] != '@' || p[i] != '\0' ;i++);
    if( i == strlen(p) )
    {
        printf("No @ inputed\n");
        return 0;
    }
    putchar('t');
    j=i;
    for(i=j ;  p[i+1] != '.' || p[i] != '\0'  ;i++);
       {
        if( !(p[i]>='a' && p[i] <='z') && !(p[i] >='A' && p[i] <='Z'))
            {
                printf("Only Character are allowed after the @\n");
                return 0;
            }
        if (i == strlen(p))
            {
                printf("No \".com\" Inputed\n");
                return 0;
            }
       }
       j=i;
       if(p[j+1] != 'c')
        {
                printf("Incorrect \".com\" Inputed\n");
                return 0;
        }
        if(p[j+2] != 'o')
        {
                printf("Incorrect \".com\" Inputed\n");
                return 0;
        }
       if(p[j+3] != 'm')
        {
                printf("Incorrect \".com\" Inputed\n");
                return 0;
        }
        putchar('t');
        return 1;*/

}

void valiEMail(char *  p)
{
    scanf("%s",p);
    while( !Emailcheck(p) )
    {
        printf("Invalid Input\n");
        scanf("%s",p);
    }
}

void valiPhone(char * p)
{
    int i,flag;
    while(1)
    {
        flag =0;
        for(i=0; i<strlen(p); i++)
        {
            if(!(p[i]<='9' && p[i] >='0') && !(p[i]=='-'))
            {
                flag =1;
            }
        }
        if(!flag)
            return;
        else
            printf("Invalid Phone Number\n");
        scanf("%s",p);
    }

}

void viewData(Conta p,int n)
{
    if(!n)
        printf("No Entries\n");
    else
        printf("%-5d%-16s %-16s %d/%d/%d   \t%-30s%-25s\t%s\n",n,p.firstName,p.lastName,p.dateOBirth.day,p.dateOBirth.month,p.dateOBirth.year,p.address,p.email,p.phoneNumber);

}

void viewDataQ(Conta p,int n)
{
    if(!n)
        printf("No Contacts with the Inputed Last name\n");
    else
        printf("%-5d%-16s \t%-30s\t%-30s\t%s\n",n,p.firstName,p.address,p.email,p.phoneNumber);

}

void printHelp()// prints help menu
{
    printf("L\tLoads in contacts\n");
    printf("Q\tSearches for inputed contact\n");
    printf("A\tAdds user inputed contact\n");
    printf("D\tDeletes a user inputed contact\n");
    printf("M\tModifies a stored contact\n");
    printf("P\tPrints all contacts in phonebook\n");
    printf("S\tSaves data to files\n");
    printf("E\tExits the phonebook\n\n");
}

char errorInput(char com[])// prints error of inputed character
{
    char x;
    while(strlen(com) != 1)
        {
            printf("Error Invalid command\nPlease enter a valid character\n");
            scanf("%s",com);
        }
    x = com[0];
    if( x != 'l' && x != 'q' && x != 'a' && x != 'd' && x != 'm' && x != 'p' && x != 's' &&x != 'e' && x != 'h' && x != 'L' && x != 'Q' &&x != 'A' &&x != 'D' &&x != 'M' &&x != 'P' &&x != 'S' &&x != 'E' &&x != 'H' && x != 0x0A  )
        printf("Error Invalid command\n");
    return x;
}

void printPhonebook()
{
    int i;
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n%-5s%-16s %-16s %s\t%-30s%-25s\t%s\n","ID","First Name","Last Name","Day of Birth","Address","Email Address","Phone Number");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<noOfEntries; i++)
        viewData(Contacts[i],i+1);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void printSort()  //sorts the contacts
{
    int t;
    char in;
    printf("Input 1 to sort by Last Name\nInput 2 to sort by date of birth\n");
    getchar();
    scanf("%c",&in);
    t = atoi (&in);
    while( t!=2 && t!=1 )
    {
        printf("Invalid Input\n");
        scanf("%c",&in);
        t = atoi (&in);
    }
    if(t==1)
        qsort(Contacts,noOfEntries,sizeof(Conta),comparatorString);
    if(t==2)
        qsort(Contacts,noOfEntries,sizeof(Conta),comparatorAge);
    /* for(i=0;i<noOfEntries;i++)
         Contacts[i]=*p[i];*/
    printPhonebook();
}

int choice()
{
    char n[40];
    int te;
    scanf("%s",n);
    if( strlen(n) != 1 )
    {
        printf("please enter 1 or 2");
    }
    else
    {
        te= atoi (n);
        while( te !=1 && te !=2 )
        {
            printf("the number inputed is not in the list\n");
            scanf("%s",n);
            te = atoi (n);
        }
    }
    return te;
}

int choiceCont()
{
    char n[40];
    int te;
    scanf("%s",n);
    te= atoi (n);
    while( te < 1 && te > noOfEntries )
    {
        printf("the inputed number is not in the list\n");
        scanf("%s",n);
        te = atoi (n);
    }
    return te;
}

int choiceContMod(int j)
{
    char n[40];
    int te;
    scanf("%s",n);
    te=atoi(n);
    while( te < 1 && te > j )
    {
        printf("the inputed number is not in the list\n");
        scanf("%s",n);
        te = atoi(n);
    }
    return te;
}

void modChoice(int te)
{
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    viewData(Contacts[te-1],te);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    Conta contactTemp;
    int t;
    printf("Enter the First name\n");
    valiName(contactTemp.firstName);
    printf("Enter the Last name\n");
    valiName(contactTemp.lastName);
    printf("Enter the Date of birth\n");
    printf("Year:");
    contactTemp.dateOBirth.year=valiyear();
    printf("Month:");
    contactTemp.dateOBirth.month=valimonth();
    printf("Day:");
    contactTemp.dateOBirth.day=validay(contactTemp.dateOBirth.year,contactTemp.dateOBirth.month);
    getchar();
    printf("Enter the Address\n");
    valiaddress(contactTemp.address);
    printf("Enter the Email\n");
    printf("Please don't forget to write the @ and the .com\n");
    valiEMail(contactTemp.email);
    printf("Enter the Phone number\n");
    scanf("%s",contactTemp.phoneNumber);
    valiPhone(contactTemp.phoneNumber);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    viewData(contactTemp,te);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Input 1 to Confirm Modification OR Input 2 to Cancel\n");
    t = choice();
    if(t==1)
    {
        Contacts[te-1]=contactTemp;
        justSaved = 0;
    }
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    viewData(Contacts[te-1],te);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printPhonebook();
}

/*double  valifold()
{
    double sum=0;
    int i,j=0;
    for(i=0; i<noOfEntries ;i++)
    {
        while(Contacts[i].firstName[j])
        sum += Contacts[i].firstName[j++];

        while(Contacts[i].lastName[j])
        sum += Contacts[i].lastName[j++];

        while(Contacts[i].email[j])
        sum += Contacts[i].email[j++];

        while(Contacts[i].address[j])
        sum += Contacts[i].address[j++];

        while(Contacts[i].phoneNumber[j])
        sum += Contacts[i].phoneNumber[j++];

        sum += Contacts[i].dateOBirth.year;

        sum += Contacts[i].dateOBirth.day;

        sum += Contacts[i].dateOBirth.month;
    }
    return sum;
}*/

void loads()
{
    FILE * fptr = fopen("phonebook.txt","r");
    //double vali=0;
    if(fptr == NULL)
    {
        printf("Failed to open File");
        return;
    }
    //fscanf(fptr,"%lf\n",&vali);
    while(!feof(fptr))
    {
        fscanf(fptr,"%[^,],",Contacts[noOfEntries].lastName);
        fscanf(fptr,"%[^,],",Contacts[noOfEntries].firstName);
        fscanf(fptr,"%d-",&Contacts[noOfEntries].dateOBirth.day);
        fscanf(fptr,"%d-",&Contacts[noOfEntries].dateOBirth.month);
        fscanf(fptr,"%d,",&Contacts[noOfEntries].dateOBirth.year);
        fscanf(fptr,"%[^,],",Contacts[noOfEntries].address);
        fscanf(fptr,"%[^,],",Contacts[noOfEntries].email);
        fscanf(fptr,"%s\n",Contacts[noOfEntries].phoneNumber);
        noOfEntries++;
    }
    fclose(fptr);
     //printf("%lf  %lf\n",vali,valifold());
    //if( vali == valifold() )
    printf("\nLoad Complete.\n");
    /*else
    {
        noOfEntries = 0;
        printf("Corrupted file\n");
    }*/
printf("%d contacts loaded.\n",noOfEntries);
}

void save()
{
    int i=0;
    FILE * fptr= fopen("phonebook.txt","w");
    if(fptr == NULL)
    {
        printf("Failed to open File");
        return;
    }
    //fprintf(fptr,"%lf\n",valifold());
    for(i=0; i<noOfEntries; i++)
    {
        fprintf(fptr,"%s,%s,%d-%d-%d,%s,%s,%s\n",Contacts[i].lastName,Contacts[i].firstName,Contacts[i].dateOBirth.day,Contacts[i].dateOBirth.month,Contacts[i].dateOBirth.year,Contacts[i].address,Contacts[i].email,Contacts[i].phoneNumber);
    }
    fclose(fptr);
    justSaved = 1;
    printf("\nSave Complete.\n");
}

void addRecord()
{
    Conta contactTemp;
    int t;
    printf("Enter the First name\n");
    valiName(contactTemp.firstName);
    printf("Enter the Last name\n");
    valiName(contactTemp.lastName);
    printf("Enter the Date of birth\n");
    printf("Year:");
    contactTemp.dateOBirth.year=valiyear();
    printf("Month:");
    contactTemp.dateOBirth.month=valimonth();
    printf("Day:");
    contactTemp.dateOBirth.day=validay(contactTemp.dateOBirth.year,contactTemp.dateOBirth.month);
    getchar();
    printf("Enter the Address\n");
    valiaddress(contactTemp.address);
    printf("Enter the Email\n");
    printf("Please don't forget to write the @ and the .com\n");
    valiEMail(contactTemp.email);
    printf("Enter the Phone number\n");
    scanf("%s",contactTemp.phoneNumber);
    valiPhone(contactTemp.phoneNumber);
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    viewData(contactTemp,noOfEntries+1);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Input 1 to Confirm Entry OR Input 2 to Cancel\n");
    t = choice();
    if(t==1)
    {
        Contacts[noOfEntries]=contactTemp;
        noOfEntries+=1;
        justSaved = 0;
        printf("\nRecord Added.\n");
    }
    printPhonebook();
    if(t==2)printf("\nAdded Record Canceled.\n");
}

void exitCode()
{
    int te ;
    if(!justSaved)
    {
        printf("Are you sue you want to exit without saving ?\n");
        printf("Enter 1 to Exit or 2 to cancel\n");
        te=choice();
        if( te == 1 )
            exit(1);
    }
    else
        exit(1);
}

void deleteEntry ()
{
    printPhonebook();
    printf("\nEnter the number of Entry you want to delete\n");
    int t,te;
    char in;
    getchar();
    scanf("%c",&in);
    t = atoi (&in);
    while( t > noOfEntries || t < 0 )
    {
        getchar();
        printf("Invalid Input\n");
        scanf("%c",&in);
        t = atoi (&in);
    }

    printf("Are you sure you want to delete Entry no.%d \n",t);
    printf("Input 1 to confirm or 2 to cancel\n");
    getchar();
    te=choice();
    if(te == 1)
    {
        Contacts[t-1] = Contacts[noOfEntries-1];
        noOfEntries --;
        printPhonebook();
        printf("\n");
    }
    justSaved  = 0;
    printf("\nRecord Deleted.\n");
}

void query()
{
    int i,j=0;
    char name[40];
    printf("Enter the last Name of the Contact\n");
    valiName(name);
    printf("----------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<noOfEntries; i++)
    {
        if(!stricmp(Contacts[i].lastName,name))
        {
            j++;
            viewDataQ(Contacts[i],j);
        }
    }
    printf("----------------------------------------------------------------------------------------------------------\n\nSearch Complete.\n");

}

void modify()
{
    char name[40];
    int te,te1,i,j=0,k[noOfEntries],f=0,r;
    printf("1:Modify by a Last Name sorted list.\n2:Modify by Phone book listing.\n");
    te=choice();
    if(te == 2)
    {
        printPhonebook();
        printf("Enter the number of the contact you want to modify\n");
        te1 = choiceCont();
        printf("Input 1 to confirm or 2 to cancel\n");
        te=choice();
        if(te == 1 )
        {
            modChoice(te1);
            printf("\nRecord modified.\n");
            justSaved=0;
        }
        else
            printf("Modification Canceled");
    }
    else
    {
        printf("Enter the last name of the contact to be modified\n");
        valiName(name);
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
        for(i=0; i<noOfEntries; i++)
        {
            if(!stricmp(Contacts[i].lastName,name))
            {
                f=1;
                k[j]=i+1;
                j++;
                viewData(Contacts[i],j);
            }
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while(!f)
        {
            printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("Name not in Phone book\nRenter Last Name? (1:yes|2:no):");
            printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
            r=choice();
            if(r==1)
            {
                printf("Enter Last Name:");
                valiName(name);
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
                for(i=0; i<noOfEntries; i++)
                {
                    if(!stricmp(Contacts[i].lastName,name))
                    {
                        f=1;
                        k[j]=i+1;
                        j++;
                        viewData(Contacts[i],j);

                    }
                }
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
            }
            else
            {
                printf("\nModification Canceled.");
                return;
            }
        }
        printf("Enter the number of the contact you want to modify\n");
        te1 = choiceContMod(j);
        printf("\nInput 1 to confirm or 2 to cancel\n");
        te=choice();
        if(te == 1 )
        {
            modChoice(k[te1-1]);
            printf("\nRecord Edited Successfully.\n");
            justSaved=0;
        }
        else
            printf("Modification Canceled");
    }

}


