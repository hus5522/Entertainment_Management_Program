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
			printf("�Ҽӻ��  ��ǥ\t    ��ȭ��ȣ\t  \t�ּ�\n");
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
			printf("ID\t�̸�\t\t�������\t�Ի���\t\t����\t����ID\t�Ҽӻ�\n");
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
			printf("����\t  Ȱ����    ������\t   �������\t  ����\t  �Ҽӱ׷��\t     ��ǥ��\t   �Ŵ���ID\t �Ҽӻ�\t������Ŭ��\n");
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
			printf("����\t  Ȱ����    ������Ŭ����   �Ἲ��\t ���\tȸ����\n");
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
			printf("�׷��\t    ������    �����  �Ŵ���ID\t�׷���Ŭ����  �Ҽӻ�\t ��ǥ��\n");
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
			printf("�׷��\t  �׷���Ŭ����   �Ἲ��       ���    ȸ����\n");
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
			printf("����\t  Ȱ����    �������       ������         ����\t   �Ŵ���ID  �Ҽӻ�\t��ǥ��\n");
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
			printf("��ȭID  ��ȭ���� \t   ������       ��޻�       ��������\t     ��ȭ��ID\n");
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
			printf("��ȭ��ID  ��ȭ����\t      �ּ�               \t    ��ȭ��ȣ          �󿵰� ��\n");
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

		char inserted[300]; //������Է� ������ �޴� ���� ����
		
		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][30];
		SQLINTEGER nulldata[50];

		int i;

		//cin.ignore();
		printf("������ �Է� : ");
		cin.getline(inserted, 300);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "%s", inserted);
			retcode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
				printf("Query Execute Error \n");
				return;
			}

			if (strstr(inserted, "SELECT") != NULL) { // SELECT�� �ƴ� ������ ������ �߻��ϴ� �̻������� �������� ���ǹ�

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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT S.Working_Name, A.Agency_Name FROM AGENCY AS A, SINGER AS S WHERE A.Agency_Name = S.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("Ȱ����\t�Ҽӻ�\n");
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT G.Group_Name, A.Agency_Name FROM GROUPS AS G, AGENCY AS A WHERE A.Agency_Name = G.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("�׷��\t�Ҽӻ�\n");
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT AC.Working_Name, A.Agency_Name FROM ACTOR AS AC, AGENCY AS A WHERE AC.Agency_Name = A.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("Ȱ����\t�Ҽӻ�\n");
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT M.Name, A.Agency_Name FROM MANAGER AS M, AGENCY AS A WHERE A.Agency_Name = M.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("�̸� \t�Ҽӻ�\n");
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT D.Movie_Name, A.Agency_Name FROM DISTRIBUTED_MOVIE AS D, AGENCY AS A WHERE D.Distributor = A.Agency_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("��ȭ����\t\t      �Ҽӻ�\n");
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

void DB_Control::search_MS(char* inserted) { // �Ŵ��� ���� ���� ���� ã��
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
			printf("�Ŵ��� �̸�\t\t      Ȱ����\n");
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

void DB_Control::search_MG(char* inserted) { // �Ŵ��� ���� ���� �׷� ã��
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
			printf("�Ŵ��� �̸�\t\t      �׷��\n");
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

void DB_Control::search_MA(char* inserted) { // �Ŵ��� ���� ���� ��� ã��
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
			printf("�Ŵ��� �̸�\t\t      Ȱ����\n");
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
	char inserted[10]; //�Ҽӻ���� ���� ���� ����

	//cin.ignore();
	cout << "�Ŵ��� �̸� �Է� : ";
	cin.getline(inserted, 10);

	while (trigger_s <= 0 || trigger_s > 4) { // �߸��� �޴� �Է½� ���Է� �䱸

		cout << "�Ŵ����� ���� ã���� �ϴ� ���� �����ϼ���.\n" << endl;
		cout << "1. ����   2. �׷�   3. ���  4. SELECT Menu��" << endl;
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
			cout << "�߸��� �޴� �Է�" << endl;
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, S.Working_Name, P.Single_Panclub_Name FROM AGENCY AS A, SINGER AS S, SINGLEPAN AS P WHERE A.Agency_Name = S.Agency_Name AND S.Single_Panclub_Name = P.Single_Panclub_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("�Ҽӻ�\t  Ȱ����    ���� ��Ŭ����\n");
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, G.Group_Name, GP.Group_Panclub_Name FROM AGENCY AS A, GROUPS AS G, GROUPPAN AS GP WHERE A.Agency_Name = G.Agency_Name AND G.Group_Panclub_Name = GP.Group_Panclub_Name AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("�Ҽӻ�\t  �׷��    �׷� ��Ŭ����\n");
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, S.Working_Name, P.Single_Panclub_Name, M.Name FROM AGENCY AS A, SINGER AS S, SINGLEPAN AS P, MANAGER AS M WHERE A.Agency_Name = S.Agency_Name AND S.Single_Panclub_Name = P.Single_Panclub_Name AND M.MID = S.MID AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("�Ҽӻ�\t  Ȱ����    ���� ��Ŭ����  �Ŵ��� �̸�\n");
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

		char inserted[10]; //�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		printf("�Ҽӻ� �Է� : ");
		cin.getline(inserted, 10);

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "SELECT A.Agency_Name, G.Group_Name, GP.Group_Panclub_Name, M.Name FROM AGENCY AS A, GROUPS AS G, GROUPPAN AS GP, MANAGER AS M WHERE A.Agency_Name = G.Agency_Name AND G.Group_Panclub_Name = GP.Group_Panclub_Name AND G.MID = M.MID AND A.Agency_Name = '%s';", inserted);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLNumResultCols(hStmt, &colCount);


			for (i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}

			printf("--------------------------------------------------------------------------------------------\n");
			printf("�Ҽӻ�\t  �׷��    �׷� ��Ŭ����  �Ŵ��� �̸�\n");
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
		char name[10];		//�Ŵ������� ���� ���� ����
		char birthday[15];	//�������
		char DoE[15];		//�Ի���
		char agency[10];	//�Ҽӻ��

		//cin.ignore();
		cout << "Manager ID �Է� : ";
		cin >> mid;

		cin.ignore();
		cout << "�Ŵ��� �̸� �Է� : ";
		cin.getline(name, 10);

		//cin.ignore();
		cout << "������� �Է� : ";
		cin.getline(birthday, 15);

		//cin.ignore();
		cout << "�Ի��� �Է� : ";
		cin.getline(DoE, 15);

		//cin.ignore();
		cout << "���� �Է� : ";
		cin >> salary;

		//cin.ignore();
		cout << "���� �Ŵ��� ID �Է� : ";
		cin >> sid;

		cin.ignore();
		cout << "�Ҽӻ� �� �Է� : ";
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

		//(����, Ȱ����, ������, �������, ����, �׷��, ��ǥ��, MID, �Ҽӻ��, ������Ŭ����)
		int mid, salary;
		int ch_null;
		char ori_name[10];		//������ ���� ���� ����
		char work_name[10];		//Ȱ������ ���� ���� ����
		char birthday[15];		//�������
		char DoD[15];			//������
		char agency[10];		//�Ҽӻ��
		char group[20];			//�׷��
		char MoR[20];			//��ǥ��
		//char single[15];		//������Ŭ���� ( ������ ������ �ٷ� ������Ŭ���� ���� �� ���� )

		//cin.ignore();
		cout << "���� �Է� : ";
		cin.getline(ori_name, 10);

		cout << "Ȱ���� �Է� : ";
		cin.getline(work_name, 10);

		cout << "������ �Է� : ";
		cin.getline(DoD, 15);

		cout << "������� �Է� : ";
		cin.getline(birthday, 15);

		cout << "���� �Է� : ";
		cin >> salary;

		cin.ignore();
		cout << "�׷�� �Է��Դϴ�." << endl;
		cout << "Ȥ��, NULL ���� �����̴ϱ� ? (�����Ÿ� 1 �Է� �ƴϸ� 0 �Է�) -> ";
		cin >> ch_null;
		if (ch_null == 1) {
			cout << "�׷���� �����ϴ�." << endl;
			cin.ignore(); // 1�� ������ �� ���� ���Ͱ� ���ֱ�
		}
		else {
			cout << "�׷�� �Է� : ";
			cin.getline(group, 20);
		}

		cout << "��ǥ�� �Է� : ";
		cin.getline(MoR, 20);

		cout << "�Ŵ��� ID �Է� : ";
		cin >> mid;

		cin.ignore();
		cout << "�Ҽӻ�� �Է� : ";
		cin.getline(agency, 10);

		//�� ������ �������� ���� ��Ŭ���� �ٷ� ������ �ʽ��ϴ�.

		//(����, Ȱ����, ������, �������, ����, �׷��, ��ǥ��, MID, �Ҽӻ��, ������Ŭ����)
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			if (ch_null == 1) { // �׷���� ���� ��.
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

		//(�׷��, ������, �����(int), MID, �׷���Ŭ����, �Ҽӻ��, ��ǥ��)
		int mid;
		char group[20];			//�׷��
		char DoD[15];			//������
		int member;				//�����
		char agency[10];		//�Ҽӻ��
		char MoR[20];			//��ǥ��
		//( ������ �׷� �ٷ� �׷���Ŭ���� ���� �� ���� )

		//cin.ignore();
		cout << "�׷�� �Է� : ";
		cin.getline(group, 20);

		cout << "������ �Է� : ";
		cin.getline(DoD, 15);

		cout << "����� �Է� : ";
		cin >> member;

		cin.ignore();
		cout << "�Ŵ��� ID �Է� : ";
		cin >> mid;

		cin.ignore();
		cout << "�Ҽӻ�� �Է� : ";
		cin.getline(agency, 10);

		cout << "��ǥ�� �Է� : ";
		cin.getline(MoR, 20);


		//(�׷��, ������, �����(int), MID, �׷���Ŭ����, �Ҽӻ��, ��ǥ��)
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
		char ori_name[10];		//������ ���� ���� ����
		char work_name[10];		//Ȱ������ ���� ���� ����
		char birthday[15];		//�������
		char DoD[15];			//������
		char agency[10];		//�Ҽӻ��
		char MoR[20];			//��ǥ��

		//cin.ignore();
		cout << "���� �Է� : ";
		cin.getline(ori_name, 10);

		cout << "Ȱ���� �Է� : ";
		cin.getline(work_name, 10);

		cout << "������� �Է� : ";
		cin.getline(birthday, 15);

		cout << "������ �Է� : ";
		cin.getline(DoD, 15);

		cout << "���� �Է� : ";
		cin >> salary;

		cin.ignore();
		cout << "�Ŵ��� ID �Է� : ";
		cin >> mid;

		cin.ignore();
		cout << "�Ҽӻ�� �Է� : ";
		cin.getline(agency, 10);

		cout << "��ǥ�� �Է� : ";
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

		//(�Ҽӻ��, ��ǥ�̸�, ��ȭ��ȣ, �ּ�)
		char agency[10];		//�Ҽӻ��
		char rep[10];			//��ǥ�̸�
		char tel[20];			//��ȭ��ȣ
		char addr[30];			//�ּ�

		//cin.ignore();
		cout << "�Ҽӻ�� �Է� : ";
		cin.getline(agency, 10);

		cout << "��ǥ �̸� �Է� : ";
		cin.getline(rep, 10);

		cout << "��ȭ��ȣ �Է� : ";
		cin.getline(tel, 20);

		cout << "�ּ� �Է� : ";
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

		//(MovieID(21����), ��ȭ����, ������, ��޻�, ��������, TID)
		int mid;
		char movie_name[30];	//��ȭ����
		char DoR[15];			//������
		char agency[10];		//��޻��
		char age_Limit[20];		//��������
		int tid;				//��ȭ�� ID

		//cin.ignore();
		cout << "Movie ID �Է� : ";
		cin >> mid;

		cin.ignore();
		cout << "��ȭ���� �Է� : ";
		cin.getline(movie_name, 30);

		cout << "������ �Է� : ";
		cin.getline(DoR, 15);

		cout << "��޻� �Է� : ";
		cin.getline(agency, 10);

		cout << "���� ���� �Է� : ";
		cin.getline(age_Limit, 20);

		cout << "��ȭ�� ID �Է� : ";
		cin >> tid;

		cin.ignore();

		//(MovieID(21����), ��ȭ����, ������, ��޻�, ��������, TID)
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

		char name[10];		//�Ŵ������� ���� ���� ����

		//cin.ignore();
		cout << "����� �Ŵ��� �̸� �Է� : ";
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

		char name[10];		//���� ������ ���� ���� ����

		//cin.ignore();
		cout << "������ ���� �̸�(����) �Է� : ";
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

		char name[10];		//��� ������ ���� ���� ����

		//cin.ignore();
		cout << "������ ��� �̸�(����) �Է� : ";
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

		char name[10];		//�Ҽӻ���� ���� ���� ����

		//cin.ignore();
		cout << "���� �Ҽӻ�� �Է� : ";
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

		char name[10];		//��ȭ�� �̸��� ���� ���� ����

		//cin.ignore();
		cout << "���� ��ȭ�� �̸� �Է� : ";
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
void DB_Control::update_MoS() {	//������ �Ŵ��� ����
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int mid;
		char sname[10];		//���� ������ ���� ���� ����

		//cin.ignore();
		cout << "�Ŵ����� �ٲ� ������ ������ �Է� : ";
		cin.getline(sname, 10);

		cout << "���� ������ Manager ID �Է� : ";
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

void DB_Control::update_MoG() {	//�׷��� �Ŵ��� ����
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int mid;
		char gname[10];		//���� ������ ���� ���� ����

		//cin.ignore();
		cout << "�Ŵ����� �ٲ� �׷���� �Է� : ";
		cin.getline(gname, 10);

		cout << "���� ������ Manager ID �Է� : ";
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

void DB_Control::update_MoA() {	//����� �Ŵ��� ����
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int mid;
		char name[10];		//�Ŵ��� �̸��� ���� ���� ����

		//cin.ignore();
		cout << "�Ŵ����� �ٲ� ����� ������ �Է� : ";
		cin.getline(name, 10);

		cout << "���� ������ Manager ID �Է� : ";
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
	cout << "\t1. ������ �Ŵ����� ����Ǿ���." << endl;
	cout << "\t2. �׷��� �Ŵ����� ����Ǿ���." << endl;
	cout << "\t3. ����� �Ŵ����� ����Ǿ���." << endl;
	cout << "\t4. ó������" << endl;

	while (trigger <= 0 || trigger > 3) { // �߸��� �޴� �Է½� ���Է� �䱸
		cout << "Your choice -> ";
		cin >> select_Num;
		
		while (cin.get() != '\n');

		switch (select_Num) {
		case 1: //������ �Ŵ����� ���� �����ƴ�.
			update_MoS();
			break;
		case 2: //�׷��� �Ŵ����� ���� �����ƴ�.
			update_MoG();
			break;
		case 3: //����� �Ŵ����� ���� �����ƴ�.
			update_MoA();
			break;
		case 4: //ó������
			system("cls");
			print_Form();
			return;
			break;
		default:
			cout << "�˸��� �޴��� �Է��ϼ���." << endl;
			break;
		}
	}
}

void DB_Control::update_Manager_Salary() {	//�Ŵ����� ������ �ø���.
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		float num;			//�λ� ������ ������ ���� ����
		char name[10];		//�Ŵ��� �̸��� ���� ���� ����

		//cin.ignore();
		cout << "������ �λ��ų �Ŵ��� �̸��� �Է� : ";
		cin.getline(name, 10);

		cout << "��% �λ����� �Է� [ex) 10% �λ� -> 1.1 �Է�] : ";
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

void DB_Control::update_Singer_Salary() {	//������ ������ �ø���.
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		float num;			//�λ� ������ ������ ���� ����
		char name[10];		//���� ������ ���� ���� ����

		//cin.ignore();
		cout << "������ �λ��ų ���� ������ �Է� : ";
		cin.getline(name, 10);

		cout << "��% �λ����� �Է� [ex) 10% �λ� -> 1.1 �Է�] : ";
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

void DB_Control::update_Group_Out() {	//�׷��� ����� �� ���� Ż�� �ߴ�. 
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		int num;			//Ż���� ��� ���� ������ ���� ����
		char name[10];		//�׷���� ���� ���� ����

		//cin.ignore();
		cout << "��� ���� ������ ���� �׷���� �Է� : ";
		cin.getline(name, 10);

		cout << "����� ����� Ż���ߴ��� �Է� : ";
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

void DB_Control::update_Theater_Tel() {	//��ȭ���� ��ȭ��ȣ�� ����Ǿ���.

	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;

		char name[20];		//��ȭ�� ���� ���� ���� ����
		char tel[20];		//�ٲ� ��ȭ��ȣ�� ���� ���� ����

		//cin.ignore();
		cout << "��ȭ��ȣ�� ������ ���� ��ȭ�� ���� �Է� : ";
		cin.getline(name, 20);

		cout << "�ٲ� ��ȭ��ȣ �Է� : ";
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