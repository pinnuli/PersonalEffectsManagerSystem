int Save(user login,info *head)
{
    FILE *fp;
    info *p;
    char name[20];
    char number[8];
    char leibie[20];
    char address[20];
    char time[11];
    char out[11];
    int k;
    system("cls");
    printf("                        ╔╦╦╦╦╦╦╦╦╦╗\n");
    printf("                        ╠ 欢迎录入物品信息 ╣\n");
    printf("                        ╚╩╩╩╩╩╩╩╩╩╝\n\n\n\n");
    while(1)
    {
        printf("1、录入物品信息； 2、返回主菜单\n请选择：");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            p=(info*)malloc(sizeof(info));
            printf("请输入物品名称：");
            scanf("%s",name);
            printf("请输入物品编号：");
            scanf("%s",number);
            printf("请输入物品类别：");
            scanf("%s",leibie);
            printf("请输入物品生产地址：");
            scanf("%s",address);
            printf("请输入物品生产日期(如2017.03.03)：");
            scanf("%s",time);
            printf("请输入物品过期日期(如2017.03.03)：");
            scanf("%s",out);
            if((fp=fopen(login.account,"a+"))==NULL)
            {
                printf("信息录入失败!");
                return 0;
            }
            fputs(name,fp);
            fputc('\n',fp);
            fputs(number,fp);
            fputc('\n',fp);
            fputs(leibie,fp);
            fputc('\n',fp);
            fputs(address,fp);
            fputc('\n',fp);
            fputs(time,fp);
            fputc('\n',fp);
            fputs(out,fp);
            fputc('\n',fp);
            printf("信息录入成功！");
            strcpy(p->name,name);
            strcpy(p->number,number);
            strcpy(p->leibie,leibie);
            strcpy(p->address,address);
            strcpy(p->time,time);
            strcpy(p->out,out);
            p->next=NULL;
            Insert(head,p);
            fclose(fp);
            break;
        case 2:
            return 0;
        }
    }
}
