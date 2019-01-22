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
#include"verify.c"//登录验证
#include"rfile.c"//阅读文件
#include"save.c"//录入信息
#include"update.c"//修改信息
#include"delete.c"//删除信息
#include"find.c"//查询信息，包括查询物品（Find）、分类筛选、关键字筛选（Class）、过期物品查询（Overdue）等
#include"statistics.c"
#include"excel.c"//导出信息

int main()
{
    system("title 个人物品管理程序");
    system("color 0A");
    system("mode con cols=80 lines=30");
    user login;
    info *head,*p;
    int c;
    char password[7];
    int i=0,mark=1;
    for(i=0; i<6; i++) printf("\n");
    i=0;
    printf("                        ╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗\n");
    printf("                        ╠ 欢迎登录个人物品管理系统 ╣\n");//登陆界面
    printf("                        ╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝\n\n\n\n");
    PlaySound("music.wav",NULL,SND_LOOP|SND_ASYNC|SND_FILENAME);
    printf("请输入您的账号:");
    scanf("%s",login.account);
    printf("请输入您的密码:");
    while((login.password[i]=getch())!='\r')
    {
        printf("*");
        i++;
    }
    login.password[i]='\0';
    while(!verify(login)) //验证账号
    {
        system("cls");
        system("color 0C");
        printf("\n\n ┏━━━━━━━┓\n");
        printf(" ┃该账号不存在! ┃\n");
        printf(" ┗━━━━━━━┛\n");
        printf(" 请重新输入账号:");
        scanf("%s",login.account);
    }
    for(i=0; i<6; i++)
    {
        password[i]=login.account[i+6];
    }
    password[i]='\0';
    while(mark)   //验证密码
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
            printf(" \n\n ┏━━━━━┓\n");
            printf(" ┃密码错误！┃\n");
            printf(" ┗━━━━━┛\n");
            printf("请重新输入密码：");
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
    printf("\n登录成功！！！");
    Sleep(500);
    system("cls");
    while(1)
    {
        system("color 0A");
        printf("\n\n                     ┏━━━━━━━━┓\n");
        printf("                     ┃个人物品管理系统┃\n");//登陆界面
        printf("                     ┃━━━━━━━━┃\n");
        printf("                     ┃1.录入 ┃ 2.修改┃\n");
        printf("                     ┃━━━━━━━━┃\n");
        printf("                     ┃3.删除 ┃4.查询 ┃\n");
        printf("                     ┃━━━━━━━━┃\n");
        printf("                     ┃5.筛选 ┃ 6.过期┃\n");
        printf("                     ┃━━━━━━━━┃\n");
        printf("                     ┃7.统计 ┃8.导出 ┃\n");
        printf("                     ┃━━━━━━━━┃\n");
        printf("                     ┃    0.退出      ┃\n");
        printf("                     ┗━━━━━━━━┛\n");
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

