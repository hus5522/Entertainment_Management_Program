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
	void update_MoS();	//������ �Ŵ��� ����
	void update_MoG();	//�׷��� �Ŵ��� ����
	void update_MoA();	//����� �Ŵ��� ����
	//���� or �׷� or ����� �Ŵ����� ���� �����ƴ�.
	void update_Manager();
	//�Ŵ����� ������ ����Ѵ� ( �Ŵ����� �̸��� ������ �Է¹��� )
	void update_Manager_Salary();
	//������ ������ ����Ѵ� ( ������ �̸��� ������ �Է¹��� )
	void update_Singer_Salary();
	//�׷��� ����� �� ���� Ż�� �ߴ�. ( �׷��� Ż���� ��� �� �Է¹���)
	void update_Group_Out();
	//��ȭ���� ��ȭ��ȣ�� ����ƴ� (��ȭ�� ��� ��ȭ��ȣ�� �Է¹���)
	void update_Theater_Tel();

	//update menu

	//������
	public: DB_Control();
};