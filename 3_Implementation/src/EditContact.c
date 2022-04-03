#include<Contact_Managment_system.h>

/**
 * @brief function to modify the Contact
 * 
 * 
 * @return test_values 
 */

void editContact(char name[20],long ph,char address[20],char email[30])
{
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
}
