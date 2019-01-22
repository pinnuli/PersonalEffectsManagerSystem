info *rfile(user login)
{
    info *head=NULL,*p;
    FILE *fp,*fw;
    if((fp=fopen(login.account,"r"))==NULL)
    {
        fw=fopen(login.account,"w");
        fclose(fw);
        fp=fopen(login.account,"r");
    }
    p=(info *)malloc(sizeof(info));
    while((fscanf(fp,"%s%s%s%s%s%s",p->name,p->number,p->leibie,p->address,p->time,p->out))!=EOF)
    {
        head=Insert(head,p);
        p=(info *)malloc(sizeof(info));
    }
    free(p);
    fclose(fp);
    return head;
}