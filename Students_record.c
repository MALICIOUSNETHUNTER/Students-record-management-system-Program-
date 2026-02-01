#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int roll_n0;
    char name[100];
    float marks;
    struct student *next;
} node;

node *create_list();
void display(node *s);
void count(node *s);
void search(node *s, int data);
node *addatbeg(node *);
node *addatend(node *);
node *addafter(node *, int);
node *addbefore(node *, int);
node *addatpos(node *, int);
node *del(node *, int);
node *reverse(node *);

int main()
{
    int choice, data, item, pos;
    node *start;

    do
    {
        printf("STUDENT RECORDS\n");
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list / Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            start = create_list();
            break;

        case 2:
            display(start);
            break;

        case 3:
            count(start);
            break;

        case 4:
            printf("Enter element to be searched: ");
            scanf("%d", &data);
            search(start, data);
            break;

        case 5:
            addatbeg(start);
            break;

        case 6:
            addatend(start);
            break;

        case 7:
            printf("Enter the roll no after which to insert: ");
            scanf("%d", &item);
            start = addafter(start, item);
            break;

        case 8:
            printf("Enter the roll no before which to insert: ");
            scanf("%d", &item);
            start = addbefore(start, item);
            break;

        case 9:
            printf("Enter the position at which to insert: ");
            scanf("%d", &pos);
            start = addatpos(start, pos);
            break;

        case 10:
            printf("Enter the roll no of the student to be deleted: ");
            scanf("%d", &data);
            start = del(start, data);
            break;

        case 11:
            start = reverse(start);
            break;

        case 12:
            exit(0);

        default:
            printf("Invalid choice!, Try again\n");
        }

    } while (choice != 12);

    return 0;
}

node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

node *create_list()
{
    int roll, flag = 1;
    float marks;
    char answer = 'y';

    node *tem = NULL, *new = NULL, *start = NULL;
    do
    {
        new = getnode();

        if (new == NULL)
        {
            printf("<<<MEMORY IS NOT ALLOCATED>>>");
            return start;
        }

        printf("Enter the roll no of the student: ");
        scanf("%d", &roll);
        getchar();
        printf("Enter the name of the student: ");

        fgets(new->name, sizeof(new->name), stdin);
        new->name[strcspn(new->name, "\n")] = '\0';

        printf("Enter the marks: ");
        scanf("%f", &marks);

        new->roll_n0 = roll;
        new->marks = marks;
        new->next = NULL;

        if (flag == 1)
        {
            start = new;
            tem = start;
            flag = 0;
        }
        else
        {
            tem->next = new;
            tem = new;
        }

        printf("Do you want to enter more elements? (y/n): ");
        scanf(" %c", &answer);

    } while (answer == 'y' || answer == 'Y');
    printf("\nthe list of students is created.\n");
    return start;
}

void display(node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------------\n");

    node *p = start;
    while (p != NULL)
    {
        printf("%-10d %-20s %-10.2f\n",
               p->roll_n0,
               p->name,
               p->marks);
        p = p->next;
    }
}

void count(node *s)
{
    node *p = s;
    int cnt = 0;

    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }

    if (cnt == 0)
        printf("List is empty\n");
    else
        printf("No of students in the list is: %d\n", cnt);
}

void search(node *s, int data)
{
    node *p = s;
    int pos = 1;
    while (p != NULL)
    {
        if (p->roll_n0 == data)
        {
            printf("Roll No. %d found at position %d\n", data, pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("Roll No. %d not found in the list.\n", data);
}

node *addatbeg(node *s)
{
    node *tem, *new;
    new = getnode();

    if (new == NULL)
    {
        printf("<<<MEMORY IS NOT ALLOCATED>>>");
        return s;
    }

    printf("Enter student Roll no : ");
    scanf("%d", &new->roll_n0);
    getchar();
    printf("Enter Student name: ");
    fgets(new->name, sizeof(new->name), stdin);
    new->name[strcspn(new->name, "\n")] = '\0';
    printf("Enter Student marks: ");
    scanf("%f", &new->marks);
    new->next = NULL;
    if (s == NULL)
    {
        s = new;
    }
    else
    {
        new->next = s;
        s = new;
    }
    return s;
}

node *addatend(node *s)
{
    node *tem, *new;
    new = getnode();

    if (new == NULL)
    {
        printf("<<<MEMORY IS NOT ALLOCATED>>>\n");
        return s;
    }

    printf("Enter Student roll no: ");
    scanf("%d", &new->roll_n0);
    getchar();
    printf("Enter name: ");
    fgets(new->name, sizeof(new->name), stdin);
    new->name[strcspn(new->name, "\n")] = '\0';
    printf("Enter marks: ");
    scanf("%f", &new->marks);
    new->next = NULL;

    if (s == NULL)
    {
        s = new;
    }
    else
    {
        tem = s;
        while (tem->next != NULL)
        {
            tem = tem->next;
        }
        tem->next = new;
    }
    return s;
}

node *addafter(node *s, int item)
{
    node *new, *tem;

    new = getnode();

    if (new == NULL)
    {
        printf("<<<MEMORY IS NOT ALLOCATED>>>");
        return s;
    }

    printf("Enter Student roll no: ");
    scanf("%d", &new->roll_n0);
    getchar();
    printf("Enter name: ");
    fgets(new->name, sizeof(new->name), stdin);
    new->name[strcspn(new->name, "\n")] = '\0';
    printf("Enter marks: ");
    scanf("%f", &new->marks);
    new->next = NULL;

    if (s == NULL)
    {
        printf("List is Empty!\n");
        return s;
    }
    else
    {
        tem = s;
        while (tem != NULL)
        {
            if (tem->roll_n0 == item)
            {
                new->next = tem->next;
                tem->next = new;
                return s;
            }
            else
                tem = tem->next;
        }
    }
    printf("Roll no. %d not found in the list.\n", item);
    return s;
}

node *addbefore(node *s, int item)
{

    node *new, *tem;

    if (s == NULL)
    {
        printf("List is empty!\n");
        return s;
    }
    if (s->roll_n0 == item)
    {
        return addatbeg(s);
    }
    tem = s;
    while (tem->next != NULL)
    {
        if (tem->next->roll_n0 == item)
        {
            new = getnode();

            if (new == NULL)
            {
                printf("<<<MEMORY IS NOT ALLOCATED>>>\n");
                return s;
            }
            printf("Enter Student roll no: ");
            scanf("%d", &new->roll_n0);
            getchar();
            printf("Enter name: ");
            fgets(new->name, sizeof(new->name), stdin);
            new->name[strcspn(new->name, "\n")] = '\0';
            printf("Enter marks: ");
            scanf("%f", &new->marks);
            new->next = tem->next;
            tem->next = new;
            return s;
        }
        tem = tem->next;
    }
    printf("Roll no %d is not present in the list..\n", item);
    return s;
}

node *addatpos(node *s, int item)
{
    node *new, *tem;
    if (s == NULL)
    {
        printf("List is empty!\n");
        return s;
    }
    if (s->roll_n0 == item)
    {
        return addatbeg(s);
    }
    tem = s;
    while (tem->next != NULL)
    {
        if (tem->next->roll_n0 == item)
        {
            new = getnode();
            if (new == NULL)
            {
                printf("<<<MEMORY IS NOT ALLOCATED>>>");
                return s;
            }
            printf("Enter Student roll no: ");
            scanf("%d", &new->roll_n0);
            getchar();
            printf("Enter name: ");
            fgets(new->name, sizeof(new->name), stdin);
            new->name[strcspn(new->name, "\n")] = '\0';
            printf("Enter marks: ");
            scanf("%f", &new->marks);
            new->next = tem->next;
            tem->next = new;
            return s;
        }
        tem = tem->next;
    }
    printf("Roll no %d is not present in the list..\n", item);
    return s;
}

node *del(node *start, int data)
{
    node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    if (start->roll_n0 == data)
    {
        tmp = start;
        start = start->next;
        free(tmp);
        return start;
    }

    p = start;
    while (p->next != NULL)
    {
        if (p->next->roll_n0 == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return start;
        }
        p = p->next;
    }
    printf("Element %d not found\n", data);
    return start;
}

node *reverse(node *start)
{
    node *prev, *ptr, *n;
    prev = NULL;
    ptr = start;
    while (ptr != NULL)
    {
        n = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = n;
    }
    start = prev;
    return start;
}