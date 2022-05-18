#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void main()
{
    //LINKED LIST DECLARATION
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head=NULL, *pos=NULL, *tail=NULL;
   
    //FOR TIME CALCULATION
    struct timeval t0;
       struct timeval t1;
       float elapsed;
  
    int ch, num, entry, count, c;
   
      while(1)
    {
        printf("\n\tMAIN MENU\n1. Insert\n2. Display\n3. Count\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
   
        switch(ch)
        {
            case 1: {
                    printf("\nCHOOSE NUMBER OF ELEMENTS\n1. 10\n2. 100\n3. 1000\n4. 10000\n5. 100000");
                    printf("\n\nEnter your choice: ");
                    scanf("%d", &c);
   
                    switch(c)
                    {
                        case 1: num=10;
                            break;
                        case 2: num=100;
                            break;
                        case 3: num=1000;
                            break;
                        case 4: num=10000;
                            break;
                        case 5: num=100000;
                            break;
                    }
                    gettimeofday(&t0, NULL);
                    for(int i=0; i<num; i++)
                    {
                        if(head==NULL)
                        {
                            head=(struct node *)malloc(sizeof(struct node));
                            entry=rand()%100;
                            head->data=entry;
                            pos=head;
                            tail=head;
                        }
                        else
                        {   
                            tail->next=(struct node *)malloc(sizeof(struct node));
                            tail=tail->next;
                            tail->data=rand()%100;
                        }
                    }
                    gettimeofday(&t1, NULL);
                    elapsed = timedifference_msec(t0, t1);
                    printf("Code executed in %f milliseconds.\n", elapsed);
                    break;
                }
           
            case 2: {
                    pos=head;
                    printf("\nElements are: ");
                    while(pos!=NULL)
                    {
                        printf("\t%d", pos->data);
                        pos=pos->next;
                    }
                    printf("\n");
                    break;
                }
           
       
            case 3: {
                    count=0;
                    pos=head;
                    printf("\nThe total number of elements are: ");
                    while(pos!=NULL)
                    {
                        count++;
                        pos=pos->next;
                    }
                    printf("%d\n", count);
                    break;
                }
           
            case 4: {
                    printf("\nGood bye!\n\n");
                    exit(0);
                }
        }
    }
}
