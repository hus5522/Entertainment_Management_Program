#include "Main.h"
#include "DB_control.h"
#include <string>
#include <iostream>
using namespace std;

//view table
void DB_Control::show_Agency() {

	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];

		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM AGENCY;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);

			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("---------------------------------------------------------------\n");
			printf("소속사명  대표\t    전화번호\t  \t주소\n");
			printf("---------------------------------------------------------------\n");
			while (SQLFetch(hStmt) != SQL_NO_DATA) {

				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf("NULL  ");
					else
						printf("%-6s", data[i]);
				}
				printf("\n");

			}
			printf("---------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
	
}

void DB_Control::show_Manager() {

	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM MANAGER;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}
			
			printf("----------------------------------------------------------------------------------\n");
			printf("ID\t이름\t\t생년월일\t입사일\t\t월급\t선임ID\t소속사\n");
			printf("----------------------------------------------------------------------------------\n");
			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf("NULL\t");
					else
						printf("%-6s\t", data[i]);
				}
				printf("\n");
			}
			printf("----------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}

}

void DB_Control::show_Singer() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM SINGER;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("본명\t  활동명    데뷔일\t   생년월일\t  월급\t  소속그룹명\t     대표곡\t   매니저ID\t 소속사\t개인팬클럽\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL               ");
					else {
						if(i == 5)
							printf(" %-6s", data[i]);
						else
							printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("-------------------------------------------------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::show_SinglePan() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM SINGLEPAN;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("------------------------------------------------------------------\n");
			printf("본명\t  활동명    개인팬클럽명   결성일\t 기수\t회원수\n");
			printf("------------------------------------------------------------------\n");
			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL               ");
					else {
							printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::show_Group() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM GROUPS;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("-------------------------------------------------------------------------------\n");
			printf("그룹명\t    데뷔일    멤버수  매니저ID\t그룹팬클럽명  소속사\t 대표곡\n");
			printf("-------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL               ");
					else {
						if (i == 4)
							printf("   %-6s", data[i]);
						else
							printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("-------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::show_GroupPan() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM GROUPPAN;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("-------------------------------------------------------------------------------\n");
			printf("그룹명\t  그룹팬클럽명   결성일       기수    회원수\n");
			printf("-------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL               ");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("-------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::show_Actor() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM ACTOR;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("본명\t  활동명    생년월일       데뷔일         월급\t   매니저ID  소속사\t대표작\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL               ");
					else {
						if (i == 5)
							printf("\t%-6s", data[i]);
						else
							printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::show_Film() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][20];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM DISTRIBUTED_MOVIE;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("영화ID  영화제목 \t   개봉일       배급사       연령제한\t     영화관ID\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL               ");
					else {
						if (i == 0)
							printf("%-6s  ", data[i]);
						else if(i==4)
							printf("%-6s\t", data[i]);
						else
							printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::show_Theater() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT * FROM THEATER;");
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("영화관ID  영화관명\t      주소               \t    전화번호          상영관 수\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL               ");
					else {
						if (i == 0)
							printf("%-6s    ", data[i]);
						else if(i==3)
							printf("%-6s", data[i]);
						else
							printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

//select menu
void DB_Control::insert_Query() {
	
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		SQLRETURN retcode;

		char inserted[300]; //사용자입력 쿼리를 받는 변수 선언
		
		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][30];
		SQLINTEGER nulldata[50];

		int i;

		//cin.ignore();
		printf("쿼리문 입력 : ");
		cin.getline(inserted, 300);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "%s", inserted);
			retcode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
				printf("Query Execute Error \n");
				return;
			}

			if (strstr(inserted, "SELECT") != NULL) { // SELECT가 아닌 구문을 썻을때 발생하는 이상현상을 막기위한 조건문

				SQLNumResultCols(hStmt, &colCount);

				for (i = 0; i < colCount; i++) {
					SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
				}

				while (SQLFetch(hStmt) != SQL_NO_DATA) {

					for (i = 0; i < colCount; i++) {
						if (nulldata[i] == SQL_NULL_DATA)
							printf("NULL    ");
						else
							printf("%-6s  ", data[i]);
					}
					printf("\n");

				}
				printf("---------------------------------------------------------------\n");

				SQLCloseCursor(hStmt);
				SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
			}
		}
		else {

		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
	
}

void DB_Control::singer_Two_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		
		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT S.Working_Name, A.Agency_Name FROM AGENCY AS A, SINGER AS S WHERE A.Agency_Name = S.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("활동명\t소속사\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::group_Two_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT G.Group_Name, A.Agency_Name FROM GROUPS AS G, AGENCY AS A WHERE A.Agency_Name = G.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("그룹명\t소속사\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::actor_Two_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT AC.Working_Name, A.Agency_Name FROM ACTOR AS AC, AGENCY AS A WHERE AC.Agency_Name = A.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("활동명\t소속사\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::manager_Two_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT M.Name, A.Agency_Name FROM MANAGER AS M, AGENCY AS A WHERE A.Agency_Name = M.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("이름 \t소속사\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::movie_Two_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT D.Movie_Name, A.Agency_Name FROM DISTRIBUTED_MOVIE AS D, AGENCY AS A WHERE D.Distributor = A.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("영화제목\t\t      소속사\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::search_MS(char* inserted) { // 매니저 명을 통해 가수 찾기
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT M.Name, S.Working_Name FROM MANAGER AS M, SINGER AS S WHERE M.MID = S.MID AND M.Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("매니저 이름\t\t      활동명\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::search_MG(char* inserted) { // 매니저 명을 통해 그룹 찾기
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT M.Name, G.Group_Name FROM MANAGER AS M, GROUPS AS G WHERE M.MID = G.MID AND M.Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("매니저 이름\t\t      그룹명\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::search_MA(char* inserted) { // 매니저 명을 통해 배우 찾기
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT M.Name, A.Working_Name FROM MANAGER AS M, ACTOR AS A WHERE M.MID = A.MID AND M.Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("매니저 이름\t\t      활동명\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::search_By_Manager() {

	int trigger_s = 0;
	int select_Num;
	char inserted[10]; //소속사명을 넣을 변수 선언

	//cin.ignore();
	cout << "매니저 이름 입력 : ";
	cin.getline(inserted, 10);

	while (trigger_s <= 0 || trigger_s > 4) { // 잘못된 메뉴 입력시 재입력 요구

		cout << "매니저를 통해 찾고자 하는 것을 선택하세요.\n" << endl;
		cout << "1. 가수   2. 그룹   3. 배우  4. SELECT Menu로" << endl;
		cout << "Your Choice --> ";
		cin >> select_Num;

		switch (select_Num) {
		case 1:
			search_MS(inserted);
			break;
		case 2:
			search_MG(inserted);
			break;
		case 3:
			search_MA(inserted);
			break;
		case 4:
			system("cls");
			select_Menu();
			return;
			break;
		default:
			cout << "잘못된 메뉴 입력" << endl;
			break;
		}
	}
}

void DB_Control::singer_Three_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, S.Working_Name, P.Single_Panclub_Name FROM AGENCY AS A, SINGER AS S, SINGLEPAN AS P WHERE A.Agency_Name = S.Agency_Name AND S.Single_Panclub_Name = P.Single_Panclub_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("소속사\t  활동명    개인 팬클럽명\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::group_Three_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, G.Group_Name, GP.Group_Panclub_Name FROM AGENCY AS A, GROUPS AS G, GROUPPAN AS GP WHERE A.Agency_Name = G.Agency_Name AND G.Group_Panclub_Name = GP.Group_Panclub_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("소속사\t  그룹명    그룹 팬클럽명\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::singer_Four_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, S.Working_Name, P.Single_Panclub_Name, M.Name FROM AGENCY AS A, SINGER AS S, SINGLEPAN AS P, MANAGER AS M WHERE A.Agency_Name = S.Agency_Name AND S.Single_Panclub_Name = P.Single_Panclub_Name AND M.MID = S.MID AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("소속사\t  활동명    개인 팬클럽명  매니저 이름\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::group_Four_Join() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLINTEGER nulldata[50];
		int i;

		char inserted[10]; //소속사명을 넣을 변수 선언

		//cin.ignore();
		printf("소속사 입력 : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, G.Group_Name, GP.Group_Panclub_Name, M.Name FROM AGENCY AS A, GROUPS AS G, GROUPPAN AS GP, MANAGER AS M WHERE A.Agency_Name = G.Agency_Name AND G.Group_Panclub_Name = GP.Group_Panclub_Name AND G.MID = M.MID AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("소속사\t  그룹명    그룹 팬클럽명  매니저 이름\n");
			printf("--------------------------------------------------------------------------------------------\n");

			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf(" NULL\t");
					else {
						printf("%-6s", data[i]);
					}
				}
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

//Insert menu
void DB_Control::insert_Manager() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		//(MID, Name, Birth, Date_of_Employment, Salary, SID, Agency_Name)
		int mid, salary, sid;
		char name[10];		//매니저명을 넣을 변수 선언
		char birthday[15];	//생년월일
		char DoE[15];		//입사일
		char agency[10];	//소속사명

		//cin.ignore();
		cout << "Manager ID 입력 : ";
		cin >> mid;

		cin.ignore();
		cout << "매니저 이름 입력 : ";
		cin.getline(name, 10);

		//cin.ignore();
		cout << "생년월일 입력 : ";
		cin.getline(birthday, 15);

		//cin.ignore();
		cout << "입사일 입력 : ";
		cin.getline(DoE, 15);

		//cin.ignore();
		cout << "월급 입력 : ";
		cin >> salary;

		//cin.ignore();
		cout << "선임 매니저 ID 입력 : ";
		cin >> sid;

		cin.ignore();
		cout << "소속사 명 입력 : ";
		cin.getline(agency, 10);
		//(MID, Name, Birth, Date_of_Employment, Salary, SID, Agency_Name)
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "INSERT INTO MANAGER VALUES(%d, '%s', '%s', '%s', %d, %d, '%s');",mid,name,birthday,DoE,salary,sid,agency);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Manager();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::insert_Singer() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		//(본명, 활동명, 데뷔일, 생년월일, 월급, 그룹명, 대표곡, MID, 소속사명, 개인팬클럽명)
		int mid, salary;
		int ch_null;
		char ori_name[10];		//본명을 넣을 변수 선언
		char work_name[10];		//활동명을 넣을 변수 선언
		char birthday[15];		//생년월일
		char DoD[15];			//데뷔일
		char agency[10];		//소속사명
		char group[20];			//그룹명
		char MoR[20];			//대표곡
		//char single[15];		//개인팬클럽명 ( 데뷔한 가수가 바로 개인팬클럽이 생길 순 없다 )

		//cin.ignore();
		cout << "본명 입력 : ";
		cin.getline(ori_name, 10);

		cout << "활동명 입력 : ";
		cin.getline(work_name, 10);

		cout << "데뷔일 입력 : ";
		cin.getline(DoD, 15);

		cout << "생년월일 입력 : ";
		cin.getline(birthday, 15);

		cout << "월급 입력 : ";
		cin >> salary;

		cin.ignore();
		cout << "그룹명 입력입니다." << endl;
		cout << "혹시, NULL 값을 넣을겁니까 ? (넣을거면 1 입력 아니면 0 입력) -> ";
		cin >> ch_null;
		if (ch_null == 1) {
			cout << "그룹명은 없습니다." << endl;
			cin.ignore(); // 1번 눌렀을 때 생긴 엔터값 없애기
		}
		else {
			cout << "그룹명 입력 : ";
			cin.getline(group, 20);
		}

		cout << "대표곡 입력 : ";
		cin.getline(MoR, 20);

		cout << "매니저 ID 입력 : ";
		cin >> mid;

		cin.ignore();
		cout << "소속사명 입력 : ";
		cin.getline(agency, 10);

		//갓 데뷔한 가수들은 개인 팬클럽이 바로 생기지 않습니다.

		//(본명, 활동명, 데뷔일, 생년월일, 월급, 그룹명, 대표곡, MID, 소속사명, 개인팬클럽명)
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			if (ch_null == 1) { // 그룹명이 없을 때.
				sprintf((char*)query, "INSERT INTO SINGER VALUES('%s','%s','%s','%s',%d,'%s',NULL,%d,'%s',NULL);", ori_name, work_name, DoD, birthday, salary, MoR, mid, agency);
			}
			else {
				sprintf((char*)query, "INSERT INTO SINGER VALUES('%s','%s','%s','%s',%d,'%s','%s',%d,'%s',NULL);", ori_name, work_name, DoD, birthday, salary, group, MoR, mid, agency);
			}
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Singer();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::insert_Group() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		//(그룹명, 데뷔일, 멤버수(int), MID, 그룹팬클럽명, 소속사명, 대표곡)
		int mid;
		char group[20];			//그룹명
		char DoD[15];			//데뷔일
		int member;				//멤버수
		char agency[10];		//소속사명
		char MoR[20];			//대표곡
		//( 데뷔한 그룹 바로 그룹팬클럽이 생길 순 없다 )

		//cin.ignore();
		cout << "그룹명 입력 : ";
		cin.getline(group, 20);

		cout << "데뷔일 입력 : ";
		cin.getline(DoD, 15);

		cout << "멤버수 입력 : ";
		cin >> member;

		cin.ignore();
		cout << "매니저 ID 입력 : ";
		cin >> mid;

		cin.ignore();
		cout << "소속사명 입력 : ";
		cin.getline(agency, 10);

		cout << "대표곡 입력 : ";
		cin.getline(MoR, 20);


		//(그룹명, 데뷔일, 멤버수(int), MID, 그룹팬클럽명, 소속사명, 대표곡)
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			
			sprintf((char*)query, "INSERT INTO GROUPS VALUES('%s','%s',%d,%d,  NULL,'%s','%s');", group, DoD, member, mid, agency, MoR);
			
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Group();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::insert_Actor() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		//ori_name, work_name, birthday, DoD, salary, mid, agency, MoR
		int mid, salary;
		char ori_name[10];		//본명을 넣을 변수 선언
		char work_name[10];		//활동명을 넣을 변수 선언
		char birthday[15];		//생년월일
		char DoD[15];			//데뷔일
		char agency[10];		//소속사명
		char MoR[20];			//대표작

		//cin.ignore();
		cout << "본명 입력 : ";
		cin.getline(ori_name, 10);

		cout << "활동명 입력 : ";
		cin.getline(work_name, 10);

		cout << "생년월일 입력 : ";
		cin.getline(birthday, 15);

		cout << "데뷔일 입력 : ";
		cin.getline(DoD, 15);

		cout << "월급 입력 : ";
		cin >> salary;

		cin.ignore();
		cout << "매니저 ID 입력 : ";
		cin >> mid;

		cin.ignore();
		cout << "소속사명 입력 : ";
		cin.getline(agency, 10);

		cout << "대표작 입력 : ";
		cin.getline(MoR, 20);

		//ori_name, work_name, birthday, DoD, salary, mid, agency, MoR
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			
			sprintf((char*)query, "INSERT INTO ACTOR VALUES('%s','%s','%s','%s',%d,%d,'%s','%s');",ori_name,work_name,birthday,DoD,salary,mid,agency,MoR);
			
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Actor();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::insert_Agency() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		//(소속사명, 대표이름, 전화번호, 주소)
		char agency[10];		//소속사명
		char rep[10];			//대표이름
		char tel[20];			//전화번호
		char addr[30];			//주소

		//cin.ignore();
		cout << "소속사명 입력 : ";
		cin.getline(agency, 10);

		cout << "대표 이름 입력 : ";
		cin.getline(rep, 10);

		cout << "전화번호 입력 : ";
		cin.getline(tel, 20);

		cout << "주소 입력 : ";
		cin.getline(addr, 30);

		//ori_name, work_name, birthday, DoD, salary, mid, agency, MoR
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {

			sprintf((char*)query, "INSERT INTO AGENCY VALUES('%s','%s','%s','%s');", agency,rep,tel,addr);

			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Agency();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::insert_Movie() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		//(MovieID(21부터), 영화제목, 개봉일, 배급사, 연령제한, TID)
		int mid;
		char movie_name[30];	//영화제목
		char DoR[15];			//개봉일
		char agency[10];		//배급사명
		char age_Limit[20];		//연령제한
		int tid;				//영화관 ID

		//cin.ignore();
		cout << "Movie ID 입력 : ";
		cin >> mid;

		cin.ignore();
		cout << "영화제목 입력 : ";
		cin.getline(movie_name, 30);

		cout << "개봉일 입력 : ";
		cin.getline(DoR, 15);

		cout << "배급사 입력 : ";
		cin.getline(agency, 10);

		cout << "연령 제한 입력 : ";
		cin.getline(age_Limit, 20);

		cout << "영화관 ID 입력 : ";
		cin >> tid;

		cin.ignore();

		//(MovieID(21부터), 영화제목, 개봉일, 배급사, 연령제한, TID)
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {

			sprintf((char*)query, "INSERT INTO DISTRIBUTED_MOVIE VALUES(%d,'%s','%s','%s','%s',%d);",mid,movie_name,DoR,agency,age_Limit,tid);

			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Film();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}


//delete menu
void DB_Control::delete_Manager() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		char name[10];		//매니저명을 넣을 변수 선언

		//cin.ignore();
		cout << "퇴사한 매니저 이름 입력 : ";
		cin.getline(name, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "DELETE FROM MANAGER WHERE Name = '%s';",name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Manager();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::delete_Singer() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		char name[10];		//가수 본명을 넣을 변수 선언

		//cin.ignore();
		cout << "은퇴한 가수 이름(본명) 입력 : ";
		cin.getline(name, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "DELETE FROM SINGER WHERE Original_Name = '%s';", name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Singer();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::delete_Actor() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		char name[10];		//배우 본명을 넣을 변수 선언

		//cin.ignore();
		cout << "은퇴한 배우 이름(본명) 입력 : ";
		cin.getline(name, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "DELETE FROM ACTOR WHERE Original_Name = '%s';", name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Actor();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::delete_Agency() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		char name[10];		//소속사명을 넣을 변수 선언

		//cin.ignore();
		cout << "망한 소속사명 입력 : ";
		cin.getline(name, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "DELETE FROM AGENCY WHERE Agency_Name = '%s';", name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Agency();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::delete_Theater() {
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		char name[10];		//영화관 이름을 넣을 변수 선언

		//cin.ignore();
		cout << "망한 영화관 이름 입력 : ";
		cin.getline(name, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "DELETE FROM THEATER WHERE Theater_Name = '%s';", name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Theater();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

//update menu
void DB_Control::update_MoS() {	//가수의 매니저 변경
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int mid;
		char sname[10];		//가수 본명을 넣을 변수 선언

		//cin.ignore();
		cout << "매니저가 바뀐 가수의 본명을 입력 : ";
		cin.getline(sname, 10);

		cout << "새로 배정된 Manager ID 입력 : ";
		cin >> mid;
		cin.ignore();

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "UPDATE SINGER SET MID = %d WHERE Original_Name = '%s';",mid, sname);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Singer();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::update_MoG() {	//그룹의 매니저 변경
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int mid;
		char gname[10];		//가수 본명을 넣을 변수 선언

		//cin.ignore();
		cout << "매니저가 바뀐 그룹명을 입력 : ";
		cin.getline(gname, 10);

		cout << "새로 배정된 Manager ID 입력 : ";
		cin >> mid;
		cin.ignore();

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "UPDATE GROUPS SET MID = %d WHERE Group_Name = '%s';", mid, gname);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Group();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::update_MoA() {	//배우의 매니저 변경
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int mid;
		char name[10];		//매니저 이름을 넣을 변수 선언

		//cin.ignore();
		cout << "매니저가 바뀐 배우의 본명을 입력 : ";
		cin.getline(name, 10);

		cout << "새로 배정된 Manager ID 입력 : ";
		cin >> mid;
		cin.ignore();

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "UPDATE ACTOR SET MID = %d WHERE Original_Name = '%s';", mid, name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Actor();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::update_Manager() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a Update Manager Menu you want -------" << endl;
	cout << "\t1. 가수의 매니저가 변경되었다." << endl;
	cout << "\t2. 그룹의 매니저가 변경되었다." << endl;
	cout << "\t3. 배우의 매니저가 변경되었다." << endl;
	cout << "\t4. 처음으로" << endl;

	while (trigger <= 0 || trigger > 3) { // 잘못된 메뉴 입력시 재입력 요구
		cout << "Your choice -> ";
		cin >> select_Num;
		
		while (cin.get() != '\n');

		switch (select_Num) {
		case 1: //가수의 매니저가 새로 배정됐다.
			update_MoS();
			break;
		case 2: //그룹의 매니저가 새로 배정됐다.
			update_MoG();
			break;
		case 3: //배우의 매니저가 새로 배정됐다.
			update_MoA();
			break;
		case 4: //처음으로
			system("cls");
			print_Form();
			return;
			break;
		default:
			cout << "알맞은 메뉴를 입력하세요." << endl;
			break;
		}
	}
}

void DB_Control::update_Manager_Salary() {	//매니저의 월급을 올린다.
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		float num;			//인상 배율을 저장할 변수 선언
		char name[10];		//매니저 이름을 넣을 변수 선언

		//cin.ignore();
		cout << "월급을 인상시킬 매니저 이름을 입력 : ";
		cin.getline(name, 10);

		cout << "몇% 인상할지 입력 [ex) 10% 인상 -> 1.1 입력] : ";
		cin >> num;
		cin.ignore();

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "UPDATE MANAGER SET Salary = Salary * %f WHERE Name = '%s';", num, name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Manager();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::update_Singer_Salary() {	//가수의 월급을 올린다.
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		float num;			//인상 배율을 저장할 변수 선언
		char name[10];		//가수 본명을 넣을 변수 선언

		//cin.ignore();
		cout << "월급을 인상시킬 가수 본명을 입력 : ";
		cin.getline(name, 10);

		cout << "몇% 인상할지 입력 [ex) 10% 인상 -> 1.1 입력] : ";
		cin >> num;
		cin.ignore();

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "UPDATE SINGER SET Salary = Salary * %f WHERE Original_Name = '%s';", num, name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Singer();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::update_Group_Out() {	//그룹의 멤버중 몇 명이 탈퇴를 했다. 
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int num;			//탈퇴한 멤버 수를 저장할 변수 선언
		char name[10];		//그룹명을 넣을 변수 선언

		//cin.ignore();
		cout << "멤버 수에 변동이 생긴 그룹명을 입력 : ";
		cin.getline(name, 10);

		cout << "몇명의 멤버가 탈퇴했는지 입력 : ";
		cin >> num;
		cin.ignore();

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "UPDATE GROUPS SET The_number_of_member = The_number_of_member - %d WHERE Group_Name = '%s';", num, name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Group();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}

void DB_Control::update_Theater_Tel() {	//영화관의 전화번호가 변경되었다.

	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		char name[20];		//영화관 명을 넣을 변수 선언
		char tel[20];		//바뀐 전화번호를 넣을 변수 선언

		//cin.ignore();
		cout << "전화번호에 변동이 생긴 영화관 명을 입력 : ";
		cin.getline(name, 20);

		cout << "바뀐 전화번호 입력 : ";
		cin.getline(tel, 20);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "UPDATE THEATER SET Tel = '%s' WHERE Theater_Name = '%s';", tel, name);
			SQLExecDirect(hStmt, query, SQL_NTS);

			show_Theater();

			printf("--------------------------------------------------------------------------------------------\n");

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		DBDisconnect();
	}
	else {
		cout << "DB connect fail" << endl;
		exit(1);
	}
}