int Update(user login,info *head)
{
    system("cls");
    printf("                        ╔╦╦╦╦╦╦╦╦╦╗\n");
    printf("                        ╠ 欢迎修改物品信息 ╣\n");
    printf("                        ╚╩╩╩╩╩╩╩╩╩╝\n\n\n\n");
    FILE *fp;
    info *p=head,*q=head;
    int k;
    char cmp[20],c;
    printf("请输入物品名称或编号：");
    scanf("%s",cmp);
    while(p!=NULL)
    {
        if((strcmp(cmp,p->name)==0)||(strcmp(cmp,p->number)==0))
        {
            break;
        }
        else  p=p->next;
    }
    if(!p) printf("不存在该物品！");
    else
    {

        while(1)
        {
            printf("\n1、修改物品信息； 2、返回主菜单\n请选择：");
            scanf("%d",&k);
            switch(k)
            {
            case 1:
                printf("\n名称     编号     类别      生产地址      生产日期      过期日期\n");
                printf("%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
                printf("\n1、名称 2、编号 3、类别4、生产地址5、生产日期6、过期日期\n");
                printf("\n请选择修改目标:");
                scanf(" %c",&c);
                switch(c)
                {
                case'1':
                    printf("请输入新的名称：");
                    scanf("%s",cmp);
                    strcpy(p->name,cmp);
                    break;
                case'2':
                    printf("请输入新的编号：");
                    scanf("%s",cmp);
                    strcpy(p->number,cmp);
                    break;
                case'3':
                    printf("请输入新的类别：");
                    scanf("%s",cmp);
                    strcpy(p->leibie,cmp);
                    break;
                case'4':
                    printf("请输入新的生产地址：");
                    scanf("%s",cmp);
                    strcpy(p->address,cmp);
                    break;
                case'5':
                    printf("请输入新的生产日期：");
                    scanf("%s",cmp);
                    strcpy(p->time,cmp);
                    break;
                case'6':
                    printf("请输入新的过期日期：");
                    scanf("%s",cmp);
                    strcpy(p->out,cmp);
                    break;
                }
                if((fp=fopen(login.account,"w"))==NULL) printf("信息修改失败！");
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
                printf("信息修改成功！");
                fclose(fp);
                break;
            case 2:
                return 0;
            }

        }
    }
}