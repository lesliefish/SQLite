#include "FastUseSQLite.h"
#include <string>

FastUseSQLite::FastUseSQLite()
{
}

FastUseSQLite::~FastUseSQLite()
{
}

int FastUseSQLite::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

/*
 * @func   FastUseSQLite::connectTest
 * @brief  连接数据库
 * @return void
 */
void FastUseSQLite::connectFunc()
{
    sqlite3* db;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}

/*
 * @func   FastUseSQLite::createTable
 * @brief  create table test
 * @return void
 */
void FastUseSQLite::createTable()
{
    sqlite3* db;
    char* zErrMsg = 0;
    int  rc;

    /* Open database */
    rc = sqlite3_open("test.db", &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
    }

    std::string sql = "CREATE TABLE COMPANY("  \
        "ID INT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL," \
        "AGE            INT     NOT NULL," \
        "ADDRESS        CHAR(50)," \
        "SALARY         REAL );";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }
    sqlite3_close(db);
    return;
}
