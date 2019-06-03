/** @file   FastUseSQLite.h
 * 
 *  @brief  SQLITE 基本操作
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
    // 连接/打开一个数据库
    static void connectFunc();

    // 创建表
    static void createTable();

    // 插入数据
    static void insertTable();
};