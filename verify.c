
info *Insert(info *head,info *p)
{
    info *q=head;
    if(p==NULL) return head;
    if(head==NULL)
    {
        head=p;
        head->next=NULL;
        return head;
    }
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=p;
    p->next=NULL;
    return head;
}
int verify(user login)
{
    int mark=0;
    char cmp[13];
    FILE *fp;
    if((fp=fopen("mingdan.in","r"))==NULL)
        printf("打开文件失败");
    while((fgets(cmp,13,fp))!=NULL)
    {
        if((strcmp(cmp,login.account))==0)
        {
            mark=1;
            break;
            fclose(fp);
        }
    }
    return mark;
}
