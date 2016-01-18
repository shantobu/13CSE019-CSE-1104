#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdlib.h>


#define LC 0.30

#define NWD 0.65

#define ISD 7.52

#define VAT .25



void store(int i);

void read(void);

void input(void);

void delete(void);


struct customer
{
    char name[30];

    char address[30];

    char telenumber[15];

    char date[15];

    char month[10];

    float min_local;

    float min_nwd;

    float min_isd;

    float t_local;

    float t_nwd;

    float t_isd;

    float s_total;

    float g_total;


}
p[100];

void main()

{
    system("color f9");

    int n;
    char c;

    printf("\n *************Welcome to Telephone Bill Payment System*************.\n\n              Please chose your option from the menu below\n\n ");

    start:

        system("color f9");


    printf("\n   1.Press 1 for input your data\n   2.Press 2 for show data from file(if exists)\n   3.Press 3 for delete all info from file.\n   4.If you press any alphabet incidentally, the program will be terminated\n   5.Press -1 for closing the program.    \n\n");

    scanf("%d",&n);

    c=getchar();

    if(isalpha(c))
    {

        printf("\n\nYou have pressed a alphabet\nThe program will be terminated \n");

        exit(0);


    }



    while(n!=-1)
    {

        switch(n)
        {



    case 1:

        input();
        break;

    case 2:

        read();
        break;

    case 3:



        delete();


        break;

    default:

        printf("\n You have pressed wrong number. Please press ");


        break;

        }

       goto start;

    }




    printf("\n\nThanks for using the program. Have a nice day %c %c %c",1,1,1);




}



void input(void)


{
    system("color 1f");
int i,n;

printf("\nHow many record u want to input?\nPRESS ANY NUMBER LESS THEN 1 TO RETURNT AT MAIN MENU\n) ");

scanf("%d\n",&n);

for(i=1; i<=n; i++)
{
    printf("\nName of the customer: ");


    gets(p[i].name);


    printf("\nDate of bill: ");

    gets(p[i].date);

    printf("\nAddress: ");

    gets(p[i].address);

    printf("\nTele no.: ");

    gets(p[i].telenumber);

    printf("\nMonth: ");

    gets(p[i].month);

    printf("\nMinutes in local call: ");

    scanf("%f",&p[i].min_local);

    printf("\nMinutes in NWD call: ");

    scanf("%f",&p[i].min_nwd);

    printf("\nMinutes in ISD call: ");

    scanf("%f",&p[i].min_isd);

    p[i].t_local= p[i].min_local*LC;

    p[i].t_nwd= p[i].min_nwd*NWD;

    p[i].t_isd= p[i].min_isd*ISD;

    p[i].s_total= p[i].t_local+p[i].t_isd+p[i].t_nwd;

    p[i].g_total=p[i].s_total+p[i].s_total*VAT;



    store(i);

}

for(i=1;i<=n;i++)

{


 printf("\n*****************************Telephone Bill************************************\n");

 printf("Name: %s                                            Date:%s",p[i].name,p[i].date);

 printf("\n\nAddress: %s                                         Telephone NO.:%s",p[i].address,p[i].telenumber);

 printf("\n\n\n Type          Minute           Rate            Total tk.  ");

 printf("\n\nLocal          %f          %f             %f",p[i].min_local,LC,p[i].t_local);

 printf("\nNWD            %f          %f             %f",p[i].min_nwd,NWD,p[i].t_nwd);

 printf("\nISD            %f          %f            %f",p[i].min_isd,ISD,p[i].t_isd);

 printf("\n________________________________________________________________________________");

 printf("                                                    sub total=%f Tk.\n                                                    VAT 15% = %f Tk.\n\n                                                    Grand total=%f Tk.\n\n",p[i].s_total,(p[i].s_total*VAT), p[i].g_total );




}

}


void store(int i)
{

FILE *f;

f=fopen("Record file.txt","a");



fprintf(f,"*****************************Telephone Bill************************************");

    fprintf(f,"Name: %s                                            Date:%s",p[i].name,p[i].date);

 fprintf(f,"\n\nAddress: %s                                         Telephone NO.:%s",p[i].address,p[i].telenumber);

 fprintf(f,"\n\n\n Type          Minute           Rate                 Total tk.  ");

 fprintf(f,"\nLocal          %f           %f                %f",p[i].min_local,LC,p[i].t_local);

 fprintf(f,"\nNWD            %f          %f                 %f",p[i].min_nwd,NWD,p[i].t_nwd);

 fprintf(f,"\nISD            %f          %f               %f",p[i].min_isd,ISD,p[i].t_isd);

 fprintf(f,"\n________________________________________________________________________________");

 fprintf(f,"                                                    sub total=%f Tk.\n                                                    VAT 15% = %f Tk.\n\n                                                    Grand total=%f Tk.\n\n",p[i].s_total,(p[i].s_total*VAT), p[i].g_total );



    fclose(f);






}

void read(void)
{
    char c;

    FILE *f;

    f=fopen("Record file.txt","r");

    if((c=getc(f))==EOF)
    {
        printf("\n\nNo data found.Please a record first\n\n");

        return;
    }

    while((c=getc(f))!=EOF)
        printf("%c",c);

    fclose(f);



}

void delete (void)
{

    FILE *f;

    char opt;

    //f=fopen("Record file.txt","w");

    printf("\nYou want to erase the file?\nPress y/Y if yes, or press n/N if no.\n");

    scanf(" %c",&opt);

     if(toupper(opt)=='Y')
     {



    if(remove("Record file.txt"))
    {
        printf("\nCan not erase file.\n ");

        return;
    }

    printf("\nErase file successfully.\n");

     }
     else
        printf("\n\nErasing canceled\n\n");
//fclose(f);

}






