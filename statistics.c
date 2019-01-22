int Statistics(info *head)
{
    info *p,*q,*h2,*h1=NULL;
    char sn[20],qo[20];
    int i,k;
    system("cls");
    h2=(info *)malloc(sizeof(info));
    p=head;
    while(p)
    {
        strcpy(h2->leibie,p->leibie);
        h1=Insert(h1,h2);
        p=p->next;
        h2=(info *)malloc(sizeof(info));
    }
    free(h2);
    printf("\n\n ┏━━━━━━━━━━┓\n");
    printf(" ┃   分类   ┃   数目 ┃ \n");
    printf(" ┗━━━━━━━━━━┛\n");
    while(h1!=NULL)
    {

        strcpy(sn,h1->leibie);
        q=h1->next;
        i=1;
        while(q!=NULL&&h1->leibie[0]!='\0')
        {
            strcpy(qo,q->leibie);
            if(strcmp(qo,sn)==0&&q->leibie[0]!='\0')
            {
                i++;
                q->leibie[0]='\0';
                q=q->next;
            }
            else
                {
                    q=q->next;
                }

        }
        if(h1->leibie[0]!='\0')
         {
             printf(" ┃%-7s   ┃   %-5d┃ \n",h1->leibie,i);
             printf(" ┗━━━━━━━━━━┛\n");
         }
            h1=h1->next;
    }
    printf("按'1'返回主菜单:");
    while(1)
    {
         scanf("%d",&k);
         if(k==1)  return 0;
    }
}
