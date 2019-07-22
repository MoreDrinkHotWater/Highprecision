#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "include/DataStructs.h"
#include "include/Add.h"
#include "include/Sub.h"
#include "include/Mul.h"
#include <random>
#include <string>

void String_toInt(std::string str, int *arr, int length);
void CreateLinkList(LinkList &L, int arr[], int n);
void output(LinkList &L);
int substring(std::string str, int length);

int main() {

    LinkList first_LinkList;
    first_LinkList = (LinkList)malloc(sizeof(LNode));
    first_LinkList->next = nullptr;

    LinkList second_LinkList;
    second_LinkList = (LinkList)malloc(sizeof(LNode));
    second_LinkList->next = nullptr;

//    std::string first =  "74342226";
//    std::string second = "35757";

//    std::string first =  "74343";
//    std::string second = "35757";

    std::string first =         "985757456189";
    std::string second = "1274314252687532121";

//    std::string first = "1274314252687532121";
//    std::string second =       "985757456189";

//    std::string first =  "7434222687532121";
//    std::string second =      "35757456189";

//    std::string first =  "985757456189";
//    std::string second =       "127431";

    first = std::string(first.rbegin(),first.rend());
    second = std::string(second.rbegin(),second.rend());

    int first_length = 0, second_length = 0 ;
    first_length = substring(first, first_length);
    second_length =  substring(second, second_length);


//    std::cout<<"first_length: "<<first_length<<std::endl;
//    std::cout<<"first: "<<first.length()<<std::endl;

//    std::cout<<"second_length: "<<second_length<<std::endl;
//    std::cout<<"second: "<<second.length()<<std::endl;

    // 定义一个字符串数组 存储 数据的每一位
    int firstarr[first_length];
    int secondarr[second_length];

    String_toInt(first, firstarr, first_length);
    String_toInt(second, secondarr, second_length);

    CreateLinkList(first_LinkList,firstarr,first_length);
    CreateLinkList(second_LinkList,secondarr,second_length);

    Add firstAddsecond;

    if(first.length()>=second.length())
    {
        LinkList result = firstAddsecond.add(first_LinkList,second_LinkList,first_length,second_length);
    }

    else
    {
        LinkList result = firstAddsecond.add(second_LinkList,first_LinkList,second_length,first_length);
    }

    output(first_LinkList);
    output(second_LinkList);
}

void String_toInt(std::string str, int *arr, int length)
{
    int k = 0;
    for (int i = 0; i < length; ++i) {

            while(k < str.length())
            {
                std::cout<<"K: "<<k<<std::endl;

                std::string temp_char = str.substr(k, 4);


                std::cout<<"temp_char.c_str(): "<<temp_char.c_str()<<std::endl;

                arr [i] = atoi(temp_char.c_str());

                k=k+4;

                break;
            }
    }

}

int substring(std::string str, int length)
{
    if(str.length()%4==0)
    {
        length = str.length()/4;

    }
    else
    {
        length = str.length() / 4 + 1;

    }
    return length;
}

void CreateLinkList(LinkList &L, int arr[], int n)
{
      LNode *p;

      for(int i = n; i>0; i--)
      {
          p = (LinkList) malloc(sizeof(LNode));
          p->data = arr[i-1];

          p->next = L->next;
          L->next=p;
      }
}

void output(LinkList &L)
{
    LNode *p;
    p=L->next;
    while(p!=NULL)
    {
        printf("%d\n",atoi(p->data.c_str()));
        p=p->next;
    }
}
