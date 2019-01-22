int Excel(info *head)
{
    info *p=head;
    FILE *fp;
    int mark=0;
    fp=fopen("things.xls","w");
    if(fp==NULL)
        printf("您没有任何物品，Excel文档建立失败！");
    fprintf(fp,"名称	编号	分类	生产地址	   生产日期	   过期日期\n");
    while(p)
    {
        fprintf(fp,"%s	%s	%s	%s	%s	%s\n",p->name,p->number,p->leibie,p->address,p->time,p->out);
        p=p->next;
        mark++;
    }
    if(mark)
    {
        printf("Excel文件成功导出！\n");
    }
    return 0;
}