int Excel(info *head)
{
    info *p=head;
    FILE *fp;
    int mark=0;
    fp=fopen("things.xls","w");
    if(fp==NULL)
        printf("��û���κ���Ʒ��Excel�ĵ�����ʧ�ܣ�");
    fprintf(fp,"����	���	����	������ַ	   ��������	   ��������\n");
    while(p)
    {
        fprintf(fp,"%s	%s	%s	%s	%s	%s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
        p=p->next;
        mark++;
    }
    if(mark)
    {
        printf("Excel�ļ��ɹ�������\n");
    }
    return 0;
}