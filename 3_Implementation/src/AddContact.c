#include<library_Managment_system.h>
**
 * @brief function to add new contacts
 * 
 * @return test_values 
 */

test_values addContact(char name[20],long ph,char address[20],char email[30])
{
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
}
