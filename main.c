#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <string.h>
#include<time.h>
#include<mmsystem.h>
typedef struct
{
    char account[13];
    char password[7];
} user;
typedef struct info
{
    char name[20];
    char number[8];
    char leibie[20];
    char address[20];
    char time[11];
    char out[11];
    struct info *next;
} info;
#include"verify.c"//��¼��֤
#include"rfile.c"//�Ķ��ļ�
#include"save.c"//¼����Ϣ
#include"update.c"//�޸���Ϣ
#include"delete.c"//ɾ����Ϣ
#include"find.c"//��ѯ��Ϣ��������ѯ��Ʒ��Find��������ɸѡ���ؼ���ɸѡ��Class����������Ʒ��ѯ��Overdue����
#include"statistics.c"
#include"excel.c"//������Ϣ

int main()
{
    system("title ������Ʒ�������");
    system("color 0A");
    system("mode con cols=80 lines=30");
    user login;
    info *head,*p;
    int c;
    char password[7];
    int i=0,mark=1;
    for(i=0; i<6; i++) printf("\n");
    i=0;
    printf("                        �X�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�[\n");
    printf("                        �d ��ӭ��¼������Ʒ����ϵͳ �g\n");//��½����
    printf("                        �^�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�a\n\n\n\n");
    PlaySound("music.wav",NULL,SND_LOOP|SND_ASYNC|SND_FILENAME);
    printf("�����������˺�:");
    scanf("%s",login.account);
    printf("��������������:");
    while((login.password[i]=getch())!='\r')
    {
        printf("*");
        i++;
    }
    login.password[i]='\0';
    while(!verify(login)) //��֤�˺�
    {
        system("cls");
        system("color 0C");
        printf("\n\n ������������������\n");
        printf(" �����˺Ų�����! ��\n");
        printf(" ������������������\n");
        printf(" �����������˺�:");
        scanf("%s",login.account);
    }
    for(i=0; i<6; i++)
    {
        password[i]=login.account[i+6];
    }
    password[i]='\0';
    while(mark)   //��֤����
    {
        if((strcmp(password,login.password))==0)
        {
            mark=0;
            system("color 0A");
        }
        else
        {
            system("cls");
            system("color 0C");
            printf(" \n\n ��������������\n");
            printf(" ��������󣡩�\n");
            printf(" ��������������\n");
            printf("�������������룺");
            i=0;
            while((login.password[i]=getch())!='\r')
            {
                printf("*");
                i++;
            }
            login.password[i]='\0';
        }
    }
    head=rfile(login);
    p=head;
    printf("\nwait");
    for(i=0; i<4; i++)
    {
        Sleep(300);
        printf(".");
    }
    printf("\n��¼�ɹ�������");
    Sleep(500);
    system("cls");
    while(1)
    {
        system("color 0A");
        printf("\n\n                     ��������������������\n");
        printf("                     ��������Ʒ����ϵͳ��\n");//��½����
        printf("                     ��������������������\n");
        printf("                     ��1.¼�� �� 2.�޸ĩ�\n");
        printf("                     ��������������������\n");
        printf("                     ��3.ɾ�� ��4.��ѯ ��\n");
        printf("                     ��������������������\n");
        printf("                     ��5.ɸѡ �� 6.���ک�\n");
        printf("                     ��������������������\n");
        printf("                     ��7.ͳ�� ��8.���� ��\n");
        printf("                     ��������������������\n");
        printf("                     ��    0.�˳�      ��\n");
        printf("                     ��������������������\n");
        printf("please choose:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            Save(login,head);
            break;
        case 2:
            Update(login,head);
            break;
        case 3:
            Delete(login,head);
            break;
        case 4:
            Find(head);
            break;
        case 5:
            Class(head);
            break;
        case 6:
            Overdue(head);
            break;
        case 7:
            Statistics(head);
            break;
        case 8:
            Excel(head);
            break;
        case 0:
            for(i=0; i<4; i++)
            {
                Sleep(300);
                printf(".");
            }
            exit(0);
        }
        printf("wait");
        for(i=0; i<4; i++)
        {
            Sleep(300);
            printf(".");
        }
        system("cls");
    }
    return 0;
}

