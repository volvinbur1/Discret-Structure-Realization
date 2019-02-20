#include <stdio.h>
#include <iostream>

#include <windows.h>
#include <sqlext.h>

//#using <System.Data.dll>

//using namespace System::Data::OleDb;

SQLCHAR dataForComunication[] = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\\Users\volvinbur\Documents\BookInfo.accdb;";

int main()
{
	SQLHDBC connHandle = NULL; // statement handle
	SQLHENV envirHandle = NULL; // statement handle
	SQLHSTMT statHandle = NULL; // statement handle

	SQLRETURN retCode; // place for return data

	SQLCHAR outputData[256];
	SQLSMALLINT connLengh2Pt;

	retCode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &envirHandle);
	retCode = SQLAllocHandle(SQL_HANDLE_DBC, envirHandle, &connHandle);

	retCode = SQLDriverConnect(connHandle, NULL, (SQLCHAR*)dataForComunication, SQL_NTS, (SQLCHAR*)outputData, sizeof(outputData), &connLengh2Pt, SQL_DRIVER_NOPROMPT);

	if (SQL_SUCCEEDED(retCode))
		printf("Yeeeah, bitch. Connection was set correct");
	else
		printf("Vova you are an idiot. Never ever never take a code for questions on StackOverFlow");

	SQLDisconnect(connHandle);

	SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, envirHandle);
	
	getchar();
	return 0;
}
