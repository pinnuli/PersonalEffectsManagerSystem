int Delete(user login,info *head)
{
    int k;
    FILE *fp;
    info *p=head,*q,*m;
    char cmp[20];
    system("cls");
    printf("请输入物品名称或编号：");
    scanf("%s",cmp);
    while(p)
    {
        if((strcmp(cmp,p->name)==0)||(strcmp(cmp,p->number)==0))
        {
            printf("\n名称     编号     类别      生产地址      生产日期      过期日期\n");
            printf("\n%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
            printf("\n即将删除该物品信息，请确认：");
            break;
        }
        else
        {
            m=p;
            p=p->next;
        }
    }
    if(!p)
    {
        printf("该物品不存在！");
        return 0;
    }
    else
    {
        printf("\n1、确认；2、取消:\n请选择：");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            if(p==head)
            {
                head=p->next;
            }
            else
            {
                m->next=p->next;
            }
            free(p);
            q=head;
            if((fp=fopen(login.account,"w"))==NULL)
            {
                printf("信息删除失败！");
                return 0;
            }
            while(q!=NULL)
            {
                fputs(q->name,fp);
                fputc('\n',fp);
                fputs(q->number,fp);
                fputc('\n',fp);
                fputs(q->leibie,fp);
                fputc('\n',fp);
                fputs(q->address,fp);
                fputc('\n',fp);
                fputs(q->time,fp);
                fputc('\n',fp);
                fputs(q->out,fp);
                fputc('\n',fp);
                q=q->next;
            }
            fclose(fp);
            printf("信息删除成功！");
            break;
        case 2:
            printf("取消成功！");break;
        }
    }
    return 0;
}