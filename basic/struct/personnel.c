#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 32
#define SEXSIZE 10

struct personnel_st
{
    int id;
    char name[NAMESIZE];
    int age;
    char sex[SEXSIZE];
};

void p_set(struct personnel_st *p, const struct personnel_st *q)
{
    *p = *q;
}

void p_revise(struct personnel_st *p, const int *newid)
{
    p->id = *newid;
}

void p_show(struct personnel_st *p)
{
    printf("%d %s %d %s\n", p->id, p->name, p->age, p->sex);
}

void menu(void)
{
    printf("1設定員工信息\t2.修改員工訊息\t3.顯示員工訊息\n");
    printf("請選擇你要的操作[1(設定)  2(修改)  3(顯示)  q(退出)]:");
}

int main()
{

    struct personnel_st person, person_tmp;
    int newid, result, choice;
    do
    {
        menu();
        result = scanf("%d", &choice);
        if (result != 1)
            break;
        switch (choice)
        {
        case 1:
            printf("請輸入員工訊息[編號(id) 名字(name) 年齡(age) 性別(sex)]:");
            scanf("%d%s%d%s", &person_tmp.id, person_tmp.name, &person_tmp.age, person_tmp.sex);
            p_set(&person, &person_tmp);
            break;
        case 2:
            printf("請輸入員工新的編號:");
            scanf("%d", &newid);
            p_revise(&person, &newid);
            break;
        case 3:
            p_show(&person);
            break;
        default:
            break;
        }
    } while (1);

    return 0;
}