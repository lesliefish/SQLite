#pragma once
#include "FastUseSQLite.h"

FastUseSQLite::FastUseSQLite()
{
}

FastUseSQLite::~FastUseSQLite()
{
}

void FastUseSQLite::connectTest()
{
    sqlite3* db;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}
