//
// Created by zhihui on 7/16/19.
//

#ifndef HIGHPRECISION_INCLUDE_GETELEM_H_
#define HIGHPRECISION_INCLUDE_GETELEM_H_

#include <iostream>
#include "../include/DataStructs.h"

int GetElem(LinkList &L, int i)
{
    LNode *p;
    // p = (LinkList)malloc(sizeof(LNode));
    p = L->next;
    int j=0;
    while(p &&j<i)
    {
        p=p->next;
        ++j;
    }
    return p->data;
}

#endif //HIGHPRECISION_INCLUDE_GETELEM_H_
