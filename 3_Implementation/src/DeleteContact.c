#include<Contact_Managment_system.h>

/**
 * @brief function to remove the details of a Contact
 * 
 * @param name 
 * @return test_values 
 */

test_values deleteContact(char name)
{
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
}
