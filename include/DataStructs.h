//
// Created by zhihui on 7/16/19.
#include <string>

#ifndef HIGHPRECISION_INCLUDE_DATASTRUCTS_H_
#define HIGHPRECISION_INCLUDE_DATASTRUCTS_H_

//
typedef struct LNode{
//    int data;
    std::string data;
    struct LNode *next;
}LNode, *LinkList;

#endif //HIGHPRECISION_INCLUDE_DATASTRUCTS_H_
