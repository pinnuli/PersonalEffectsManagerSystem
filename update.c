int Update(user login,info *head)
{
    system("cls");
    printf("                        �X�j�j�j�j�j�j�j�j�j�[\n");
    printf("                        �d ��ӭ�޸���Ʒ��Ϣ �g\n");
    printf("                        �^�m�m�m�m�m�m�m�m�m�a\n\n\n\n");
    FILE *fp;
    info *p=head,*q=head;
    int k;
    char cmp[20],c;
    printf("��������Ʒ���ƻ��ţ�");
    scanf("%s",cmp);
    while(p!=NULL)
    {
        if((strcmp(cmp,p->name)==0)||(strcmp(cmp,p->number)==0))
        {
            break;
        }
        else  p=p->next;
    }
    if(!p) printf("�����ڸ���Ʒ��");
    else
    {

        while(1)
        {
            printf("\n1���޸���Ʒ��Ϣ�� 2���������˵�\n��ѡ��");
            scanf("%d",&k);
            switch(k)
            {
            case 1:
                printf("\n����     ���     ���      ������ַ      ��������      ��������\n");
                printf("%s%8s%10s%10s       %12s   %12s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
                printf("\n1������ 2����� 3�����4��������ַ5����������6����������\n");
                printf("\n��ѡ���޸�Ŀ��:");
                scanf(" %c",&c);
                switch(c)
                {
                case'1':
                    printf("�������µ����ƣ�");
                    scanf("%s",cmp);
                    strcpy(p->name,cmp);
                    break;
                case'2':
                    printf("�������µı�ţ�");
                    scanf("%s",cmp);
                    strcpy(p->number,cmp);
                    break;
                case'3':
                    printf("�������µ����");
                    scanf("%s",cmp);
                    strcpy(p->leibie,cmp);
                    break;
                case'4':
                    printf("�������µ�������ַ��");
                    scanf("%s",cmp);
                    strcpy(p->address,cmp);
                    break;
                case'5':
                    printf("�������µ��������ڣ�");
                    scanf("%s",cmp);
                    strcpy(p->time,cmp);
                    break;
                case'6':
                    printf("�������µĹ������ڣ�");
                    scanf("%s",cmp);
                    strcpy(p->out,cmp);
                    break;
                }
                if((fp=fopen(login.account,"w"))==NULL) printf("��Ϣ�޸�ʧ�ܣ�");
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
                printf("��Ϣ�޸ĳɹ���");
                fclose(fp);
                break;
            case 2:
                return 0;
            }

        }
    }
}