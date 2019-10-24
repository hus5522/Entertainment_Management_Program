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
			case 1: //직접 쿼리 입력
				insert_Query();
				system("Pause"); // 쿼리문의 결과를 잠시 보여준 후 처음 화면으로
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
				cout << "알맞은 메뉴를 입력하세요." << endl;
				break;
		}
	}
	else {
		cout << "알맞은 메뉴를 입력하세요." << endl;
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
	cout << "\t1. 소속사" << endl;
	cout << "\t2. 매니저" << endl;
	cout << "\t3. 가수" << endl;
	cout << "\t4. 개인 팬클럽" << endl;
	cout << "\t5. 그룹" << endl;
	cout << "\t6. 그룹 팬클럽" << endl;
	cout << "\t7. 영화배우" << endl;
	cout << "\t8. 배급된 영화" << endl;
	cout << "\t9. 영화관" << endl;
	cout << "\t10. 처음으로" << endl;

	while (trigger <= 0 || trigger > 10) { // 잘못된 메뉴 입력시 재입력 요구
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "알맞은 메뉴를 입력하세요." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			view_Table();
			return;
		}

		switch (select_Num) {
			case 1: //소속사 테이블 출력
				show_Agency();
				break;
			case 2: //매니저 테이블 출력
				show_Manager();
				break;
			case 3: //가수 테이블 출력
				show_Singer();
				break;
			case 4: //개인 팬클럽 테이블 출력
				show_SinglePan();
				break;
			case 5: //그룹 테이블 출력
				show_Group();
				break;
			case 6: //그룹 팬클럽 테이블 출력
				show_GroupPan();
				break;
			case 7: //영화배우 테이블 출력
				show_Actor();
				break;
			case 8: //배급된영화 테이블 출력
				show_Film();
				break;
			case 9: //영화관 테이블 출력
				show_Theater();
				break;
			case 10: //처음으로
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

void DB_Control::select_Menu() {
	
	system("cls");
	int trigger = 0;

	cout << "------- Select number you want -------" << endl;
	cout << "\t< ↓2개의 조인을 사용한 메뉴↓ >" << endl;
	cout << "\t(소속사 명을 입력받음)" << endl;
	cout << "\t1. 해당 소속사명과 거기에 소속된 모든 가수의 활동명을 찾아라." << endl;
	cout << "\t2. 해당 소속사명과 거기에 소속된 모든 그룹의 활동명을 찾아라" << endl;
	cout << "\t3. 해당 소속사명과 거기에 소속된 모든 배우의 활동명을 찾아라." << endl;
	cout << "\t4. 해당 소속사명과 거기에 소속된 모든 매니저의 이름을 찾아라." << endl;
	cout << "\t5. 해당 소속사명과 그 소속사가 배급한 영화제목을 찾아라." << endl;
	cout << "\t(매니저 명을 입력받음)" << endl;
	cout << "\t6. 해당 매니저가 관리하고 있는 가수 or 그룹 or 배우를 찾아라." << endl;
	cout << "\t< ↓3개의 조인을 사용한 메뉴↓ >" << endl;
	cout << "\t(소속사 명을 입력받음)" << endl;
	cout << "\t7. 해당 소속사명과 거기에 소속된 모든 가수의 활동명과 그 가수의 개인 팬클럽명을 찾아라." << endl;
	cout << "\t8. 해당 소속사명과 거기에 소속된 모든 그룹의 그룹명과 그 그룹의 그룹 팬클럽명을 찾아라." << endl;
	cout << "\t< ↓4개의 조인을 사용한 메뉴↓ >" << endl;
	cout << "\t(소속사 명을 입력받음)" << endl;
	cout << "\t9. 해당 소속사명과 거기에 소속된 모든 가수의 활동명과 그 가수의 개인 팬클럽명과 그 가수의 매니저 이름을 찾아라." << endl;
	cout << "\t10.해당 소속사명과 거기에 소속된 모든 그룹의 활동명과 그 그룹의 그룹 팬클럽명과 그 그룹의 매니저 이름을 찾아라." << endl;
	cout << "\t11. 처음으로" << endl;

	while (trigger <= 0 || trigger > 11) { // 잘못된 메뉴 입력시 재입력 요구
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "알맞은 메뉴를 입력하세요." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			select_Menu();
			return;
		}

		switch (select_Num) {
		case 1: // 소속사테이블과 가수테이블을 조인하여 소속사와 가수활동명을 찾기
			singer_Two_Join();
			break;
		case 2: // 소속사테이블과 그룹테이블을 조인하여 소속사와 그룹명을 찾기
			group_Two_Join();
			break;
		case 3: // 소속사테이블과 배우테이블을 조인하여 소속사와 배우 활동명을 찾기
			actor_Two_Join();
			break;
		case 4: // 소속사테이블과 매니저테이블을 조인하여 소속사와 매니저이름 찾기
			manager_Two_Join();
			break;
		case 5: // 소속사테이블과 배급된영화 테이블을 조인하여 소속사와 그 소속사가 만든 영화제목을 찾기
			movie_Two_Join();
			break;
		case 6: // 매니저 테이블과 가수 or 그룹 or 영화배우 테이블을 조인하여 그 매니저가 관리하는 사람 찾기
			search_By_Manager();
			break;
		case 7: // 해당 소속사명과 거기에 소속된 모든 가수의 활동명과 그 가수의 개인 팬클럽명을 찾아라
			singer_Three_Join();
			break;
		case 8: // 해당 소속사명과 거기에 소속된 모든 그룹의 그룹명과 그 그룹의 그룹 팬클럽명을 찾아라
			group_Three_Join();
			break;
		case 9: // 해당 소속사명과 거기에 소속된 모든 가수의 활동명과 그 가수의 개인 팬클럽명과 그 가수의 매니저 이름을 찾아라
			singer_Four_Join();
			break;
		case 10: //해당 소속사명과 거기에 소속된 모든 그룹의 활동명과 그 그룹의 그룹 팬클럽명과 그 그룹의 매니저 이름을 찾아라
			group_Four_Join();
			break;
		case 11: //처음으로
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

void DB_Control::insert_Menu() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a Insert Menu you want -------" << endl;
	cout << "\t1. 새로운 매니저가 입사했다." << endl;
	cout << "\t2. 새로운 가수가 데뷔했다." << endl;
	cout << "\t3. 새로운 그룹이 데뷔했다." << endl;
	cout << "\t4. 새로운 배우가 데뷔했다." << endl;
	cout << "\t5. 새로운 소속사가 생겼다." << endl;
	cout << "\t6. 새로운 영화가 만들어졌다." << endl;
	cout << "\t7. 처음으로" << endl;

	while (trigger <= 0 || trigger > 6) { // 잘못된 메뉴 입력시 재입력 요구
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "알맞은 메뉴를 입력하세요." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			insert_Menu();
			return;
		}

		switch (select_Num) {
		case 1: //새로운 매니저가 입사했다.
			insert_Manager();
			break;
		case 2: //새로운 가수가 데뷔했다.
			insert_Singer();
			break;
		case 3: //새로운 그룹이 데뷔했다.
			insert_Group();
			break;
		case 4: //새로운 배우가 데뷔했다.
			insert_Actor();
			break;
		case 5: //새로운 소속사가 생겼다.
			insert_Agency();
			break;
		case 6: //새로운 영화가 만들어졌다.
			insert_Movie();
			break;
		case 7: //처음으로
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

void DB_Control::delete_Menu() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a Delete Menu you want -------" << endl;
	cout << "\t1. 매니저가 퇴사했다." << endl;
	cout << "\t2. 가수가 은퇴했다." << endl;
	cout << "\t3. 배우가 은퇴했다." << endl;
	cout << "\t4. 소속사가 망했다." << endl;
	cout << "\t5. 영화관이 망했다." << endl;
	cout << "\t6. 처음으로" << endl;

	while (trigger <= 0 || trigger > 5) { // 잘못된 메뉴 입력시 재입력 요구
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "알맞은 메뉴를 입력하세요." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			delete_Menu();
			return;
		}

		switch (select_Num) {
		case 1: //매니저가 퇴사했다.
			delete_Manager();
			break;
		case 2: //가수가 은퇴했다.
			delete_Singer();
			break;
		case 3: //배우가 은퇴했다.
			delete_Actor();
			break;
		case 4: //소속사가 망했다.
			delete_Agency();
			break;
		case 5: //영화관이 망했다.
			delete_Theater();
			break;
		case 6: //처음으로
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

void DB_Control::update_Menu() {
	system("cls");
	int trigger = 0;

	cout << "------- Select a Update Menu you want -------" << endl;
	cout << "\t1. 가수 or 그룹 or 배우의 매니저가 새로 배정됐다." << endl;
	cout << "\t2. 매니저의 월급을 올리고 싶다." << endl;
	cout << "\t3. 가수의 월급을 올리고 싶다." << endl;
	cout << "\t4. 그룹의 멤버중 몇 명이 탈퇴를 했다." << endl;
	cout << "\t5. 영화관의 전화번호가 변경됐다." << endl;
	cout << "\t6. 처음으로" << endl;

	while (trigger <= 0 || trigger > 5) { // 잘못된 메뉴 입력시 재입력 요구
		cout << "Your choice -> ";
		cin >> select_Num;

		while (cin.get() != '\n');

		if (!cin) {
			cout << "알맞은 메뉴를 입력하세요." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			update_Menu();
			return;
		}

		switch (select_Num) {
		case 1: //새로 입사한 매니저가 관리할 가수 or 그룹 or 배우가 배정됐다.
			update_Manager();
			break;
		case 2: //매니저의 월급을 올리고 싶다.
			update_Manager_Salary();
			break;
		case 3: //가수의 월급을 올리고 싶다.
			update_Singer_Salary();
			break;
		case 4: //그룹의 멤버중 몇 명이 탈퇴를 했다. 
			update_Group_Out();
			break;
		case 5: //영화관의 전화번호가 변경됐다.
			update_Theater_Tel();
			break;
		case 6: //처음으로
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

DB_Control::DB_Control() {
	print_Form();
}