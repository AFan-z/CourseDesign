
#define MAX 50

typedef struct
{                                   //������Ϣ
	char FlightNum[10];             //�����
	char StartPoint[10];			//���վ
	char EndPoint[10];				//�յ�վ
	char StartTime[15];				//���ʱ��
	char EndTime[15];				//����ʱ��
	char PlaneType[10];				//����
	int price;						//Ʊ��
}flightInfo;

typedef struct {
	flightInfo infos[MAX];
	int length;					 //�������
}flightLists;

//ѡ����Ҫͨ������Ϣ��ѯ������Ϣ
void SearchSelectOne(flightLists *info);

//ͨ������Ų�ѯ
void searchByFlightNum(flightLists *info);

//ͨ�����վ��ѯ
void searchByStartPoint(flightLists *info);

//ͨ���յ�վ��ѯ
void searchByEndPoint(flightLists *info);

//ͨ���յ�վ��ѯ
void searchByStartTime(flightLists *info);

//ͨ������ʱ���ѯ
void searchByEndTime(flightLists *info);

//ͨ�����Ͳ�ѯ
void searchByPlaneType(flightLists *info);