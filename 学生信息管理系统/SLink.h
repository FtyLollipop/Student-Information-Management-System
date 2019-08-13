//学生数据结构
typedef struct Student
{
	int num;		//学号
	char name[20];	//姓名
	char sex[3];	//性别
	int age;		//年龄
	float ma;		//数学成绩
	float ch;		//语文成绩
	float en;		//英语成绩
}Student;

//学生数据链表
typedef struct SLINK
{
	Student stu;
	struct SLINK *next;
}SLINK;
