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
    printf("                        �X�j�j�j�j�j�j�j�j�j�[\n");
    printf("                        �d ��ӭ¼����Ʒ��Ϣ �g\n");
    printf("                        �^�m�m�m�m�m�m�m�m�m�a\n\n\n\n");
    while(1)
    {
        printf("1��¼����Ʒ��Ϣ�� 2���������˵�\n��ѡ��");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            p=(info*)malloc(sizeof(info));
            printf("��������Ʒ���ƣ�");
            scanf("%s",name);
            printf("��������Ʒ��ţ�");
            scanf("%s",number);
            printf("��������Ʒ���");
            scanf("%s",leibie);
            printf("��������Ʒ������ַ��");
            scanf("%s",address);
            printf("��������Ʒ��������(��2017.03.03)��");
            scanf("%s",time);
            printf("��������Ʒ��������(��2017.03.03)��");
            scanf("%s",out);
            if((fp=fopen(login.account,"a+"))==NULL)
            {
                printf("��Ϣ¼��ʧ��!");
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
            printf("��Ϣ¼��ɹ���");
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
