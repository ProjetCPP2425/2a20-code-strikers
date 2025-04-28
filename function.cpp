#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>
#include"functions.h"
bool isAlphabetic(const QString str) {
    for (int i = 0; i < str.length(); i++) {
        if (!str[i].isLetter()) {
            return false;
        }
    }
    return true;
}
