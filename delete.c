int Delete(user login,info *head)
{
    int k;
    FILE *fp;
    info *p=head,*q,*m;
    char cmp[20];
    system("cls");
    printf("��������Ʒ���ƻ��ţ�");
    scanf("%s",cmp);
    while(p)
    {
        if((strcmp(cmp,p->name)==0)||(strcmp(cmp,p->number)==0))
        {
            printf("\n����     ���     ���      ������ַ      ��������      ��������\n");
            printf("\n%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
            printf("\n����ɾ������Ʒ��Ϣ����ȷ�ϣ�");
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
        printf("����Ʒ�����ڣ�");
        return 0;
    }
    else
    {
        printf("\n1��ȷ�ϣ�2��ȡ��:\n��ѡ��");
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
                printf("��Ϣɾ��ʧ�ܣ�");
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
            printf("��Ϣɾ���ɹ���");
            break;
        case 2:
            printf("ȡ���ɹ���");break;
        }
    }
    return 0;
}