#include"Contact_Managment_system.h"

/**
 * @brief function to view all the Contacts
 * 
 * @return test_values 
 */

test_values viewContact()
{
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
}
