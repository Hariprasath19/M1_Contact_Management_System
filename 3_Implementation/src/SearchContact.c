#include<Contact_Managment_system.h>
/**
 * @brief function to find the details about a contact
 * 
 * 
 * @return test_values 
 */

test_values searchContact(char name)
{
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
}
  
