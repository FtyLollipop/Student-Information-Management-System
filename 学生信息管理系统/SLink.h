//ѧ�����ݽṹ
typedef struct Student
{
	int num;		//ѧ��
	char name[20];	//����
	char sex[3];	//�Ա�
	int age;		//����
	float ma;		//��ѧ�ɼ�
	float ch;		//���ĳɼ�
	float en;		//Ӣ��ɼ�
}Student;

//ѧ����������
typedef struct SLINK
{
	Student stu;
	struct SLINK *next;
}SLINK;
