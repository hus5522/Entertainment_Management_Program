#pragma once
#include <stdio.h>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

bool DBConnect();
void DBDisconnect();


SQLHENV hEnv = NULL;
SQLHDBC hDbc = NULL;

bool DBConnect() {
	SQLRETURN Ret;

	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS) {
		return false;
	}

	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS) {
		return false;
	}

	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS) {
		return false;
	}

	Ret = SQLConnect(hDbc, (SQLCHAR *)"DB01_SERVER", SQL_NTS, (SQLCHAR *)"DB01", SQL_NTS, (SQLCHAR *)"1111", SQL_NTS);

	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
	{
		return false;
	}

	return true;
}

void DBDisconnect()
{
	SQLDisconnect(hDbc);					// Disconnect from the SQL Server
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);	// Free the Connection Handle
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);	// Free the Environment Handle
}
