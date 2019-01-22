int Find(info *head)
{
    int k;
    info *p;
    char cmp[20];
    system("cls");
    printf("                        ╔╦╦╦╦╦╦╦╦╦╗\n");
    printf("                        ╠ 欢迎查询物品信息 ╣\n");
    printf("                        ╚╩╩╩╩╩╩╩╩╩╝\n\n\n\n");
    while(1)
    {
        printf("\n1、查询物品信息； 2、返回主菜单\n请选择：");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            printf("\n请输入物品名称或编号：");
            scanf("%s",cmp);
            p=head;
            while(p)
            {
                if((strcmp(cmp,p->name)==0)||(strcmp(cmp,p->number)==0)) break;
                else p=p->next;
            }
            if(!p) printf("该物品不存在！");
            else
            {
                printf("\n名称     编号     类别      生产地址      生产日期      过期日期\n");
                printf("\n%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
            }
            break;
        case 2:
            return 0;
        }
    }
}
int Class(info *head)
{
    info *p=head;
    int mark=0,k,i,j,m,flag;
    char cmp[20];
    system("cls");
    printf("                        ╔╦╦╦╦╦╦╦╦╦╗\n");
    printf("                        ╠ 欢迎筛选物品信息 ╣\n");
    printf("                        ╚╩╩╩╩╩╩╩╩╩╝\n\n\n\n");
     while(1)
    {
        mark=0;
        printf("1、筛选物品信息；2、模糊查找 3、返回主菜单\n请选择：");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            p=head;
            printf("请输入物品类别：");
            scanf("%s",cmp);
            system("cls");
            while(p)
            {
                if(strcmp(cmp,p->leibie)==0)
                {
                    if(mark==0)printf("\n名称     编号     类别      生产地址      生产日期      过期日期\n");
                printf("%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
                    mark=1;
                }
                p=p->next;
            }
            if(mark==0) printf("无此类物品！");
            break;
        case 2:
            p=head;
            printf("请输入物品关键字：");
            scanf("%s",cmp);
            system("cls");
            while(p)
            {
                flag=0;
                i=strlen(cmp);
                j=strlen(p->name);
                for(m=0;m<j;m++)
                {
                    if(cmp[flag]==p->name[m])
                        flag++;
                }
                if(flag==i)
                {
                    if(mark==0)printf("\n名称     编号     类别      生产地址      生产日期      过期日期\n");
                     printf("%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
                    mark=1;
                }
                p=p->next;
            }
            if(mark==0) printf("\n\n没有物品符合关键字！");
            break;
        case 3:
            return 0;
        }
    }
}
int Overdue(info *head)
{
    system("cls");
    int date_now[3],date_th[3],days=0,mark=0,i,k;
    info *p=head;
    char year[5],month[5],day[5],d;
    time_t timep;
    struct tm *q;
    time(&timep);
    q = gmtime(&timep);
    date_now[0]=1900+q->tm_year;
    date_now[1]=q->tm_mon+1;
    date_now[2]=q->tm_mday;
    printf("                        ╔╦╦╦╦╦╦╦╦╦╗\n");
    printf("                        ╠ 欢迎查询物品信息 ╣\n");
    printf("                        ╚╩╩╩╩╩╩╩╩╩╝\n\n\n\n");
     while(1)
    {
        printf("\n1、查询物品信息； 2、返回主菜单\n请选择：");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            printf("\n1、过期物品，2、3个月后过期物品\n");
            printf("please choose:");
            scanf(" %c",&d);
            switch(d)
            {
            case '1':
                p=head;
                if(p==NULL)
                {
                    printf("您没有任何物品！");
                    break;
                }
                while(p)
                {
                    for(i=0; i<4; i++) year[i]=p->out[i];
                    for(i=0; i<2; i++) month[i]=p->out[i+5];
                    for(i=0; i<2; i++) day[i]=p->out[i+8];
                    date_th[0]=atoi(year);
                    date_th[1]=atoi(month);
                    date_th[2]=atoi(day);
                    days=(date_th[0]-date_now[0])*365+(date_th[1]-date_now[1])*30+(date_th[2]-date_now[2]);

                    if(days<=0)
                    {
                        if(mark==0)
                        {
                            mark=1;
                            printf("\n过期物品如下：\n");
                           printf("\n名称     编号     类别      生产地址      生产日期      过期日期\n");
                        }

                printf("%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
                    }
                    p=p->next;
                }
                if(mark==0)printf("您没有过期物品！");
                break;

            case '2':
                p=head;
                mark=0;
                if(p==NULL)
                {
                    printf("您没有任何物品！");
                    break;
                }
                while(p)
                {
                    for(i=0; i<4; i++) year[i]=p->out[i];
                    for(i=0; i<2; i++) month[i]=p->out[i+5];
                    for(i=0; i<2; i++) day[i]=p->out[i+8];
                    date_th[0]=atoi(year);
                    date_th[1]=atoi(month);
                    date_th[2]=atoi(day);
                    days=(date_th[0]-date_now[0])*365+(date_th[1]-date_now[1])*31+(date_th[2]-date_now[2]);
                    if(days<90&&days>0)
                    {
                        if(mark==0)
                        {
                            mark=1;
                            printf("过期物品如下：\n");
                            printf("\n名称     编号     类别      生产地址      生产日期      过期日期\n");
                        }

                    printf("%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
                    }
                    p=p->next;
                }
                if(mark==0)printf("您没有3个月内过期物品！");
                break;
            }
            break;
    case 2:
          return 0;
        }
    }
}
