#include "DB_control.h"
#include <Windows.h> // system("cls")
#include <iostream>
using namespace std;

void DB_Control::print_Form() {
	cout << "----------Entertainment DataBase Program----------" << endl;
	cout << "\tSelect the Menu!!" << endl;
	cout << "1. typing Query" << endl;
	cout << "2. Select" << endl;
	cout << "3. Insert" << endl;
	cout << "4. Delete" << endl;
	cout << "5. Update" << endl;
	cout << "6. Show a Table" << endl;
	cout << "0. Exit" << endl;
	cout << "Your choice -> ";
	cin >> select_Num;

	while (cin.get() != '\n');

	if (select_Num >= 0 && select_Num <= 6) {
		switch (select_Num) {
			case 1: //���� ���� �Է�
				insert_Query();
				system("Pause"); // �������� ����� ��� ������ �� ó�� ȭ������
				system("cls");
				print_Form();
				break;
			case 2: //select menu
				select_Menu();
				break;
			case 3: //insert menu
				insert_Menu();
				break;
			case 4: //delete menu
				delete_Menu();
				break;
			case 5: //update menu
				update_Menu();
				break;
			case 6: //view a table
				view_Table();
			case 0: //exit
				exit(1);
				break;
			default:
				cout << "�˸��� �޴��� �Է��ϼ���." << endl;
				break;
		}
	}
	else {
		cout << "�˸��� �޴��� �Է��ϼ���." << endl;
		system("pause");
		system("cls");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		print_Form();
		return;
	}
}

void DB_Control::view_Table() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a table number you want -------" << endl;
	cout << "\t1. �Ҽӻ�" << endl;
	cout << "\t2. �Ŵ���" << endl;
	cout << "\t3. ����" << endl;
	cout << "\t4. ���� ��Ŭ��" << endl;
	cout << "\t5. �׷�" << endl;
	cout << "\t6. �׷� ��Ŭ��" << endl;
	cout << "\t7. ��ȭ���" << endl;
	cout << "\t8. ��޵� ��ȭ" << endl;
	cout << "\t9. ��ȭ��" << endl;
	cout << "\t10. ó������" << endl;

	while (trigger <= 0 || trigger > 10) { // �߸��� �޴� �Է½� ���Է� �䱸
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "�˸��� �޴��� �Է��ϼ���." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			view_Table();
			return;
		}

		switch (select_Num) {
			case 1: //�Ҽӻ� ���̺� ���
				show_Agency();
				break;
			case 2: //�Ŵ��� ���̺� ���
				show_Manager();
				break;
			case 3: //���� ���̺� ���
				show_Singer();
				break;
			case 4: //���� ��Ŭ�� ���̺� ���
				show_SinglePan();
				break;
			case 5: //�׷� ���̺� ���
				show_Group();
				break;
			case 6: //�׷� ��Ŭ�� ���̺� ���
				show_GroupPan();
				break;
			case 7: //��ȭ��� ���̺� ���
				show_Actor();
				break;
			case 8: //��޵ȿ�ȭ ���̺� ���
				show_Film();
				break;
			case 9: //��ȭ�� ���̺� ���
				show_Theater();
				break;
			case 10: //ó������
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

void DB_Control::select_Menu() {
	
	system("cls");
	int trigger = 0;

	cout << "------- Select number you want -------" << endl;
	cout << "\t< ��2���� ������ ����� �޴��� >" << endl;
	cout << "\t(�Ҽӻ� ���� �Է¹���)" << endl;
	cout << "\t1. �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� ������ Ȱ������ ã�ƶ�." << endl;
	cout << "\t2. �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� �׷��� Ȱ������ ã�ƶ�" << endl;
	cout << "\t3. �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� ����� Ȱ������ ã�ƶ�." << endl;
	cout << "\t4. �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� �Ŵ����� �̸��� ã�ƶ�." << endl;
	cout << "\t5. �ش� �Ҽӻ��� �� �Ҽӻ簡 ����� ��ȭ������ ã�ƶ�." << endl;
	cout << "\t(�Ŵ��� ���� �Է¹���)" << endl;
	cout << "\t6. �ش� �Ŵ����� �����ϰ� �ִ� ���� or �׷� or ��츦 ã�ƶ�." << endl;
	cout << "\t< ��3���� ������ ����� �޴��� >" << endl;
	cout << "\t(�Ҽӻ� ���� �Է¹���)" << endl;
	cout << "\t7. �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� ������ Ȱ����� �� ������ ���� ��Ŭ������ ã�ƶ�." << endl;
	cout << "\t8. �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� �׷��� �׷��� �� �׷��� �׷� ��Ŭ������ ã�ƶ�." << endl;
	cout << "\t< ��4���� ������ ����� �޴��� >" << endl;
	cout << "\t(�Ҽӻ� ���� �Է¹���)" << endl;
	cout << "\t9. �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� ������ Ȱ����� �� ������ ���� ��Ŭ����� �� ������ �Ŵ��� �̸��� ã�ƶ�." << endl;
	cout << "\t10.�ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� �׷��� Ȱ����� �� �׷��� �׷� ��Ŭ����� �� �׷��� �Ŵ��� �̸��� ã�ƶ�." << endl;
	cout << "\t11. ó������" << endl;

	while (trigger <= 0 || trigger > 11) { // �߸��� �޴� �Է½� ���Է� �䱸
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "�˸��� �޴��� �Է��ϼ���." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			select_Menu();
			return;
		}

		switch (select_Num) {
		case 1: // �Ҽӻ����̺�� �������̺��� �����Ͽ� �Ҽӻ�� ����Ȱ������ ã��
			singer_Two_Join();
			break;
		case 2: // �Ҽӻ����̺�� �׷����̺��� �����Ͽ� �Ҽӻ�� �׷���� ã��
			group_Two_Join();
			break;
		case 3: // �Ҽӻ����̺�� ������̺��� �����Ͽ� �Ҽӻ�� ��� Ȱ������ ã��
			actor_Two_Join();
			break;
		case 4: // �Ҽӻ����̺�� �Ŵ������̺��� �����Ͽ� �Ҽӻ�� �Ŵ����̸� ã��
			manager_Two_Join();
			break;
		case 5: // �Ҽӻ����̺�� ��޵ȿ�ȭ ���̺��� �����Ͽ� �Ҽӻ�� �� �Ҽӻ簡 ���� ��ȭ������ ã��
			movie_Two_Join();
			break;
		case 6: // �Ŵ��� ���̺�� ���� or �׷� or ��ȭ��� ���̺��� �����Ͽ� �� �Ŵ����� �����ϴ� ��� ã��
			search_By_Manager();
			break;
		case 7: // �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� ������ Ȱ����� �� ������ ���� ��Ŭ������ ã�ƶ�
			singer_Three_Join();
			break;
		case 8: // �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� �׷��� �׷��� �� �׷��� �׷� ��Ŭ������ ã�ƶ�
			group_Three_Join();
			break;
		case 9: // �ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� ������ Ȱ����� �� ������ ���� ��Ŭ����� �� ������ �Ŵ��� �̸��� ã�ƶ�
			singer_Four_Join();
			break;
		case 10: //�ش� �Ҽӻ��� �ű⿡ �Ҽӵ� ��� �׷��� Ȱ����� �� �׷��� �׷� ��Ŭ����� �� �׷��� �Ŵ��� �̸��� ã�ƶ�
			group_Four_Join();
			break;
		case 11: //ó������
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

void DB_Control::insert_Menu() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a Insert Menu you want -------" << endl;
	cout << "\t1. ���ο� �Ŵ����� �Ի��ߴ�." << endl;
	cout << "\t2. ���ο� ������ �����ߴ�." << endl;
	cout << "\t3. ���ο� �׷��� �����ߴ�." << endl;
	cout << "\t4. ���ο� ��찡 �����ߴ�." << endl;
	cout << "\t5. ���ο� �Ҽӻ簡 �����." << endl;
	cout << "\t6. ���ο� ��ȭ�� ���������." << endl;
	cout << "\t7. ó������" << endl;

	while (trigger <= 0 || trigger > 6) { // �߸��� �޴� �Է½� ���Է� �䱸
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "�˸��� �޴��� �Է��ϼ���." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			insert_Menu();
			return;
		}

		switch (select_Num) {
		case 1: //���ο� �Ŵ����� �Ի��ߴ�.
			insert_Manager();
			break;
		case 2: //���ο� ������ �����ߴ�.
			insert_Singer();
			break;
		case 3: //���ο� �׷��� �����ߴ�.
			insert_Group();
			break;
		case 4: //���ο� ��찡 �����ߴ�.
			insert_Actor();
			break;
		case 5: //���ο� �Ҽӻ簡 �����.
			insert_Agency();
			break;
		case 6: //���ο� ��ȭ�� ���������.
			insert_Movie();
			break;
		case 7: //ó������
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

void DB_Control::delete_Menu() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a Delete Menu you want -------" << endl;
	cout << "\t1. �Ŵ����� ����ߴ�." << endl;
	cout << "\t2. ������ �����ߴ�." << endl;
	cout << "\t3. ��찡 �����ߴ�." << endl;
	cout << "\t4. �Ҽӻ簡 ���ߴ�." << endl;
	cout << "\t5. ��ȭ���� ���ߴ�." << endl;
	cout << "\t6. ó������" << endl;

	while (trigger <= 0 || trigger > 5) { // �߸��� �޴� �Է½� ���Է� �䱸
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "�˸��� �޴��� �Է��ϼ���." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			delete_Menu();
			return;
		}

		switch (select_Num) {
		case 1: //�Ŵ����� ����ߴ�.
			delete_Manager();
			break;
		case 2: //������ �����ߴ�.
			delete_Singer();
			break;
		case 3: //��찡 �����ߴ�.
			delete_Actor();
			break;
		case 4: //�Ҽӻ簡 ���ߴ�.
			delete_Agency();
			break;
		case 5: //��ȭ���� ���ߴ�.
			delete_Theater();
			break;
		case 6: //ó������
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

void DB_Control::update_Menu() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a Update Menu you want -------" << endl;
	cout << "\t1. ���� or �׷� or ����� �Ŵ����� ���� �����ƴ�." << endl;
	cout << "\t2. �Ŵ����� ������ �ø��� �ʹ�." << endl;
	cout << "\t3. ������ ������ �ø��� �ʹ�." << endl;
	cout << "\t4. �׷��� ����� �� ���� Ż�� �ߴ�." << endl;
	cout << "\t5. ��ȭ���� ��ȭ��ȣ�� ����ƴ�." << endl;
	cout << "\t6. ó������" << endl;

	while (trigger <= 0 || trigger > 5) { // �߸��� �޴� �Է½� ���Է� �䱸
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "�˸��� �޴��� �Է��ϼ���." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			update_Menu();
			return;
		}

		switch (select_Num) {
		case 1: //���� �Ի��� �Ŵ����� ������ ���� or �׷� or ��찡 �����ƴ�.
			update_Manager();
			break;
		case 2: //�Ŵ����� ������ �ø��� �ʹ�.
			update_Manager_Salary();
			break;
		case 3: //������ ������ �ø��� �ʹ�.
			update_Singer_Salary();
			break;
		case 4: //�׷��� ����� �� ���� Ż�� �ߴ�. 
			update_Group_Out();
			break;
		case 5: //��ȭ���� ��ȭ��ȣ�� ����ƴ�.
			update_Theater_Tel();
			break;
		case 6: //ó������
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

DB_Control::DB_Control() {
	print_Form();
}