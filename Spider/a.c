#include <stdio.h>
#include <string.h>

struct Signals
{
    char signalname[100];
    int ID;
    int length;
    int values;
};

struct SignalGroup
{
    char groupname[100];
    struct Signals signal[10];
};

struct E2E_Cfg
{
    char frame[100];
    struct SignalGroup signalgroup[10];
};

struct E2E_Cfg cfg[100] = {{"frame1",
                            {
                                {"group01",
                                 {{"signal001", 1, 40, 17},
                                  {"signal002", 1, 40, 17},
                                  {"signal003", 1, 40, 17}}},
                                {"group02",
                                 {{"signal005", 2, 50, 18},
                                  {"signal006", 2, 50, 18},
                                  {"signal007", 2, 50, 18}}},
                                {"group03",
                                 {{"signal009", 3, 60, 19},
                                  {"signal010", 2, 50, 18},
                                  {"signal011", 2, 50, 18}}},
                            }},
                           {"frame2",
                            {
                                {"group04",
                                 {{"signal012", 1, 40, 17},
                                  {"signal013", 1, 40, 17},
                                  {"signal014", 1, 40, 17}}},
                                {"group05",
                                 {{"signal015", 2, 50, 18},
                                  {"signal016", 2, 50, 18},
                                  {"signal017", 2, 50, 18}}},
                                {"group06",
                                 {{"signal018", 3, 60, 19},
                                  {"signal019", 2, 50, 18},
                                  {"signal020", 2, 50, 18}}},
                            }},
                           {"frame3",
                            {
                                {"group07",
                                 {{"signal021", 1, 40, 17},
                                  {"signal022", 1, 40, 17},
                                  {"signal023", 1, 40, 17}}},
                                {"group08",
                                 {{"signal024", 2, 50, 18},
                                  {"signal025", 2, 50, 18},
                                  {"signal026", 2, 50, 18}}},
                                {"group09",
                                 {{"signal027", 3, 60, 19},
                                  {"signal028", 2, 50, 18},
                                  {"signal029", 2, 50, 18}}},
                            }},
                           {"frame3",
                            {
                                {"group10",
                                 {{"signal030", 1, 40, 17},
                                  {"signal031", 1, 40, 17},
                                  {"signal032", 1, 40, 17}}},
                                {"group11",
                                 {{"signal033", 2, 50, 18},
                                  {"signal034", 2, 50, 18},
                                  {"signal035", 2, 50, 18}}},
                                {"group12",
                                 {{"signal036", 3, 60, 19},
                                  {"signal037", 2, 50, 18},
                                  {"signal038", 2, 50, 18}}},
                            }}};

// 查找嵌套结构体数组中的元素
int find_signal3_group3(char signal[])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        // 遍历E2E_Cfg结构体数组中的每个元素
        int j;
        for (j = 0; j < 10; j++)
        {
            // 遍历SignalGroup结构体数组中的每个元素
            int k;
            for (k = 0; k < 10; k++)
            {
                if (strcmp(cfg[i].signalgroup[j].signal[k].signalname, signal) == 0)
                {
                    printf("frame index = %d,signalgroup index = %d,signal index = %d\n", i,
                           j, k);
                    printf("%s\n", cfg[i].frame);
                    printf("%s\n", cfg[i].signalgroup[j].groupname);
                    printf("%s\n", cfg[i].signalgroup[j].signal[k].signalname);
                    cfg[i].signalgroup[j].signal[k].values = 100;
                    printf("cfg[i].signalgroup[j].signal[k].values=%d", cfg[i].signalgroup[j].signal[k].values);
                    return i;
                }
            }
        }
    }
    // 如果未找到group3，打印错误信息
    printf("Failed to find group3 in cfg array\n");

    return -1;
}

int main(void) { find_signal3_group3("signal035"); }
