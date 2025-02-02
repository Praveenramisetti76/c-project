#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee
{
    char name[100], email_ID[50], gender,role_of_emp[50];
    long long int mobile_no,dob;
    int employee_ID;
};
struct employee emp[100];

int start();
void details_entry();
void search_by_id(int id);
void edit_details(int id);
void printing_details(int i);
void flush();
void reenter();
void delete_emp(int id);
void emp_list();
int details_entry_counter = 0;

int main()
{
    int serial_no, id;
    serial_no = start();

    switch (serial_no)
    {
    case 1:
        details_entry();
        break;
    case 2:
        printf("\nSearch for employee\n");
        printf("Enter Employee ID : ");
        scanf("%d", &id);
        search_by_id(id);
        break;
    case 3:
        printf("\nEdit employee details\n");
        printf("Enter Employee ID : ");
        scanf("%d", &id);
        edit_details(id);
        break;
    case 4:
        printf("\nDeleting employee\n");
        printf("Enter Employee ID : ");
        scanf("%d", &id);
        delete_emp(id);
    case 5:
        printf("The employees in this organisation are : ");
        emp_list();
        break;
    case 6:
        printf("Exiting...\n");
        return 0;
        break;
    }
}

int start()
{
    printf("\nWelcome!\n");
    int serial_no;
    printf("1. Register an employee.\n");
    printf("2. Search for an employee.\n");
    printf("3. Edit employee details.\n");
    printf("4. Delete a employee.\n");
    printf("5. Show employee list.\n");
    printf("6. Exit\n");
    printf("\nEnter their respective number to access : ");
    scanf("%d", &serial_no);
    return serial_no;
}

void details_entry()
{
    char doubt;
    char copyname[100];
    printf("\nEnter the following details\n");
    flush();
    printf("Name : ");
    fgets(emp[details_entry_counter].name, sizeof(emp[details_entry_counter].name), stdin);
    printf("Gender : ");
    scanf(" %c", &emp[details_entry_counter].gender);
    printf("Date of Birth : ");
    scanf("%lld",&emp[details_entry_counter].dob);
    flush();
    printf("Mobile Number : ");
    scanf("%lld", &emp[details_entry_counter].mobile_no);
    printf("Employee ID : ");
    scanf("%d", &emp[details_entry_counter].employee_ID);
    printf("Email ID : ");
    scanf(" %s", emp[details_entry_counter].email_ID);
    printf("Role of Employee : ");
    scanf("%s", emp[details_entry_counter].role_of_emp);
    details_entry_counter++;
    printf("\nRegistered successfully\n");
    printf("\nIf you want to register another employee press y otherwise n\n");
    printf("\nEnter your input : ");
    scanf(" %c", &doubt);
    if (doubt == 'y' || doubt == 'Y')
    {
        details_entry();
    }
    else
    {
        reenter();

    }
}

void search_by_id(int id)
{
    int result = 0;
    char doubt;
    for (int i = 0; i < 100; i++)
    {
        if (id == emp[i].employee_ID)
        {
            printing_details(i);
            printf("If you want to search employee again enter y otherwise any character : ");
            scanf(" %c", &doubt);
            if (doubt == 'y' || doubt == 'Y')
            {
                printf("Enter Employee ID : ");
                scanf("%d", &id);
                search_by_id(id);
            }
            else
            {
                reenter();
            }
            result = 1;
            break;
        }
    }
    if (result != 1)
    {
        printf("Invalid Employee ID\n");
        printf("If you want to search employee again enter y otherwise any character : ");
        scanf(" %c", &doubt);
        if (doubt == 'y' || doubt == 'Y')
        {
            printf("Enter Employee ID : ");
            scanf("%d", &id);
            search_by_id(id);
        }
        else
        {
            reenter();
        }
    }
}

void edit_details(int id)
{
    int serial_no, result = 0;
    char doubt;
    char copyname[100];
    for (int i = 0; i < 100; i++)
    {
        if (id == emp[i].employee_ID)
        {
            printing_details(i);
            printf("Enter serial number you want to edit : ");
            scanf("%d", &serial_no);
            switch (serial_no)
            {
            case 1:
                printf("Enter new name : ");
                scanf("%s", copyname);
                strcpy(emp[i].name, copyname);
                printf("\nChanges have been applied successfully");
                break;
            case 2:
                printf("Enter gender : ");
                scanf(" %c", &emp[i].gender);
                printf("\nChanges have been applied successfully");
                break;
            case 3:
                printf("Enter new Date of Birth : ");
                scanf("%lld", &emp[i].dob);
                printf("\nChanges have been applied successfully");
                break;
            case 4:
                printf("Enter new Mobile number : ");
                scanf("%lld", &emp[i].mobile_no);
                printf("\nChanges have been applied successfully");
                break;
            case 5:
                printf("Enter new Employee ID : ");
                scanf("%d", &emp[i].employee_ID);
                printf("\nChanges have been applied successfully");
                break;
            case 6:
                printf("Enter new Email ID : ");
                scanf("%s", emp[i].email_ID);
                printf("\nChanges have been applied successfully");
                break;
            case 7:
                printf("Enter new AADHAR number : ");
                scanf("%s", emp[i].role_of_emp);
                printf("\nChanges have been applied successfully");
                break;
            }
            printf("Do you want to change any other employee details :");
            scanf(" %c", &doubt);
            if (doubt == 'y' || doubt == 'Y')
            {
                printf("Enter Employee ID : ");
                scanf("%d", &id);
                edit_details(id);
            }
            else
            {
                reenter();
            }
            result = 1;
            break;
        }
    }
    if (result != 1)
    {
        printf("Invalid Employee ID\n");
        printf("If you want to search employee again enter y otherwise n : ");
        scanf(" %c", &doubt);
        if (doubt == 'y' || doubt == 'Y')
        {
            printf("Enter Employee ID : ");
            scanf("%d", &id);
            edit_details(id);
        }
        else
        {
            reenter();
        }
    }
}

void printing_details(int i)
{
    printf("The employee details are : \n");
    printf("1. Name : ");
    fputs(emp[i].name,stdout);
    printf("2. Gender : %c\n", emp[i].gender);
    printf("3. Date of Birth : %lld\n", emp[i].dob);
    printf("4. Mobile Number : %lld\n", emp[i].mobile_no);
    printf("5. Employee ID : %d\n", emp[i].employee_ID);
    printf("6. Email ID : %s\n", emp[i].email_ID);
    printf("7. Role of employee : %s\n", emp[i].role_of_emp);
}

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void reenter()
{
    int serial_no,id;
        serial_no = start();
        switch (serial_no)
        {
            case 1:
                details_entry();
                break;
            case 2:
                printf("Enter Employee ID : ");
                scanf("%d", &id);
                search_by_id(id);
                break;
            case 3:
                printf("Enter Employee ID : ");
                scanf("%d", &id);
                edit_details(id);
                break;
            case 4:
                printf("Enter Employee ID : ");
                scanf("%d", &id);
                delete_emp(id);
                break;
            case 5:
                printf("The employees in this organisation are : ");
                emp_list();
                break;
            case 6:
                printf("Exiting...\n");
                exit(1);
        }
}

void delete_emp(int id)
{
    int result = 0,serial_no;
    char doubt,copyname[100];
    for (int i = 0; i < 100; i++)
    {
        if (id == emp[i].employee_ID)
        {
            printing_details(i);
            printf("Do you want to delete this employee details (Press y if yes) : ");
            scanf(" %c", &doubt);
            if( doubt=='Y' || doubt=='y' )
            {
                for(int j=i+1;j<details_entry_counter;j++,i++)
                {
                    strcpy(emp[i].name,emp[j].name);
                    emp[i].mobile_no=emp[j].mobile_no;
                    strcpy(emp[i].role_of_emp,emp[j].role_of_emp);
                    emp[i].dob=emp[j].dob;
                    emp[i].employee_ID=emp[j].employee_ID;
                    emp[i].gender=emp[j].gender;
                    strcpy(emp[i].email_ID,emp[j].email_ID);
                }
                printf("The employee details have been successfully deleted\n");
            }
            printf("Do you want to delete any other employee details (enter y otherwise enter any character) : ");
            printf("Enter your input : ");
            scanf(" %c", &doubt);
            if (doubt == 'y' || doubt == 'Y')
            {
                printf("Enter Employee ID : ");
                scanf("%d", &id);
                delete_emp(id);
            }
            else
            {
                reenter();
            }
            result=1;
        }
    }
    if (result != 1)
    {
        printf("Invalid Employee ID\n");
        printf("If you want to search employee again enter y otherwise enter any character : ");
        printf("Enter your input : ");
        scanf(" %c", &doubt);
        if (doubt == 'y' || doubt == 'Y')
        {
            printf("Enter Employee ID : ");
            scanf("%d", &id);
            delete_emp(id);
        }
        else
        {
            reenter();
        }
    }
}

void emp_list()
{
    for(int i=0;i<details_entry_counter;i++)
    {
        printing_details(i);
        printf("\n");
    }
}