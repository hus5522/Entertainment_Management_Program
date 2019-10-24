#pragma once

class DB_Control {
	int select_Num;

	//Main menu
	void view_Table();
	void select_Menu();
	void insert_Menu();
	void delete_Menu();
	void update_Menu();
	void print_Form();
	//Main menu

	//view_Table();
	void show_Agency();
	void show_Manager();
	void show_Singer();
	void show_SinglePan();
	void show_Group();
	void show_GroupPan();
	void show_Actor();
	void show_Film();
	void show_Theater();
	//view_Table();

	//Select menu
	void insert_Query();
	void singer_Two_Join();
	void group_Two_Join();
	void actor_Two_Join();
	void manager_Two_Join();
	void movie_Two_Join();
	void search_MS(char* inserted);
	void search_MG(char* inserted);
	void search_MA(char* inserted);
	void search_By_Manager();
	void singer_Three_Join();
	void group_Three_Join();
	void singer_Four_Join();
	void group_Four_Join();
	//Select menu

	//Insert menu
	void insert_Manager();
	void insert_Singer();
	void insert_Group();
	void insert_Actor();
	void insert_Agency();
	void insert_Movie();
	//Insert menu

	//delete menu
	void delete_Manager();
	void delete_Singer();
	void delete_Actor();
	void delete_Agency();
	void delete_Theater();
	//delete menu

	//update menu
	void update_MoS();	//가수의 매니저 변경
	void update_MoG();	//그룹의 매니저 변경
	void update_MoA();	//배우의 매니저 변경
	//가수 or 그룹 or 배우의 매니저가 새로 배정됐다.
	void update_Manager();
	//매니저의 월급이 상승한다 ( 매니저의 이름과 배율을 입력받음 )
	void update_Manager_Salary();
	//가수의 월급이 상승한다 ( 가수의 이름과 배율을 입력받음 )
	void update_Singer_Salary();
	//그룹의 멤버중 몇 명이 탈퇴를 했다. ( 그룹명과 탈퇴한 사람 수 입력받음)
	void update_Group_Out();
	//영화관의 전화번호가 변경됐다 (영화관 명과 전화번호를 입력받음)
	void update_Theater_Tel();

	//update menu

	//생성자
	public: DB_Control();
};