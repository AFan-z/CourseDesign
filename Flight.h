
#define MAX 50                      //�����������Ϊ50

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
	int length;					 //��������
}flightLists;


//ѡ�����(FlightSystem.c)
void SelectOptions(flightLists *info);



/** ** ** ** ** ** ** ¼��(FlightInfoInput.c) ** ** ** ** ** ** ** ** ** ** ** **/


//ѡ����Ҫͨ������Ϣ¼�뺽����Ϣ
void InputSelectOne(flightLists *info);

//����ԭ�е������ļ���Ϣ
void InputByOld(flightLists *info);

//������Ϣ¼��
void InputInfo(flightLists *info);

//���ļ���¼�뺽����Ϣ
void InfoInputByFlie(flightLists *info);

//��ӡ������Ϣ
void InfoPrint(flightLists *info);

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/



/** ** ** ** ** ** ** ��ѯ(FlightInfoInput.c) ** ** ** ** ** ** ** ** ** ** ** **/

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

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/



/** ** ** ** ** ** ** ����(FlightInfoSort.c) ** ** ** ** ** ** ** ** ** ** ** **/

//ѡ����Ҫͨ������Ϣ���򺽰���Ϣ
void SortSelectOne(flightLists *info);

//ͨ������Ž�����������
void SortByFlightNum(flightLists *info);

//ͨ��Ʊ�۽���������������
void SortByPrice(flightLists *info);

//��ӡ�������Ϣ
void SortPrint(flightLists *info);

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/



/** ** ** ** ** ** ** ɾ��(FlightInfoDelete.c) ** ** ** ** ** ** ** ** ** ** ** **/

//ѡ����Ҫͨ������Ϣɾ��������Ϣ
void DeleteSelectOne(flightLists *info);

//���ݺ����ɾ�����������Ϣ
void DeleteByFlightNum(flightLists *info, int one);

//���ݻ���ɾ�����������Ϣ
void DeleteByPlaneType(flightLists *info, int one);

//ɾ������
void DeleteOptions(flightLists *info, char type[], int one);

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/




/** ** ** ** ** ** ** �޸�(FlightInfoUpdate.c) ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/


//ѡ����Ҫͨ������Ϣ�޸ĺ�����Ϣ
void UpdateSelectOne(flightLists *info);

//���ݺ�����޸ĺ��������Ϣ
void UpdateByFlightNum(flightLists *info);

//���ݻ����޸ĺ��������Ϣ
void UpdateByPlaneType(flightLists *info);


//ȷ����Ҫ�޸ĵĺ�����Ϣ
int UpdateWhichOne(flightLists *info, int num[], int j);

//ѡ���޸�ĳһ���ĺ�����Ϣ
void UpdateSelect(flightLists *info, int num[], int j);


//�޸ĺ����
void UpdateFlightNum(flightLists *info, int one, int whichOne, int num[], int j);

//�޸����վ
void UpdateStartPoint(flightLists *info, int one, int whichOne, int num[], int j);

//�޸��յ�վ
void UpdateEndPoint(flightLists *info, int one, int whichOne, int num[], int j);

//�޸����ʱ��
void UpdateStartTime(flightLists *info, int one, int whichOne, int num[], int j);

//�޸ĵ���ʱ��
void UpdateEndTime(flightLists *info, int one, int whichOne, int num[], int j);

//�޸Ļ���
void UpdatePlaneType(flightLists *info, int one, int whichOne, int num[], int j);

//�޸�Ʊ��
void UpdatePrice(flightLists *info, int one, int whichOne, int num[], int j);


/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/