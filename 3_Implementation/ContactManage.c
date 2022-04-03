#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>

struct contact
{
    long ph;
    char name[20],address[20],email[30];
} list;

char query[20],name[20];
FILE *fp, *ft;
int x,num,ch,len,found;

int main()
{
main:
    system("hp");    /* ************Main menu ***********************  */

void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =                  CONTACT                  =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                  SYSTEM                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}
    welcomeMessage();
    //printf("\n\t **** Welcome to Contact Management System (CMS) ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t************************\n\t\t(1) Create a new Contact\n\t\t(2) All Contacts List\n\t\t(3) Search for a contact\n\t\t(4) Delete a Contact\n\t\t(5) Edit a Contact\n\t\t(0) Exit\n\t\t************************\n\t\t");


    printf("Enter your option :");
    scanf("%d",&ch);

    switch(ch)
    {
    case 0:
        printf("\n\n\t\tAre you sure you want to exit??");
        break;

        /* *********************Adding of new new contacts***************  */
    case 1:
        system("cls");
        fp=fopen("contact.dll","a");
        for (;;)
        {
            fflush(stdin);
            printf("To exit enter  enter blank space in the name input\nName :");
            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);

            printf("Phone.no :");
            scanf("%ld",&list.ph);


            fflush(stdin);

            printf("address :");
            scanf("%[^\n]",&list.address);

            fflush(stdin);

            printf("email ID:");
            gets(list.email);
            printf("\n");
            printf("Added Contact Successfully \n");
            fwrite(&list,sizeof(list),1,fp);
        }

        fclose(fp);

        break;

        /* *********************list of contacts*************************  */

    case 2:

        system("cls");
        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone.No\t    Address\t\tE-mail ID.\n=================================================================\n\n");

        for(x=97; x<=122; x=x+1)
        {
            fp=fopen("contact.dll","r");
            fflush(stdin);
            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==x || list.name[0]==x-32)
                {
                    printf("\nName       \t: %s\nPhone.No\t: %ld\nAddress       \t: %s\nEmail ID\t: %s\n",list.name, list.ph,list.address,list.email);
                    printf("Viewed all the Contacts Successfully");
                    found++;
                }
            }
            if(found!=0)
            {
                printf("=========================================================== [%c]-(%d)\n\n",x-32,found);
                getch();
            }
            fclose(fp);

        }
        break;
        /* *******************search contacts**********************  */

    case 3:
        system("cls");
        do
        {
            found=0;
            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact you wish to search: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            len=strlen(query);
            fp=fopen("contact.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(x=0; x<=len; x++)
                    name[x]=list.name[x];

                name[len]='\0';

                if(stricmp(name,query)==0)
                {
                    printf("\n..::Name\t: %s\n..::Phone.No\t: %ld\n..::Address\t: %s\n..::Email ID\t: %s\n",list.name,list.ph,list.address,list.email);
                    found++;

                    if (found%4==0)
                    {
                        printf("..::Press any key to continue::..");
                        getch();

                    }
                }
            }
            if(found==0)
                printf("\n..::No match found!");
            else{
                printf("\n..::%d match(s) found! \n",found);
                printf("Searched successfully");}
            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);

        }
        while(ch==1);
        break;


        /* ********************delete contacts**********************/

    case 4:
        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t=========================\n\t..::Enter the name of contact you wish to delete:");
        scanf("%[^\n]",&name);

        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        printf("Delete the specified Contact Successfully");
        rename("temp.dat","contact.dll");
        break;

    
        /* *********************edit contacts************************/

    case 5:

        system("cls");

        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact you wish to edit:");
        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::Name:");
        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::Phone.No:");
        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::address:");
        scanf("%[^\n]",&list.address);

        fflush(stdin);

        printf("..::email ID:");
        gets(list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);
        fclose(ft);

        remove("contact.dll");
        rename("temp.dat","contact.dll");
        printf("Contact Modified Successfully");
        break;
    
    default:
        printf("Invalid choice");
        break;
    }
    printf("\n\n\n..::Enter your Option:\n\n\t(1) Main Menu\t\t(0) Exit\n");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1: 
        goto main;
    case 0:
        break;
    default:
        printf("Invalid option");
        break;
    }
return 0;
}

