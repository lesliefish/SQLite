/** @file   FastUseSQLite.h
 * 
 *  @brief  SQLITE ��������
 *  @note
 *  @author lesliefish
 *  @date   2019/06/03
 */
#pragma once
#include <stdio.h>
#include <sqlite3.h>
class FastUseSQLite
{
public:
    FastUseSQLite();
    ~FastUseSQLite();

    static int callback(void* NotUsed, int argc, char** argv, char** azColName);

public:
    // ����/��һ�����ݿ�
    static void connectFunc();

    // ������
    static void createTable();

    // ��������
    static void insertTable();
};